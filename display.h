/*****************************************************************************
​ ​* ​ ​ @file​ ​  display.h
​ * ​ ​ @brief​ ​ This header file contains the function declaration of the display
 *	     function which displays the data present in the addresses selected
 *	     by the user. 
 *   @Tools_Used GCC
​ * ​ ​ @author​ ​Devansh Mittal, Souvik De
​ * ​ ​ @date​ ​ October 3rd, 2018
​ * ​ ​ @version​ ​ 1.0
*****************************************************************************/

/**
​ * ​ ​ @brief​ ​ Displays the data present in the memory using the addresses/ offset and number of block
 *           as selected by the user.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */

void display_mem(void);

/**
​ * ​ ​ @brief​ ​ Displays the data present in the memory using addresses and no. of block selected by the user.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */
void display_direct(void);

/**
​ * ​ ​ @brief​ ​ Displays the data present in the memory using addresses offset and no. of block selected by the user.
 *
​ * ​ ​ @param​ ​ void
​ *
​ * ​ ​ @return void
 */
void display_offset(void);
