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

<img width="712" height="522" alt="image" src="https://github.com/user-attachments/assets/9cb0a6fc-6c8c-40f4-bb34-7505577f2ac9" />


## assembly Guide

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
  
     ## BOM

The bom is also present in BOM.csv as well as here also i need to buy some components more than they are required cuz lcsc has a minimum quantity but it is only adding some dollers cuz those parts are very cheap anyways.  

| LCSC# | MPN | Manufacturer | Package | Description | Quantity | Unit Price ($) | Extended Price ($) | Product Link |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| C49304925 | 330uF10V6.3x11GF | Econd | Through Hole,D6.3xL11mm | 10V ±20% 330uF 140mΩ Through Hole,D6.3xL11mm Aluminum Electrolytic Capacitors | 20 | 0.0225 | 0.45 | [Link](https://www.lcsc.com/product-detail/C49304925.html) |
| C2840026 | CG100ME511BPTWBOR | - | Through Hole,D5xL11mm | 10uF 25V Aluminum Electrolytic Capacitors Through Hole,D5xL11mm 2000hrs@105℃ | 50 | 0.0131 | 0.66 | [Link](https://www.lcsc.com/product-detail/C2840026.html) |
| C436244 | FM32X104K101EMGPSA | - | 1210 | 100nF ±10% 100V Ceramic Capacitor X7R 1210 | 10 | 0.0616 | 0.62 | [Link](https://www.lcsc.com/product-detail/C436244.html) |
| C49066 | CL32A107MQVNNNE | Samsung Electro-Mechanics | 1210 | 100uF ±20% 6.3V Ceramic Capacitor X5R 1210 | 1 | 0.3472 | 0.35 | [Link](https://www.lcsc.com/product-detail/C49066.html) |
| C5188434 | MX126-5.0-02P-GN01-Cu-S-A | MAX | Through Hole,P=5mm | 2 Position Wire to Board Terminal Block Through Hole 5mm | 20 | 0.0627 | 1.25 | [Link](https://www.lcsc.com/product-detail/C5188434.html) |
| C258182 | 1N4148 | onsemi | DO-35 | Diode 100V 200mA Through Hole DO-35 | 20 | 0.0330 | 0.66 | [Link](https://www.lcsc.com/product-detail/C258182.html) |
| C2980917 | SR720361W/32ARK | LED | Through Hole | Blue to white 4 70mW Common Cathode 0.36 Through Hole LED Character and Numeric RoHS | 1 | 1.0575 | 1.06 | [Link](https://www.lcsc.com/product-detail/C2980917.html) |
| C2896924 | CR1/8W-10K±5%-ST52VO | - | Through Hole,D2.3xL3.7mm | 10kΩ 125mW 200V Carbon Film Resistor ±350ppm/℃ ±5% Through Hole,D2.3xL3.7mm Through Hole Resistors | 100 | 0.0037 | 0.37 | [Link](https://www.lcsc.com/product-detail/C2896924.html) |
| C470717 | RK09Y11L0001 | ALPSALPINE | Through Hole | ±30% 10mW 10kΩ Through Hole Rotary Potentiometers, Rheostats RoHS | 1 | 0.8674 | 0.87 | [Link](https://www.lcsc.com/product-detail/C470717.html) |
| C18186456 | KH-12X12X9H-TJ | kinghelm | Through Hole,12x12mm | Tactile Switch 9mm 12mm x 12mm | 10 | 0.0580 | 0.58 | [Link](https://www.lcsc.com/product-detail/C18186456.html) |
| C20626143 | LCKFB-ESP32S3R8N8 | LCSC-boards- | - | Embedded MCU, DSP Evaluation Boards | 1 | 5.4162 | 5.42 | [Link](https://www.lcsc.com/product-detail/C20626143.html) |
| C20612516 | LM386N(XBLW) | XBLW | DIP-8 | 4mA 4V~12V 1-Channel 700mWx1@8Ω Class AB DIP-8 Audio Amplifiers RoHS | 5 | 0.1075 | 0.54 | [Link](https://www.lcsc.com/product-detail/C20612516.html) |
| C22767313 | TM1637-DIP20 | TM(Shenzhen Titan Micro Elec) | DIP-20 | 2-Wire Serial Interface 4.5V~5.5V DIP-20 LED Drivers ICs RoHS | 6 | 0.4589 | 2.75 | [Link](https://www.lcsc.com/product-detail/C22767313.html) |
| **COMPONENTS MERCHANDISE TOTAL** | - | - | - | - | **245** | - | **15.58** | - |
| **COMPONENTS DISCOUNT** | - | - | - | - | **1** | - | **-0.20** | - |
| **COMPONENTS SHIPPING FEE** | - | - | - | - | **1** | - | **12.95** | - |
| **PCB MERCHANDISE TOTAL** | - | - | - | Custom Printed Circuit Board Manufacturing | **1** | - | **10.30** | - |
| **PCB SHIPPING ESTIMATE** | - | - | - | - | **1** | - | **16.49** | - |
| **PCB DISCOUNT** | - | - | - | - | **1** | - | **-10.00** | - |
| **GRAND TOTAL** | - | - | - | - | **251** | - | **45.12** | - |


made in easyeda
total price aproxx 43$ (as of aug 2026 with voulcher from jlc too)
 made for hackclub 
