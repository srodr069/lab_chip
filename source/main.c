/*	Author: stevenrodriguez
 *  Partner(s) Name: Anthony Pham
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//https://docs.google.com/document/d/15Y1Fxs51NiZmmVObMsH5w_fu_tY0oTOj6ysDvW2hmDo/edit

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
   return (b ?  (x | (0x01 << k))  :  (x & ~(0x01 << k)) );
              //   Set bit to 1           Set bit to 0
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF; //inputs
    //DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00; //output portc

    unsigned char C = 0x00; // to set portC
    /* Insert your solution below */
    while (1) {
        unsigned char A = PINA & 0xFF;

        /* opting for switch/case statement method from lab partner 
        if ((A == 0x01) || (A == 0x02)){ //if A = 1 or 2 turn on PC5 / also below 4 so PC6
            //C = 0x60; // 01100000
            C = SetBit(C, 6, 1);
            C = SetBit(C, 5, 1);

            //setbit does not seem that much more efficient

        }

        if ((A == 0x03) || (A == 0x04)){ //if A = 3 or 4 turn on PC45 / also below 4 so PC6
            C = 0x70; // 01110000
        }

        //low fuel sets P6
        */

    switch(A) {
        case 0x00:
            C = SetBit(C, 6, 1); // low fuel light
        break;
        
        case 0x01: //same result so if we land on 0x01 same result as 0x02
        case 0x02:
            C = SetBit(C, 6, 1);
            C = SetBit(C, 5, 1);
            break;

        case 0x03:
        case 0x04:
            C = SetBit(C, 6, 1);
            C = SetBit(C, 5, 1);
            C = SetBit(C, 4, 1);
            break;

        case 0x05:
        case 0x06:
            C = SetBit(C, 5, 1);
            C = SetBit(C, 4, 1);
            C = SetBit(C, 3, 1);
            break;

        case 0x07:
        case 0x08:
        case 0x09:
            C = SetBit(C, 5, 1);
            C = SetBit(C, 4, 1);
            C = SetBit(C, 3, 1);
            C = SetBit(C, 2, 1);
            break;
            
        case 0x0A:
        case 0x0B:
        case 0x0C:
            C = SetBit(C, 5, 1);
            C = SetBit(C, 4, 1);
            C = SetBit(C, 3, 1);
            C = SetBit(C, 2, 1);
            C = SetBit(C, 1, 1);
            break;

        case 0x0D:
        case 0x0E:
        case 0x0F: //obviously a simple or = will do next time
            C = SetBit(C, 5, 1);
            C = SetBit(C, 4, 1);
            C = SetBit(C, 3, 1);
            C = SetBit(C, 2, 1);
            C = SetBit(C, 1, 1);
            C = SetBit(C, 0, 1);
            break;          
        }

        PORTC = C;
        C = 0x00;


        
    }
    return 1;
}
