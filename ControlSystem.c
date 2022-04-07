#include <LiquidCrystal.h>
#include <LedControl.h>   //display controller
#include <avr/pgmspace.h> //memory management
#include <Wire.h>         //i2c communication between boards



const int rs = 13, en = A3, d4 = A2, d5 = A1, d6 = A0, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

 
int switched = 0;

//display pin number declarations
int DIN = 12;
int CS =  6;
int CLK = 10;

int gm = 1;
int mm = 1;

int rndum = 0;

//time var used for calculating time when switching between different modes

int st = 0;
long spausetime = 0;

long pausetime = 0;


//variable for tracking time for display of arrow to the correct movement
long timef = 0;
long endtime = 0;
long duration = 0;
//int for average time for moving 
long averagetimeforward = 0;
long totaltimeforward = 0;
String averagetime;
//int for stopping the timer
int timerstop = 0;
//int number of times that the project has been moved forward
int numberoftries = 0;








//variable for tracking time for display of arrow to the correct movement
long timef1 = 0;
long endtime1 = 0;
long duration1 = 0;
//int for average time for moving 
long averagetimeforward1 = 0;
long totaltimeforward1 = 0;
String averagetime1;
//int for stopping the timer
int timerstop1 = 0;
//int number of times that the project has been moved forward
int numberoftries1 = 0;





//variable for tracking time for display of arrow to the correct movement
long timef2 = 0;
long endtime2 = 0;
long duration2 = 0;
//int for average time for moving 
long averagetimeforward2 = 0;
long totaltimeforward2 = 0;
String averagetime2;
//int for stopping the timer
int timerstop2 = 0;
//int number of times that the project has been moved forward
int numberoftries2 = 0;





//variable for tracking time for display of arrow to the correct movement
long timef3 = 0;
long endtime3 = 0;
long duration3 = 0;
//int for average time for moving 
long averagetimeforward3 = 0;
long totaltimeforward3 = 0;
String averagetime3;
//int for stopping the timer
int timerstop3 = 0;
//int number of times that the project has been moved forward
int numberoftries3 = 0;


//variable for tracking time for display of arrow to the correct movement
long timef4 = 0;
long endtime4 = 0;
long duration4 = 0;
//int for average time for moving 
long averagetimeforward4 = 0;
long totaltimeforward4 = 0;
String averagetime4;
//int for stopping the timer
int timerstop4 = 0;
//int number of times that the project has been moved forward
int numberoftries4 = 0;


//variable for tracking time for display of arrow to the correct movement
long timef5 = 0;
long endtime5 = 0;
long duration5 = 0;
//int for average time for moving 
long averagetimeforward5 = 0;
long totaltimeforward5 = 0;
String averagetime5;
//int for stopping the timer
int timerstop5 = 0;
//int number of times that the project has been moved forward
int numberoftries5 = 0;

//variable for tracking time for display of arrow to the correct movement
long timef6 = 0;
long endtime6 = 0;
long duration6 = 0;
//int for average time for moving 
long averagetimeforward6 = 0;
long totaltimeforward6 = 0;
String averagetime6;
//int for stopping the timer
int timerstop6 = 0;
//int number of times that the project has been moved forward
int numberoftries6 = 0;

//variable for tracking time for display of arrow to the correct movement
long timef7 = 0;
long endtime7 = 0;
long duration7 = 0;
//int for average time for moving 
long averagetimeforward7 = 0;
long totaltimeforward7 = 0;
String averagetime7;
//int for stopping the timer
int timerstop7 = 0;
//int number of times that the project has been moved forward
int numberoftries7 = 0;


//variable for tracking time for display of arrow to the correct movement
long timef8 = 0;
long endtime8 = 0;
long duration8 = 0;
//int for average time for moving 
long averagetimeforward8 = 0;
long totaltimeforward8 = 0;
String averagetime8;
//int for stopping the timer
int timerstop8 = 0;
//int number of times that the project has been moved forward
int numberoftries8 = 0;


//variable for tracking time for display of arrow to the correct movement
long timef9 = 0;
long endtime9 = 0;
long duration9 = 0;
//int for average time for moving 
long averagetimeforward9 = 0;
long totaltimeforward9 = 0;
String averagetime9;
//int for stopping the timer
int timerstop9 = 0;
//int number of times that the project has been moved forward
int numberoftries9 = 0;

