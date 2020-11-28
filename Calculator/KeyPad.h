/*
* KeyPad.h
*
* Created: 10/4/2020 6:43:41 PM
*  Author: Mirette
*/


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include "BitMath.h"
#include "LCD.h"

#define r1 0
#define r2 1
#define r3 2
#define r4 3
#define c1 4
#define c2 5
#define c3 6
#define c4 7

unsigned char check1();
unsigned char check2();
unsigned char check3();
unsigned char check4();
unsigned char GetKey();

#endif /* KEYPAD_H_ */