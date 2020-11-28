/*
* Calculator.c
*
* Created: 10/5/2020 8:31:44 PM
* Author : Mirette
*/

#include <avr/io.h>
#include "KeyPad.h"
#include <string.h>

int main(void)
{
	DIO_Init();
	LCD_Init();
	LCD_Clear();
	char str[16]="" , strAns[16]="", temp[16] = "";
	char op=0;
	int num[16]={};
	char begin1[16] = "A:+, B:-, C:/,  ";
	char begin2[16] = "D:=, #:clear    ";
	unsigned char res;
	int i = 0, pos=15,y=0,c=0,cnt=0,n=0,m=0,f=0,s=0;
	while (1)
	{
		res = GetKey();
		if (res != 0 && res != '#')
		{
			LCD_Char(res);
			strncat(str,&res,1);
			if (res == '=')
			{
				for (i=0;i<strlen(str)-1;i++)
				{
					if (str[i]=='+' || str[i] == '-' || str[i] == 'x' || str[i] == '/')
					{
						op = str[i];
						strncat(temp,&str,i);
						num[cnt] = atoi(temp);
						temp[0]=0;
						cnt++;
						for (c = i+1; c < strlen(str)-1; c++) strncat(temp,&str[c],1);
						num[cnt] = atoi(temp);
					}
					
				}
				switch (op)
				{
					case '+':
					itoa((num[0] + num[1]),strAns,10);
					break;
					case '-':
					if (num[0]<num[1])
					{
						strAns[0]='-';
						itoa((num[0] - num[1]),strAns,10);
					}
					else  itoa((num[0] - num[1]),strAns,10);
					break;
					case 'x':
					itoa((num[0] * num[1]),strAns,10);
					break;
					case '/':
					itoa((num[0] / num[1]),strAns,10);
					break;
				}
				//LCD_Clear();
				LCD_ClearbyLine(1);
				LCD_StringPos(strAns,1,0);
			}
		}
		else if (res == '#')
		{
			LCD_Clear();
			num[0]= 0;
			temp[0]= 0;
			str[0]= 0;
			strAns[0]=0;
			op= 0;
			cnt=0;
		}
	}
}

//Attempt for MultiTasking
/*for (pos = 15,n=0; pos>=0,n<16; pos--,n++)
{
for (y=0;y<=n;y++)
{
LCD_CharPos(begin1[y],2,pos+y);
}
_delay_ms(100);
}
if (pos>=0 && n<16)
{
}
LCD_ClearbyLine(2);
_delay_ms(100);

begin2[16] = "D:=, #:clear    ";
for (pos = 15,n=0; pos>=0,n<16; pos--,n++)
{
for (y=0;y<=n;y++)
{
LCD_CharPos(begin2[y],2,pos+y);
}
_delay_ms(100);
}
LCD_ClearbyLine(2);
_delay_ms(100);
if (f==15) f=0;
else f++;
}*/

/*//if (s<16)
//{

res = GetKey();
if (res != 0 && res != '#')
{
	LCD_Char(res);
	strncat(str,&res,1);
	if (res == '=')
	{
		for (i=0;i<strlen(str)-1;i++)
		{
			if (str[i]=='+' || str[i] == '-' || str[i] == 'x' || str[i] == '/')
			{
				op = str[i];
				strncat(temp,&str,i);
				num[cnt] = atoi(temp);
				temp[0]=0;
				cnt++;
				for (c = i+1; c < strlen(str)-1; c++) strncat(temp,&str[c],1);
				num[cnt] = atoi(temp);
			}
			
		}
		switch (op)
		{
			case '+':
			itoa((num[0] + num[1]),strAns,10);
			break;
			case '-':
			if (num[0]<num[1])
			{
				strAns[0]='-';
				itoa((num[0] - num[1]),strAns,10);
			}
			else  itoa((num[0] - num[1]),strAns,10);
			break;
			case 'x':
			itoa((num[0] * num[1]),strAns,10);
			break;
			case '/':
			itoa((num[0] / num[1]),strAns,10);
			break;
		}
		//LCD_Clear();
		LCD_ClearbyLine(1);
		LCD_StringPos(strAns,1,0);
	}
}
else if (res == '#')
{
	LCD_ClearbyLine(1);
	num[0]= 0;
	temp[0]= 0;
	str[0]= 0;
	strAns[0]=0;
	op= 0;
	cnt=0;
}
//if (s==15) s=0;
//else s++;
//}
//if (f<16)
//{
//if (m==0)
//{
//if (pos<=15 && n>=0 && pos != 0 && n != 16)
//{
//if (y<=n)
//{
//LCD_CharPos(begin1[y],2,pos+y);
//y++;
//}
//else y=0;
//_delay_ms(100);
//pos--;
//n++;
//}
//else
//{
//LCD_ClearbyLine(2);
//_delay_ms(100);
//pos = 15;
//n=0;
//m=1;
//}
//}
//else if (m==1)
//{
//if (pos<=15 && n>=0 && pos != 0 && n != 16)
//{
//if (y<=n)
//{
//LCD_CharPos(begin2[y],2,pos+y);
//y++;
//}
//else y=0;
//_delay_ms(100);
//pos--;
//n++;
//}
//else
//{
//LCD_ClearbyLine(2);
//_delay_ms(100);
//pos=15;
//n=0;
//m = 0;
//}
//}
//}
}*/