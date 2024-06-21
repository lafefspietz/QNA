

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 59 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12 // 
//there are 9

// When setting up the NeoPixel library, we tell it how many pixels,  
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define SP8T_1 2
#define SP8T_2 3
#define SP8T_3 4
#define SP8T_4 5

#define SP8T_5 6
#define SP8T_6 7
#define SP8T_7 8
#define SP8T_8 9

#define NOT_SP8T_1 10
#define NOT_SP8T_2 11
#define NOT_SP8T_3 12
#define NOT_SP8T_4 13

#define NOT_SP8T_5 14
#define NOT_SP8T_6 15
#define NOT_SP8T_7 16
#define NOT_SP8T_8 17

#define ECAL_SHORT 30
#define ECAL_LOAD 32
#define ECAL_1234 34
#define ECAL_5678 36

int analog = 0;
int analogEcal = 0;
int delta = 20;
int mode = 1;//modes are 1,2,3,4,5,6,7,8 which are pixel 7,6,5,4,3,2,1, and 0 respectively
int modeEcal = 4;//modes are 1,2,3,4 which are pixel 3,2,1, and 0 respectively. mode 1 is short, 2 is open, 3 is load, 4 is thru


void setup() {
    Serial.begin(115200);


  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

/*
    pinMode(2,OUTPUT);// DSUB 8,  U4 -> U1
    pinMode(3,OUTPUT);// DSUB 9,  U4 -> U2
    pinMode(4,OUTPUT);// DSUB 10, U4 -> U3
    pinMode(5,OUTPUT);// DSUB 11, U4 COM
    pinMode(6,OUTPUT);// DSUB 14, U3 -> port 7
    pinMode(7,OUTPUT);// DSUB 15, U3 -> port 8
    pinMode(8,OUTPUT);// DSUB 16, U3 -> port 9
    pinMode(9,OUTPUT);// DSUB 17, U3 COM
    pinMode(10,OUTPUT);//DSUB 18, U2 -> 4 
    pinMode(11,OUTPUT);//DSUB 19, U2 -> 5
    pinMode(12,OUTPUT);//DSUB 20, U2 -> 6
    pinMode(13,OUTPUT);//DSUB 21, U2 COM
    pinMode(14,OUTPUT);//DSUB 22, U1 -> 1
    pinMode(15,OUTPUT);//DSUB 23, U1 -> 2
    pinMode(16,OUTPUT);//DSUB 24, U1 -> 3
    pinMode(17,OUTPUT);//DSUB 25, U1 COM
*/

    pinMode(SP8T_1,OUTPUT);
    pinMode(SP8T_2,OUTPUT);
    pinMode(SP8T_3,OUTPUT);
    pinMode(SP8T_4,OUTPUT);
    pinMode(SP8T_5,OUTPUT);
    pinMode(SP8T_6,OUTPUT);
    pinMode(SP8T_7,OUTPUT);
    pinMode(SP8T_8,OUTPUT);

    pinMode(NOT_SP8T_1,OUTPUT);
    pinMode(NOT_SP8T_2,OUTPUT);
    pinMode(NOT_SP8T_3,OUTPUT);
    pinMode(NOT_SP8T_4,OUTPUT);
    pinMode(NOT_SP8T_5,OUTPUT);
    pinMode(NOT_SP8T_6,OUTPUT);
    pinMode(NOT_SP8T_7,OUTPUT);
    pinMode(NOT_SP8T_8,OUTPUT);

    pinMode(ECAL_SHORT,OUTPUT);
    pinMode(ECAL_LOAD,OUTPUT);
    pinMode(ECAL_1234,OUTPUT);
    pinMode(ECAL_5678,OUTPUT);

    digitalWrite(SP8T_1,LOW);
    digitalWrite(SP8T_2,LOW);
    digitalWrite(SP8T_3,LOW);
    digitalWrite(SP8T_4,LOW);
    digitalWrite(SP8T_5,LOW);
    digitalWrite(SP8T_6,LOW);
    digitalWrite(SP8T_7,LOW);
    digitalWrite(SP8T_8,LOW);

    digitalWrite(NOT_SP8T_1,LOW);
    digitalWrite(NOT_SP8T_2,LOW);
    digitalWrite(NOT_SP8T_3,LOW);
    digitalWrite(NOT_SP8T_4,LOW);
    digitalWrite(NOT_SP8T_5,LOW);
    digitalWrite(NOT_SP8T_6,LOW);
    digitalWrite(NOT_SP8T_7,LOW);
    digitalWrite(NOT_SP8T_8,LOW);

    digitalWrite(ECAL_SHORT,LOW);
    digitalWrite(ECAL_LOAD,LOW);
    digitalWrite(ECAL_1234,HIGH);
    digitalWrite(ECAL_5678,LOW);


  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}





