byte dsAddr[8];
byte dsScratchpadMem[9];
//step-3
#include<OneWire.h>
OneWire ds(10);// output of DS with Dpin-10

void setup() {
  //step-4
  ds.reset();         
  ds.search(dsAddr); //it collects Rom code/address(8 byte,16 digit(8*2),64(8*8) bit) and automatically saves it in dsAdder array 

//step-5
  Serial.begin(9600);
  Serial.print("Address : ");
 for(int i=0;i<8;i++)
 {
  if (dsAddr [i]<18)
 { Serial.print("0");}
 
  Serial.print(dsAddr[i],HEX);
 }
 Serial.println();
 Serial.println();
}

void loop() {
  //step-6 (converting heat into bit as digital temp sensor)
  ds.reset();
  ds.select(dsAddr);  //selecting my sensor with its address as more sensors can be paralley connected
  ds.write(0x44);    //convert command
  delay(1000);
  //step-7 ............

  //step-8
  ds.reset();
  ds.select(dsAddr);//selecting my sensor with its address
  ds.write(0xBE);//command to transmiting data from EEPROM to Scratchpad Memory
  //code to read 9 byte(18(9*2) digit,72(9*8) bit) data from EEPROM to dsScratchpadMem(not autommatic like address)
  for(int i=0;i<9;i++)
  {
    dsScratchpadMem[i]=ds.read();
  }
  
  //step-9 (printing 9 byte Scratchpad Memory)
  Serial.print("Scratchpad Memory : ");
    for(int i=0;i<9;i++)
  {  
    if (dsScratchpadMem[i]<18)
    { Serial.print("0");}
       
    Serial.print(dsScratchpadMem[i],HEX);
  }
  Serial.println();
  //step-10 computing unsigned 16 bit rawdsTemp from byte-0 & byte-1 of scratchpad Memory
  unsigned int rawdsTemp = (dsScratchpadMem[1] << 8) | dsScratchpadMem[0]; // or operator & left shift as byte-1 is at bottom of byte-0
  float Temp=(float)rawdsTemp/16; //The value is a simple 16-bit signed integer that is 16 times larger than the temperature
  Serial.print("Room Temp : ");
  Serial.print(Temp);
  Serial.println(" Deg C");
  Serial.println();
  delay(2000);
}
