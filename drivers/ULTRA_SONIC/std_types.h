/***************************************************
 *  Module : std_types.h
 *
 *  Details: 
 *
 *  Author: Mahmoud Ghoniem
 ***************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL_PTR     ((void *)0)              /*             NULL pointer definition            */


#define LOGIC_HIGH      (1u)                  /*             Logic value definition             */
#define LOGIC_LOW       (0u)

typedef unsigned char         boolean;        /*             Boolean Data Type                  */

                /* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

typedef unsigned char         uint8;          /*                    0  to  255                  */
typedef signed char           sint8;          /*                 -128  to  +127                 */
typedef unsigned short        uint16;         /*                    0  to 65535                 */
typedef signed short          sint16;         /*               -32768  to +32767                */
typedef unsigned long         uint32;         /*                    0  to 4294967295            */
typedef signed long           sint32;         /*          -2147483648  to +2147483647           */
typedef unsigned long long    uint64;         /*                0      to 18446744073709551615  */
typedef signed long long      sint64;         /*  -9223372036854775808 to 9223372036854775807   */
typedef float                 float32;
typedef double                float64;


#endif /* STD_TYPES_H_ */
