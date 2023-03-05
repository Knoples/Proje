#include <Servo.h>
Servo motorumuz;  
// motorumuz isminde bir servo motor tanımladık
String deger;
bool oda1 = false;
bool oda2= false;
bool oda3 = false;
bool oda4 = false;
bool koridor = false;

void setup() 
{
  Serial.begin(9600);
  motorumuz.attach(3);
  pinMode(7,OUTPUT);//ODA1
  pinMode(9,OUTPUT);//ODA2
  pinMode(10,OUTPUT);//ODA3
  pinMode(11,OUTPUT);//ODA4
  pinMode(12,OUTPUT);//KORİDOR
}

void loop() 
{
  if(Serial.available())   
  {
    deger = Serial.readString();   //Gelen verileri oku
  }
  if(deger=="1"){
    if(oda1 == false){
      digitalWrite(7,HIGH);
      oda1 = true;
    } 
    else if(oda1 == true){
      digitalWrite(7,LOW);
      oda1 =false;
    }
  }
  if(deger=="2"){
    if(oda2 == false){
      digitalWrite(9,HIGH);
      oda2 = true;
    } 
    else if(oda2 == true){
      digitalWrite(9,LOW);
      oda2 =false;
    }
  }
  if(deger=="3"){
    if(oda3 == false){
      digitalWrite(10,HIGH);
      oda3 = true;
    } 
    else if(oda3 == true){
      digitalWrite(10,LOW);
      oda3 =false;
    }
  }
  if(deger=="4"){
    if(oda4 == false){
      digitalWrite(11,HIGH);
      oda4 = true;
    } 
    else if(oda4 == true){
      digitalWrite(11,LOW);
      oda4 =false;
    }
  }
  if(deger=="5"){
    if(koridor == false){
      digitalWrite(12,HIGH);
      koridor = true;
    } 
    else if(koridor == true){
      digitalWrite(12,LOW);
      koridor = false;
    }
  }
  
  if(deger=="7"){
    motorumuz.write(90);  // 90 dereceye gel (kapıyı aç)
    }
  if(deger=="8"){
    motorumuz.write(0);  // 0 dereceye gel (kapıyı kapat)
    }
    deger=2000;
}
