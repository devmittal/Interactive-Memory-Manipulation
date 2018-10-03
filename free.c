#include<stdio.h>
#include"allocate.h"

void free_mem(void)
{
	if(memory == NULL)
	{
		printf("\nMemory not allocated, allocate and try again...!\n");
	}
	else
	{
		free(memory);
		memory = NULL;
		printf("\n%lu bytes of memory has been freed\n",size * sizeof(uint32_t));
	}
}
