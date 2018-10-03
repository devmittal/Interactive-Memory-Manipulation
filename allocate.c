/*****************************************************************************
​ ​* ​ ​ @file​ ​  allocate.c
​ * ​ ​ @brief​ ​ This file allocates memory based on user's input of number of 
 *	     blocks. It also does the bound checking for future read and write 
 *	     operations.
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

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
		memory = (uint32_t*) malloc(size * sizeof(uint32_t)); /* Allocating bytes of memory using malloc based on user's input of number of blocks */
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
	if((address >= size) || (address < 0)) /* Checking if the address selected by user is within the range allocated */
	{
		return 0;
	}
	return 1;
}
