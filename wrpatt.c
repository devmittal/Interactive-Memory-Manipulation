/*****************************************************************************
​ ​* ​ ​ @file​ ​  wrpatt.c
​ * ​ ​ @brief​ ​ This file writes a pseudo random pattern to the addresses 
 *	     specified by the user. Time taken to carry out this pattern 
 *	     generation is also calculated. 
 *   @Tools_Used GCC
​ * ​ ​ @author​ Souvik De, Devansh Mittal
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdio.h>
#include<time.h>
#include"allocate.h"
#include"wrpatt.h"

void write_pattern(void)
{

	unsigned char mode = 0;	

	if(memory == NULL)
	{
		printf("\nFirst allocate memory...!\n");
	}
	else
	{
		printf("\n\nWrite Pattern :");
		printf("\n**************");
		
		printf("\n1 - Offset Addressing\n2 - Direct Addressing");
		printf("\nMode : ");
		scanf("%hhu",&mode);
		
		switch(mode)
		{

			case 1: wrpatt_offset();
				break;

			case 2: wrpatt_direct();
				break;

			default:printf("\nInvalid Selection!\n");
		}
	}
}

void wrpatt_offset(void)
{
	uint32_t parser = 0,num_blocks = 0, seed = 0;
	uint64_t address = 0;
	unsigned char choice = 0;
	clock_t BeginCapture,EndCapture;

		do
		{
			printf("\nProvide address index to write pattern (starts from '0') : ");
			scanf("%lu",&address); /* Accepts the offset value from the starting memory address to write random pattern to */

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
			printf("\nHow many words would you like to write the pattern to? ");
			scanf("%u",&num_blocks); /* Accepts the number of 32 bit words to which random pattern is to be written to */

			if(!IsWithinBounds(address + num_blocks - 1)) /* Calls function and checks if number of words goes outside the allocated address range */
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address + num_blocks - 1) && choice); /* Keep looping if number of words crosses bounds and user wishes to input again */
		
		printf("\nEnter the seed value for pattern generation : ");
		scanf("%u",&seed); /* Accepts seed value from user for pseudo random pattern generation */

		BeginCapture = clock(); /* Start clock timer */
		for(parser = address ; parser < address + num_blocks ; parser++)
		{
						 
			*(memory + parser) = generate_pattern(seed); /* Call function to generate random pattern */
			seed = *(memory + parser); /* The seed value for random pattern for the next word is the random pattern of the previous word */
		}
		EndCapture = clock(); /* End clock timer */
		
		printf("\nPattern was successfully generated in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC);
		/**
		* In the above calculation, the difference provides us with the number of clock ticks elapsed. To get time taken in
		* seconds, we divide it by the number of clock ticks per second which depends on the system.
		*/	
}

void wrpatt_direct(void)
{
	uint32_t parser = 0,num_blocks = 0,direct_offset = 0, seed = 0;
	uint64_t address = 0;
	unsigned char choice = 0;
	clock_t BeginCapture,EndCapture;

	do
	{
		printf("\nEnter address to write pattern : ");
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
		printf("\nHow many words would you like to write the pattern to? ");
		scanf("%u",&num_blocks);

		if(!IsWithinBounds(direct_offset + num_blocks -1))
		{
			printf("\nUnacceptable input, index is out of bounds!\n");
			printf("1-to enter again and 0-ignore : ");
			scanf("%hhu",&choice);
		}
	}
	while(!IsWithinBounds((direct_offset + num_blocks -1) && choice));

	printf("\nEnter the seed value for pattern generation : ");
		scanf("%u",&seed); /* Accepts seed value from user for pseudo random pattern generation */

		BeginCapture = clock(); /* Start clock timer */
		for(parser = direct_offset ; parser < direct_offset + num_blocks ; parser++)
		{
						 
			*(memory + parser) = generate_pattern(seed); /* Call function to generate random pattern */
			seed = *(memory + parser); /* The seed value for random pattern for the next word is the random pattern of the previous word */
		}
		EndCapture = clock(); /* End clock timer */
		
		printf("\nPattern was successfully generated in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC);
		/**
		* In the above calculation, the difference provides us with the number of clock ticks elapsed. To get time taken in
		* seconds, we divide it by the number of clock ticks per second which depends on the system.
		*/	
}

uint32_t generate_pattern(uint32_t seed)
{
	/**
	*Pseudo Random Pattern Generation Algorithm:
	*Constant value is used as base value.
	*Base value is left shifted by 2 bits. 
	*Seed value is modulated by the maximum number possible to ensure it does not cross 32 bits.
	*This value is added to the left shifted base value.
 	*This random pattern generated is used as the seed value for the random pattern of the next word.
	*/

	const uint32_t base_rand = BASE;
	return (seed%0xFFFFFFFF) + base_rand << 2; 
}
