#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 0
#define TEMPERATURE_PRECISION 9 // Lower resolution

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

int numberOfDevices; // Number of temperature devices found

DeviceAddress tempDeviceAddress; // We'll use this variable to store a found device address

#include <Wire.h>
#include <ArduCAM.h>
#include <SPI.h>
#include <SD.h>
#include "memorysaver.h"
//This demo can only work on OV5640_MINI_5MP_PLUS or OV5642_MINI_5MP_PLUS platform.
#if !(defined (OV5640_MINI_5MP_PLUS)||defined (OV5642_MINI_5MP_PLUS))
#error Please select the hardware platform and camera module in the ../libraries/ArduCAM/memorysaver.h file
#endif
#define   FRAMES_NUM    0x06
// set pin 7 as the slave select for the digital pot:
const int CS = 3;
#define SD_CS 5
bool is_header = false;
int total_time = 0;
#if defined (OV5640_MINI_5MP_PLUS)
  ArduCAM myCAM(OV5640, CS);
#else
  ArduCAM myCAM(OV5642, CS);
#endif
uint8_t read_fifo_burst(ArduCAM myCAM);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
  
  // Grab a count of devices on the wire
  numberOfDevices = sensors.getDeviceCount();
  
  // locate devices on the bus
  Serial.print("Locating devices...");
  
  Serial.print("Found ");
  Serial.print(numberOfDevices, DEC);
  Serial.println(" devices.");

  // report parasite power requirements
  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");
  
  // Loop through each device, print out address
  for(int i=0;i<numberOfDevices; i++)
  {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i))
  {
    Serial.print("Found device ");
    Serial.print(i, DEC);
    Serial.print(" with address: ");
    printAddress(tempDeviceAddress);
    Serial.println();
    
    Serial.print("Setting resolution to ");
    Serial.println(TEMPERATURE_PRECISION, DEC);
    
    // set the resolution to TEMPERATURE_PRECISION bit (Each Dallas/Maxim device is capable of several different resolutions)
    sensors.setResolution(tempDeviceAddress, TEMPERATURE_PRECISION);
    
    Serial.print("Resolution actually set to: ");
    Serial.print(sensors.getResolution(tempDeviceAddress), DEC); 
    Serial.println();
  }else{
    Serial.print("Found ghost device at ");
    Serial.print(i, DEC);
    Serial.print(" but could not detect address. Check power and cabling");
  }
  }
// put your setup code here, to run once:
uint8_t vid, pid;
uint8_t temp;
#if defined(__SAM3X8E__)
  Wire1.begin();
#else
  Wire.begin();
#endif
Serial.begin(115200);
Serial.println(F("ArduCAM Start!"));

// set the CS as an output:
pinMode(CS, OUTPUT);
digitalWrite(CS, HIGH);

// initialize SPI:
SPI.begin();
//Reset the CPLD
myCAM.write_reg(0x07, 0x80);
delay(100);
myCAM.write_reg(0x07, 0x00);
delay(100); 
  
while(1){
  //Check if the ArduCAM SPI bus is OK
  myCAM.write_reg(ARDUCHIP_TEST1, 0x55);
  temp = myCAM.read_reg(ARDUCHIP_TEST1);
  if(temp != 0x55)
  {
    Serial.println(F("SPI interface Error!"));
    delay(1000);continue;
  }else{
    Serial.println(F("SPI interface OK."));break;
  }
}
#if defined (OV5640_MINI_5MP_PLUS)
while(1){
  //Check if the camera module type is OV5640
  myCAM.rdSensorReg16_8(OV5640_CHIPID_HIGH, &vid);
  myCAM.rdSensorReg16_8(OV5640_CHIPID_LOW, &pid);
  if ((vid != 0x56) || (pid != 0x40)){
    Serial.println(F("Can't find OV5640 module!"));
    delay(1000); continue;
  }else{
    Serial.println(F("OV5640 detected."));break;      
  }
}
#else
while(1){
  //Check if the camera module type is OV5642
  myCAM.rdSensorReg16_8(OV5642_CHIPID_HIGH, &vid);
  myCAM.rdSensorReg16_8(OV5642_CHIPID_LOW, &pid);
  if ((vid != 0x56) || (pid != 0x42)){
    Serial.println(F("Can't find OV5642 module!"));
    delay(1000);continue;
  }else{
    Serial.println(F("OV5642 detected."));break;      
  }
}
#endif
//Initialize SD Card
while(!SD.begin(SD_CS))
{
  Serial.println(F("SD Card Error!"));delay(1000);
}
Serial.println(F("SD Card detected."));
//Change to JPEG capture mode and initialize the OV5640 module
myCAM.set_format(JPEG);
myCAM.InitCAM();
myCAM.set_bit(ARDUCHIP_TIM, VSYNC_LEVEL_MASK);
myCAM.clear_fifo_flag();
myCAM.write_reg(ARDUCHIP_FRAMES, FRAMES_NUM);
}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  // method 1 - slower
  //Serial.print("Temp C: ");
  //Serial.print(sensors.getTempC(deviceAddress));
  //Serial.print(" Temp F: ");
  //Serial.print(sensors.getTempF(deviceAddress)); // Makes a second call to getTempC and then converts to Fahrenheit

  // method 2 - faster
  float tempC = sensors.getTempC(deviceAddress);
  if(tempC == DEVICE_DISCONNECTED_C) 
  {
    Serial.println("Error: Could not read temperature data");
    return;
  }
  Serial.print("Temp C: ");
  Serial.print(tempC);
  Serial.print(" Temp F: ");
  Serial.println(DallasTemperature::toFahrenheit(tempC)); // Converts tempC to Fahrenheit
}

