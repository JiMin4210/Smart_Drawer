#include <Arduino.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
//**x,y좌표**//
//테스트 기본 좌표
//220,200 / 100,200 / 0,200
//220,150 / 100,150 / 0,140
//220,60  / 100,60  / 0,50
//220,0   / 100,0   / 0,0

//위 테스트 좌표 값 기준으로 움직이면 됩니다.
//***좌표 값 입력 시 시리얼 모니터에 x,z(100,100)입력 후 엔터**//
//좌표 값 입력 시 좌표 값에 3,333,4,444,132,142..등 3과 4가 포함되지 않도록**//


//3단 서랍장은 책상에서 10cm 높이
//xy 모듈 위치는 3단 서랍장 좌/우 모서리 끝과
//xy 모듈의 판의 x0(서랍장 오른쪽 끝), x1(서랍장 왼쪽 끝)과 일치되게 설치

//스탭모터 동시 구동을 위한 라이브러리 셋팅
AccelStepper stepper1(AccelStepper::FULL2WIRE, 2, 5);
AccelStepper stepper2(AccelStepper::FULL2WIRE, 4, 7);
AccelStepper stepper3(AccelStepper::FULL2WIRE, 3, 6);

MultiStepper steppers;
MultiStepper steppers1;

//스탭모터 위치 변수

int xpos,zpos;
String strxPos,strzPos;
int yPos = 6000;

//밸트 및 기어비
float gearRatio = 25.0f;
String incomming;
void setup()
{
  Serial.begin(9600);

  //스탭모터 속도 및 가감속 설정
  stepper1.setMaxSpeed(2000);
  stepper1.setAcceleration(3000.0);
  stepper2.setMaxSpeed(2000);
  stepper2.setAcceleration(3000.0);
  stepper3.setMaxSpeed(2000);
  stepper3.setAcceleration(3000.0);
  
   
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
  steppers1.addStepper(stepper3);

  Serial.println("START...");
  delay(1000);
  Serial.println("READY...");
}
void loop()
{
  long positions[2];      //x,z position
  long positions1[2];     //y position

  while(Serial.available())
  {
    //좌표 값 입력을 위한 프로세스
    incomming = Serial.readStringUntil('\n');
    xpos = incomming.indexOf(",");
    zpos = incomming.indexOf(",",xpos+1);

    strxPos = incomming.substring(0,xpos);
    strzPos = incomming.substring(xpos+1,zpos);

    xpos = strxPos.toInt();
    zpos = strzPos.toInt();
    
    Serial.println(strxPos);
    Serial.println(strzPos);
    Serial.print("x pos: ");
    Serial.println(xpos);
    Serial.print("z pos: ");
    Serial.println(zpos);
    Serial.println("y pos: ");
    Serial.println(yPos);
    //move x-axis and z-axis
    Serial.println("GO");
    positions[0] = -xpos * gearRatio;
    positions[1] = -zpos * gearRatio;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    delay(500);

    //forward push axis
    Serial.println("Forward");
    positions1[0] = yPos;
    positions1[1] = 0;
    steppers1.moveTo(positions1);
    steppers1.runSpeedToPosition();
    delay(100);

    //backwrad push axis
    Serial.println("Backward");
    positions1[0] = yPos * 0;
    positions1[1] = 0;
    steppers1.moveTo(positions1);
    steppers1.runSpeedToPosition();
    delay(100);

    //move to home x-axis and z-axis
    Serial.println("Back Home");
    positions[0] = 0 * gearRatio;
    positions[1] = 0 * gearRatio;
    steppers.moveTo(positions);
    steppers.runSpeedToPosition();
    delay(500);    
  }
  incomming = "";
}
