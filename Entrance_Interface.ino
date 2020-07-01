int photo_res = A3;
int ledR = 4;
int ledG = 5;
int photocellReading;
int any_place = 1;
int nbre_cars_in = 0;
int places_valables = 3;
int buzzer = 6;

int car_out_info = 8;
int car_out_ack = 0;

// Command for 7 Segment Display with 2 bits:
/*
   A | B --- OUT
   0 | 0 --- 0
   0 | 1 --- 1
   1 | 0 --- 2
   1 | 1 --- 3
 */
int A = 2;
int B = 3;


// RFID_Module
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

#include <Servo.h> 
int servoPin = 7;
Servo Servo1; 

//----------------------------------------------------------------sous fonctions du programmes:

void display_number_places_valables(int number){
  if(number == 0){
    places_valables = 3;
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
  }
  else if(number == 1){
    places_valables = 2;
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
  }
  else if(number == 2){
    places_valables = 1;
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
  }
  else if(number == 3){
    places_valables = 0;
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
  }
}

//-----

void open_servo(void){
  Servo1.attach(servoPin); 
  for(int i=90; i>35; i--){
   Servo1.write(i); 
   delay(15); 
  }
  Servo1.detach();
}

//-----

void close_servo(void){
  Servo1.attach(servoPin); 
  for(int i=35; i<115; i++){
   Servo1.write(i); 
   delay(15); 
  }
  Servo1.detach();
}

//-----

void setup() {
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(car_out_info, INPUT);
  pinMode(car_out_ack, OUTPUT);

  Serial.begin(9600);   // Initiate a serial communication
  
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

  pinMode(photo_res, INPUT);
}

void loop() {
  display_number_places_valables(nbre_cars_in);
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);

  if(digitalRead(car_out_info)){
    Serial.println("car_out");
    nbre_cars_in --;
    if(nbre_cars_in<0) nbre_cars_in=0;
    digitalWrite(car_out_ack,HIGH);
    delay(200);
  }
  else{
    digitalWrite(car_out_ack,LOW);
  }
  digitalWrite(car_out_ack,LOW);
  
  /*----------------------------------------------------------------------
   * 
   * 
   * 
   * 
   */

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
    Serial.println("Aboné");
    Serial.println();
    digitalWrite(buzzer,HIGH); //--buzzer high
    delay(500);
    digitalWrite(buzzer,LOW); //--buzzer low
    if(nbre_cars_in < 3){
      nbre_cars_in++;
      New_car();
    }
    else{
      digitalWrite(ledG,LOW);
      digitalWrite(ledR,HIGH);
      digitalWrite(buzzer,HIGH); //--buzzer high
      delay(500);
      digitalWrite(buzzer,LOW); //--buzzer low
      digitalWrite(ledR,LOW);
      delay(500);
      digitalWrite(ledR,HIGH);
      digitalWrite(buzzer,HIGH); //--buzzer high
      delay(500);
      digitalWrite(buzzer,LOW); //--buzzer low
      digitalWrite(ledR,LOW);
      delay(500);
      digitalWrite(ledR,HIGH);
      digitalWrite(buzzer,HIGH); //--buzzer high
      delay(500);
      digitalWrite(buzzer,LOW); //--buzzer low
    }
  }
 
 else   {
    Serial.println("Non abonné");
    digitalWrite(ledG,LOW);
    digitalWrite(ledR,HIGH);
    digitalWrite(buzzer,HIGH); //--buzzer high
    delay(500);
    digitalWrite(buzzer,LOW); //--buzzer low
    digitalWrite(ledR,LOW);
    delay(500);
    digitalWrite(ledR,HIGH);
    digitalWrite(buzzer,HIGH); //--buzzer high
    delay(500);
    digitalWrite(buzzer,LOW); //--buzzer low
    digitalWrite(ledR,LOW);
    delay(500);
    digitalWrite(ledR,HIGH);
    digitalWrite(buzzer,HIGH); //--buzzer high
    delay(500);
    digitalWrite(buzzer,LOW); //--buzzer low
  }
  
}




void New_car(void){
  digitalWrite(ledG,HIGH);
  digitalWrite(ledR,LOW);
  open_servo();
  photocellReading = analogRead(photo_res);
  Serial.print(photocellReading); // the raw analog reading
  if (photocellReading > 300) {
    Serial.println(" - Lumière");
    while(photocellReading > 300){    /*motor maintenu*/
      photocellReading = analogRead(photo_res);
      Serial.println(photocellReading);
      delay(200);
    }
  }

  Serial.print(photocellReading);
  Serial.println(" - Sombre");
  digitalWrite(ledG,LOW);
  digitalWrite(ledR,HIGH);
  close_servo();
  delay(50);
}


