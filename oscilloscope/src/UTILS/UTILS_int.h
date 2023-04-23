#ifndef UTILS_INT_H_
#define UTILS_INT_H_

#define NULL ((void *)0)
#define SET_BIT(REG, BIT) REG |= (1 << BIT)
#define CLR_BIT(REG, BIT) REG &= ~(1 << BIT)
#define GET_BIT(REG, BIT) ((REG >> BIT) & 1)
#define ASSIGN_REG(REG, VALUE) REG = VALUE

#endif
