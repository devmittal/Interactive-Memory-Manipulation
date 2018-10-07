/*****************************************************************************
​ ​* ​ ​ @file​ ​  invblk.c
​ * ​ ​ @brief​ ​ This file inverts the data bits present at the addresses
 * 	     specified by the user. It also measures the amount of time taken
 *	     to carry out the invert operation.
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdio.h>
#include<time.h>
#include"allocate.h"
#include"invblk.h"

void invert_block(void)
{
	unsigned char mode = 0;

	if(memory == NULL)
	{
		printf("\nFirst allocate memory...!\n");
	}
	else
	{
		printf("\n\nInvert Block :");
		printf("\n**************");

		printf("\n1 - Offset Addressing\n2 - Direct Addressing");
		printf("\nMode : ");
		scanf("%hhu",&mode);
		
		switch(mode)
		{
			case 1: invert_offset();
				break;

			case 2: invert_direct();
				break;

			default:printf("\nInvalid Selection!\n");
		}
	}
}

void invert_offset(void)
{
	uint32_t parser = 0,num_blocks = 0;
	uint64_t address = 0;
	unsigned char choice = 0;
	clock_t BeginCapture,EndCapture;

	do
	{
		printf("\nProvide address index to invert memory bits (starts from '0') : ");
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
		printf("\nHow many words would you like to invert? ");
		scanf("%u",&num_blocks);

		if(!IsWithinBounds(address + num_blocks - 1))
		{
			printf("\nUnacceptable input, index is out of bounds!\n");
			printf("1-to enter again and 0-ignore : ");
			scanf("%hhu",&choice);
		}
	}
	while(!IsWithinBounds(address + num_blocks - 1) && choice);
		
	BeginCapture = clock();
	for(parser = address ; parser < address + num_blocks ; parser++)
	{
		*(memory + parser) ^= 4294967295;
	}
	EndCapture = clock();
		
	printf("\nMemory blocks were successfully inverted in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC);	
}

void invert_direct(void)
{
	uint32_t parser = 0,num_blocks = 0,direct_offset = 0;
	uint64_t address = 0;
	unsigned char choice = 0;
	clock_t BeginCapture,EndCapture;

	do
	{
		printf("\nProvide address to invert memory bits : ");
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
		printf("\nHow many words would you like to invert? ");
		scanf("%u",&num_blocks);

		if(!IsWithinBounds(direct_offset + num_blocks - 1))
		{
			printf("\nUnacceptable input, index is out of bounds!\n");
			printf("1-to enter again and 0-ignore : ");
			scanf("%hhu",&choice);
		}
	}
	while(!IsWithinBounds(direct_offset + num_blocks - 1) && choice);
		
	BeginCapture = clock();
	for(parser = direct_offset ; parser < direct_offset + num_blocks ; parser++)
	{
		*(memory + parser) ^= 4294967295;
	}
	EndCapture = clock();

	printf("\nMemory blocks were successfully inverted in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC);	
}

