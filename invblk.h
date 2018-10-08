/*****************************************************************************
​ ​* ​ ​ @file​ ​  invblk.h
​ * ​ ​ @brief​ ​ This header file contains the function declaration of the invert
 *	     block function.
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

/**
​ * ​ ​ @brief​ ​ Inverts the data bits spannig the addresses/offset and blocks as specified by the
 *	     user.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void invert_block(void);

/**
​ * ​ ​ @brief​ ​ Inverts the data bits in memory as per the addresses offset and no. of blocks specified by the
 *	     user. It also measures the amount of time taken to carry out the
 *	     invert operation.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */
void invert_offset(void);

/**
​ * ​ ​ @brief​ ​ Inverts the data bits in memory as per the addresses and no. of blocks specified by the
 *	     user. It also measures the amount of time taken to carry out the
 *	     invert operation.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */
void invert_direct(void);
