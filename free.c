/*****************************************************************************
​ ​* ​ ​ @file​ ​  free.h
​ * ​ ​ @brief​ ​ This file frees up whatever memory was allocated by the malloc
 *	     function in the allocate function. 
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdio.h>
#include"allocate.h"
#include"free.h"

void free_mem(void)
{
	if(memory == NULL) /* Checks if memory is allocated */
	{
		printf("\nMemory not allocated, allocate and try again...!\n");
	}
	else
	{
		free(memory); /* Command to free allocated memory */
		memory = NULL;
		printf("\n%lu bytes of memory has been freed\n",size * sizeof(uint32_t));
	}
}
