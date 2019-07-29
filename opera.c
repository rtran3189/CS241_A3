/*	Name: Richard Tran
 * 	Date: January 23, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file contains all operations and arithmetic used by the program.
 */
#include <stdio.h>
#include <stdlib.h>
#include "help.h"

/*
 * This function takes a int number and int base number and converts
 * that number from that base to a decimal (base 10) number for use in processing.
 * Since it is easier and cleaner to convert any number to decimal before
 * converting it to another base, this function is necessary.
 */
short int baseToDecimal (int n, int baseNum)
{
	int num = n;
	int decimalValue = 0;

	/* Anything to the zero-th power is 1. */
	int base = 1;
	int temp = num;

	while (temp)
	{
		/* Extracts the last digit by finding remainder of
		   mod 10 (decimal base). */
		int lastDigit = temp % 10;
		temp = temp / 10;
		decimalValue += lastDigit * base;

		/* Multiplies the last digit with appropriate base value
		   and adds it to decimalValue.*/
		base = base * baseNum;
	}

	return decimalValue;
}

/*
 * This function converts hex numbers (represented by char arrays) to a decimal
 * (base 10) value for use in processing. This would have been merged into the
 * baseToDecimal function but I believe it had enough nuances to justify having
 * it be its own function.
 */
short int hexToDecimal (char* hexValue)
{
	int base = 1;
	int decimalValue = 0;
	int counter = 0;
	int i = 0;

	/* Counts the length of the array. */
	while (hexValue[counter])
	{
		counter++;
	}

	for (i = counter-1; i >= 0; i--)
	{
		/* If the character is 0-9, it can be converted to integer
		by substracting 48 from its ascii value (look up ascii table). */
		if (hexValue[i] >= '0' && hexValue[i] <= '9')
		{
			decimalValue += (hexValue[i] - 48) * base;

			/* The base is incremented in power here. */
			base = base * 16;
		}

		/* If the character is A-F, it can be converted to integer 10-15
		by substracting 55 from its ascii value (look up ascii table). */
		else if (hexValue[i] >= 'A' && hexValue[i] <= 'F')
		{
			decimalValue += (hexValue[i] - 55) * base;

			/* The base is incremented in power here. */
			base = base * 16;
		}
	}

	return decimalValue;
}

/*
 * This function converts a decimal (base 10) number to a specified base.
 * If the base is hex (base 16), then it performs appropriate hex specific
 * arithmetic and prints the char array instead of the default int array.
 */
void decimalToBase (int n, int base)
{
	int numberArr[100];

	/* Char array used for hex base only. */
	char hexDecimalNumber[100];

	/* Counters and temporary variables.*/
	int i = 0;
	int j = 0;
	int temp = 0;

	/* Loops through the number */
	while (n != 0)
	{
		/* If the specified base is hex, perform hex specific operations. */
		if ((base == 16))
		{
			temp = 0;
			temp = n % 16;

			if (temp < 10)
			{
				hexDecimalNumber[i] = temp + 48;
				i++;
			}
			else
			{
				hexDecimalNumber[i] = temp + 55;
				i++;
			}

			n = n/16;
		}

		/* Otherwise proceed as normal. Performs conversion arithmetic. */
		else
		{
			numberArr[i] = n % base;
			n = n / base;
			i++;
		}
	}

	/* Prints out appropriate message based on specified base. */
	switch(base)
	{
		case 2:
			printf("Converted to binary: ");
			break;
		case 8:
			printf("Converted to octal: O");
			break;
		case 10:
			printf("Converted to decimal: ");
			break;
		case 16:
			printf("Converted to hexadecimal: 0x");
			break;
		default:
			printf("Converted to base %d: ", base);
			break;
	}

	/* Checks if either array has populated values. In the case
		where the result is 0, the arrays are empty so it prints 0.*/
	if(hexDecimalNumber[0] || numberArr[0])
	{
		for (j = i - 1; j >= 0; j--)
		{
			/* If base is hex, prints out the char array. */
			if ((base == 16))
			{
				printf("%c", hexDecimalNumber[j]);
			}
			/* Otherwise, prints out the int array. */
			else
			{
				printf("%d", numberArr[j]);
			}
		}
		printf("\n");
	}
	else
	{
		printf("0\n");
	}
	
}

/*
 * Adds, substracts, divides, or multiplies two whole numbers.
 */
short int arithmetic (short int left, char operator, short int right)
{
	int opValue = operator;

	/* The switch statement uses the operator value because there
		were issues with matching the exact with certain operators like
		the multiplication star '*'. */
	switch(opValue)  
    {  
    	/* 43 is value of operator '+' */
        case 43:
          	return (left + right);

        /* 45 is value of operator '-' */  	 
        case 45:  
           	return (left - right);

        /* 100 is value of operator '*' */   	
        case 100:  
           	return (left * right);

        /* 47 is value of operator '/'*/
        case 47: 
           	return (left / right);

        /* 124 is value of operator '|'*/
        case 124:
           	return (left | right);

        /* 38 is value of operator '&'*/
        case 38:  
           	return (left & right);

        /* 94 is value of operator '^'*/
        case 94:  
           	return (left ^ right);

        /* 126 is value of operator '~'*/
        case 126:  
           	return (~left);

        /* 60 is value of operator '<<'*/
        case 60:
        	return (left << right);

        /* 62 is value of operator '>>'*/
        case 62:
        	return (left >> right);

        default:
        	printError(2);
    }  
	return 0;
}

/*
 * This function takes in a char representation of a number and the base
 * that it is in and then converts that into a decimal representation for
 * processing.
 */
short int convertIn (char *number, char baseIn)
{
	int num = atoi(number);
	switch(baseIn)
	{
		case 'd':
			return baseToDecimal(num, 10);
		case 'b':
			return baseToDecimal(num, 2);
		case 'o':
			return baseToDecimal(num, 8);
		case 'x':
			/* Since hex contains non-numeric values,
				the char array is sent instead of the int.*/
			return hexToDecimal(number);
	}
	return 0;
}

/*
* This function takes in the decimal representation of the number and
* the base to convert it to and prints the answer in the correct base.
*/
void convertOut (char **equation, short int number, char baseOut)
{
	switch(baseOut)
	{
		case 'd':
			decimalToBase(number, 10);
			break;
		case 'x':
			decimalToBase(number, 16);
			break;
		case 'o':
			decimalToBase(number, 8);
			break;
		case 'b':
			decimalToBase(number, 2);
			break;
	}
}
