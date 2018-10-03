#include<stdio.h>
#include<time.h>
#include"allocate.h"
#include"wrpatt.h"

void verify_pattern(void)
{
	uint32_t parser = 0,num_blocks = 0,address = 0, seed = 0, expected_pattern = 0;
	unsigned char choice = 0, IsPatternValid = 1, parsed_once = 0;
	clock_t BeginCapture,EndCapture;


	if(memory == NULL)
	{
		printf("\nFirst allocate memory...!\n");
	}
	else
	{
		printf("\n\nVerify Pattern :");
		printf("\n**************");
		
		do
		{
			printf("\nProvide address index to verify pattern (starts from '0') : ");
			scanf("%u",&address);

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
			printf("\nHow many words would you like to verify the pattern with? ");
			scanf("%u",&num_blocks);

			if(!IsWithinBounds(address + num_blocks - 1))
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address + num_blocks - 1) && choice);
		
		printf("\nEnter the seed value to verify pattern : ");
		scanf("%u",&seed);

		BeginCapture = clock();
		for(parser = address ; parser < address + num_blocks ; parser++)
		{
			expected_pattern = generate_pattern(seed);			
			if(*(memory + parser) != expected_pattern)
			{			 
				IsPatternValid = 0;
				if(!parsed_once)
				{
					parsed_once = 1;
					printf("\nPattern not verified!");
					printf("\n\nAddress \tPresent Value\tExpected Value");
					printf("\n_______ \t_____________\t______________");
				}
				printf("\n%lu",(unsigned long)(memory + parser));
				printf("\t0X%08lx",(unsigned long)*(memory + parser));
				printf("\t0X%08lx",(unsigned long)expected_pattern);
			}
			seed = expected_pattern;
		}
		EndCapture = clock();

		if(IsPatternValid)
		{
			printf("\nPattern was successfully verified in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC);
		}
	}
}
