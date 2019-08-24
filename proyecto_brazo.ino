//Inicio
#include <Servo.h>
#include <Esplora.h>

Servo miServo;
Servo miServo2;
Servo miServo3;
Servo miServo4;


void setup() {
  miServo.attach (1);
  miServo2.attach (0);
  miServo3.attach (11);
  miServo4.attach (3);
}

void loop() {
  int pot = Esplora.readSlider ();      //Control de la base del brazo
  int angulo = map (pot, 0, 1023, 0, 180);
  miServo.write (angulo);
  delay (20);
////////////////////////////////////////////////////////////////////////////////////
int valorJoy;                                                //Control del angulo X
int servopos;
boolean frezze=Esplora.readButton(SWITCH_4);

if(frezze==false)
{ valorJoy=Esplora.readJoystickX();
servopos=map(valorJoy,-512,512,0,180);
miServo2.write(servopos);
}

if ((Esplora.readButton(SWITCH_4)==0)
&&(frezze==false))
{
  frezze==true;
delay(20);
}

if ((Esplora.readButton(SWITCH_4)==0)
&&(frezze==true))
{
  frezze==false;
delay(20);
}
//////////////////////////////////////////////////////////////////////////////////////
int valorJoy_Y;                                                //Control del angulo Y
int servopos2;
boolean frezzer=Esplora.readButton(SWITCH_2);

if(frezzer==false)
{ valorJoy_Y=Esplora.readJoystickY();
servopos2=map(valorJoy_Y,-512,512,0,180);
miServo3.write(servopos2);
}

if ((Esplora.readButton(SWITCH_2)==0)
&&(frezzer==false))
{
  frezzer==true;
delay(20);
}

if ((Esplora.readButton(SWITCH_2)==0)
&&(frezzer==true))
{
  frezzer==false;
delay(20);
}
 ////////////////////////////////////////////////////////////////////////////////

int boton3=Esplora.readButton(SWITCH_3);
int botonest=Esplora.readButton(SWITCH_1);

if(botonest==LOW){
    Esplora.writeGreen(0);
  Esplora.tone(523,100);
 Esplora.writeRed(255);
 delay(300);
  Esplora.noTone();
   Esplora.writeRed(0);
  delay(300);
   Esplora.tone(523,100);
    Esplora.writeRed(255);
 delay(300);
  Esplora.noTone();
   Esplora.writeRed(0);
  
  miServo4.write(45);
 delay(600);


}
if(boton3==LOW){
  miServo4.write(90);
  Esplora.writeGreen(255);
  }
}     //Fin del código
