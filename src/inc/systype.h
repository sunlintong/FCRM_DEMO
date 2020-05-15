/* file systype.h    */
/************************************************************/
/************************************************************/
/*Copyright (c) 2012, Chengdu Aircraft Design&Research Institute */
//All rights reserved.
//
//File Name£ºsystype.h
//File ID£º
//Description£ºThis package contains all sys packege type definition.
//
//Code By:Z.Y 
//Data£º2013-5-11 
/************************************************************/
/************************************************************/
//Modifications£º

#ifndef SYSTYPE_H_
#define SYSTYPE_H_

typedef struct {
    void          (*task) ();          /* pointer to the task address       */
    boolean       inhib;               /* task inhibit flag                 */
    } sys_task_rec;
#endif		/* SYSTYPE_H_ */
