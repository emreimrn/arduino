/*
Istanbul Kültür University
Electronic Engineering
Embedded System Applications

Objective 1: Digitally controlLed dimmer for single Led

Using two pushbuttons, user should be able to adjust brightness of a Led. 
The inital of brightness should be the half of the possible maximum.

Author: Emre IMREN
Oct 2018
*/

#define Button_Inc 2 //Brightness Increasing Button / Button1
#define Button_Dec 4 //Brightness Decreasing Button /  Button2
#define Led 3       //Led connected to pin 5 for PWM

int brightness = 127; //Inital of brightness


void setup() {
  
  pinMode(Button_Inc, INPUT_PULLUP); //Button1 adjusted Pullup Input
  pinMode(Button_Dec, INPUT_PULLUP); //Button2 adjusted Pullup Input
  pinMode(Led, OUTPUT);             // Led adjusted as an Output for observing changing

}
void loop() {

  analogWrite(Led, brightness); //Led burned with button that adjustable brightness.

  if (digitalRead(Button_Inc)) //Buton1 status checked.
  {
    if (brightness < 255) { //The brightness was checked for the highest value.
      brightness++;         //brightness increased.
      delay(30);            //30ms waiting for process.
    }
  }

  if (digitalRead(Button_Dec))//Buton2 status checked.
  {
    if (brightness > 0) { //The brightness was checked for the lowest value.
      brightness--;       //brightness decreased.
      delay(30);          //30ms waiting for process.
    }
  }
}
