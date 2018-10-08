/*****************************************************************************
​ ​* ​ ​ @file​ ​  write.c
​ * ​ ​ @brief​ ​ This file writes hexadecimal data specified by the user to the 
 * 	     address selected by the user. 
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdio.h>
#include"allocate.h"
#include"write.h"

void write_mem(void)
{
	unsigned char mode = 0;

	if(memory == NULL)
	{
		printf("\nFirst allocate memory...!\n");
	}
	else
	{
		printf("\n\nWrite Memory :");
		printf("\n**************");
		//Select addressing mode
		printf("\n1 - Offset Addressing\n2 - Direct Addressing");
		printf("\nMode : ");
		scanf("%hhu",&mode);
		
		switch(mode)
		{

			case 1: write_offset();
				break;

			case 2: write_direct();
				break;

			default:printf("\nInvalid Selection!\n");
		}
	}
}

void write_offset(void)
{
	uint32_t parser = 0,num_blocks = 0, data = 0;
	uint64_t address = 0;
	unsigned char choice = 0;

		do
		{
			printf("\nProvide address index to modify buffer (starts from '0') : ");
			scanf("%lu",&address); /* Accepts offset value to the starting allocated address where data will be written */ 

			if(!IsWithinBounds(address)) /* Calls function and checks if the address offset inputted by user is within bounds */
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address) && choice); /* Keep looping if address is outside bounds and user wishes to input again */

		printf("Enter data (in hexadecimal) to modify index-%lu : ",address);
		scanf("%X",&data); /* Accepts data in hexadecimal from user */
		*(memory + address) = data; /* Writes the data to the memory offset as specified by user */
		printf("\nData successfully written to buffer\n");
}

void write_direct(void)
{
	uint32_t parser = 0,num_blocks = 0,direct_offset = 0, data = 0;
	uint64_t address = 0;
	unsigned char choice = 0;

	do
	{	//Get memory address to write at
		printf("\nProvide address to modify buffer : ");
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

	printf("\nEnter data (in hexadecimal) to modify address-%lu : ",address);
	scanf("%X",&data); /* Accepts data in hexadecimal from user */
	*(memory + direct_offset) = data; /* Writes data to the address specified by user */
	printf("\nData successfully written to buffer\n");
}