void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  
  
  // Loop through each device, print out temperature data
  for(int i=0;i<numberOfDevices; i++)
  {
    // Search the wire for address
    if(sensors.getAddress(tempDeviceAddress, i))
  {
    // Output the device ID
    Serial.print("Temperature for device: ");
    Serial.println(i,DEC);
    
    // It responds almost immediately. Let's print out the data
    printTemperature(tempDeviceAddress); // Use a simple function to print out the data
  } 
  //else ghost device! Check your power requirements and cabling
  
  }
  // sensor UV Light
  float sensorVoltage; 
  float sensorValue;
  float uVindex;
  
  sensorValue = analogRead(A4);
  sensorVoltage = sensorValue/1024*5;
  uVindex = sensorVoltage/0.1;
  Serial.print("sensor reading = ");
  Serial.print(sensorValue);
  Serial.println("");
  Serial.print("sensor voltage = ");
  Serial.print(sensorVoltage);
  Serial.println(" V");
  Serial.print("UV index = ");
  Serial.println(uVindex);
  Serial.println();

//camara
  // put your main code here, to run repeatedly:
myCAM.flush_fifo();
myCAM.clear_fifo_flag();
#if defined (OV5640_MINI_5MP_PLUS)
  myCAM.OV5640_set_JPEG_size(OV5640_320x240);delay(1000);
#else
  myCAM.OV5642_set_JPEG_size(OV5642_320x240);delay(1000);
#endif
//Start capture
myCAM.start_capture();
Serial.println(F("start capture."));
total_time = millis();
while ( !myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK)); 
Serial.println(F("CAM Capture Done."));
total_time = millis() - total_time;
Serial.print(F("capture total_time used (in miliseconds):"));
Serial.println(total_time, DEC);
total_time = millis();
read_fifo_burst(myCAM);
total_time = millis() - total_time;
Serial.print(F("save capture total_time used (in miliseconds):"));
Serial.println(total_time, DEC);
//Clear the capture done flag
myCAM.clear_fifo_flag();
delay(5000);
}
uint8_t read_fifo_burst(ArduCAM myCAM)
{
uint8_t temp = 0, temp_last = 0;
uint32_t length = 0;
static int i = 0;
static int k = 0;
char str[8];
File outFile;
byte buf[256]; 
length = myCAM.read_fifo_length();
Serial.print(F("The fifo length is :"));
Serial.println(length, DEC);
if (length >= MAX_FIFO_SIZE) //8M
{
  Serial.println("Over size.");
  return 0;
}
if (length == 0 ) //0 kb
{
  Serial.println(F("Size is 0."));
  return 0;
} 
myCAM.CS_LOW();
myCAM.set_fifo_burst();//Set fifo burst mode
i = 0;
while ( length-- )
{
  temp_last = temp;
  temp =  SPI.transfer(0x00);
  //Read JPEG data from FIFO
  if ( (temp == 0xD9) && (temp_last == 0xFF) ) //If find the end ,break while,
  {
    buf[i++] = temp;  //save the last  0XD9     
    //Write the remain bytes in the buffer
    myCAM.CS_HIGH();
    outFile.write(buf, i);    
    //Close the file
    outFile.close();
    Serial.println(F("OK"));
    is_header = false;
    myCAM.CS_LOW();
    myCAM.set_fifo_burst();
    i = 0;
  }  
  if (is_header == true)
  { 
    //Write image data to buffer if not full
    if (i < 256)
     buf[i++] = temp;
    else
    {
      //Write 256 bytes image data to file
      myCAM.CS_HIGH();
      outFile.write(buf, 256);
      i = 0;
      buf[i++] = temp;
      myCAM.CS_LOW();
      myCAM.set_fifo_burst();
    }        
  }
  else if ((temp == 0xD8) & (temp_last == 0xFF))
  {
    is_header = true;
    myCAM.CS_HIGH();
    //Create a avi file
    k = k + 1;
    itoa(k, str, 10);
    strcat(str, ".jpg");
    //Open the new file
    outFile = SD.open(str, O_WRITE | O_CREAT | O_TRUNC);
    if (! outFile)
    {
      Serial.println(F("File open failed"));
      while (1);
    }
    myCAM.CS_LOW();
    myCAM.set_fifo_burst();   
    buf[i++] = temp_last;
    buf[i++] = temp;   
  }
}
  myCAM.CS_HIGH();
  return 1;
}
// function to print a device address
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
  
}
