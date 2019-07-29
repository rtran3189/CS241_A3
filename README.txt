Name: Richard Tran
Assignment: 3
Course: CS241L Summer 2019
Date: June 23 2019

Directory: Top
Compile Command: gcc -Wall -pedantic -ansi main.c help.c opera.c rcalc.c
Run Command: ./a.out <SEE BELOW FOR INSTRUCTIONS>
Running Test: N/A
Bugs:
	- Does not do well with negative numbers since I was not able to come up with a solution to handle that in time. This includes negative numbers in the input as well as some cases for the output.
	- Due to the way I handled parsing argument options, the input REQUIRES that the whole equation is surrounded by parenthesis.
	- There is no conversion to different bases. It only inputs and outputs in decimal.
	- "Lengthy" equations do not work due to implementation.  This is solved by implementing subArray function in the splitRecurse and when the equations returns 'lhs' and 'rhs', calling 'splitRecurse(lhs)' and 'splitRecurse(rhs)' is likely to fix this. But did not have time to implement.

 
-----------INSTRUCTIONS-----------
run ./a.out followed by the equations. Escape the parenthesis by adding '\' followed by the parenthesis or operator (if it is * or /).



SAMPLE INPUT AND OUTPUTS:

./a.out \( \( 2 \* 3 \) - 2 \)

Printing equation: ((2*3)-2) =  4


./a.out \( \( 2 \* 3 \) + 2 \)

Printing equation: ((2*3)-2) =  8