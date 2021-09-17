#include <Arduino.h>
#include <SoftwareSerial.h>
SoftwareSerial myserial (2,3) ;

  int IN3 = 9;
  int IN4 = 8;
  int ENA = 11;
  int ENB = 10;
  int IN2 =  7;
  int IN1 = 6;

  int JX = A5;
  int JY = A4;


void setup() {
  // put your setup code here, to run once:
  pinMode(IN3 , OUTPUT);
  pinMode(IN4 , OUTPUT);
  pinMode(IN1 , OUTPUT);
  pinMode(IN2 , OUTPUT);
  pinMode(ENB , OUTPUT);
  pinMode(ENA , OUTPUT);

  // Joystick 
  pinMode(JX , INPUT);
  pinMode(JY , INPUT);
  
  myserial.begin(9600); 
  Serial.begin (9600) ;  
 
}

void moveForward(int A,int  B){
  digitalWrite(IN1 , 0);
  digitalWrite(IN2 , 1);
  // analogWrite(ENB, A);
  digitalWrite(IN3 , 1);
  digitalWrite(IN4 , 0);
  // analogWrite(ENA, B);
}
void moveBackward(int A,int  B){
  digitalWrite(IN1 , 1);
  digitalWrite(IN2 , 0);
  // analogWrite(ENB, A);
  digitalWrite(IN3 , 0);
  digitalWrite(IN4 , 1);
  // analogWrite(ENA, B);
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
  
  Serial.println("JX=");
  Serial.println(analogRead(JX));
    
  Serial.println("JY=" );
  Serial.println(analogRead(JY));
  int motorSpeedA;
  int motorSpeedB;
  int vJX = analogRead(JX);
  int vJY = analogRead(JY);
  
  if(vJY < 470){
      moveForward(1,1);
      motorSpeedA = map(vJY, 470, 0, 0, 127);
      motorSpeedB = map(vJY, 470, 0, 0, 127);  
      // moveForward(motorSpeedA, motorSpeedB);
  } else if (vJY > 550) 
  {
      moveBackward(1,1);
    motorSpeedA = map(vJY, 550, 1023, 0, 127);
    motorSpeedB = map(vJY, 550, 1023, 0, 127);
    // moveBackward(motorSpeedA, motorSpeedB);
  }
  else 
  {
    motorSpeedA = 0;
    motorSpeedB = 0;
    // moveForward(motorSpeedA, motorSpeedB);
  }

  if (vJX < 470) {
   
    int xMapped = map(vJX, 470, 0, 0, 127);
    motorSpeedA = motorSpeedA - xMapped*2;
    motorSpeedB = motorSpeedB + xMapped*2;
    
    if (motorSpeedA < 0) 
    {
      motorSpeedA = 0;
    }
    if (motorSpeedB > 127) 
    {
      motorSpeedB = 127;
    }
 }
     if (vJX > 550) 
    {
    int xMapped = map(vJX, 550, 1023, 0, 127);
    motorSpeedA = motorSpeedA + xMapped*2;
    motorSpeedB = motorSpeedB - xMapped*2;
    if (motorSpeedA > 127) 
    {
      motorSpeedA = 127;
    }
    if (motorSpeedB < 0) 
    {
      motorSpeedB = 0;
    }
  }
 
  if (motorSpeedA < 70) 
  {
    motorSpeedA = 0;
  }
  if (motorSpeedB < 70) 
  {
    motorSpeedB = 0;
  }
  analogWrite(ENA, motorSpeedA);
  analogWrite(ENB, motorSpeedB);
  // if(myserial.available() )
  // {
  //   String data = (String) myserial.readString();
  //    Serial.print( data ); 
  //   if(data == "trh"){
  //     turnRightHard();
  //     Serial.println("turning");
  // }
  //   else if (data = "stop")
  //   {
  //     stop();
  //   }
    
  // }
  //   if (Serial.available () )
  //   {
  //     myserial.write(Serial.read() );
  //     }


     



// move forward
// in1 =0, in2= 1 ==> right motor
// in3 =1, in4= 0 ==> left motor 
}



