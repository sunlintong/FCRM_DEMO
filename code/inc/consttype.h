/* file consttype.h                                                         */
    
/****************************************************************************/
/****************************************************************************/
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/
// MODIFICATIONS:
//
//
#ifndef CONSTTYPE_H_
#define CONSTTYPE_H_
#include <partition.h>
                 /*--------------------------------*/
                 /* language - element definitions */ 
                 /*--------------------------------*/

#define  LAND         &&                     /* logical AND                 */
#define  LOR          ||                     /* logical OR                  */
#define  LNOT         !                      /* unary not                   */
#define  BWAND        &                      /* bitwise AND                 */
#define  BWOR         |                      /* bitwise OR                  */
#define  BWXOR        ^                      /* bitwise XOR                 */
#define  BWNOT        ~                      /* bitwise NOT                 */
#define  EQ           ==                     /* equal                       */
#define  NE           !=                     /* not equal                   */
#define  NOT          !                      /* unary not                   */
#define  POSITIVE     <                      /* less than !! ONLY FOR CAS ! */
#define  NEGATIVE     >                      /* great than ! ONLY FOR CAS ! */
                 /*--------------------------------*/
                 /*      definition of types       */ 
                 /*--------------------------------*/

typedef short            int16;              /* 16 bits                     */
typedef int              int32;              /* 32 bits                     */
typedef unsigned short   boolean;            /*  16 bits                     */
typedef unsigned char    byte;               /*  8 bits                     */
typedef unsigned short   word16;             /* 16 bits                     */
typedef unsigned int     word32;             /* 32 bits                     */
typedef unsigned long long word64;           /* ÎÞ·ûºÅ64bit */


#endif /* CONSTTYPE_H */
