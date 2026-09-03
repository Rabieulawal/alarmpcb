#include <Arduino.h>
#include <FS.h>
#include <LittleFS.h>

#define PIN_AUDIO    1
#define PIN_TM_DIO   10
#define PIN_TM_CLK   11

const uint8_t rowPins[3] = {4, 5, 6};
const uint8_t colPins[3] = {7, 8, 9};

uint8_t currentPlane = 1;
const uint8_t maxPlanes = 5;

const uint8_t segmentP = 0x73;
const uint8_t digitMap[] = {
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f
};

class TM1637Display {
private:
  uint8_t clkPin, dioPin;
  void start() {
    pinMode(dioPin, OUTPUT);
    digitalWrite(dioPin, HIGH); digitalWrite(clkPin, HIGH);
    delayMicroseconds(2); digitalWrite(dioPin, LOW);
  }
  void stop() {
    pinMode(dioPin, OUTPUT);
    digitalWrite(clkPin, LOW); digitalWrite(dioPin, LOW);
    delayMicroseconds(2); digitalWrite(clkPin, HIGH); digitalWrite(dioPin, HIGH);
    delayMicroseconds(2);
  }
  void writeByte(uint8_t b) {
    for (uint8_t i = 0; i < 8; i++) {
      digitalWrite(clkPin, LOW);
      digitalWrite(dioPin, (b & 0x01) ? HIGH : LOW);
      delayMicroseconds(2); digitalWrite(clkPin, HIGH); delayMicroseconds(2);
      b >>= 1;
    }
    digitalWrite(clkPin, LOW); pinMode(dioPin, INPUT);
    digitalWrite(clkPin, HIGH); delayMicroseconds(2);
    pinMode(dioPin, OUTPUT);
  }
public:
  TM1637Display(uint8_t clk, uint8_t dio) : clkPin(clk), dioPin(dio) {}
  void init() {
    pinMode(clkPin, OUTPUT); pinMode(dioPin, OUTPUT);
    start(); writeByte(0x8f); stop();
  }
  void showPlane(uint8_t planeNum) {
    start(); writeByte(0x40); stop();
    start(); writeByte(0xC0);
    writeByte(segmentP);
    writeByte(0x40);
    writeByte(digitMap[(planeNum / 10) % 10]);
    writeByte(digitMap[planeNum % 10]);
    stop();
  }
};

TM1637Display display(PIN_TM_CLK, PIN_TM_DIO);

void playWAV(const char* filename) {
  if (!LittleFS.exists(filename)) {
    Serial.printf("File not found: %s\n", filename);
    return;
  }

  File wavFile = LittleFS.open(filename, "r");
  if (!wavFile) return;

  wavFile.seek(44);

  ledcAttachChannel(PIN_AUDIO, 32000, 8, 0);

  uint8_t sample;
  while (wavFile.available()) {
    sample = wavFile.read();
    ledcWrite(PIN_AUDIO, sample);
    delayMicroseconds(45);
  }

  wavFile.close();
  ledcWrite(PIN_AUDIO, 0);
}

uint8_t scanKeypad() {
  for (uint8_t r = 0; r < 3; r++) {
    digitalWrite(rowPins[r], HIGH);
    delayMicroseconds(20);
    for (uint8_t c = 0; c < 3; c++) {
      if (digitalRead(colPins[c]) == HIGH) {
        digitalWrite(rowPins[r], LOW);
        return (r * 3) + c + 1;
      }
    }
    digitalWrite(rowPins[r], LOW);
  }
  return 0;
}

void setup() {
  Serial.begin(115200);

  if (!LittleFS.begin(true)) {
    Serial.println("LittleFS Mount Failed");
  }

  for (uint8_t i = 0; i < 3; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], LOW);
    pinMode(colPins[i], INPUT_PULLDOWN);
  }

  display.init();
  display.showPlane(currentPlane);
}

uint8_t lastBtn = 0;
unsigned long lastDebounce = 0;

void loop() {
  uint8_t btn = scanKeypad();

  if (btn != 0 && btn != lastBtn && (millis() - lastDebounce > 150)) {
    lastDebounce = millis();
    lastBtn = btn;

    if (btn == 2) {
      currentPlane = (currentPlane % maxPlanes) + 1;
      display.showPlane(currentPlane);
      Serial.printf("Switched to Aircraft P-%02d\n", currentPlane);
    } 
    else if (btn == 3) {
      currentPlane = (currentPlane == 1) ? maxPlanes : currentPlane - 1;
      display.showPlane(currentPlane);
      Serial.printf("Switched to Aircraft P-%02d\n", currentPlane);
    } 
    else {
      uint8_t alarmMap[] = {0, 1, 0, 0, 2, 3, 4, 5, 6, 7};
      uint8_t alarmIndex = alarmMap[btn];

      if (alarmIndex > 0) {
        char path[32];
        snprintf(path, sizeof(path), "/p%d/a%d.wav", currentPlane, alarmIndex);
        Serial.printf("Playing: %s\n", path);
        playWAV(path);
      }
    }
  } else if (btn == 0) {
    lastBtn = 0;
  }
}