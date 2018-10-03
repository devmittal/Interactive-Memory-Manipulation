#include<stdio.h>
#include"allocate.h"

void allocate_mem(void)
{
	printf("\n\nAllocate Memory :");
	printf("\n*****************");
	
	if(memory == NULL)
	{	
		printf("\nHow many blocks would you like to allocate? ");
		scanf("%d",&size);
		memory = (uint32_t*) malloc(size * sizeof(uint32_t));
		printf("%lu bytes of memory allocated successfully",size * sizeof(uint32_t));
		printf("\nAssigned memory starts from 0X%lx\n\n",(unsigned long)memory);
	}
	else
	{
		printf("\nFree memory to allocate again !!\n");
		printf("\nAssigned memory starts from 0X%lx\n\n",(unsigned long)memory);
	}
}

unsigned char IsWithinBounds(uint32_t address)
{
	if((address >= size) || (address < 0))
	{
		return 0;
	}
	return 1;
}
