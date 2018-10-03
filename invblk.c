#include<stdio.h>
#include<time.h>
#include"allocate.h"

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
}

