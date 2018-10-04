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
	uint32_t parser = 0,num_blocks = 0,address = 0;
	unsigned char choice = 0;
	clock_t BeginCapture,EndCapture;

	if(memory == NULL)
	{
		printf("\nFirst allocate memory...!\n");
	}
	else
	{
		printf("\n\nInvert Block :");
		printf("\n**************");
		
		do
		{
			printf("\nProvide address index to invert memory bits (starts from '0') : ");
			scanf("%u",&address); /* Accepts the offset value from the starting memory address to invert data bits */

			if(!IsWithinBounds(address)) /* Calls function and checks if the address offset inputted by user is within bounds */
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address) && choice); /* Keep looping if address is outside bounds and user wishes to input again */

		do
		{		
			printf("\nHow many words would you like to invert? ");
			scanf("%u",&num_blocks); /* Accepts the number of 32 bit words from which to invert data bits */

			if(!IsWithinBounds(address + num_blocks - 1)) /* Calls function and checks if number of words goes outside the allocated address range */
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address + num_blocks - 1) && choice); /* Keep looping if number of words crosses bounds and user wishes to input again */
		
		BeginCapture = clock(); /* Start clock timer */
		for(parser = address ; parser < address + num_blocks ; parser++)
		{
			*(memory + parser) ^= 4294967295; /* XOR operation with 'FFFFFFFF' to invert data bits */
		}
		EndCapture = clock(); /* End clock timer */
		
		printf("\nMemory blocks were successfully inverted in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC); 
		/**
		* In the above calculation, the difference provides us with the number of clock ticks elapsed. To get time taken in
		* seconds, we divide it by the number of clock ticks per second which depends on the system.
		*/
		
	}	
}

