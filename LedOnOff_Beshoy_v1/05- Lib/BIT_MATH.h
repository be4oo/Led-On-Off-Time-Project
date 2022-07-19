/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V02																*/
/* Date    : 17 JUL 2022															*/
/********************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(VAR,BIT)			VAR |=  (1<<(BIT))
#define CLR_BIT(VAR,BIT)			VAR &= ~(1<<(BIT))
#define GET_BIT(VAR,BIT)			((VAR >> BIT) & 1)
#define TOG_BIT(VAR,BIT)			VAR ^=  (1<<(BIT))

#define GET_REG(BASE_ADDR, REG_TYPE, REG_OFFSET)                (*((volatile REG_TYPE*)(BASE_ADDR+REG_OFFSET)))

#define ASSIGN_BIT(VAR,BIT,Val)                            (VAR = (VAR&~(1<<BIT))|(Val<<BIT))



#endif