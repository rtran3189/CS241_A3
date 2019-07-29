#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "printauthor.h"

void printName(int assignmentNumber)
{
	printf("\n\n");
	printf("/**********************************************/\n");
	printf("/*Name: Richard Tran                          */\n");
	printf("/*Course: CS241L Summer 2019                  */\n");
	printf("/*Date: June 04, 2019                         */\n");
	printf("/*Assignment: %d                               */\n", assignmentNumber);
	printf("/**********************************************/\n");
}

void checkForFlag(int argc, char ** argv, int assignmentNum)
{
  	int opt;
      
    /* put ':' in the starting of the 
     string so that program can  
    distinguish between '?' and ':'*/  
    while((opt = getopt(argc, argv, ":if:alrx")) != -1)  
    {  
        switch(opt)  
        {  
            case 'a':
            	printName(assignmentNum);  
            	break;  
            case 'l':  
            case 'r':  
                printf("option: %c\n", opt);
                break;  
            case 'f':  
                printf("filename: %s\n", optarg);  
                break;  
            case ':':  
                printf("option needs a value\n");  
                break;  
            case '?':  
                printf("unknown option: %c\n", optopt); 
                break;  
        }  
    }

    for (; optind < argc; optind++)
    {
    	printf("Extra arguments: %s\n", argv[optind]);
    }  
}