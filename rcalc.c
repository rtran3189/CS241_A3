/*	Name: Richard Tran
 * 	Date: June 23, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file contains functions that relate to recursively
 * 	calculating equations.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * This function uses malloc to allocate the memory size AND verifies
 * it was allocated. Failure to allocate result in an error (if 
 * ptr = NULL it fails to allocate).
 */
void *getMem (size_t size)
{
	void *p = malloc(size);

	if (p)
	{
		return p;
	}
	else
	{
		fprintf(stderr, "ERROR: Can not allocate memory.\n");
		exit(0);
	}
}

/*
 * Frees the pointer and sets it to NULL.
 */
void freeMem (void *ptr)
{
	free(ptr);
	ptr = NULL;
}

/*
 * This function takes a char ** and returns a subset of the char ** based
 * on the start and stop positions.
 * 	i.NOTE: You must use pointer math for this (do not use []).
 		1.Keep in mind, pointers don’t know where they you just change the 
 		  address it is pointing too.
 	ii.You need to allocate memory for the new char **AND char*.
 */
char **subArray (char **equation, unsigned int start, unsigned int stop)
{
	size_t size = (stop - start + 1) * sizeof(void*);
	char **res = getMem(size);

	unsigned int i;
	unsigned int j = 0;
	for (i = start; i <= stop; ++i)
	{
		*(res + j) = getMem(sizeof(*(equation + i)));
		strcpy(*(res+j), *(equation + i));
		j++;
	}

	return res;
}

/*
 *	This function is the recursive function. It will recurse, finding
 * 	parenthesis and process left hand side and right hand side, recursing
 *	through until return.
 */
int splitRecurse(char*** equation, int *equationLength) {

    char *equationPtr = **equation;
    char op;
    int lhs;
    int rhs;

    if (*equationPtr == '(') {
        (*equation)++;  /* Skips the first parenthesis */
        (*equationLength)--;

        lhs = splitRecurse(equation, equationLength);

        op = ***equation;
        (*equation)++;
        (*equationLength)--;

        rhs = splitRecurse(equation, equationLength);

        (*equation)++;  /* Skips closing parenthesis */
        (*equationLength)--;

        switch (op) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
            case '/':
                return lhs / rhs;
            default:
                return 0;
        }

    } else {
        int op;
        if (sscanf(equationPtr, "%2d", &op) != 1) {
            printf("Cannot parse %s.\n", equationPtr);
            exit(1);
        }
        (*equation)++;
        (*equationLength)--;
        return op;
    }
}
/*
 * This function uses tail recursion to convert the number to a string of
 * the appropriate base. The output may be just the value or may contain
 * the base designator as well.
 * 	i.NOTE: You must use pointer math for this (do not use []).
 		1.Keep in mind, pointers don’t know where they you just change the 
 		  address it is pointing too.
 	ii.You need to allocate memory for the new char **AND char*.
 */
char *convertToBaseOut (short num, int base, int acc)
{
	return 0;
}
