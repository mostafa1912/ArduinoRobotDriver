#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial myserial (2,3) ;

  int IN3 = 9;
  int IN4 = 8;
  int ENA = 11;
  int ENB = 10;
  int IN2 =  7;
  int IN1 = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(IN3 , OUTPUT);
  pinMode(IN4 , OUTPUT);
  pinMode(IN1 , OUTPUT);
  pinMode(IN2 , OUTPUT);
  pinMode(ENB , OUTPUT);
  pinMode(ENA , OUTPUT);
  myserial.begin(9600); 
  Serial.begin (9600) ;  
 
}
void moveForward(int A,int  B){
  digitalWrite(IN1 , 0);
  digitalWrite(IN2 , 1);
  analogWrite(ENB, A);
  digitalWrite(IN3 , 1);
  digitalWrite(IN4 , 0);
  analogWrite(ENA, B);
}
 void turnRightHard(){
  moveForward(70, 50);  }

void turnLeftHard(){
  moveForward(50, 70);  
  }
void stop(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  

  if(myserial.available() )
  {
    String data = (String) myserial.readString();
     Serial.print( data ); 
    if(data == "trh"){
      turnRightHard();
      Serial.println("turning");
  }
    else if (data = "stop")
    {
      stop();
    }
    
  }
    if (Serial.available () )
    {
      myserial.write(Serial.read() );
      }



// move forward
// in1 =0, in2= 1 ==> right motor
// in3 =1, in4= 0 ==> left motor 
}



