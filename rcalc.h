/*	Name: Richard Tran
 * 	Date: June 23, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file is the header file for rcalc.c */

void *getMem (size_t size);

void freeMem (void *ptr);

char **subArray (char **equation, unsigned int start, unsigned int stop);

int splitRecurse(char*** expression, int *num_tokens);

char *convertToBaseOut (short num, int base);

void resultOut (char **equation, char *result, char baseOut);