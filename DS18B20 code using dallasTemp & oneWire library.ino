#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 10
OneWire ds(10);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer;
byte data[9];  //to hold Scratch Pad data of Ds18B20
float DStemp;
byte busStatus;
void setup(void)
{

  Serial.begin(9600);
  sensors.begin();
  //sensors.isParasitePowerMode();
 
  sensors.getAddress(insideThermometer, 0);
  sensors.setResolution(insideThermometer, 10); // 0 R1 R0 1 1 1 1 1; R1 R0 = 00 (9); 01 (01); 10; 10 (11); 11 (12)

  ds.reset();
  ds.select(insideThermometer);    //selectimg the desired DS18B20
  ds.write(0xBE);                 //Function command to read Scratchpad Memory (9Byte)
  ds.read_bytes(data, 9);        //data comes from DS-scratchpad  and are saved into buffer data[9]
}

void printTemperature(DeviceAddress deviceAddress)
{
  DStemp = sensors.getTempC(deviceAddress);
  Serial.print("DST: ");
  Serial.print(DStemp);
  Serial.print(" ");
  Serial.println("deg C");
}

void loop(void)
{
  sensors.requestTemperatures();
  printTemperature(insideThermometer);    // Use a simple function to print out the data
  delay(2000);
}
