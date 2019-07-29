/*	Name: Richard Tran
 * 	Date: January 23, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file includes helper functions used for the assignment and
 *	for printing helpful feedback for the user.
 */

#include <stdio.h>
#include <limits.h>
#include "opera.h"

/*
 * On program input flag -a, will print the caption described in
 * assignment 1.
 */
void printName(int assignmentNum)
{
	printf("\n\n");
	printf("/**********************************************/\n");
	printf("/*Name: Richard Tran                          */\n");
	printf("/*Course: CS241L Summer 2019                  */\n");
	printf("/*Date: June 23, 2019                         */\n");
	printf("/*Assignment: %d                               */\n", assignmentNum);
	printf("/**********************************************/\n");
}

/*
 * On program input flag -h, will print information on how to
 * run the program. This information may be the same information
 * you included in your readme file.
 */
void printHelp()
{
	printf("\n-----------------HELP-----------------\n");
	printf("To perform arithmetic or bitwise operations (except NOT):\n");
	printf("\t Six (6) arguments need to be supplied and in this format:\n");
	printf("\t -<input base> num1 -operation -<input base> num2 -<output base>\n");
	printf("\t Example: -d 14 -+ -b 11 -x\n");
	printf("\t\twill add 14 (base 10) and 11 (base 2) and print the result in hex.\n");
	printf("\n\t NOTE: When performing any logical operators (|, &, ^, <, >)\n");
	printf("\t You MUST escape the operator with '\\' before the operator itself.\n");
	printf("\t Example: -d 14 -\\& -b 11 -x \n");
	printf("\nTo perform Bitwise Not:\n");
	printf("\t Four (4) arguments need to be supplied and in this format:\n");
	printf("\t -<input base> num -n -<output base>\n");
	printf("\t Example: -o 11 -n -d\n");
	printf("\t\t will perform bitwise not on 11 (base 8) and outputs the answer in base 10.\n");
	printf("\nTo perform Change Base:\n");
	printf("\t Four (4) arguments need to be supplied and in this format:\n");
	printf("\t -<input base> operand -c -<output base>\n");
	printf("\t Example: -x AB -c -o\n");
	printf("\t\t will convert AB (base 16) and outputs the answer in base 8.\n");
	printf("\nMultiple output formats can be chained at the end to output into different bases.\n");
	printf("\tExample: -b 1111 -+ -x F -dbxo\n");
	printf("\t\t will output the solution in all four bases.\n");
	printf("\nValid Numerical Base Designations:\n");
	printf("\t -b : binary      (base 2)\n");
	printf("\t -d : decimal     (base 10)\n");
	printf("\t -o : octal       (base 8)\n");
	printf("\t -x : hexidecimal (base 16)\n");
	printf("--------------------------------------\n\n");

}	

/*
 * Print the appropriate error code *you may have as many error codes
 * as deemed necessary to give helpful information to the user and also
 * refer the user to using the -h flag. An error will cause the program
 * to exit. 
 */
void printError(int errorCode)
{
	switch (errorCode)
	{
		case 0:
			fprintf(stderr, "%s", "ERROR: Invalid number of arguments. Please run again and use -h for help.\n");
			break;
		case 1:
			fprintf(stderr, "%s %d\n", "ERROR: Input value exceeded short int max value of", SHRT_MAX);
			break;
		case 2:
			fprintf(stderr, "%s\n", "ERROR: Invalid input order. Please run again and use -h for help.");
			break;
	}
}


/*
 * This function loops through the arguments (argv) and checks for a
 * dash (-) which signifies a flag. If a flag is detected, it will keep
 * looking for the 'a' character after that flag. If found, will print name.
 * If the 'h' character is found, it will print the help message.
 */
void checkForPrintFlag(int argc, char ** argv, int assignmentNum)
{
	int i = 0;
	int j = 0;

	while (i < argc)
	{
		switch (argv[i][0])
		{
			case '-':
				j = 0;
				while(argv[i][j])
				{
					switch (argv[i][j])
					{
						case 'a':
							printName(assignmentNum);
							break;
						case 'h':
							printHelp();
							break;
					}
					j++;
				}
		}
		i++;
	}
}
