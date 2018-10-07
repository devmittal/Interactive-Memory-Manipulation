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
#include"display.h"

void display_mem(void)
{
	unsigned char mode = 0;

	if(memory == NULL)
	{		
		printf("\nAllocate memory first...!\n");
	}
	else
	{
		printf("\n\nDisplay Memory :");
		printf("\n ****************");

		printf("\n1 - Offset Addressing\n2 - Direct Addressing");
		printf("\nMode : ");
		scanf("%hhu",&mode);
		
		switch(mode)
		{

			case 1: display_offset();
				break;

			case 2: display_direct();
				break;

			default:printf("\nInvalid Selection!\n");
		}
	}
}

void display_offset(void)
{
	uint32_t parser = 0,num_blocks = 0;
	uint64_t address = 0;
	unsigned char choice = 0;

	do
	{
		printf("\nEnter address index to see contiguous data : ");
		scanf("%lu",&address);
		
		if(!IsWithinBounds(address))
		{
			printf("\nUnacceptable input, index is out of bounds!\n");
			printf("1-to enter again and 0-ignore : ");
			scanf("%hhu",&choice);
		}
	}
	while(!IsWithinBounds(address) && choice);
	
	do
	{		
		printf("\nHow many words would you like to see? ");
		scanf("%u",&num_blocks);

		if(!IsWithinBounds(address + num_blocks - 1))
		{
			printf("\nUnacceptable input, index is out of bounds!\n");
			printf("1-to enter again and 0-ignore : ");
			scanf("%hhu",&choice);
		}
	}
	while(!IsWithinBounds(address + num_blocks - 1) && choice);
	
	printf("\nIndex\tAddress \tData");
	printf("\n_____\t_______ \t____\n");

	for(parser = address ; parser < address + num_blocks ; parser++)
	{
		printf("%lu",(unsigned long)parser);
		printf("\t%lu",(unsigned long)(memory + parser));
		printf("\t0X%08lx\n",(unsigned long)*(memory+parser));
	}	
}

void display_direct(void)
{
	uint32_t parser = 0,num_blocks = 0,direct_offset = 0;
	uint64_t address = 0;
	unsigned char choice = 0;

	do
	{
		printf("\nEnter address to see contiguous data : ");
		scanf("%lu",&address);

		direct_offset = (address - (unsigned long)memory)/sizeof(uint32_t);
		
		if(!IsWithinBounds(direct_offset))
		{
			printf("\nUnacceptable input, index is out of bounds!\n");
			printf("1-to enter again and 0-ignore : ");
			scanf("%hhu",&choice);
		}
	}
	while(!IsWithinBounds(direct_offset) && choice);
	
	do
	{		
		printf("\nHow many words would you like to see? ");
		scanf("%u",&num_blocks);

		if(!IsWithinBounds(direct_offset + num_blocks -1))
		{
			printf("\nUnacceptable input, index is out of bounds!\n");
			printf("1-to enter again and 0-ignore : ");
			scanf("%hhu",&choice);
		}
	}
	while(!IsWithinBounds((direct_offset + num_blocks -1) && choice));
	
	printf("\nAddress \tData");
	printf("\n_______ \t____\n");
		
	for(parser = direct_offset ; parser < direct_offset + num_blocks ; parser++)
	{
		printf("%lu",(unsigned long)(memory + parser));
		printf("\t0X%08lx\n",(unsigned long)*(memory+parser));
	}	
}
