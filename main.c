/*****************************************************************************
​ ​* ​ ​ @file​ ​ main.c
​ * ​ ​ @brief​ ​ The main function of this program which contains the welcome 
​ *	     greeting and the function calls for each feature according to
​ * ​ ​ 	     user input.
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Souvik De, Devansh Mittal
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
	char* commands[10] = {"help","alloc","free","disp","write","inv","wrpat","verpat","exit"};
	void (*func[])(void) = {help,allocate_mem,free_mem,display_mem,write_mem,invert_block,write_pattern,verify_pattern,quit};	
	unsigned char i = 0;
	
	printf("\n\nWelcome to the Interactive Memory Manipulation");
	printf("\n**********************************************\n");

	do
	{
		printf("\nWrite 'help' for Menu\n>>");
		scanf("%s",response);
		
		for(i = 0 ; i < 9 ; i++)
		{
			if(strcmp(response,commands[i]) == 0)
			{
				func[i]();
				break;
			}
		}

		if(i == 9)
		{
			printf("\nInvalid Command..!\n");
		}
	}
	while(strcmp(response,"exit") != 0);
	
	return 0;
}

void quit(void)
{
	exit(0);
}
