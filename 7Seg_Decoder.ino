int A = 2;
int B = 3;

int state_A = 0;
int state_B = 0;

// Commont Chathode of 7-Seg
int seven_seg_a = 13;
int seven_seg_b = 12;
int seven_seg_c = 11;
int seven_seg_d = 10;
int seven_seg_e = 9;
int seven_seg_f = 8;
int seven_seg_g = 7; 

void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  
  pinMode(seven_seg_a, OUTPUT);
  pinMode(seven_seg_b, OUTPUT);
  pinMode(seven_seg_c, OUTPUT);
  pinMode(seven_seg_d, OUTPUT);
  pinMode(seven_seg_e, OUTPUT);
  pinMode(seven_seg_f, OUTPUT);
  pinMode(seven_seg_g, OUTPUT);
}

void loop() {  
  state_A = digitalRead(A);
  state_B = digitalRead(B);
  
  if(state_A == 0 && state_B == 0){
    digitalWrite(seven_seg_a,HIGH);
    digitalWrite(seven_seg_b,HIGH);
    digitalWrite(seven_seg_c,HIGH);
    digitalWrite(seven_seg_d,HIGH);
    digitalWrite(seven_seg_e,HIGH);
    digitalWrite(seven_seg_f,HIGH);
    digitalWrite(seven_seg_g,LOW);
  }
  else if(state_A == 0 && state_B == 1){
    digitalWrite(seven_seg_a,LOW);
    digitalWrite(seven_seg_b,HIGH);
    digitalWrite(seven_seg_c,HIGH);
    digitalWrite(seven_seg_d,LOW);
    digitalWrite(seven_seg_e,LOW);
    digitalWrite(seven_seg_f,LOW);
    digitalWrite(seven_seg_g,LOW);
  }
  else if(state_A == 1 && state_B == 0){
    digitalWrite(seven_seg_a,HIGH);
    digitalWrite(seven_seg_b,HIGH);
    digitalWrite(seven_seg_c,LOW);
    digitalWrite(seven_seg_d,HIGH);
    digitalWrite(seven_seg_e,HIGH);
    digitalWrite(seven_seg_f,LOW);
    digitalWrite(seven_seg_g,HIGH);
  }
  else if(state_A == 1 && state_B == 01){
    digitalWrite(seven_seg_a,HIGH);
    digitalWrite(seven_seg_b,HIGH);
    digitalWrite(seven_seg_c,HIGH);
    digitalWrite(seven_seg_d,HIGH);
    digitalWrite(seven_seg_e,LOW);
    digitalWrite(seven_seg_f,LOW);
    digitalWrite(seven_seg_g,HIGH);
  }
}

