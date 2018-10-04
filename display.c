/*****************************************************************************
​ ​* ​ ​ @file​ ​  display.c
​ * ​ ​ @brief​ ​ This file displays a table with the range of addresses chosen by 
 *	     the user and the data present in those addresses. 
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdio.h>
#include"allocate.h"

void display_mem(void)
{
	uint32_t parser = 0,num_blocks = 0,address = 0;
	unsigned char choice = 0;

	if(memory == NULL)
	{		
		printf("\nAllocate memory first...!\n");
	}
	else
	{
		printf("\n\nDisplay Memory :");
		printf("\n ****************");
		
		do
		{
			printf("\nEnter address index to see contiguous data : ");
			scanf("%u",&address); /* Accepts the offset value from the starting memory address to display data present in those locations */
			
			if(!IsWithinBounds(address)) /* Calls function and checks if the address inputted by user is within bounds */
			{
				printf("\nUnacceptable input, index is out of bounds!\n"); 
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address) && choice); /* Keep looping if address is outside bounds and user wishes to input again */
		
		do
		{		
			printf("\nHow many words would you like to see? ");
			scanf("%u",&num_blocks); /* Accepts the number of 32 bit words from which to display data */

			if(!IsWithinBounds(address + num_blocks - 1)) /* Calls function and checks if number of words goes outside the allocated address range */
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address + num_blocks - 1) && choice); /* Keep looping if number of words crosses bounds and user wishes to input again */
		

		printf("\nIndex\tAddress \tData"); /* Displays table of Index, Address and data present at the address */
		printf("\n_____\t_______ \t____\n");
		
		for(parser = address ; parser < address + num_blocks ; parser++)
		{
			printf("%lu",(unsigned long)parser);
			printf("\t0X%08lx",(unsigned long)(memory + parser));
			printf("\t0X%08lx\n",(unsigned long)*(memory+parser));
		}
	}
}
