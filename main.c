/*	Name: Richard Tran
 * 	Date: June 23, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file contains the main function for the entire program.
 *	Also contains functions relating to parsing the arguments when
 *	running the program.
 */

#include <stdio.h>
#include <limits.h>
#include "opera.h"
#include "help.h"
#include "rcalc.h"
#include <string.h>

#define ASSIGNMENT_NUMBER 3

int eqLength;

/*
 * This function checks if a specified flag exists in the arguments.
 * Returns 1 (True) if found, otherwise 0 (False).
 */
int checkForSpecificFlag(int argc, char ** argv, char c)
{
	int i = 0;
	int j = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while(argv[i][j])
			{
				if (argv[i][j] == c)
				{
					return 1;
				}
				j++;
			}
		}
		i++;
	}
	return 0;
}

/*
 *	Gets passed argc (# of arguments) and argv (the arguments themselves).
 * 	The number of arguments determines what operation to take (4 is Bitwise Not or
 *	change of base) and 6 is Arithmetic or Bitwise Operations.
 */
void parseArguments(int argc, char ** argv)
{
	int result;
	result = splitRecurse(&argv, &argc);
	printf(" %d\n", result);
}

int pruneFlags(char **strings, int stringLength)
{
	int i = 0;
	int j = 0;
	while (i < stringLength)
	{
		if (strings[i][0] == '-')
		{
			j = 0;
			while(strings[i][j])
			{
				if (strings[i][j] >= 'a' && strings[i][j] <= 'z')
				{
					return i;
				}
				j++;
			}
		}
		i++;
	}
	return stringLength;
}

char **extractEquation(char **argv, int argLength)
{
	int i = 0;
	char **prunedEquation;
	int flagIndex = pruneFlags(argv, argLength);
	eqLength = flagIndex-1;
	prunedEquation = subArray(argv, 1, flagIndex-1);

	/** DEBUG MESSAGES **/
	printf("\nPrinting equation: ");
	while(i < eqLength)
	{
		printf("%s", prunedEquation[i]);
		i++;
	}
	printf(" = ");
	return prunedEquation;
}

/*
 *	Main function that drives the entire program.
 */
int main (int argc, char **argv)
{
	char** eq;

	checkForPrintFlag(argc, argv, ASSIGNMENT_NUMBER);
	/* Remove file name and flags and return back just the equation. */
	eq = extractEquation(argv, argc);
	/* Recurse in parseArguments */
	parseArguments(eqLength, eq);
 
	return 0; 
}
