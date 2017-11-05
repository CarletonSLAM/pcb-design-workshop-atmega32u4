// Source: https://www.pololu.com/docs/0J61/6.3

// Toggle an LED connected to PC7 (Port C, Pin 7)

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
 
int main()
{
  DDRC |= (1 << DDC7);    // Make pin 13 be an output.  
  while(1)
  {
    PORTC |= (1 << PORTC7);   // Turn the LED on.
    _delay_ms(1000);
    PORTC &= ~(1 << PORTC7);  // Turn the LED off.
    _delay_ms(1000);
  }
}