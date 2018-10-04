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

void write_mem(void)
{
	uint32_t address = 0,data = 0;
	unsigned char choice = 0;
	
	if(memory == NULL)
	{
		printf("\nFirst allocate memory...!\n");
	}
	else
	{
		printf("\n\nWrite Memory :");
		printf("\n**************");

		do
		{
			printf("\nProvide address index to modify buffer (starts from '0') : ");
			scanf("%u",&address); /* Accepts offset value to the starting allocated address where data will be written */ 

			if(!IsWithinBounds(address)) /* Calls function and checks if the address offset inputted by user is within bounds */
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address) && choice); /* Keep looping if address is outside bounds and user wishes to input again */

		printf("Enter data (in hexadecimal) to modify index-%u : ",address);
		scanf("%X",&data); /* Accepts data in hexadecimal from user */
		*(memory + address) = data; /* Writes the data to offset value from the starting allocated memory address */
		printf("\nData successfully written to buffer\n");
	}
}
