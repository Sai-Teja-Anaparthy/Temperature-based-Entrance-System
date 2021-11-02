  
//Playing song on the arduino
//author: Adesola Samuel 2020

//This code produce the jingle bells melody using arduino and a buzzer. The buzzer used is an active buzzer
//Connect the positive side of the passive buzzer to arduino pin 8 and connect the negative part to ground 


//To make a RGB led on in tune with the buzzer, you can connect the LED on pin 2,3,4 and uncomment the specifed codes

#include "pitches.h"

// notes in the melody:
int melody[] = {
    //jingle bells
  NOTE_CS1, NOTE_CS1, NOTE_CS1,NOTE_CS1, NOTE_CS1, NOTE_CS1, NOTE_CS1, NOTE_CS1/* NOTE_E5, NOTE_G5, NOTE_C5,NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5,NOTE_F5, NOTE_F5, NOTE_E5,NOTE_E5, NOTE_E5,NOTE_E5, NOTE_D5, NOTE_D5,NOTE_E5, NOTE_D5, NOTE_G5,
  NOTE_E5, NOTE_E5, NOTE_E5,NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_G5, NOTE_C5,NOTE_D5, NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5,NOTE_F5, NOTE_F5, NOTE_E5,NOTE_E5, NOTE_E5,NOTE_G5, NOTE_G5, NOTE_F5,NOTE_D5, NOTE_C5 */
  };


// note durations: 4 = quarter note, 8 = eighth note, etc.:
float noteDurations[] = {
 /* 4,4,2,4,4,2,4,4,4,4,1,
  4,4,4,4,4,4,4,2,4,4,4,4,2,2,
  4,4,2,4,4,2,4,4,4,4,1,
  4,4,4,4,4,4,4,2,4,4,4,4,1 */
  3,3,3,3,3,3,3,3
};

void setup() {
pinMode(3, OUTPUT);
  
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 49; thisNote++) {
      //digitalWrite(i , HIGH);  //uncomment for the LED
    
     // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(3, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(3);
}
}

void loop() {

     
  }
