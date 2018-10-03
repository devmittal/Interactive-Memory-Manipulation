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
		scanf("%d",&response);

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
