/* file fcrmram.c     */
/************************************************************/
/************************************************************/
/*Copyright (c) 2012, Chengdu Aircraft Design&Research Institute */
//All rights reserved.
//
//File Name：fcrmnvm.c
//Description：This package contains RAM variables definition for FCRM partition.
//
//Code By:Z.Y 
//Data：2013-5-10 
/************************************************************/
/************************************************************/

#include <vmkTypes.h>
#include "consttype.h"
#include "const.h"

/*  declaration begin:                              Don't remove this line. */
/*  declaration end:                              	Don't remove this line. */
//word32 claw_pre_heart[4];
//word32 sim_pre_heart[4];
word16	  piu_ccdl_status;			   /* PIU数据CCDL有效状态				   */
word16	dummy_data_err;					/* 非自主CCDL的数据错误状态字*/
word16 ilm_ccdl_status;
boolean ads_scsflg_isr;


word16    ads_ccdl_status;				/* 大气数据CCDL有效状态 				*/				
 word16    ins_ccdl_status;				/* 惯导数据CCDL有效状态 				*/
 word16    isacf_ccdl_status;				/* 前作动器控制器数据CCDL有效状态		*/
 word16    isacb_ccdl_status;				/* 后作动器控制器数据CCDL有效状态		*/ 
 word16    etcl_ccdl_status;				/* ETCL数据CCDL有效状态		*/
 word16    etcr_ccdl_status;				/* ETCR数据CCDL有效状态		*/
 word16    vpu_ccdl_status;					/* VPU数据CCDL有效状态			*/
 word16    acon_ccdl_status;				/* 辅助控制器数据CCDL有效状态			*/
 word16    wspin_data_err;					/* 轮速特殊数据错误状态					*/ 
 word16    wspin_ccdl_status;				/* 轮速特殊CCDL有效状态					*/
 word16		claw_ccdl_err; 
 word16		sim1_ccdl_err;
word16	ch_health;					  /* CCDL & S/W & H/W status		   */
boolean	ch_scsflg;					  /* single steering channel flag	   */
word16	mo_ocm_stat;				  /* status of output commands		   */
//int16  	ivot_dummy;
int32	eq_vo_pint;					  /* 积分器输出表决值 */
 boolean sb_sw_step;                   /* reconfigration cond. for SB SW    */
 boolean vsb_sw_step;                  /* failure delare flag of virtual sb */
word32  vmc_mod_word;
word16 pbit_start_fg;
word16 pbit_end;
word16 mbit_start;
word16 mbit_end;
word32	pre_apalt_time;             /* 上一次AP高度保持请求值 */
word32	pre_aptrk_time;             /* 上一次AP航迹保持请求值 */
word16  piu_cmd_ilm;
word16	piu_an_ilm;

