// Source: http://www.fourwalledcubicle.com/AVRArticles.php


// Echo back from UART0

#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((( F_CPU / 16) + ( USART_BAUDRATE / 2) ) / ( USART_BAUDRATE )) - 1)


void UART_init () {
	UCSR1B = (1 << RXEN1 ) | (1 << TXEN1 ); // Turn on the transmission and reception circuitry
	UCSR1C = (1 << UCSZ12 ) | (1 << UCSZ10 ) | (1 << UCSZ11 ); // Use 8- bit character sizes
	UBRR1H = ( BAUD_PRESCALE >> 8) ; // Load upper 8- bits of the baud rate value into the high byte of the UBRR register
	UBRR1L = BAUD_PRESCALE ; // Load lower 8 - bits of the baud rate value into the low byte of the UBRR register
}

void UART_send(const char* msg, uint16_t size) {
	while(size--) {
		while (( UCSR1A & (1 << UDRE1 )) == 0); // Do nothing until UDR is ready for more data to be written to it
		UDR1 = *(msg++); // Echo back the received byte back to the computer
	}
}


int main (void) {
	//char ReceivedByte ;
	char msgToSend [12] = {'h','e','l','l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\n'};
	UART_init();
	for (;;) {
		_delay_ms(1000);
		UART_send((char*) msgToSend, sizeof(msgToSend)/sizeof(char));
	}
	
	return 0;
}