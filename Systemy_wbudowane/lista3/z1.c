
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>



#define SPEAKER PB5
#define SPEAKER_DDR DDRB
#define SPEAKER_PORT PORTB

#define BUZZ PB5
#define BUZZ_DDR DDRB
#define BUZZ_PORT PORTB



#define c4 131
#define d4 117
#define e4 104
#define f4 98
#define g4 88
#define a4 78
#define h4 74
#define b4 69
#define c5 65
#define d5 58
#define e5 52
#define f5 49
#define g5 44
#define a5 39
#define h5 37
#define b5 34
#define c6 32





// void playNote(uint32_t wavelength, uint32_t duration){
//     uint32_t elapsed;
//     // uint32_t i;
//     if (wavelength) {
//     for(elapsed = 0; elapsed < duration; elapsed += wavelength){
//         for (int k = 0; k < wavelength; k++){
//             _delay_us(1);
//         }
//         SPEAKER_PORT ^= (1 << SPEAKER);
//     }
//     }
//     else {
//         SPEAKER_PORT &= ~(1 << SPEAKER);
//         for (int k = 0; k < duration/2; k++){
//             _delay_us(1);
//         }
//     }
// }

#define TONE(step, delay) \
    if (!step) { \
        for (int k = 0; k < delay/4; k++){ \
            _delay_us(1); \
        }\
    }\
    else{ \
    for (uint16_t i = 0; i < (delay) / (step) / 2; i++) { \
      SPEAKER_PORT |= _BV(SPEAKER); \
      for (int k = 0; k < step; k++){ \
            _delay_us(1); \
        } \
      SPEAKER_PORT &= ~_BV(SPEAKER); \
      for (int k = 0; k < step; k++){ \
            _delay_us(1); \
        } \
    }\
    }




const uint16_t tempo=100;

static const uint32_t mozart[] PROGMEM = {
    g4, 0, d4, g4, 0, d4,
    g4, d4, g4, h4, d5, 0,
    c5, 0, a4, c5, 0, a4,
    c5, a4, f4, a4, d4, 0,
    g4, g4, h4, a4, g4,
    g4, f4, f4, a4, c5, f4,
    a4, g4, g4, h4, a4, g4,
    g4, f4, f4, a4, c5, f4,
    g4, g4, g4, f4, e4, f4, g4, g4, h4, a4, g4, a4,
    h4, h4, d5, c5, h4, c5, d5,
    d5, e5,
    d5, c5, c5, c5, c5, h4, h4,
    h4, a4, a4, g4, f4, e4, f4,
    g4, a4, h4,
    d5, e5,
    d5, c5, c5, c5, c5, h4, h4, h4,
    h4, a4, a4, a4, g4, f4, e4, f4,
    g4, h5, g5, e5, g5, ///uwaga, akompaniament
    0, g4, d4, g4, h4, d5, f4,
    g4, h5, g5, e5, g5, h5, 
    g4, d4, g4, h4, d5, f4, g4,
    0, g4, 0, g4
    
};

static const uint32_t duration[] PROGMEM = {
    4, 2, 2, 4, 2, 2,
    2, 2, 2, 2, 4, 4,
    4, 2, 2, 4, 2, 2,
    2, 2, 2, 2, 4, 4,
    4, 6, 2, 2, 2,
    2, 2, 6, 2, 2, 2,
    2, 2, 6, 2, 2, 2,
    2, 2, 6, 2, 2, 2,
    2, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1,
    2, 2, 1, 1, 1, 1, 8,
    8, 8,
    2, 2, 4, 2, 2, 4,
    2, 2, 4, 2, 2, 2, 2,
    4, 4, 8,
    8, 8,
    2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2,
    // 16,
    12, 1, 1, 1, 1,
    4, 1, 1, 1, 1, 4, 4,
    // 16,
    8, 1, 1, 1, 1, 4,
    4, 1, 1, 1, 1, 4, 4,
    4, 4, 4, 4
};



uint32_t temp = 65;

int main(){
  
  BUZZ_DDR |= _BV(BUZZ); 
  while(1) {
    for (int i=0;i<203;i++){
        uint32_t delay = pgm_read_word(&duration[i]), step = pgm_read_word(&mozart[i]);
            // playNote(step, (uint32_t)(1000)*delay*temp);
            TONE(step, (uint32_t)(1000)*delay*temp);
    }          
  }
}

