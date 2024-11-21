
/*

4 buttons set 4 s paramters in this order: S11, S22, S21, S12

*/



#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 19 // A5 on UNO is pin 19

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 9 // 
//there are 9

// When setting up the NeoPixel library, we tell it how many pixels,  
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define OUTPUT_SWITCH_RFC 5
#define OUTPUT_SWITCH_RF1 4
#define OUTPUT_SWITCH_RF2 3
#define OUTPUT_SWITCH_RF3 2

#define INPUT_SWITCH_RFC 9
#define INPUT_SWITCH_RF1 8
#define INPUT_SWITCH_RF2 7
#define INPUT_SWITCH_RF3 6


int analog = 0;
int delta = 20;
int mode = 1;//modes are 1,2,3,4,5,6,7,8,9 which are pixel 8,7,6,5,4,3,2,1, and 0 respectively
int cycle = 0;//variable for cycling colors as test pattern with switch off

//input and output = 1 is S21, input and output = 2 is S22, S21 is from port 1 to port 2, and is input 1 and output 2
int inputselect = 1;
int outputselect = 1;

String sparameter = "Hello String";  

//modes are 

void setup() {
    Serial.begin(9600);

    pinMode(OUTPUT_SWITCH_RFC,OUTPUT);
    pinMode(OUTPUT_SWITCH_RF1,OUTPUT);
    pinMode(OUTPUT_SWITCH_RF2,OUTPUT);
    pinMode(OUTPUT_SWITCH_RF3,OUTPUT);

    pinMode(INPUT_SWITCH_RFC,OUTPUT);
    pinMode(INPUT_SWITCH_RF1,OUTPUT);
    pinMode(INPUT_SWITCH_RF2,OUTPUT);
    pinMode(INPUT_SWITCH_RF3,OUTPUT);

    digitalWrite(OUTPUT_SWITCH_RFC,HIGH);
    digitalWrite(INPUT_SWITCH_RFC,HIGH);
    digitalWrite(INPUT_SWITCH_RF2,LOW);
    digitalWrite(OUTPUT_SWITCH_RF2,LOW);

    digitalWrite(OUTPUT_SWITCH_RF1,HIGH);
    digitalWrite(OUTPUT_SWITCH_RF3,LOW);
    digitalWrite(INPUT_SWITCH_RF1,HIGH);
    digitalWrite(INPUT_SWITCH_RF3,LOW);
  
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
      outputselect = 1;
      inputselect = 1;
    }
  }
  if(analog > 836 - delta && analog < 836 + delta){
    delay(5);
    analog = analogRead(A4);
    if(analog > 836 - delta && analog < 836 + delta){
      outputselect = 2;
      inputselect = 2;
    }
  }
  if(analog > 690 - delta && analog < 690 + delta){
     delay(5);
     analog = analogRead(A4);

    if(analog > 690 - delta && analog < 690 + delta){
      outputselect = 2;
      inputselect = 1;
    }
  }

  if(analog > 569 - delta && analog < 569 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 569 - delta && analog < 569 + delta){
      outputselect = 1;
      inputselect = 2;
    }
  }


  if(analog > 464 - delta && analog < 464 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 464 - delta && analog < 464 + delta){
      //mode = 5;    
    }
  }

  if(analog > 372 - delta && analog < 372 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 372 - delta && analog < 372 + delta){
      //mode = 6;    
    }
  }

  if(analog > 283 - delta && analog < 283 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 283 - delta && analog < 283 + delta){
      //mode = 7;    
    }
  }

  if(analog > 195 - delta && analog < 195 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 195 - delta && analog < 195 + delta){
      //mode = 8;    
    }
  }

  if(analog > 103 - delta && analog < 103 + delta){
     delay(1);
     analog = analogRead(A4);

    if(analog > 103 - delta && analog < 103 + delta){
      //mode = 9;    
    }
  }

  if (Serial.available()) {

    //read serial as ascii integer
     int ser = Serial.read();
    //    Serial.println(ser);
    if(ser == 48){    //ASCII for 0

     }  
     if(ser == 49){    //ASCII for 1 
      outputselect = 1;
      inputselect = 1;
     }
     if(ser == 50){    //ASCII for 2
      outputselect = 2;
      inputselect = 2;
    }
     if(ser == 51){    //ASCII for 3
      outputselect = 2;
      inputselect = 1;
     }
     if(ser == 52){    //ASCII for 4
      outputselect = 1;
      inputselect = 2;
     }
     if(ser == 53){    //ASCII for 5

     }
     if(ser == 54){    //ASCII for 6

     }
     if(ser == 55){    //ASCII for 7

     }
     if(ser == 56){    //ASCII for 8

     }
     if(ser == 57){    //ASCII for 9

     }
     if(ser == 99){    //ASCII for c, which stands for "cycle"
     }

  }
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(4, pixels.Color(0, 0, 0));   

  if(outputselect == 1 && inputselect == 1){

    pixels.setPixelColor(8, pixels.Color(155, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(INPUT_SWITCH_RF1,HIGH);
    digitalWrite(INPUT_SWITCH_RF3,LOW);
    digitalWrite(OUTPUT_SWITCH_RF1,HIGH);
    digitalWrite(OUTPUT_SWITCH_RF3,LOW);

  }
  if(outputselect == 2 && inputselect == 2){

    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 155, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(INPUT_SWITCH_RF1,LOW);
    digitalWrite(INPUT_SWITCH_RF3,HIGH);
    digitalWrite(OUTPUT_SWITCH_RF1,LOW);
    digitalWrite(OUTPUT_SWITCH_RF3,HIGH);

  }
  if(outputselect == 2 && inputselect == 1){

    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 155)); 
    pixels.setPixelColor(5, pixels.Color(0, 0, 0));    

    digitalWrite(INPUT_SWITCH_RF1,HIGH);
    digitalWrite(INPUT_SWITCH_RF3,LOW);
    digitalWrite(OUTPUT_SWITCH_RF1,LOW);
    digitalWrite(OUTPUT_SWITCH_RF3,HIGH);

  }
    if(outputselect == 1 && inputselect == 2){

    pixels.setPixelColor(8, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(7, pixels.Color(0, 0, 0));    
    pixels.setPixelColor(6, pixels.Color(0, 0, 0)); 
    pixels.setPixelColor(5, pixels.Color(100, 0, 100));    

    digitalWrite(INPUT_SWITCH_RF1,LOW);
    digitalWrite(INPUT_SWITCH_RF3,HIGH);
    digitalWrite(OUTPUT_SWITCH_RF1,HIGH);
    digitalWrite(OUTPUT_SWITCH_RF3,LOW);

  }
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(1); // Pause before next pass through loop

  //Serial.println(analog);

}