void loop() {

    

  pixels.clear(); // Set all pixel colors to 'off'
  analog = analogRead(A8);

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
  if(analog > 1023 - delta){
    delay(1);
    analog = analogRead(A8);
    if(analog > 1023 - delta){
       mode = 1;      
    }
  }
  if(analog > 822 - delta && analog < 822 + delta){
    delay(5);
    analog = analogRead(A8);
    if(analog > 822 - delta && analog < 822 + delta){
         mode = 2; 
    }
  }
  if(analog > 667 - delta && analog < 667 + delta){
     delay(5);
     analog = analogRead(A8);

    if(analog > 667 - delta && analog < 667 + delta){
      mode = 3;    
    }
  }

  if(analog > 538 - delta && analog < 538 + delta){
     delay(1);
     analog = analogRead(A8);

    if(analog > 538 - delta && analog < 538 + delta){
      mode = 4;    
    }
  }

  if(analog > 425 - delta && analog < 425 + delta){
     delay(1);
     analog = analogRead(A8);

    if(analog > 425 - delta && analog < 425 + delta){
      mode = 5;    
    }
  }

  if(analog > 321 - delta && analog < 321 + delta){
     delay(1);
     analog = analogRead(A8);

    if(analog > 321 - delta && analog < 321 + delta){
      mode = 6;    
    }
  }

  if(analog > 220 - delta && analog < 220 + delta){
     delay(1);
     analog = analogRead(A8);

    if(analog > 220 - delta && analog < 220 + delta){
      mode = 7;    
    }
  }

  if(analog > 115 - delta && analog < 115 + delta){
     delay(1);
     analog = analogRead(A8);

    if(analog > 115 - delta && analog < 115 + delta){
      mode = 8;    
    }
  }

  analogEcal = analogRead(A4);

  if(analogEcal > 1023 - delta){
    delay(1);
    analog = analogRead(A4);
    if(analogEcal > 1023 - delta){
       modeEcal = 1;      
    }
  }

  if(analogEcal > 714 - delta && analogEcal < 714 + delta){
     delay(1);
     analogEcal = analogRead(A4);
    if(analogEcal > 714 - delta && analogEcal < 714 + delta){
      modeEcal = 2;    
    }
  }

  if(analogEcal > 463 - delta && analogEcal < 463 + delta){
     delay(1);
     analogEcal = analogRead(A4);
    if(analogEcal > 463 - delta && analogEcal < 463 + delta){
      modeEcal = 3;    
    }
  }

  if(analogEcal > 236 - delta && analogEcal < 236 + delta){
     delay(1);
     analogEcal = analogRead(A4);
    if(analogEcal > 236 - delta && analogEcal < 236 + delta){
      modeEcal = 4;    
    }
  }

  if (Serial.available()) {

    //for more info on this code see http://adam-meyer.com/arduino/arduino-serial
    //read serial as ascii integer
     int ser = Serial.read();
    //    Serial.println(ser);
     if(ser == 49){    //ASCII for 1
      mode = 1;
     }
     if(ser == 50){    //ASCII for 2
      mode = 2;
     }
     if(ser == 51){    //ASCII for 3
      mode = 3;
     }
     if(ser == 52){    //ASCII for 4
      mode = 4;
     }
     if(ser == 53){    //ASCII for 5
      mode = 5;
     }
     if(ser == 54){    //ASCII for 6
      mode = 6;
     }
     if(ser == 55){    //ASCII for 4
      mode = 7;
     }
     if(ser == 56){    //ASCII for 5
      mode = 8;
     }
 
     if(ser == 115){    //ASCII for s
      modeEcal = 1;
     }
     if(ser == 111){    //ASCII for o
      modeEcal = 2;
     }
     if(ser == 108){    //ASCII for l
      modeEcal = 3;
     }
     if(ser == 116){    //ASCII for t
      modeEcal = 4;
     }


  }

  if(mode == 1){
   
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(11, pixels.Color(100, 0, 100));    



    digitalWrite(SP8T_1,HIGH);
    digitalWrite(SP8T_2,LOW);
    digitalWrite(SP8T_3,LOW);
    digitalWrite(SP8T_4,LOW);
    digitalWrite(SP8T_5,LOW);
    digitalWrite(SP8T_6,LOW);
    digitalWrite(SP8T_7,LOW);
    digitalWrite(SP8T_8,LOW);

    digitalWrite(NOT_SP8T_1,LOW);
    digitalWrite(NOT_SP8T_2,HIGH);
    digitalWrite(NOT_SP8T_3,HIGH);
    digitalWrite(NOT_SP8T_4,HIGH);
    digitalWrite(NOT_SP8T_5,HIGH);
    digitalWrite(NOT_SP8T_6,HIGH);
    digitalWrite(NOT_SP8T_7,HIGH);
    digitalWrite(NOT_SP8T_8,HIGH);
    
  }
  if(mode == 2){

    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(10, pixels.Color(100, 0, 100));    
    pixels.setPixelColor(11, pixels.Color(0, 0, 0)); 
    
    digitalWrite(SP8T_1,LOW);
    digitalWrite(SP8T_2,HIGH);
    digitalWrite(SP8T_3,LOW);
    digitalWrite(SP8T_4,LOW);
    digitalWrite(SP8T_5,LOW);
    digitalWrite(SP8T_6,LOW);
    digitalWrite(SP8T_7,LOW);
    digitalWrite(SP8T_8,LOW);

    digitalWrite(NOT_SP8T_1,HIGH);
    digitalWrite(NOT_SP8T_2,LOW);
    digitalWrite(NOT_SP8T_3,HIGH);
    digitalWrite(NOT_SP8T_4,HIGH);
    digitalWrite(NOT_SP8T_5,HIGH);
    digitalWrite(NOT_SP8T_6,HIGH);
    digitalWrite(NOT_SP8T_7,HIGH);
    digitalWrite(NOT_SP8T_8,HIGH);
  }
  if(mode == 3){
  
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(100, 0, 100));    
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(11, pixels.Color(0, 0, 0));    
        
    digitalWrite(SP8T_1,LOW);
    digitalWrite(SP8T_2,LOW);
    digitalWrite(SP8T_3,HIGH);
    digitalWrite(SP8T_4,LOW);
    digitalWrite(SP8T_5,LOW);
    digitalWrite(SP8T_6,LOW);
    digitalWrite(SP8T_7,LOW);
    digitalWrite(SP8T_8,LOW);

    digitalWrite(NOT_SP8T_1,HIGH);
    digitalWrite(NOT_SP8T_2,HIGH);
    digitalWrite(NOT_SP8T_3,LOW);
    digitalWrite(NOT_SP8T_4,HIGH);
    digitalWrite(NOT_SP8T_5,HIGH);
    digitalWrite(NOT_SP8T_6,HIGH);
    digitalWrite(NOT_SP8T_7,HIGH);
    digitalWrite(NOT_SP8T_8,HIGH);
  }
  if(mode == 4){

    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(100, 0, 100));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(11, pixels.Color(0, 0, 0)); 

    digitalWrite(SP8T_1,LOW);
    digitalWrite(SP8T_2,LOW);
    digitalWrite(SP8T_3,LOW);
    digitalWrite(SP8T_4,HIGH);
    digitalWrite(SP8T_5,LOW);
    digitalWrite(SP8T_6,LOW);
    digitalWrite(SP8T_7,LOW);
    digitalWrite(SP8T_8,LOW);

    digitalWrite(NOT_SP8T_1,HIGH);
    digitalWrite(NOT_SP8T_2,HIGH);
    digitalWrite(NOT_SP8T_3,HIGH);
    digitalWrite(NOT_SP8T_4,LOW);
    digitalWrite(NOT_SP8T_5,HIGH);
    digitalWrite(NOT_SP8T_6,HIGH);
    digitalWrite(NOT_SP8T_7,HIGH);
    digitalWrite(NOT_SP8T_8,HIGH);    

  }
  if(mode == 5){

    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(100, 0, 100));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(11, pixels.Color(0, 0, 0));   
    
    digitalWrite(SP8T_1,LOW);
    digitalWrite(SP8T_2,LOW);
    digitalWrite(SP8T_3,LOW);
    digitalWrite(SP8T_4,LOW);
    digitalWrite(SP8T_5,HIGH);
    digitalWrite(SP8T_6,LOW);
    digitalWrite(SP8T_7,LOW);
    digitalWrite(SP8T_8,LOW);

    digitalWrite(NOT_SP8T_1,HIGH);
    digitalWrite(NOT_SP8T_2,HIGH);
    digitalWrite(NOT_SP8T_3,HIGH);
    digitalWrite(NOT_SP8T_4,HIGH);
    digitalWrite(NOT_SP8T_5,LOW);
    digitalWrite(NOT_SP8T_6,HIGH);
    digitalWrite(NOT_SP8T_7,HIGH);
    digitalWrite(NOT_SP8T_8,HIGH);

  }
  if(mode == 6){


  
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(100, 0, 100));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(11, pixels.Color(0, 0, 0)); 

    digitalWrite(SP8T_1,LOW);
    digitalWrite(SP8T_2,LOW);
    digitalWrite(SP8T_3,LOW);
    digitalWrite(SP8T_4,LOW);
    digitalWrite(SP8T_5,LOW);
    digitalWrite(SP8T_6,HIGH);
    digitalWrite(SP8T_7,LOW);
    digitalWrite(SP8T_8,LOW);

    digitalWrite(NOT_SP8T_1,HIGH);
    digitalWrite(NOT_SP8T_2,HIGH);
    digitalWrite(NOT_SP8T_3,HIGH);
    digitalWrite(NOT_SP8T_4,HIGH);
    digitalWrite(NOT_SP8T_5,HIGH);
    digitalWrite(NOT_SP8T_6,LOW);
    digitalWrite(NOT_SP8T_7,HIGH);
    digitalWrite(NOT_SP8T_8,HIGH);

  }

  if(mode == 7){
   

    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(100, 0, 100));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(11, pixels.Color(0, 0, 0)); 
    
    digitalWrite(SP8T_1,LOW);
    digitalWrite(SP8T_2,LOW);
    digitalWrite(SP8T_3,LOW);
    digitalWrite(SP8T_4,LOW);
    digitalWrite(SP8T_5,LOW);
    digitalWrite(SP8T_6,LOW);
    digitalWrite(SP8T_7,HIGH);
    digitalWrite(SP8T_8,LOW);

    digitalWrite(NOT_SP8T_1,HIGH);
    digitalWrite(NOT_SP8T_2,HIGH);
    digitalWrite(NOT_SP8T_3,HIGH);
    digitalWrite(NOT_SP8T_4,HIGH);
    digitalWrite(NOT_SP8T_5,HIGH);
    digitalWrite(NOT_SP8T_6,HIGH);
    digitalWrite(NOT_SP8T_7,LOW);
    digitalWrite(NOT_SP8T_8,HIGH);
 }
  if(mode == 8){
    
    pixels.setPixelColor(4, pixels.Color(100, 0, 100));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(9, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(10, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(11, pixels.Color(0, 0, 0)); 
        
    digitalWrite(SP8T_1,LOW);
    digitalWrite(SP8T_2,LOW);
    digitalWrite(SP8T_3,LOW);
    digitalWrite(SP8T_4,LOW);
    digitalWrite(SP8T_5,LOW);
    digitalWrite(SP8T_6,LOW);
    digitalWrite(SP8T_7,LOW);
    digitalWrite(SP8T_8,HIGH);

    digitalWrite(NOT_SP8T_1,HIGH);
    digitalWrite(NOT_SP8T_2,HIGH);
    digitalWrite(NOT_SP8T_3,HIGH);
    digitalWrite(NOT_SP8T_4,HIGH);
    digitalWrite(NOT_SP8T_5,HIGH);
    digitalWrite(NOT_SP8T_6,HIGH);
    digitalWrite(NOT_SP8T_7,HIGH);
    digitalWrite(NOT_SP8T_8,LOW);

  }

if(modeEcal == 1){
    
    //SHORT
    pixels.setPixelColor(3, pixels.Color(150, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));        

    digitalWrite(ECAL_SHORT,HIGH);
    digitalWrite(ECAL_LOAD,LOW);
    digitalWrite(ECAL_1234,LOW);
    digitalWrite(ECAL_5678,LOW);


}
if(modeEcal == 2){
    
    //OPEN
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(100, 100, 100));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));        
    digitalWrite(ECAL_SHORT,LOW);
    digitalWrite(ECAL_LOAD,LOW);
    digitalWrite(ECAL_1234,LOW);
    digitalWrite(ECAL_5678,LOW);

}
if(modeEcal == 3){
    
    //LOAD
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(128, 82, 0));    
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));        
    digitalWrite(ECAL_SHORT,LOW);
    digitalWrite(ECAL_LOAD,HIGH);
    digitalWrite(ECAL_1234,LOW);
    digitalWrite(ECAL_5678,LOW);

}
if(modeEcal == 4){
    
    //THRU
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(0, pixels.Color(0, 150, 0));        
    digitalWrite(ECAL_SHORT,LOW);
    digitalWrite(ECAL_LOAD,LOW);
    if(mode == 1 || mode == 2 || mode == 3 || mode == 4){
      digitalWrite(ECAL_1234,HIGH);
      digitalWrite(ECAL_5678,LOW);
    }
    else{
      digitalWrite(ECAL_1234,LOW);
      digitalWrite(ECAL_5678,HIGH);
    }



}

  
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop

   // Serial.print(analog);
   // Serial.print(",");
   // Serial.println(analogEcal);

}
