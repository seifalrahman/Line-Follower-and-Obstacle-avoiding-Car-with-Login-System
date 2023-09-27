
#ifndef EXTERNAL_INT_H_
#define EXTERNAL_INT_H_
/*Select INT_INDEX
 * 1-INT_0
 * 2-TNT_1
 * 3-INT_2
 * */

#define EXTI	INT_0

/*Select Mode
 * 1-LOW_LEVEL
 * 2-ANY_LOGICAL_CHANGE
 * 3-FALLING_EDGE
 * 4-RISING_EDGE
 * */

#define EXTI_MODE	ANY_LOGICAL_CHANGE

/*GIE
 * 1-ENABLE
 * 2-DISABLE
 * */

#define GIE		ENABLE


/*****************************************************************************************************************/


#define INT_0	0
#define INT_1	1
#define INT_2	2

#define LOW_LEVEL			0
#define ANY_LOGICAL_CHANGE	1
#define FALLING_EDGE		2
#define	RISING_EDGE			3


#define ENABLE	0
#define DISABLE	1

#define I_BIT	7

#define NULL	((void *)0)
void EXTI_VidSetCallBack(u8 Copy_U8Index,void (*Copy_PFPtr)(void));

void EXTI_VidGIE (void);

void EXTI_VidInit(void);

#endif /* EXTERNAL_INT_H_ */
