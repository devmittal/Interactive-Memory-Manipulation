/*****************************************************************************
​ ​* ​ ​ @file​ ​  allocate.h
​ * ​ ​ @brief​ ​ This header file contains the function declaration of the function
 *	     used to allocate memory and the function used for bound checking.
 * 	     It also contains the declaration of the pointer used to point to
 *	     the memory allocated. 
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Souvik De, Devansh Mittal
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#include<stdint.h>
#include<stdlib.h>

/**
 * "memory" points to the address allocated by the malloc function. 
 * "size" denotes number of blocks selected by user to allocate.
*/

uint32_t *memory,size; 

/**
​ * ​ ​ @brief​ ​ Allocates bytes of memory using malloc based on user's input of 
 *	     number of blocks.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */
void allocate_mem(void);

/**
​ * ​ ​ @brief​ ​ Checks whether the address selected by user is within the range
 *	     allocated by the malloc function.
 *
​ * ​ ​ @param​ ​ Address index selected by user.
​ *
​ * ​ ​ @return unsigned char to return either 1 or 0 based on whether it satifies 
 * 	     the check.
 */

unsigned char IsWithinBounds(uint32_t address);
