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
#include"help.h"
#include"allocate.h"
#include"display.h"
#include"free.h"
#include"invblk.h"
#include"verpatt.h"
#include"write.h"
#include"wrpatt.h"

int main()
{
	int response;
	
	printf("\n\nWelcome to the Interactive Memory Manipulation");
	printf("\n**********************************************\n");

	do
	{		
		printf("\nEnter 1 for help");
		printf("\nResponse : ");
		scanf("%d",&response); /* User selects which feature is to be implemented here */

		switch(response)
		{
			case 1:	help();
				break;

			case 2:	allocate_mem();
				break;

			case 3:	free_mem();
				break;

			case 4:	display_mem();
				break;

			case 5:	write_mem();
				break;

			case 6:	invert_block();
				break;

			case 7:	write_pattern();
				break;

			case 8:	verify_pattern();
				break;

			case 9:	printf("\nEnd of Program\n\n");
				break;

			default:printf("\nInvalid Response, Try again\n");
				break;
		}

	}
	while(response != 9);

	

	return 0;
}
