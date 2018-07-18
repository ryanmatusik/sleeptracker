
#include <IOShieldOled.h>

const int BTN1 = 4;     // the number of the pushbutton pin
const int BTN2 = 78;    //***** Note: label on the board is for Uno32, this is MAX32, see MAX32 Reference Manual

const int ledPin =  13;      // System Operational LED
const int LD1 =  70;     //***** Note: label on the board is for Uno32, this is MAX32, see MAX32 Reference Manual
const int LD2 =  71;     // ******** LD pins are corrected here.
      
const int LD3 =  72;
const int LD4 =  73;
const int LD5 =  74;
const int LD6 =  75;
const int LD7 =  76;
const int LD8 =  77;

const int SW1 = 2;
const int SW2 = 7;
const int SW3 = 8;
const int SW4 = 79; 
const int potentiometer = A0;

  //input variables
  int BTN1_state = 0;
  int BTN2_state = 0;// variable for reading the pushbutton status  
  int SW1_state = 0; 
  int SW2_state = 0; 
  int SW3_state = 0; 
  int SW4_state = 0; 

  int state = 0;
  int questionIndex = 0;
  int potentiometerValue = 0;
  int zeroToTen = 0; // this will be the pot_value/100, for 1-10 questions
  int buttonStateChange = 0;
  int surveyData[11];



//QuestionBank
char surveyQuestions[12][50] = 
{"Did you exercise today?", //0
"Did you take medication today?",//1
"Did you drink caffiene today?",//2
"Did you eat <2hrs before bed?",//3
"Rate physical energy 0-10",//4
"Rate mental performance 0-10",//5
"Rate mood 0-10",//6
"Did you wake up naturally?",//7
"Did you you sleep through the night?",//8
"Did you sleep alone?",//9
"Did you struggle to fall asleep?",//100
"Rate your sleep 0-10:"};//11

String displayString;
char displayCharArray[50];

