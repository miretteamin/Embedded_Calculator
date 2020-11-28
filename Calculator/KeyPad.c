/*
* KeyPad.c
*
* Created: 10/4/2020 6:43:50 PM
*  Author: Mirette
*/

#include "KeyPad.h"

unsigned char check1() //check on coloumn
{
	PORTD = 0b11111110;
	unsigned char res = 0;
	_delay_ms(150);
	if (GetBit(PIND,c1) == 0)
	{
		_delay_ms(100);
		res='=';
		//while(GetBit(PIND,r1) == 0);
	}
	if (GetBit(PIND,c2) == 0)
	{
		_delay_ms(100);
		res='/';
		//while(GetBit(PIND,r2) == 0);
	}
	if (GetBit(PIND,c3) == 0)
	{
		_delay_ms(100);
		res='-';
		//while(GetBit(PIND,r3) == 0);
	}
	if (GetBit(PIND,c4) == 0)
	{
		_delay_ms(100);
		res='+';
		//while(GetBit(PIND,r4) == 0);
	}
	
	return res;
}
unsigned char check2()
{
	PORTD = 0b11111101;
	unsigned char res = 0;
	_delay_ms(150);
	if (GetBit(PIND,c1) == 0)
	{
		_delay_ms(100);
		res='#'; 
		//while(GetBit(PIND,r1) == 0);
	}
	if (GetBit(PIND,c2) == 0)
	{
		_delay_ms(100);
		res='9';
		//while(GetBit(PIND,r2) == 0);
	}
	if (GetBit(PIND,c3) == 0)
	{
		_delay_ms(100);
		res='6';
		//while(GetBit(PIND,r3) == 0);
	}
	if (GetBit(PIND,c4) == 0)
	{
		_delay_ms(100);
		res='3';
		//while(GetBit(PIND,r4) == 0);
	}
	return res;
}

unsigned char check3()
{
	PORTD = 0b11111011;
	unsigned char res = 0;
	_delay_ms(150);
	if (GetBit(PIND,c1) == 0)
	{
		_delay_ms(100);
		res='0';
		//while(GetBit(PIND,r1) == 0);
	}
	if (GetBit(PIND,c2) == 0)
	{
		_delay_ms(100);
		res='8';
		//while(GetBit(PIND,r2) == 0);
	}
	if (GetBit(PIND,c3) == 0)
	{
		_delay_ms(100);
		res='5';
		//while(GetBit(PIND,r3) == 0);
	}
	if (GetBit(PIND,c4) == 0)
	{
		_delay_ms(100);
		res='2';
		//while(GetBit(PIND,r4) == 0);
	}
	return res;
}

unsigned char check4()
{
	PORTD = 0b11110111;
	unsigned char res = 0;
	_delay_ms(150);
	if (GetBit(PIND,c1) == 0)
	{
		_delay_ms(100);
		res='x'; //*
		//while(GetBit(PIND,r1) == 0);
	}
	if (GetBit(PIND,c2) == 0)
	{
		_delay_ms(100);
		res='7';
		//while(GetBit(PIND,r2) == 0);
	}
	if (GetBit(PIND,c3) == 0)
	{
		_delay_ms(100);
		res='4';
		//while(GetBit(PIND,c3) == 0);
	}
	if (GetBit(PIND,c4) == 0)
	{
		_delay_ms(100);
		res='1';
		//while(GetBit(PIND,r4) == 0);
	}
	
	return res;
}

unsigned char GetKey()
{
	unsigned char res = 0;
	res = check1();
	if (res != 0) return res;
	res = check2();
	if (res != 0) return res;
	res = check3();
	if (res != 0) return res;
	res = check4();
	if (res != 0) return res;
}