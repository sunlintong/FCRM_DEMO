/* file vmstrom.c    */
/************************************************************/
/************************************************************/
/*Copyright (c) 2012, Chengdu Aircraft Design&Research Institute */
//All rights reserved.
//
//File Name��flr.c
//File ID��
//Description��Failure recording and management package .
//
//Code By:H.R 
//Data��2013-5-18 
//MODIFICATIONS:
//

/************************************************************/
/************************************************************/
//Modifications��
//
#include <ssm.h>
#include <vmkTypes.h>
#include "consttype.h"
#include "const.h"
#include "flr.h"
#include "sig.h"
#include "ccdlconst.h"
#include "vmtype.h"
#include "anavmconst.h"
#include "vmsntype.h"
#include "disvmconst.h"
#include "vmsnconst.h"
#include "simsig.h"
#include "insvmconst.h"

/*header definition begin                Don't remove this line */
#include "vdcl\vmstram.vdcl.h"
#include "vdcl\vmstrom.vdcl.h"
#include "vdcl\fcrm_nvm_ram.vdcl.h"
#include "vdcl\vmsn_io_ram.vdcl.h"
#include "vdcl\ram.vdcl.h"
#include "vdcl\fcrm_claw_ram.vdcl.h"

/*header definition end                 Don't remove this line */
/*  declaration begin:                              Don't remove this line. */
VDCL_aq_ram;                     /*��������                          */
VDCL_aq_rcv_sw;        /*�ع����ɸ�λ                        */
VDCL_AQ_ROM;
VDCL_axes_data_err;        /*�����ź�״̬ piu_data_err & gyro_status*/
VDCL_ccdl_buf;        /*�������ݻ�����                       */
VDCL_dltwowsw_ram;        /*�����ؿ���                         */
VDCL_dltwowsw_rcv_sw;        /*�ع����ɸ�λ                        */
VDCL_DLTWOWSW_ROM;
VDCL_dummy_data_err;        /*������CCDL�����ݴ���״̬��               */
VDCL_ilm_ccdl_status;
VDCL_piu_ccdl_status;        /*PIU����CCDL��Ч״̬                 */
VDCL_v_iaq;        /*�������ʱ��ֵ                       */
VDCL_v_vdltwowsw;        /*�����ؿ���                         */

/*  declaration end:                              	Don't remove this line. */

			/************************************/
			/*		PIUģ������ROM�ṹ			*/
			/************************************/

			/*		��������						*/

	vm_rom_rec const  AQ_ROM =
	{
		&aq_ram,                       /* pointer to the RAM record             */
		&axes_data_err,					/* ָ��ڵ�������Ч״̬�ֵ�ָ�� */
		&piu_ccdl_status,				/* ָ��ڵ�����CCDL״̬�ֵ�ָ�� */
		&v_iaq,                        /* NVM address for the voted value(integ)*/
		{&ccdl_buf[DAQILM + AQ],    /* pointer to the ch. A ain word         */
		&ccdl_buf[DAQILM + AQ],    /* pointer to the ch. B ain word         */
		&ccdl_buf[DAQILM + AQ],    /* pointer to the ch. C ain word         */
		&ccdl_buf[DAQILM + AQ]},    /* pointer to the ch. D ain word         */
		DAQILM & 0xF,                 /* ILM din bit number in the CCDL buffer */
		DAQILM >> 4,                  /* ILM din number in the CCDL buffer     */
		FR_AQ,                         /* failure code                          */
		FL_AQ,                         /* failure code for MAX/MIN tol. failure */
		NO_ANAL_RCNF,                       /* bit nmb. in CL reconfiguration dword  */
		TWELVE,                         /* persistence                           */
		TRUE,                          /* flag for report of signal values      */
		ABCD_SAMPLE,                   /* nibble of chan. sampling this signal  */
		FS_COMPUT,                     /* kind of fail safe value               */
		AT_LEAST_ONE,                  /* minimum of valid chan. before reconf. */
		0,                             /* fail safe value                       */
		&aq_rcv_sw						/* �ع��󲻿ɸ�λ */
	};	

			/****************************************/
			/*        ��ɢ���������ROM				*/
			/****************************************/

			/*	�����ؿ���			*/

	vm_rom_rec const  DLTWOWSW_ROM =
	{
		&dltwowsw_ram,							/*	������ram�ṹָ��		*/
		&dummy_data_err,						/* ָ��ڵ�������Ч״̬�ֵ�ָ�� 		*/
		&ilm_ccdl_status,						/* ָ��ڵ�����CCDL״̬�ֵ�ָ�� 		*/
		&v_vdltwowsw,							/*	NVM���ֵָ��			*/
		{&ccdl_buf[FR_DLTWOWSW],	/*	VMCAͨ��CCDL����ֵָ��	*/
		&ccdl_buf[FR_DLTWOWSW],	/*	VMCBͨ��CCDL����ֵָ��	*/
		&ccdl_buf[FR_DLTWOWSW],	/*	VMCCͨ��CCDL����ֵָ��	*/
		&ccdl_buf[FR_DLTWOWSW},	/*	BFCCͨ��CCDL����ֵָ��	*/
		FR_DLTWOWSW & 0xF,							/*	��ɢ��λ��				*/
		0,										/*	���߼���ź�				*/
		FR_DLTWOWSW,							/*	������					*/
		FL_DUMMY_CODE,							/*	�����������				*/
		NO_DISC_RCNF,								/*	�������ع�λ				*/
		TWELVE,									/*	��ش�������				*/
		TRUE,									/*	��¼����ֵ��־			*/
		ABCD_SAMPLE,							/*	����ͨ��					*/
		FS_CONST,								/*	���ϰ�ȫֵ����			*/
		AT_LEAST_TWO,							/*	�ع�ǰ��С��Ч�ź���		*/
		FR_DLTWOWSW,							/*	���ϰ�ȫֵ				*/
		&dltwowsw_rcv_sw						/* �ع��󲻿ɸ�λ */
	};

			/******************************************************/
			/*        ��ͨ���ɼ�����ɢ���������ROM�б�	    	*/
			/****************************************/

	vm_rom_rec const  *const LOC_DIS_INP_LST[] = 
	{
		&DLTWOWSW_ROM,
        NULL				/*	�б����					*/
	};
	
			/************************************/
			/*	PIU����ģ����ɢ��ROM�ṹ�б�	*/
			/************************************/
		  
  vm_rom_rec const	*const MO_PIU_SIG_LST[] = 
  {
		 &AQ_ROM, 				/* ��������				*/
		 NULL					/* �б������			*/
  };
  
