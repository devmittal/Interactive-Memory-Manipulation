/*****************************************************************************
​ ​* ​ ​ @file​ ​  help.c
​ * ​ ​ @brief​ ​ This is the help menu which displays to the user what features
 *	     are available and how to select them.
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdio.h>
#include"help.h"

void help()
{
	printf("\nHelp Menu");
	printf("\n*********\n");
	printf("\nSelect from the following in the main menu:\n");
	printf("\nAllocate Memory (2)\nFree Memory (3)\nDisplay Memory (4)\n");
	printf("Write Memory (5)\nInvert Block (6)\nWrite Pattern (7)\n");
	printf("Verify Pattern (8)\nExit (9)\n");
}
