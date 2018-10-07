/*****************************************************************************
​ ​* ​ ​ @file​ ​  wrpatt.h
​ * ​ ​ @brief​ ​ This header file contains the function declaration of the write
 *	     pattern function and the generate pattern function. It also 
 *	     contains the definiton of constant value needed for pattern 
 *	     generation.
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Souvik De, Devansh Mittal
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

#define BASE (4060285952) /* Constant value defined which is needed for pattern generation. */

/**
​ * ​ ​ @brief​ ​ writes a pseudo random pattern to the addresses specified by the 
 * 	     user. Time taken to carry out this pattern generation is also 
 *	     calculated.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void write_pattern(void);

/**
​ * ​ ​ @brief​ ​ Contains algorithm to generate pseudo random pattern.
​ *
 * ​ ​ @param​ ​ Seed value needed for pseudo random generation
​ *
​ * ​ ​ @return Returns unsigned 32 bit pattern generated
 */

void wrpatt_offset(void);
void wrpatt_direct(void);
uint32_t generate_pattern(uint32_t seed);

