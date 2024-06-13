

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

// Which pin on the Arduino is connected to the NeoPixels?

#define PIN 59 // MEGA
//#define PIN 19 // UNO

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 6 // 
//there are 6

// When setting up the NeoPixel library, we tell it how many pixels,  
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define switch_1 2
#define switch_2 3
#define switch_3 4
#define switch_4 5
#define switch_5 6
#define switch_6 7


int analog = 0;
int delta = 20;
int mode = 1;//modes are 1,2,3,4,5,6,7,8,9 which are pixel 8,7,6,5,4,3,2,1, and 0 respectively


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

    pinMode(switch_1,OUTPUT);
    pinMode(switch_2,OUTPUT);
    pinMode(switch_3,OUTPUT);
    pinMode(switch_4,OUTPUT);
    pinMode(switch_5,OUTPUT);
    pinMode(switch_6,OUTPUT);


    digitalWrite(switch_1,HIGH);
    digitalWrite(switch_2,LOW);
    digitalWrite(switch_3,LOW);
    digitalWrite(switch_4,LOW);
    digitalWrite(switch_5,LOW);
    digitalWrite(switch_6,LOW);
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}





void loop() {

    

  pixels.clear(); // Set all pixel colors to 'off'
  analog = analogRead(A4);
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  
  if(analog > 1024 - delta){
    delay(1);
    analog = analogRead(A4);
    if(analog > 1023 - delta){
       mode = 1;      
    }
  }
  if(analog > 784 - delta && analog < 784 + delta){
    delay(5);
    analog = analogRead(A4);
    if(analog > 784 - delta && analog < 784 + delta){
         mode = 2; 
    }
  }
  if(analog > 596 - delta && analog < 596 + delta){
     delay(5);
     analog = analogRead(A4);

    if(analog > 596 - delta && analog < 596 + delta){
      mode = 3;    
    }
  }

  if(analog > 437 - delta && analog < 437 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 437 - delta && analog < 437 + delta){
      mode = 4;    
    }
  }

  if(analog > 290 - delta && analog < 290 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 290 - delta && analog < 290 + delta){
      mode = 5;    
    }
  }

  if(analog > 158 - delta && analog < 158 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 158 - delta && analog < 158 + delta){
      mode = 6;    
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
 

  }

  if(mode == 1){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(255, 0, 0));    

    digitalWrite(switch_1,HIGH);
    digitalWrite(switch_2,LOW);
    digitalWrite(switch_3,LOW);
    digitalWrite(switch_4,LOW);
    digitalWrite(switch_5,LOW);
    digitalWrite(switch_6,LOW);

    
  }
  if(mode == 2){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(switch_1,LOW);
    digitalWrite(switch_2,HIGH);
    digitalWrite(switch_3,LOW);
    digitalWrite(switch_4,LOW);
    digitalWrite(switch_5,LOW);
    digitalWrite(switch_6,LOW);
 
  }
  if(mode == 3){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(switch_1,LOW);
    digitalWrite(switch_2,LOW);
    digitalWrite(switch_3,HIGH);
    digitalWrite(switch_4,LOW);
    digitalWrite(switch_5,LOW);
    digitalWrite(switch_6,LOW);

  }
  if(mode == 4){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
  
    digitalWrite(switch_1,LOW);
    digitalWrite(switch_2,LOW);
    digitalWrite(switch_3,LOW);
    digitalWrite(switch_4,HIGH);
    digitalWrite(switch_5,LOW);
    digitalWrite(switch_6,LOW);


  }
  if(mode == 5){
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    
    
    digitalWrite(switch_1,LOW);
    digitalWrite(switch_2,LOW);
    digitalWrite(switch_3,LOW);
    digitalWrite(switch_4,LOW);
    digitalWrite(switch_5,HIGH);
    digitalWrite(switch_6,LOW);


  }
  if(mode == 6){
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(switch_1,LOW);
    digitalWrite(switch_2,LOW);
    digitalWrite(switch_3,LOW);
    digitalWrite(switch_4,LOW);
    digitalWrite(switch_5,LOW);
    digitalWrite(switch_6,HIGH);

  }


  
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop

//    Serial.println(analog);

}