//pins to turn on and off arrow visual
int leftpin = 8;
int rightpin = 7;
int downpin = 11;
int uppin = 13;
int modepin = 5;



int leftswitch = 0;
int rightswitch = 1;
int downswitch = 2;
int upswitch = 3;

//pins for the button which controls level switchin
int levelSwitch = 9;

//tracks joystick direction changes
//vaild values are F,B,L,R,N for forward, backward, left, right, neutral
char currentDirection;
char lastDirection;

//byte arrays storing images for display
byte hi[8] = {0x00,0x7C,0x10,0x7C,0x00,0x44,0x7C,0x44,};
byte circle4[8] = {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00};
byte forward_Arrow[8] = {0x08,0x0C,0x0E,0xFF,0xFF,0x0E,0x0C,0x08,};
byte back_Arrow[8] = {0x10,0x30,0x70,0xFF,0xFF,0x70,0x30,0x10};
byte left_Arrow[8] = {0x18,0x3C,0x7E,0xFF,0x18,0x18,0x18,0x18};
byte right_Arrow[8] = {0x18,0x18,0x18,0x18,0xFF,0x7E,0x3C,0x18};
byte empty[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte bball[8] = {
  B00111100,
  B01000010,
  B11111111,
  B10000001,
  B10000001,
  B11111111,
  B01000010,
  B00111100
};

//led controller object
LedControl lc=LedControl(DIN,CLK,CS,0);

//1-byte codes standard between boards for communication
byte audioForward = 'F';
byte audioBack = 'B';
byte audioRight = 'R';
byte audioLeft = 'L';
byte audioStop = 'N';

int slaveID = 8; //audio board's i2c id number

//variables which hold the state of the switch
int leftswitchState = 0;
int upswitchState = 0;
int downswitchState = 0;
int rightswitchState = 0;
int levelState = 0;
int modeswitchState = 0;

int rSt = 0;
int lSt = 0;
int uSt = 0;
int dSt = 0;

//for gaming mode of the joystick
int lvl = 1; 

void setup(){

  // Print a message to the LCD.

  
  //serial debug connection
  Serial.begin(9600);
 // Serial.println("STARTUP");
  
  //i2c communication
  Wire.begin(); // this arduino joins the i2c bus as the master device
  
  //set up display panel
  lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0,15);      // Set the brightness to maximum value
  lc.clearDisplay(0);         // and clear the display

  //startup image to confirm display has power and correct orientation
  //if the board starts but gets stuck on this screen, its because its waiting for its partner to connect.
  printByte(hi);
 // Serial.println("Hello!");
  delay(1000);

  currentDirection = 'N'; // direction starts in neutral
  lastDirection = '_';//set to a placeholder so display updates at first loop

  //sends command to set audio arduino to neutral. may get stuck here if the other arduino is not connected.
  setAudio(audioStop);

  pinMode(leftpin, INPUT);           // set pin to input
  digitalWrite(leftpin, HIGH);
  pinMode(uppin, INPUT);           // set pin to input
  digitalWrite(uppin, HIGH);
  pinMode(rightpin, INPUT);           // set pin to input
  digitalWrite(rightpin, HIGH);
  pinMode(downpin, INPUT);           // set pin to input
  digitalWrite(downpin, HIGH);
  pinMode(levelSwitch, INPUT);           // set pin to input
  digitalWrite(levelSwitch, HIGH);
  pinMode(levelSwitch, INPUT);           // set pin to input
  digitalWrite(levelSwitch, HIGH);
  pinMode(modepin, INPUT);           // set pin to input
  digitalWrite(modepin, HIGH);
 

  pinMode(leftswitch, INPUT);           // set pin to input
  digitalWrite(leftswitch, HIGH);
  pinMode(rightswitch, INPUT);           // set pin to input
  digitalWrite(rightswitch, HIGH);
  pinMode(downswitch, INPUT);           // set pin to input
  digitalWrite(downswitch, HIGH);
  pinMode(upswitch, INPUT);           // set pin to input
  digitalWrite(upswitch, HIGH);
  lcd.begin(16,2);
}

