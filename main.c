/* 
 * main.c
 *
 *      Author: Ewa Krzaczkowska
 *
 * Project name: "projekt inzynierski"
 *
 *          MCU: ATmega8A
 *        F_CPU: 8 000 000 Hz
 *
 */

//biblioteki
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <avr/pgmspace.h>
#include "uart.h"
#include <avr/wdt.h>
#include "nRF24L01.h"

//stale
#define PWM_A    (1<<PB1) 

void odbior ( void * bufor , uint8_t length );
void PWM_init(void);

int main (void)
{
	//inicjalizacja usarta tylko do testowania
	/*USART_Init(MYUBRR);*/

	//inicjalizacja polaczenia radiowego
    	nRF_init();
	//funkcja odbiorcza
    	register_nRF_RX_Event_Callback(odbior);
	
  	//zezwolenie na przerwania
    	sei();

	//wlaczenie NRF
    	nRF_RX_Power_Up();
		
	//ustawienie PWM
   	DDRB |= (PWM_A);
    	PWM_init();
    	OCR1A = 0; //poczatkowo silnik nie pracuje

	wdt_enable( WDTO_120MS ); //watchdogi
	while(1)
	{	
		nRF_RX_EVENT();
	}
}

void odbior( void * bufor, uint8_t length )
{
	//porownywanie odebranej wartosci i odpowiednie dopasowanie szybkosci silnika
	if (!strcmp_P( bufor , PSTR("K"))) OCR1A = 0; 
	if (!strcmp_P( bufor , PSTR("trzy"))) OCR1A = 60; 
	if (!strcmp_P( bufor , PSTR("szesc"))) OCR1A = 80; 
	if (!strcmp_P( bufor , PSTR("dwana"))) OCR1A = 120; 
	if (!strcmp_P( bufor , PSTR("szesn"))) OCR1A = 160; 
	if (!strcmp_P( bufor , PSTR("dwadz"))) OCR1A = 200;
	if (!strcmp_P( bufor , PSTR("dwatr"))) OCR1A = 230;  	
}

//---------------------------------PWM------------------------------------------

void PWM_init(void){
	TCCR1A |= (1<<WGM10);         // 8 bitowy Fast PWM  
    	TCCR1B |= (1<<WGM12); 
    	TCCR1A |= (1<<COM1A1);        //Clear on Compare 
    	TCCR1B |= (1<<CS10)|(1<<CS11);// Preksaler
}
