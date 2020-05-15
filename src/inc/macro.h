/* file macro.h    */
/************************************************************/
/************************************************************/
/*Copyright (c) 2012, Chengdu Aircraft Design&Research Institute */
//All rights reserved.
//
//File Name£ºmacro.c
//File ID£º
//Description£ºThis package contains all general purpose macro.
//
//Code By:Z.Y 
//Data£º2013-5-15 
/************************************************************/
/************************************************************/
//Modifications£º
//

#ifndef MACRO_H_
#define MACRO_H_
#include <ssm.h>

/*****************************************************************************/
 /* max macro
    This macro returns maximum
    of two values
 */
#define max_val(a,b)  \
   ( (a) >= (b) ? (a) : (b) ) 

/*****************************************************************************/
 /* min macro
    This macro returns minimum
    of two values
 */
#define min_val(a,b)  \
   ( (a) <= (b) ? (a) : (b) ) 																																							\

#endif /* MACRO_H_*/


