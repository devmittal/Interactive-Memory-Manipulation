/*****************************************************************************
​ ​* ​ ​ @file​ ​ main.c
​ * ​ ​ @brief​ ​ The main function of this program which contains the welcome 
​ *	     greeting and the function calls for each feature according to
​ * ​ ​ 	     user input.
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdio.h>
#include<string.h>
#include"help.h"
#include"allocate.h"
#include"display.h"
#include"free.h"
#include"invblk.h"
#include"verpatt.h"
#include"write.h"
#include"wrpatt.h"

void quit(void);

int main()
{
	char response[20] = {};
	/* To compare and match with the user inputted command */
	char* commands[10] = {"help","alloc","free","disp","write","inv","wrpat","verpat","exit"};
	/* Innitialize function pointer to execute functions as required in command line */
	void (*func[])(void) = {help,allocate_mem,free_mem,display_mem,write_mem,invert_block,write_pattern,verify_pattern,quit};	
	unsigned char i = 0;
	
	printf("\n\nWelcome to the Interactive Memory Manipulation");
	printf("\n**********************************************\n");

	while(1)
	{
		printf("\nWrite 'help' for Menu\n>>");
		scanf("%s",response);
		
		for(i = 0 ; i < 9 ; i++)
		{
			if(strcmp(response,commands[i]) == 0) /* Compare with user input and execute requested function */
			{
				func[i](); /* Invoke the relevant function from the function pointer */
				break;
			}
		}

		if(i == 9)	/* Ignore any irrelevant entry */
		{
			printf("\nInvalid Command..!\n");
		}
	}
	
	return 0;
}

void quit(void) /* To exit the program */
{
	exit(0);
}
