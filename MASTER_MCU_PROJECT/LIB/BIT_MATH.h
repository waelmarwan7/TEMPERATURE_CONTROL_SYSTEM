/*
 * BIT_MATH.H
 *
 *  Created on: Aug 10, 2023
 *      Author: user
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define     SET_BIT(REG,BIT_NUM)      REG|=(1<<BIT_NUM)
#define     CLR_BIT(REG,BIT_NUM)      REG&=~(1<<BIT_NUM)
#define     TOG_BIT(REG,BIT_NUM)      REG^=(1<<BIT_NUM)
#define     GET_BIT(REG,BIT_NUM)      (((REG)>>(BIT_NUM))&1)


#define     SET_PORT(REG,DATA)      REG=DATA
#define     CLR_PORT(REG)           REG&=(0X00)
#define     TOG_PORT(REG)           REG^=(0XFF)

#endif /* BIT_MATH_H_ */
