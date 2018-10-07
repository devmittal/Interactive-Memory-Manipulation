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
	printf("\nAllocate Memory - 'alloc'\nFree Memory - 'free'\nDisplay Memory - 'disp'\n");
	printf("Write Memory - 'write'\nInvert Block - 'inv'\nWrite Pattern - 'wrpat'\n");
	printf("Verify Pattern - 'verpat'\nExit - 'exit'\n");
}
