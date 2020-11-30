int ledR = 2;
int ledG = 3;
int buzzer = 4;

int car_out = 5;
int car_out_ack = 6;

// RFID_Module
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int servo = 7;
int servo_ack = 8;

//--------------------------------------------fonctions du programme:
//-------
void commande_servo(void){
   digitalWrite(servo,HIGH);
    delay(100);
    if(digitalRead(servo_ack)){
      digitalWrite(servo,LOW);
    }
    else{
      while(!digitalRead(servo_ack)){}
      digitalWrite(servo,LOW);
    }
}

//-----

void setup() { 
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(servo, OUTPUT);
  pinMode(servo_ack, OUTPUT);
  pinMode(car_out, OUTPUT);
  digitalWrite(car_out,LOW);
  pinMode(car_out_ack,INPUT);
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
}

void loop(){
  digitalWrite(ledG,LOW);
  digitalWrite(ledR,HIGH);
  digitalWrite(car_out,LOW);
  //----------------------------------------------------------------------------------------------------------------------
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  if (content.substring(1) == "15 DD CC 65" || content.substring(1) == "AB D6 B0 D5" || content.substring(1) == "90 90 CF A6" || content.substring(1) == "C5 E8 D3 65") //change here the UID of the card/cards that you want to give access
  {
    Serial.print("detected");
    digitalWrite(buzzer,HIGH); //--buzzer high
    delay(100);
    digitalWrite(buzzer,LOW); //--buzzer low
    digitalWrite(ledG,HIGH);
    digitalWrite(ledR,LOW);
    commande_servo();
    delay(5000);
    digitalWrite(ledG,LOW);
    digitalWrite(ledR,HIGH);
    // close_servo();
    digitalWrite(car_out,HIGH);
    delay(100);
    if(digitalRead(car_out_ack)){
      digitalWrite(car_out,LOW);
    }
    else{
      while(!digitalRead(car_out_ack)){}
      digitalWrite(car_out,LOW);
    }
  }
  else{
    digitalWrite(buzzer,HIGH); //--buzzer high
    delay(500);
    digitalWrite(buzzer,LOW); //--buzzer low
    digitalWrite(ledG,LOW);
    digitalWrite(ledR,HIGH);
    
  }
}

