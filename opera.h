#ifndef OPERA_H
#define OPERA_H

short int baseToDecimal(int n, int baseNum);

short int hexToDecimal(char* hexValue);

void decimalToBase(int n);

short int arithmetic (short int left, char operator, short int right);

short int bitwise (short int left, char operator, short int right);

short int convertIn (char *number, char baseIn);

void convertOut (char **equation, short int number, char baseOut);


#endif