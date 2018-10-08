/*****************************************************************************
​ ​* ​ ​ @file​ ​  write.h
​ * ​ ​ @brief​ ​ This header file contains the function declaration of the write 
 * 	     function. 
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

/**
​ * ​ ​ @brief​ ​ Writes hexadecimal data to the address/offset as specified
 *	     by the user.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void write_mem(void);

/**
​ * ​ ​ @brief​ ​ Writes hexadecimal data specified by the user to the address 
 *	     offset selected by the user.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void write_offset(void);

/**
​ * ​ ​ @brief​ ​ Writes hexadecimal data specified by the user to the address 
 *	     selected by the user.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void write_direct(void);
