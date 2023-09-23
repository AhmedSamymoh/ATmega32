/*
 * BIT_MATH.h
 *
 *  Created on: Sep 1, 2023
 *      Author: AhmedSamy
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define MASK_PIN    1

#define SET_BIT(REG,PIN)      	(REG |= (MASK_PIN <<PIN))
#define CLR_BIT(REG,PIN)    	(REG &= (~(MASK_PIN << PIN)))
#define TOG_BIT(REG,PIN)   		(REG = REG ^ (MASK_PIN<<PIN))
#define GET_BIT(REG,PIN)  		((REG>>PIN)  & MASK_PIN)



#endif /* BIT_MATH_H_ */
