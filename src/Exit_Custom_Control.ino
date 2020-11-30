#include<LiquidCrystal.h>
#include<Wire.h>
#define PCF8591 (0x91 >> 1) //addresse de bus I2C
#define AIN0 0x00
///////////////////////////////////////////////////////////////////////
int analogPin = A7;
int recept_servo = 7;
int emet_ack = 8;
///////////////////////////////////////////////////////////////////////

const int RS = 53, EN = 51, D4 = 52, D5 = 50, D6 = 48, D7 = 46;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
int Value = 0;
int numericValue = 0;
int analogValue = 0;
int duree = 0;

///*************************************************
#include <Servo.h> 
int servoPin = 5;
Servo Servo1; 

void open_servo(void){  //close compris 
  Servo1.attach(servoPin);
  for(int i=90; i>0; i--){
   Servo1.write(i); 
   delay(15); 
  }
  Servo1.detach();
  
//--delay
duree = numericValue*1000;
delay(duree);
//--end of delay

  Servo1.attach(servoPin); 
  for(int i=0; i<90; i++){
   Servo1.write(i); 
   delay(15); 
  }
  Servo1.detach();
}
///*************************************************

//------------------------------------------------------------------------------------------

void setup() {
  Wire.begin();
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(recept_servo, INPUT);
  pinMode(emet_ack, OUTPUT);
}

//------------------------------------------------------------------------------------------
void loop() {
  //Wire.beginTransmission(PCF8591);
  //Wire.write(AIN0);
  //Wire.endTransmission();
  //Wire.requestFrom(PCF8591, 1);
  //Value = Wire.read();
  //lcd.print("ADC Value=");
  //lcd.print(Value);
  //Serial.println(Value);
  //delay(500);
  //lcd.clear();

  analogValue=analogRead(analogPin);
  numericValue = map(analogValue, 0, 1023, 0, 11);
  lcd.print("Attente = ");
  lcd.print(numericValue);
  lcd.print(" sec ");
  Serial.println(numericValue);
  delay(500);
  //lcd.clear();

// attente de signal de la part de Arduino(Sortie)
  if(digitalRead(recept_servo)){
    Serial.println("servo demandé.");
    // nbre_cars_in --;
    // if(nbre_cars_in<0) nbre_cars_in=0;
    digitalWrite(emet_ack,HIGH);
    delay(200);
    open_servo();
  }
  else{
    digitalWrite(emet_ack,LOW);
  }
  digitalWrite(emet_ack,LOW);
  lcd.clear();
}

