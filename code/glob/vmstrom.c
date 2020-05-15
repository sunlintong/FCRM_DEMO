/* file vmstrom.c    */
/************************************************************/
/************************************************************/
/*Copyright (c) 2012, Chengdu Aircraft Design&Research Institute */
//All rights reserved.
//
//File Name：flr.c
//File ID：
//Description：Failure recording and management package .
//
//Code By:H.R 
//Data：2013-5-18 
//MODIFICATIONS:
//

/************************************************************/
/************************************************************/
//Modifications：
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
VDCL_aq_ram;                     /*俯仰速率                          */
VDCL_aq_rcv_sw;        /*重构不可复位                        */
VDCL_AQ_ROM;
VDCL_axes_data_err;        /*三轴信号状态 piu_data_err & gyro_status*/
VDCL_ccdl_buf;        /*总线数据缓冲区                       */
VDCL_dltwowsw_ram;        /*左轮载开关                         */
VDCL_dltwowsw_rcv_sw;        /*重构不可复位                        */
VDCL_DLTWOWSW_ROM;
VDCL_dummy_data_err;        /*非自主CCDL的数据错误状态字               */
VDCL_ilm_ccdl_status;
VDCL_piu_ccdl_status;        /*PIU数据CCDL有效状态                 */
VDCL_v_iaq;        /*俯仰速率表决值                       */
VDCL_v_vdltwowsw;        /*左轮载开关                         */

/*  declaration end:                              	Don't remove this line. */

			/************************************/
			/*		PIU模拟输入ROM结构			*/
			/************************************/

			/*		俯仰速率						*/

	vm_rom_rec const  AQ_ROM =
	{
		&aq_ram,                       /* pointer to the RAM record             */
		&axes_data_err,					/* 指向节点数据有效状态字的指针 */
		&piu_ccdl_status,				/* 指向节点数据CCDL状态字的指针 */
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
		&aq_rcv_sw						/* 重构后不可复位 */
	};	

			/****************************************/
			/*        离散输入表决监控ROM				*/
			/****************************************/

			/*	左轮载开关			*/

	vm_rom_rec const  DLTWOWSW_ROM =
	{
		&dltwowsw_ram,							/*	表决监控ram结构指针		*/
		&dummy_data_err,						/* 指向节点数据有效状态字的指针 		*/
		&ilm_ccdl_status,						/* 指向节点数据CCDL状态字的指针 		*/
		&v_vdltwowsw,							/*	NVM表决值指针			*/
		{&ccdl_buf[FR_DLTWOWSW],	/*	VMCA通道CCDL输入值指针	*/
		&ccdl_buf[FR_DLTWOWSW],	/*	VMCB通道CCDL输入值指针	*/
		&ccdl_buf[FR_DLTWOWSW],	/*	VMCC通道CCDL输入值指针	*/
		&ccdl_buf[FR_DLTWOWSW},	/*	BFCC通道CCDL输入值指针	*/
		FR_DLTWOWSW & 0xF,							/*	离散量位号				*/
		0,										/*	在线监控信号				*/
		FR_DLTWOWSW,							/*	故障码					*/
		FL_DUMMY_CODE,							/*	超限类故障码				*/
		NO_DISC_RCNF,								/*	控制律重构位				*/
		TWELVE,									/*	监控次数容限				*/
		TRUE,									/*	记录故障值标志			*/
		ABCD_SAMPLE,							/*	采样通道					*/
		FS_CONST,								/*	故障安全值类型			*/
		AT_LEAST_TWO,							/*	重构前最小有效信号数		*/
		FR_DLTWOWSW,							/*	故障安全值				*/
		&dltwowsw_rcv_sw						/* 重构后不可复位 */
	};

			/******************************************************/
			/*        本通道采集的离散输入表决监控ROM列表	    	*/
			/****************************************/

	vm_rom_rec const  *const LOC_DIS_INP_LST[] = 
	{
		&DLTWOWSW_ROM,
        NULL				/*	列表结束					*/
	};
	
			/************************************/
			/*	PIU输入模拟离散量ROM结构列表	*/
			/************************************/
		  
  vm_rom_rec const	*const MO_PIU_SIG_LST[] = 
  {
		 &AQ_ROM, 				/* 俯仰速率				*/
		 NULL					/* 列表结束符			*/
  };
  
