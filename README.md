# desk alarm

## what it is
This is a desk toy which uses a esp32 and buttons to play different sounds when the buttons are clicked so basically each button will play an alarm from a sircraft and the display can be used to change the aircraft which is currently selected

### why did i make it
originally i wanted to make a project for the hardware speedrun and i wanted it to be different from devboards and macropads.SO i remembered that i wanted to buy something like this a few months back and decided why not make an even better version of it myself.

## what it does
This will play sounds of different planes when the buttons are clicked the buttons next to the disply can be used to change the plane and the other buttons will play a different sound

## why it exists 
well, i wanted to buy a product like this but it was 50$ with very expensive shiping and only had one plane so i decided to make one which will have may more functions and this is more cheaper then the product i wanted to buy and also meets my needs


<img width="852" height="642" alt="image" src="https://github.com/user-attachments/assets/8fd118cf-b310-4c45-8a28-2ca157e64230" />

## assembly buide

### solder all the compnents

this uses a lot of THT and some SMD components which can easily be soldered with a stranded soldering iron 
if you do not know soldering refer to youtube

### ESP32-S3 Firmware Flashing Guide

Follow these steps to upload the firmware and sound files to your ESP32-S3 using the Arduino IDE.

1. **Install ESP32 Board Core**
   * Open Arduino IDE and go to **File > Preferences**.
   * Add `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json` to **Additional Boards Manager URLs**.
   * Open **Tools > Board > Boards Manager**, search for **esp32**, and click **Install**.

2. **Configure Target Board Settings**
   * Go to **Tools > Board > ESP32 Arduino** and select **ESP32S3 Dev Module**.
   * Set **Partition Scheme** to **Default 4MB with spiffs** (allocates flash memory for audio files).
   * Set **USB CDC On Boot** to **Enabled** (allows USB serial output).

3. **Prepare & Flash Sound Files to LittleFS**
   * Save your sketch file.
   * Open the sketch folder by clicking **Sketch > Show Sketch Folder**.
   * Create a folder named `data` in this directory.
   * Place your `.wav` files inside using the path structure: `/p1/a1.wav`, `/p1/a2.wav`, `/p2/a1.wav`, etc.
   * Run the **LittleFS Data Upload** tool from **Tools > ESP32 Sketch Data Upload** to upload the `/data` folder to flash memory.

4. **Upload Firmware**
   * Connect your ESP32-S3 board to your PC via USB.
   * Select your device's COM port under **Tools > Port**.
   * Click the **Upload** button. 





made in easyeda
total price aproxx 43$ (as of aug 2026 with voulcher from jlc too)
 made for hackclub 
