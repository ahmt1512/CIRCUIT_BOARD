#include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN 7

int main(void) {
  DDRD |= (1 << 7);
  DDRB = 0xFF;   

  while(1) {
    PORTD = 0xFF;
    PORTB = 0x00;
    _delay_ms(1000);
    PORTB = (1 << 3) | (1);
    PORTB = ~PORTB;
    _delay_ms(1000);
    PORTD = (1 << 7);
    PORTB = (1 << 3) | (1 << 4) | (1 << 1) | (1 << 2);
    PORTB = ~PORTB;
    PORTD = ~PORTD;
    _delay_ms(1000);
    PORTB = (1 << 1) | (1 << 3) | (1 << 4) | (1);
    PORTB = ~PORTB;
    _delay_ms(1000);
  } 
  return 0;
}