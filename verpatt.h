/*****************************************************************************
​ ​* ​ ​ @file​ ​  verpatt.h
​ * ​ ​ @brief​ ​ This header file contains the function declaration of the verify
 * 	     pattern function.
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Souvik De, Devansh Mittal
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

/**
​ * ​ ​ @brief​ ​ Verifies the pseudo random pattern at the addresses specified by
 *	     the user. If it is not verified, it displays a table of address,
 *	     present value and expected value. Otherwise, the time taken to 
 *	     carry out this pattern verification is calculated.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void verify_pattern(void);

/**
​ * ​ ​ @brief​ ​ Verifies the pseudo random pattern at the addresses specified by
 *	     the user using adrress offset and blocks specified by the user.
 *           If it is not verified, it displays a table of address,
 *	     present value and expected value. Otherwise, the time taken to 
 *	     carry out this pattern verification is calculated.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void verpatt_offset(void);

/**
​ * ​ ​ @brief​ ​ Verifies the pseudo random pattern at the addresses specified by
 *	     the user using specific memory adrress and blocks specified by the user.
 *           If it is not verified, it displays a table of address,
 *	     present value and expected value. Otherwise, the time taken to 
 *	     carry out this pattern verification is calculated.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void verpatt_direct(void);

