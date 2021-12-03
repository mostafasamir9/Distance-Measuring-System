#include "lcd.h"
#include "ultrasonic.h"
#include "avr/io.h"
#include "util/delay.h"

volatile uint8 ultraSonic_Flag = 0;

int main(){
	/*enable the interrupt */

	SREG |= (1<<7);

	/* initialzie the lcd */
	LCD_init();

	uint16 distance;

	LCD_displayStringRowColumn(0 ,0 ,"Distance= ");
	LCD_displayStringRowColumn(0 ,14 ,"Cm");

	while(1){
	/*send trigger */
	Ultrasonic_trigger();

	/* wait until the pusle arrived */
	while (ultraSonic_Flag == 0);

	/* calculate distance */
	distance = Ultrasonic_readDistance();

	/*display the distance */
	LCD_moveCursor(0,10);
	LCD_intgerToString(distance);
	LCD_displayString(" ");

	}

}
