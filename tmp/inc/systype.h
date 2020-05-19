/* file systype.h    */
/************************************************************/
/************************************************************/
/*Copyright (c) 2012, Chengdu Aircraft Design&Research Institute */
//All rights reserved.
//
//File Name��systype.h
//File ID��
//Description��This package contains all sys packege type definition.
//
//Code By:Z.Y 
//Data��2013-5-11 
/************************************************************/
/************************************************************/
//Modifications��

#ifndef SYSTYPE_H_
#define SYSTYPE_H_

typedef struct {
    void          (*task) ();          /* pointer to the task address       */
    boolean       inhib;               /* task inhibit flag                 */
    } sys_task_rec;
#endif		/* SYSTYPE_H_ */
