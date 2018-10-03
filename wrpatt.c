#include<stdio.h>
#include<time.h>
#include"allocate.h"
#include"wrpatt.h"

void write_pattern(void)
{
	uint32_t parser = 0,num_blocks = 0,address = 0, seed = 0;
	unsigned char choice = 0;
	clock_t BeginCapture,EndCapture;

	if(memory == NULL)
	{
		printf("\nFirst allocate memory...!\n");
	}
	else
	{
		printf("\n\nWrite Pattern :");
		printf("\n**************");
		
		do
		{
			printf("\nProvide address index to write pattern (starts from '0') : ");
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
			printf("\nHow many words would you like to write the pattern to? ");
			scanf("%u",&num_blocks);

			if(!IsWithinBounds(address + num_blocks - 1))
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address + num_blocks - 1) && choice);
		
		printf("\nEnter the seed value for pattern generation : ");
		scanf("%u",&seed);

		BeginCapture = clock();
		for(parser = address ; parser < address + num_blocks ; parser++)
		{
						 
			*(memory + parser) = generate_pattern(seed);
			seed = *(memory + parser);
		}
		EndCapture = clock();
		
		printf("\nPattern was successfully generated in %f secs\n",(double)(EndCapture-BeginCapture)/CLOCKS_PER_SEC);
	}	
}

uint32_t generate_pattern(uint32_t seed)
{
	const uint32_t base_rand = 0xF2030C00;
	return (seed%0xFFFFFFFF) + base_rand << 2;
}
