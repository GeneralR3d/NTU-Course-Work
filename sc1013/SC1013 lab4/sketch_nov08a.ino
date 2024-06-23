#include<SPI.h>
#include<MFRC522.h>
MFRC522 mfrc522(10,9); //create MFRC522 instance
byte MyID[4]; // array to store the card
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SPI.begin();
mfrc522.PCD_Init();
Serial.println("Ready! Present NFC card to display UID and Type ...");

}

void loop() {
  // put your main code here, to run repeatedly:
if(!mfrc522.PICC_IsNewCardPresent())return;  //look for new cards
if(!mfrc522.PICC_ReadCardSerial()) return; //select one of the cards

  //Read card ID and display it in hexadecimal
  Serial.print("Card ID:");
  for(byte i=0;i<4;i++)
  {
    MyID[i] =mfrc522.uid.uidByte[i];
    Serial.print(MyID[i] < 0x10 ? "0": " ");
    Serial.print(MyID[i],HEX);
  }

  //Read card type
  byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.print("  Type:  ");
  Serial.print(mfrc522.PICC_GetTypeName(piccType));
  Serial.println();

  //stop reading
  mfrc522.PICC_HaltA();

  //compare the card ID with preset value e.g. 05 23 50 2B
  if(*(uint32_t*)MyID==0x2B502305)
  Serial.println("Correct card: Unlock");
  else
  Serial.println("Unknown card: Access Denied");
}
