#include<stdio.h>
#include"allocate.h"

void display_mem(void)
{
	uint32_t parser = 0,num_blocks = 0,address = 0;
	unsigned char choice = 0;

	if(memory == NULL)
	{		
		printf("\nAllocate memory first...!\n");
	}
	else
	{
		printf("\n\nDisplay Memory :");
		printf("\n ****************");
		
		do
		{
			printf("\nEnter address index to see contiguous data : ");
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
			printf("\t0X%08lx",(unsigned long)(memory + parser));
			printf("\t0X%08lx\n",(unsigned long)*(memory+parser));
		}
	}
}