void loop(){
  
  currentDirection = getDirection(); //get current direction as L,R,F,B, or N
    leftswitchState = digitalRead(leftpin);
    upswitchState = digitalRead(uppin);
    rightswitchState = digitalRead(rightpin);
    downswitchState = digitalRead(downpin);
   modeswitchState = digitalRead(modepin);
   
    //update if direction has changed
    if (modeswitchState == HIGH){
      if(mm == 1){
        lcd.clear();
      lcd.print("Manual Mode");
      mm = 0;
      //switched = switched + 1;
      }
      lvl = 1;
      gm = 1;
      if(switched == 1){
        if (st == 0){
          spausetime = millis();
          st = 1;
        }
           pausetime = millis();
      }
      if(switched == 2){
        if (st == 0){
          spausetime = millis();
          st = 1;
        }
           pausetime = millis();
      }
      if(switched == 3){
        if (st == 0){
          spausetime = millis();
          st = 1;
        }
           pausetime = millis();
      }
      if(switched == 4){
        if (st == 0){
          spausetime = millis();
          st = 1;
        }
           pausetime = millis();
      }
      if(switched == 5){
        if (st == 0){
          spausetime = millis();
          st = 1;
        }
           pausetime = millis();
      }
      if(switched == 6){
        if (st == 0){
          spausetime = millis();
          st = 1;
        }
           pausetime = millis();
      }
      if(switched == 7){
        if (st == 0){
          spausetime = millis();
          st = 1;
        }
           pausetime = millis();
      }
      
   
      
    if (currentDirection != lastDirection){

     
      lastDirection = currentDirection;

      //update display and send audio command when direction changes
      switch(currentDirection){
        if (levelState == LOW){
             //   Serial.println("Switch is working");
              }
              else{
                
               
              }
        case 'L':
        
        if (rightswitchState == HIGH){
          printByte(right_Arrow);
          Serial.println("RIGHT");
          setAudio(audioRight);
         }
         else{
          
         }
          break;
        case 'R':
         if (leftswitchState == HIGH){
          printByte(left_Arrow);
          Serial.println("LEFT");
          setAudio(audioLeft);
          Serial.println("the switch is on");
        }
        else{
          Serial.println("the switch is offf");
        }
          break;
        case 'F':
        
          printByte(forward_Arrow);
          Serial.println("FORWARD");
          setAudio(audioForward);
  
          break;
        case 'B':
         if(downswitchState == HIGH){
          printByte(back_Arrow);
          Serial.println("BACKWARD");
          setAudio(audioBack);
         }
         else{
          
         }
         
        
          break;
        case 'N':
          printByte(circle4);
          Serial.println("NEUTRAL");
          setAudio(audioStop);
          break;
    }
  }

}
        else{
          st=0;
        mm = 1;
         if(gm == 1){
          switched = switched + 1;
          lcd.clear();
        lcd.print("Game Mode");
        delay(2000);
        lcd.clear();
           gm = 0;
         }
          
          
          levelState = digitalRead(levelSwitch);
             
            if(lvl == 1){
              timerstop9 = 0;
               lcd.clear();
              delay(1000);
              levelState = digitalRead(levelSwitch);

                 
              
              
              printByte(forward_Arrow);
           //  Serial.println("FORWARD");
              setAudio(audioForward);
              delay(1000);
              setAudio(audioStop);
              
              if (levelState == LOW){
                lvl = 3;
            
                levelState = HIGH;
              }
              lvl++;
              
            }










            
            if(lvl == 2){
               lcd.clear();
              lcd.print("Time Forward:");
              lcd.print(averagetime);
              levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
    
                lvl = 3;
                levelState = HIGH;
                
              }
             
                   if (timerstop == 0){
                  timef = 0;
                  timef =  millis();
                
                  timerstop = 1;
                   }
              switch(currentDirection){
          
              case 'L':
              
              break;
              case 'R':
              break;
              case 'F':
              
              printByte(bball);
              delay(1000);
              
              if(timerstop == 1){
                 
                
                
              endtime = millis();
              duration = ((endtime-timef)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries++;
              
              totaltimeforward = totaltimeforward + duration;
              averagetimeforward = totaltimeforward/numberoftries;
            
              averagetime = String(averagetimeforward);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time ↑:");
              Serial.println(averagetimeforward);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop = 0;
              }
              
              lvl = 1;
           
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              break;
              
              
              }
            }















            
            if(lvl == 3){
              timerstop = 0;
              delay(1000);
              levelState = digitalRead(levelSwitch);
              Serial.println(levelSwitch);
              printByte(left_Arrow);
              Serial.println("LEFT");
              setAudio(audioLeft);
              delay(1000);
              setAudio(audioStop);
          
              if (levelState == LOW){
                lvl = 5;
              }
              if (timerstop1 == 0){
                  timef1 = 0;
             
                  timef1 = millis();
                  timerstop1 = 1;
                 } 
              
              lvl = 4;
            }




            
            if(lvl == 4){
              lcd.clear();
              lcd.print("Time Left:");
              lcd.print(averagetime1);
              levelState = digitalRead(levelSwitch);
              
              if (levelState == LOW){
                lvl = 5;
              }


              if (timerstop1 == 0){
                  timef1 = 0;
                  timef1 =  millis();
                
                  timerstop1 = 1;
                 } 

                 
              switch(currentDirection){
              case 'R':
              lvl = 3;
              printByte(bball);
              delay(500);
              if(timerstop1 == 1){
              
              endtime1 = millis();
              duration1 = ((endtime1 - timef1)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries1++;
              
              totaltimeforward1 = totaltimeforward1 + duration1;
              averagetimeforward1 = totaltimeforward1/numberoftries1;
            
              averagetime1 = String(averagetimeforward1);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time lft:");
              Serial.println(averagetimeforward1);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop1 = 0;
                
              }
              break;
              case 'L':
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              break;
              
              
            }
            }











            
            if (lvl == 5){
              timerstop1 = 0;
               delay(1000);
              levelState = digitalRead(levelSwitch);
              Serial.println(levelSwitch);
              printByte(back_Arrow);
              Serial.println("BACK");
              setAudio(audioBack);
              delay(1000);
              setAudio(audioStop);
        
              if (levelState == LOW){
                lvl = 7;
              }
               if (timerstop2 == 0){
                  timef2 = 0;
                  timef2 =  millis();
                
                  timerstop2 = 1;
                 }
              
              lvl = 6;
            }
            if (lvl == 6){
               lcd.clear();
              lcd.print("Time Back:");
              lcd.print(averagetime2);
              levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 7;
              }
              switch(currentDirection){
              case 'L':
              
              break;
              case 'R':
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              lvl = 5;
              printByte(bball);
              delay(1000);
                 if(timerstop2 == 1){
              endtime2 = millis();
              duration2 = ((endtime2 - timef2)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries2++;
              
              totaltimeforward2 = totaltimeforward2 + duration2;
              averagetimeforward2 = totaltimeforward2/numberoftries2;
            
              averagetime2 = String(averagetimeforward2);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time bck:");
              Serial.println(averagetimeforward2);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop2 = 0;
              }
              break;
              
              
            }
            }
           if (lvl == 7){
            timerstop2 = 0;
               delay(1000);
              levelState = digitalRead(levelSwitch);
              Serial.println(levelSwitch);
              printByte(right_Arrow);
              Serial.println("RIGHT");
              setAudio(audioRight);
              delay(1000);
              setAudio(audioStop);
              if (levelState == LOW){
                lvl = 9;
              }
              if (timerstop3 == 0){
                  timef3 = 0;
                  timef3 =  millis();
                
                  timerstop3 = 1;
                 }
              
              lvl = 8;
            }
            if (lvl == 8){
              lcd.clear();
              lcd.print("Time Right:");
              lcd.print(averagetime3);
              levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 9;
              }
              switch(currentDirection){
              case 'R':
              
              break;
              case 'L':
              lvl = 7;
              printByte(bball);
              delay(1000);

            if(timerstop3 == 1){
              endtime3 = millis();
              duration3 = ((endtime3 - timef3)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries3++;
              
              totaltimeforward3 = totaltimeforward3 + duration3;
              averagetimeforward3 = totaltimeforward3/numberoftries3;
            
              averagetime3 = String(averagetimeforward3);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time bck:");
              Serial.println(averagetimeforward3);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop3 = 0;
              }



              
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              
              break;
            }
            }

            
            if (lvl == 9){
             timerstop3 = 0;
             delay(1000);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 1;
              }
            int drction = randomarrow();
            Serial.println(drction);

            if (drction == 1){
              printByte(right_Arrow);
              Serial.println("RIGHT");
              setAudio(audioRight);
              delay(1000);
              setAudio(audioStop);
               if (timerstop4 == 0){
                  timef4 = 0;
                  timef4 =  millis();
                
                  timerstop4 = 1;
                 }
              lvl = 10;
            }
            if(drction == 2){
              printByte(forward_Arrow);
              Serial.println("RIGHT");
              setAudio(audioForward);
              delay(1000);
              setAudio(audioStop);
                if (timerstop4 == 0){
                  timef4 = 0;
                  timef4 =  millis();
                
                  timerstop4 = 1;
                 }
              lvl = 11;
            }
            if(drction == 3){
              printByte(left_Arrow);
              Serial.println("RIGHT");
              setAudio(audioLeft);
              delay(1000);
              setAudio(audioStop);
                if (timerstop4 == 0){
                  timef4 = 0;
                  timef4 =  millis();
                
                  timerstop4 = 1;
                 }
              lvl = 12;
            }
            if(drction == 4){
              printByte(back_Arrow);
              Serial.println("RIGHT");
              setAudio(audioBack);
              delay(1000);
              setAudio(audioStop);
                if (timerstop4 == 0){
                  timef4 = 0;
                  timef4 =  millis();
                
                  timerstop4 = 1;
                 }
              lvl = 13;
            }
          }
          if(lvl == 10){
              lcd.clear();
              lcd.print("Time Random:");
              lcd.print(averagetime4);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 14;
              }
             switch(currentDirection){
              case 'R':
              
              break;
              case 'L':
              lvl = 9;
              printByte(bball);
              delay(1000);
              if(timerstop4 == 1){
              endtime4 = millis();
              duration4 = ((endtime4 - timef4)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries4++;
              
              totaltimeforward4 = totaltimeforward4 + duration4;
              averagetimeforward4 = totaltimeforward4/numberoftries4;
            
              averagetime4 = String(averagetimeforward4);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time bck:");
              Serial.println(averagetimeforward3);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop4 = 0;
              }
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              
              break;
            }
            
          }
          if(lvl == 11){
             lcd.clear();
              lcd.print("Time Random:");
              lcd.print(averagetime4);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 14;
              }
             switch(currentDirection){
              case 'L':
              
              break;
              case 'R':
              
              break;
              case 'F':
              lvl = 9;
              printByte(bball);
              delay(1000);
              if(timerstop4 == 1){
              endtime4 = millis();
              duration4 = ((endtime4 - timef4)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries4++;
              
              totaltimeforward4 = totaltimeforward4 + duration4;
              averagetimeforward4 = totaltimeforward4/numberoftries4;
            
              averagetime4 = String(averagetimeforward4);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time bck:");
              Serial.println(averagetimeforward3);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop4 = 0;
              }
              //insert a correct or hooray audio here
              break;
              case 'B':
              
              break;
            }
            
          }
          if(lvl == 12){
             lcd.clear();
              lcd.print("Time Random:");
              lcd.print(averagetime4);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 14;
              }
             switch(currentDirection){
              case 'R':
              lvl = 9;
              printByte(bball);
              delay(1000);
              if(timerstop4 == 1){
              endtime4 = millis();
              duration4 = ((endtime4 - timef4)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries4++;
              
              totaltimeforward4 = totaltimeforward4 + duration4;
              averagetimeforward4 = totaltimeforward4/numberoftries4;
            
              averagetime4 = String(averagetimeforward4);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time bck:");
              Serial.println(averagetimeforward3);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop4 = 0;
              }
              break;
              case 'L':
              
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              
              break;
            }
            
          }
          if(lvl == 13){
             lcd.clear();
              lcd.print("Time Random:");
              lcd.print(averagetime4);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 14;
              }
             switch(currentDirection){
              case 'L':
              
              break;
              case 'R':
              
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              lvl = 9;
              printByte(bball);
              delay(1000);
              if(timerstop4 == 1){
              endtime4 = millis();
              duration4 = ((endtime4 - timef4)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries4++;
              
              totaltimeforward4 = totaltimeforward4 + duration4;
              averagetimeforward4 = totaltimeforward4/numberoftries4;
            
              averagetime4 = String(averagetimeforward4);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time bck:");
              Serial.println(averagetimeforward3);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop4 = 0;
              }
              break;
            }
            
          }
        
                 if(lvl == 14){
              timerstop4 = 0;
               lcd.clear();
              delay(1000);
              levelState = digitalRead(levelSwitch);
             printByte(empty);   
              setAudio(audioForward);
              delay(1000);
              setAudio(audioStop);
              
              if (levelState == LOW){
                lvl = 16;
            
                levelState = HIGH;
              }
              lvl++;
              
            }










            
            if(lvl == 15){
               lcd.clear();
              lcd.print("Audio Forward:");
              lcd.print(averagetime5);
              levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
    
                lvl = 16;
                levelState = HIGH;
                
              }
             
                   if (timerstop5 == 0){
                  timef5 = 0;
                  timef5 =  millis();
                
                  timerstop5 = 1;
                   }
              switch(currentDirection){
          
              case 'L':
              
              break;
              case 'R':
              break;
              case 'F':
              
              printByte(bball);
              delay(1000);
              printByte(empty);
              
              if(timerstop5 == 1){
                 
                
                
              endtime5 = millis();
              duration5 = ((endtime5-timef5)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries5++;
              
              totaltimeforward5 = totaltimeforward5 + duration5;
              averagetimeforward5 = totaltimeforward5/numberoftries5;
            
              averagetime5 = String(averagetimeforward5);
             
              
              
              delay(500);
              
              clearlcd();
              
              
       
              
              
              
              //Serial.println(averagetimeforward);
              timerstop5 = 0;
              }
              
              lvl = 14;
           
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              break;
              
              
              }
            }


          if(lvl == 16){
              timerstop5 = 0;
               lcd.clear();
              delay(1000);
              levelState = digitalRead(levelSwitch);
             printByte(empty);   
              setAudio(audioLeft);
              delay(1000);
              setAudio(audioStop);
              
              if (levelState == LOW){
                lvl = 18;
            
                levelState = HIGH;
              }
              lvl++;
              
            }

           if(lvl == 17){
               lcd.clear();
              lcd.print("Audio Left:");
              lcd.print(averagetime6);
              levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
    
                lvl = 18;
                levelState = HIGH;
                
              }
             
                   if (timerstop6 == 0){
                  timef6 = 0;
                  timef6 =  millis();
                
                  timerstop6 = 1;
                   }
              switch(currentDirection){
          
              case 'F':
              
              break;
              case 'L':
              break;
              case 'R':
              
              printByte(bball);
              delay(1000);
              printByte(empty);
              
              if(timerstop6 == 1){
                 
                
                
              endtime6 = millis();
              duration6 = ((endtime6-timef6)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries6++;
              
              totaltimeforward6 = totaltimeforward6 + duration6;
              averagetimeforward6 = totaltimeforward6/numberoftries6;
            
              averagetime6 = String(averagetimeforward6);
             
              
              
              delay(500);
              
              clearlcd();
              
              
       
              
              
              
              //Serial.println(averagetimeforward);
              timerstop6 = 0;
              }
              
              lvl = 16;
           
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              break;
              
              
              }
            }









          if(lvl == 18){
              timerstop6 = 0;
               lcd.clear();
              delay(1000);
              levelState = digitalRead(levelSwitch);

                 
              
              
            //  printByte(forward_Arrow);
             printByte(empty);   
              setAudio(audioRight);
              delay(1000);
              setAudio(audioStop);
              
              if (levelState == LOW){
                lvl = 20;
            
                levelState = HIGH;
              }
              lvl++;
              
            }

           if(lvl == 19){
               lcd.clear();
              lcd.print("Audio Right:");
              lcd.print(averagetime7);
              levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
    
                lvl = 20;
                levelState = HIGH;
                
              }
             
                   if (timerstop7 == 0){
                  timef7 = 0;
                  timef7 =  millis();
                
                  timerstop7 = 1;
                   }
              switch(currentDirection){
          
              case 'F':
              
              break;
              case 'R':
              break;
              case 'L':
              
              printByte(bball);
              delay(1000);
              printByte(empty);
              
              if(timerstop7 == 1){
                 
                
                
              endtime7 = millis();
              duration7 = ((endtime7-timef7)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries7++;
              
              totaltimeforward7 = totaltimeforward7 + duration7;
              averagetimeforward7 = totaltimeforward7/numberoftries7;
            
              averagetime7 = String(averagetimeforward7);
             
              
              
              delay(500);
              
              clearlcd();
                       

              timerstop7 = 0;
              }
              
              lvl = 18;
           
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              break;
              
              
              }
            }






            if(lvl == 20){
              timerstop7 = 0;
               lcd.clear();
              delay(1000);
              levelState = digitalRead(levelSwitch);
             printByte(empty);   
              setAudio(audioBack);
              delay(1000);
              setAudio(audioStop);
              
              if (levelState == LOW){
                lvl = 22;
            
                levelState = HIGH;
              }
              lvl++;
              
            }

           if(lvl == 21){
               lcd.clear();
              lcd.print("Audio Back:");
              lcd.print(averagetime8);
              levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
    
                lvl = 22;
                levelState = HIGH;
                
              }
             
                   if (timerstop8 == 0){
                  timef8 = 0;
                  timef8 =  millis();
                
                  timerstop8 = 1;
                   }
              switch(currentDirection){
          
              case 'F':
              
              break;
              case 'L':
              break;
              case 'B':
              
              printByte(bball);
              delay(1000);
              printByte(empty);
              
              if(timerstop8 == 1){
                 
                
                
              endtime8 = millis();
              duration8 = ((endtime8-timef8)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries8++;
              
              totaltimeforward8 = totaltimeforward8 + duration8;
              averagetimeforward8 = totaltimeforward8/numberoftries8;
            
              averagetime8 = String(averagetimeforward8);
                    
              delay(500);
              
              clearlcd();

              timerstop8 = 0;
              }
              
              lvl = 20;
           
              
              //insert a correct or hooray audio here
              break;
              case 'R':
              break;
              
              
              }
            }
                        
            if (lvl == 22){
             timerstop8 = 0;
             delay(1000);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 1;
              }
            int drction = randomarrow();
            Serial.println(drction);

            if (drction == 1){
              printByte(empty);
              Serial.println("RIGHT");
              setAudio(audioRight);
              delay(1000);
              setAudio(audioStop);
               if (timerstop9 == 0){
                  timef9 = 0;
                  timef9 =  millis();
                
                  timerstop9 = 1;
                 }
              lvl = 23;
            }
            if(drction == 2){
              printByte(empty);
              Serial.println("RIGHT");
              setAudio(audioForward);
              delay(1000);
              setAudio(audioStop);
                if (timerstop9 == 0){
                  timef9 = 0;
                  timef9 =  millis();
                
                  timerstop9 = 1;
                 }
              lvl = 24;
            }
            if(drction == 3){
              printByte(empty);
              Serial.println("RIGHT");
              setAudio(audioLeft);
              delay(1000);
              setAudio(audioStop);
                if (timerstop9 == 0){
                  timef9 = 0;
                  timef9 =  millis();
                
                  timerstop9 = 1;
                 }
              lvl = 25;
            }
            if(drction == 4){
              printByte(empty);
              Serial.println("RIGHT");
              setAudio(audioBack);
              delay(1000);
              setAudio(audioStop);
                if (timerstop9 == 0){
                  timef9 = 0;
                  timef9 =  millis();
                
                  timerstop9 = 1;
                 }
              lvl = 26;
            }
          }
          if(lvl == 23){
              lcd.clear();
              lcd.print("Audio Random:");
              lcd.print(averagetime9);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 1;
              }
             switch(currentDirection){
              case 'R':
              
              break;
              case 'L':
              lvl = 22;
              printByte(bball);
              delay(1000);
              printByte(empty);
              if(timerstop9 == 1){
              endtime9 = millis();
              duration9 = ((endtime9 - timef9)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries9++;
              
              totaltimeforward9 = totaltimeforward9 + duration9;
              averagetimeforward9 = totaltimeforward9/numberoftries9;
            
              averagetime9 = String(averagetimeforward9);
             
              
              
              delay(500);
              
              clearlcd();
              
              
         
              
              
              
              //Serial.println(averagetimeforward);
              timerstop9 = 0;
              }
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              
              break;
            }
            
          }
          if(lvl == 24){
             lcd.clear();
              lcd.print("Audio Random:");
              lcd.print(averagetime9);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 1;
              }
             switch(currentDirection){
              case 'L':
              
              break;
              case 'R':
              
              break;
              case 'F':
              lvl = 22;
              printByte(bball);
              delay(1000);
               printByte(empty);
              if(timerstop9 == 1){
              endtime9 = millis();
              duration9 = ((endtime9 - timef9)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries9++;
              
              totaltimeforward9 = totaltimeforward9 + duration9;
              averagetimeforward9 = totaltimeforward9/numberoftries9;
            
              averagetime9 = String(averagetimeforward9);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              //Serial.println(averagetimeforward);
              timerstop9 = 0;
              }
              //insert a correct or hooray audio here
              break;
              case 'B':
              
              break;
            }
            
          }
          if(lvl == 25){
             lcd.clear();
              lcd.print("Audio Random:");
              lcd.print(averagetime9);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 1;
              }
             switch(currentDirection){
              case 'R':
              lvl = 22;
              printByte(bball);
              delay(1000);
               printByte(empty);
              if(timerstop9 == 1){
              endtime9 = millis();
              duration9 = ((endtime9 - timef9)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries9++;
              
              totaltimeforward9 = totaltimeforward9 + duration9;
              averagetimeforward9 = totaltimeforward9/numberoftries9;
            
              averagetime9 = String(averagetimeforward9);
             
              
              
              delay(500);
              
              clearlcd();
              
        
              
              //Serial.println(averagetimeforward);
              timerstop9 = 0;
              }
              break;
              case 'L':
              
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              
              break;
            }
            
          }
          if(lvl == 26){
             lcd.clear();
              lcd.print("Audio Random:");
              lcd.print(averagetime9);
            levelState = digitalRead(levelSwitch);
              if (levelState == LOW){
                lvl = 1;
              }
             switch(currentDirection){
              case 'L':
              
              break;
              case 'R':
              
              break;
              case 'F':
              
              //insert a correct or hooray audio here
              break;
              case 'B':
              lvl = 22;
              printByte(bball);
              delay(1000);
              printByte(empty);
              if(timerstop9 == 1){
              endtime9 = millis();
              duration9 = ((endtime9 - timef9)-(pausetime - spausetime))/1000;
              pausetime = 0;
              spausetime = 0;
              numberoftries9++;
              
              totaltimeforward9 = totaltimeforward9 + duration9;
              averagetimeforward9 = totaltimeforward9/numberoftries9;
            
              averagetime9 = String(averagetimeforward9);
             
              
              
              delay(500);
              
              clearlcd();
              
              
              Serial.println("Average time bck:");
              Serial.println(averagetimeforward3);

              
              
              
              //Serial.println(averagetimeforward);
              timerstop9 = 0;
              }
              break;
            }
            
          }










          
      }
}

//returns current joystick direction as F,B,L,R, or N

int randomarrow (){
    int drction;

    drction = random(1,5);

    return drction;    
}
char getDirection(){
  
  delay(80); //delay prevents display flashing
  
    lSt = digitalRead(leftswitch);
    rSt = digitalRead(upswitch);
    uSt = digitalRead(rightswitch);
    dSt = digitalRead(downswitch);
  
  //evaluates direction, treating diagonals as neutral
  if (uSt == LOW){
    return 'R';
  }
  if (dSt == LOW){
    return 'F';
  }
  if (lSt == LOW){
    return 'B';
  }
  if (rSt == LOW){
    return 'L';
  }
  return 'N'; //defaults to neutral
}

void clearlcd(){
  lcd.print("");
  lcd.clear();
  delay(100);
  
}
//displays image
void printByte(byte character []){
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

//sends 1-byte command code (char) to audio board
void setAudio(byte c){
  
  Serial.println("Sending  : " + c);
  Wire.beginTransmission(slaveID);  // transmit to device
  Wire.write(c);              // sends one byte
  Serial.println("Sent code: " + c);
  Wire.endTransmission();     // stop transmitting
}
