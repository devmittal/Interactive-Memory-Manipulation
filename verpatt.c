/*****************************************************************************
​ ​* ​ ​ @file​ ​  verpatt.c
​ * ​ ​ @brief​ ​ This file verifies the pseudo random pattern at the addresses 
 *	     specified by the user. If it is not verified, it displays a 
 *	     table of address, present value and expected value. Otherwise,
 *	     the time taken to carry out this pattern verification is 
 *	     calculated. 
 *   @Tools_Used GCC
​ * ​ ​ @author​ Souvik De, Devansh Mittal
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdio.h>
#include<time.h>
#include"allocate.h"
#include"wrpatt.h"
#include"verpatt.h"

void verify_pattern(void)
{
	unsigned char mode = 0;	

	if(memory == NULL)
	{
		printf("\nFirst allocate memory...!\n");
	}
	else
	{ //Select addressing mode
		printf("\n\nVerify Pattern :");
		printf("\n**************");
		
		printf("\n1 - Offset Addressing\n2 - Direct Addressing");
		printf("\nMode : ");
		scanf("%hhu",&mode);
		
		switch(mode)
		{

			case 1: verpatt_offset();
				break;

			case 2: verpatt_direct();
				break;

			default:printf("\nInvalid Selection!\n");
		}
	}
}

void verpatt_offset(void)
{
	uint32_t parser = 0,num_blocks = 0, seed = 0, expected_pattern = 0;
	uint64_t address = 0;
	unsigned char choice = 0, IsPatternValid = 1, parsed_once = 0;
	clock_t BeginCapture,EndCapture;

		do
		{
			printf("\nProvide address index to verify pattern (starts from '0') : ");
			scanf("%lu",&address); /* Accepts the offset value from the starting memory address to verify random pattern */

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
			printf("\nHow many words would you like to verify the pattern with? ");
			scanf("%u",&num_blocks); /* Accepts the number of 32 bit words from which random pattern is to be verified */

			if(!IsWithinBounds(address + num_blocks - 1)) /* Calls function and checks if number of words goes outside the allocated address range */
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address + num_blocks - 1) && choice); /* Keep looping if number of words crosses bounds and user wishes to input again */
		
		printf("\nEnter the seed value to verify pattern : ");
		scanf("%u",&seed); /* Accepts seed value from user to verify pseudo random pattern */

		BeginCapture = clock(); /* Start clock timer */
		for(parser = address ; parser < address + num_blocks ; parser++)
		{
			expected_pattern = generate_pattern(seed); /* Calls function to generate random pattern based on current seed value inputted by user */			
			if(*(memory + parser) != expected_pattern) /* Checks if this pattern matches the pattern present in the corresponding address */
			{			 
				IsPatternValid = 0; /* Flag if pattern does not match */
				if(!parsed_once) /* Checks if it has it has looped once in order to avoid printing table heading multiple times */
				{
					parsed_once = 1;
					printf("\nPattern not verified!");
					printf("\n\nAddress \tPresent Value\tExpected Value");
					printf("\n_______ \t_____________\t______________");
				}
				printf("\n%lu",(unsigned long)(memory + parser)); /* Prints the address */
				printf("\t0X%08lx",(unsigned long)*(memory + parser)); /* Prints the present value at that address */
				printf("\t0X%08lx",(unsigned long)expected_pattern); /* Prints the expected value based on user inputted seed value */
			}
			seed = expected_pattern; /* Assigns the previous random pattern as the seed value for random pattern verification of the next word */
		}
		EndCapture = clock(); /* End clock timer */

		if(IsPatternValid) /* Checks only if verification was successful and then only prints the time taken for verification operation */
		{
			printf("\nPattern was successfully verified in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC);
			/**
			* In the above calculation, the difference provides us with the number of clock ticks elapsed. To get time taken in
			* seconds, we divide it by the number of clock ticks per second which depends on the system.
			*/
		}
}

void verpatt_direct(void)
{
	uint32_t parser = 0,num_blocks = 0,direct_offset = 0, seed = 0, expected_pattern = 0;
	uint64_t address = 0;
	unsigned char choice = 0, IsPatternValid = 1, parsed_once = 0;
	clock_t BeginCapture,EndCapture;

	do
	{/* Accepts the starting memory address to verify random pattern */
		printf("\nEnter address to verify pattern : ");
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
		printf("\nHow many words would you like to verify the pattern with? ");
		scanf("%u",&num_blocks);

		if(!IsWithinBounds(direct_offset + num_blocks -1))
		{
			printf("\nUnacceptable input, index is out of bounds!\n");
			printf("1-to enter again and 0-ignore : ");
			scanf("%hhu",&choice);
		}
	}
	while(!IsWithinBounds((direct_offset + num_blocks -1) && choice));

	printf("\nEnter the seed value to verify pattern : ");
		scanf("%u",&seed); /* Accepts seed value from user to verify pseudo random pattern */

		BeginCapture = clock(); /* Start clock timer */
		for(parser = direct_offset ; parser < direct_offset + num_blocks ; parser++)
		{
			expected_pattern = generate_pattern(seed); /* Calls function to generate random pattern based on current seed value inputted by user */			
			if(*(memory + parser) != expected_pattern) /* Checks if this pattern matches the pattern present in the corresponding address */
			{			 
				IsPatternValid = 0; /* Flag if pattern does not match */
				if(!parsed_once) /* Checks if it has it has looped once in order to avoid printing table heading multiple times */
				{
					parsed_once = 1;
					printf("\nPattern not verified!");
					printf("\n\nAddress \tPresent Value\tExpected Value");
					printf("\n_______ \t_____________\t______________");
				}
				printf("\n%lu",(unsigned long)(memory + parser)); /* Prints the address */
				printf("\t0X%08lx",(unsigned long)*(memory + parser)); /* Prints the present value at that address */
				printf("\t0X%08lx",(unsigned long)expected_pattern); /* Prints the expected value based on user inputted seed value */
			}
			seed = expected_pattern; /* Assigns the previous random pattern as the seed value for random pattern verification of the next word */
		}
		EndCapture = clock(); /* End clock timer */

		if(IsPatternValid) /* Checks only if verification was successful and then only prints the time taken for verification operation */
		{
			printf("\nPattern was successfully verified in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC);
			/**
			* In the above calculation, the difference provides us with the number of clock ticks elapsed. To get time taken in
			* seconds, we divide it by the number of clock ticks per second which depends on the system.
			*/
		}
}