void setup() {

  pinMode(ledPin, OUTPUT);  
  pinMode(LD1, OUTPUT);  
  pinMode(LD2, OUTPUT);    
  pinMode(LD3, OUTPUT);  
  pinMode(LD4, OUTPUT);     
  pinMode(LD5, OUTPUT);  
  pinMode(LD6, OUTPUT);    
  pinMode(LD7, OUTPUT);  
  pinMode(LD8, OUTPUT);  
  pinMode(BTN1, INPUT);
  pinMode(BTN2, INPUT);
  pinMode(SW1, INPUT);  
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
       digitalWrite(LD1, LOW); 
       digitalWrite(LD2, LOW); 
       digitalWrite(LD3, LOW); 
       digitalWrite(LD4, LOW); 
       digitalWrite(LD5, LOW); 
       digitalWrite(LD6, LOW); 
       digitalWrite(LD7, LOW); 
       digitalWrite(LD8, LOW); 
        
  IOShieldOled.begin();
  IOShieldOled.displayOn();

}
void loop() {


  SW1_state = digitalRead(SW1);
  SW2_state = digitalRead(SW2);
  SW3_state = digitalRead(SW3);
  SW4_state = digitalRead(SW4); 
  if(BTN1_state == 1){
    BTN1_state = 0;
  }
  else {
    BTN1_state = digitalRead(BTN1);
  }
  
  if(BTN2_state == 1){
    BTN2_state = 0;
  }
  else {
    BTN2_state = digitalRead(BTN2);
  }
  potentiometerValue = analogRead(A0);
  
switch(state)
{
  case 0:// Night Time Survey
    IOShieldOled.clearBuffer();
    IOShieldOled.setCursor(0,0);
    switch (questionIndex)
    {
     case 0:
       digitalWrite(LD1, HIGH); 
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       delay(100);
       //surveyresponse is yes
       if(BTN1_state == 1){
         surveyData[questionIndex] = 1;
         questionIndex++;
       }
       //surveyresponse is no
       else if(BTN2_state == 1){
         surveyData[questionIndex] = 0;
         questionIndex++;
       }

       break;
       
     case 1:
       digitalWrite(LD2, HIGH);  
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       delay(100);
       //surveyresponse is yes
       if(BTN1_state == 1){
         surveyData[questionIndex] = 1;
         questionIndex++;
       }
       //surveyresponse is no
       else if(BTN2_state == 1){
         surveyData[questionIndex] = 0;
         questionIndex++;
       }
       
       break;
       
     case 2: 
       
       digitalWrite(LD3, HIGH);  
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       delay(100);
       //surveyresponse is yes
       if(BTN1_state == 1){
         surveyData[questionIndex] = 1;
         questionIndex++;
       }
       //surveyresponse is no
       else if(BTN2_state == 1){
         surveyData[questionIndex] = 0;
         questionIndex++;
       }
       break;
       
     case 3:
       
       digitalWrite(LD4, HIGH);  
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       delay(100);
       //surveyresponse is yes
       if(BTN1_state == 1){
         surveyData[questionIndex] = 1;
         questionIndex++;
       }
       //surveyresponse is no
       else if(BTN2_state == 1){
         surveyData[questionIndex] = 0;
         questionIndex++;
       }
       
       break;
       
     case 4:
       delay(100);
       digitalWrite(LD5, HIGH);  
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       zeroToTen = potentiometerValue/100;
       
       IOShieldOled.setCursor(0,2);
       displayString="Rating: ";
       displayString += zeroToTen; 
       
       displayString.toCharArray(displayCharArray,50);

       IOShieldOled.putString(displayCharArray);
       
       //here pressing button1 saves the zeroToTen as the survey response
       if(BTN1_state == 1){
         surveyData[questionIndex] = zeroToTen;
         questionIndex++;
       }

       break;
       
     case 5:
       delay(100);
       digitalWrite(LD6, HIGH);  
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       zeroToTen = potentiometerValue/100;
       
       IOShieldOled.setCursor(0,2);
       displayString="Rating: ";
       displayString += zeroToTen; 
       
       displayString.toCharArray(displayCharArray,50);

       IOShieldOled.putString(displayCharArray);
       
       //here pressing button1 saves the zeroToTen as the survey response
       if(BTN1_state == 1){
         surveyData[questionIndex] = zeroToTen;
         questionIndex++;
       }
       
       break;
       
     case 6:
       delay(100);
       digitalWrite(LD7, HIGH);  
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       zeroToTen = potentiometerValue/100;
       
       IOShieldOled.setCursor(0,2);
       displayString="Rating: ";
       displayString += zeroToTen; 
       
       displayString.toCharArray(displayCharArray,50);

       IOShieldOled.putString(displayCharArray);
       
       //here pressing button1 saves the zeroToTen as the survey response
       if(BTN1_state == 1){
         surveyData[questionIndex] = zeroToTen;
         questionIndex++;
       }
       break;
       
     case 7:
       digitalWrite(LD1, LOW); 
       digitalWrite(LD2, LOW); 
       digitalWrite(LD3, LOW); 
       digitalWrite(LD4, LOW); 
       digitalWrite(LD5, LOW); 
       digitalWrite(LD6, LOW); 
       digitalWrite(LD7, LOW); 
       digitalWrite(LD8, LOW); 
       
       IOShieldOled.setCursor(0,0);
       displayString = "Flip switch to sleep";
       displayString.toCharArray(displayCharArray,50);
       IOShieldOled.putString(displayCharArray);
       delay(100);
       if(SW1_state == HIGH){
          state++;
        }
        
       break;

    }//end switch question index

  break; // end state = 0
    //****************End Night time Survey
    
  case 1: // Sleep mode
  // here all of the sensors will run and take data
 //for now we will just time the duration of the sleep.
   delay(100);
   if (SW1_state == LOW){
    state++;
   }
  break;


  
  case 2: // Morning survey
    
    IOShieldOled.clearBuffer();
    IOShieldOled.setCursor(0,0);
    
    switch (questionIndex)
    {
     case 7:
       digitalWrite(LD1, HIGH); 
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       delay(100);
       //surveyresponse is yes
       if(BTN1_state == 1){
         surveyData[questionIndex] = 1;
         questionIndex++;
       }
       //surveyresponse is no
       else if(BTN2_state == 1){
         surveyData[questionIndex] = 0;
         questionIndex++;
       }
       break;

    case 8:
       digitalWrite(LD2, HIGH); 
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       delay(100);
       //surveyresponse is yes
       if(BTN1_state == 1){
         surveyData[questionIndex] = 1;
         questionIndex++;
       }
       //surveyresponse is no
       else if(BTN2_state == 1){
         surveyData[questionIndex] = 0;
         questionIndex++;
       }
       break;

     case 9:
       digitalWrite(LD3, HIGH); 
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       delay(100);
       //surveyresponse is yes
       if(BTN1_state == 1){
         surveyData[questionIndex] = 1;
         questionIndex++;
       }
       //surveyresponse is no
       else if(BTN2_state == 1){
         surveyData[questionIndex] = 0;
         questionIndex++;
       }
       break;

     case 10:
       digitalWrite(LD4, HIGH); 
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       delay(100);
       //surveyresponse is yes
       if(BTN1_state == 1){
         surveyData[questionIndex] = 1;
         questionIndex++;
       }
       //surveyresponse is no
       else if(BTN2_state == 1){
         surveyData[questionIndex] = 0;
         questionIndex++;
       }
       break;

     case 11 :
       delay(100);
       digitalWrite(LD5, HIGH);  
       IOShieldOled.putString(surveyQuestions[questionIndex]);
       zeroToTen = potentiometerValue/100;
       
       IOShieldOled.setCursor(0,2);
       displayString="Rating: ";
       displayString += zeroToTen; 
       
       displayString.toCharArray(displayCharArray,50);

       IOShieldOled.putString(displayCharArray);
       
       //here pressing button1 saves the zeroToTen as the survey response
       if(BTN1_state == 1){
         surveyData[questionIndex] = zeroToTen;
         questionIndex++;
       }
       break;
    }
  break;
  }
}




/*
char q0[50] = "Did you exercise today?";
char q1[50] = "Did you take medication today?";
char q2[50] = "Did you drink caffiene today?";
char q3[50] = "Did you eat <2hrs before bed?";
char q4[50] = "Rate physical energy 0-10";
char q5[50] = "Rate mental performance 0-10";
char q6[50] = "Rate mood 0-10";

//Morning
char q7[50] = "Did you wake up naturally?";
char q8[50] = "Did you you sleep through the night?";
char q9[50] = "Did you sleep alone?";
char q10[50] = "Did you struggle to fall asleep?";
char q11[50] = "Rate your sleep 0-10:";
*/






