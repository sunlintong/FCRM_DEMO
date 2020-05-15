/* file fcrm_nvm.c     */
/************************************************************/
/************************************************************/
/*Copyright (c) 2012, Chengdu Aircraft Design&Research Institute */
//All rights reserved.
//
//File Name��fcrmnvm.c
//Description��This package contains NVM variables definition for FCRM partition.
//
//Code By:Z.Y 
//Data��2013-5-10 
/************************************************************/
/************************************************************/
//Modifications��
//

#include "consttype.h"
#include "const.h"
#include "flrconst.h"
#include "flrtype.h"
#include "vsepFaultLog.h"
#include "simonconst.h"
/*  declaration begin:                              Don't remove this line. */
/*  declaration end:                              	Don't remove this line. */

/* fcrm_claw_nvm begin				   Don't remove this line*/
int32 eq_ipequal_nvm;     /* ���ľ������      */
int16 v_iaq_nvm;      /* �������ʱ��ֵ      */

/* fcrm_claw_nvm end				   Don't remove this line*/



/* fcrm_loc_nvm begin				   Don't remove this line*/
word16    axes_data_err_nvm;     /* �����ź�״̬ piu_data_err & gyro_status */
int16  v_vdltwowsw_nvm;     /*  �����ؿ���        */

/* fcrm_loc_nvm end				   Don't remove this line*/
word32	mo_cl_rcnf_nvm;     		/*	�������ع���1						*/
word32	mo_cl_rcf2_nvm; 			/*	�������ع���2						*/

