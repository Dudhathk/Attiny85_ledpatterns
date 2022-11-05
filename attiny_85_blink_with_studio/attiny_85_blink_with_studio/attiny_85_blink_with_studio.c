/*
 * attiny_85_blink_with_studio.c
 *
 * Created: 11/5/2022 4:52:54 PM
 *  Author: Hardik dudhat
 */ 

/*
	For Pin configuration with DDRX and PORTX
	Pin           -->        DDR/PORT X
	5                           1
	6                           2
	7                           4
	3                           16
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	int delay_var = 500;
	int pin_numbers[] = {1,2,4,16};
	for(int i=0; i<4; i++){
		DDRB |= pin_numbers[i];
	}		
    /*DDRB |= pin_number;   */ 
    while(1){
		for(int i=0; i<4; i++){
			PORTB ^= pin_numbers[i];
			_delay_ms(delay_var);
			PORTB ^= pin_numbers[i];
		}	
		for(int i=3; i > -1; i--){
			PORTB ^= pin_numbers[i];
			_delay_ms(delay_var);
			PORTB ^= pin_numbers[i];
		}	
		_delay_ms(delay_var);
		for(int i=3; i > 0; i--){
			PORTB ^= pin_numbers[0];
			PORTB ^= pin_numbers[1];
			PORTB ^= pin_numbers[2];
			PORTB ^= pin_numbers[3];
			_delay_ms(delay_var);
			PORTB ^= pin_numbers[0];
			PORTB ^= pin_numbers[1];
			PORTB ^= pin_numbers[2];
			PORTB ^= pin_numbers[3];
		}		    
    }
}