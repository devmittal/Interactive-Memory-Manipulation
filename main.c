#include<stdio.h>
#include"controller.h"
/*
#include"allocate.c"
#include"free.c"
#include"display.c"
#include"help.c"
#include"invblk.c"
#include"verpatt.c"
#include"write.c"
#include"wrpatt.c"*/

int main()
{
	int response;

	printf("\nMemory Test\n***********\n\nSelect Options Below:\n");
	
	do
	{
		printf("\nHelp (1)\nAllocate Memory (2)\nFree Memory (3)\nDisplay Memory (4)\n");
		printf("Write Memory (5)\nInvert Block (6)\nWrite Pattern (7)\n");
		printf("Verify Pattern (8)\nExit (9)\n\nResponse : ");

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
