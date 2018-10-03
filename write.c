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
			scanf("%u",&address);

			if(!IsWithinBounds(address))
			{
				printf("\nUnacceptable input, index is out of bounds!\n");
				printf("1-to enter again and 0-ignore : ");
				scanf("%hhu",&choice);
			}
		}
		while(!IsWithinBounds(address) && choice);

		printf("Enter data to modify index-%u : ",address);
		scanf("%X",&data);
		*(memory + address) = data;
		printf("\nData successfully written to buffer\n");
	}
}
