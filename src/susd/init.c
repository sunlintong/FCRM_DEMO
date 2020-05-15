/************************************************************************
*				北京科银京成技术有限公司 版权所有
* 	 Copyright (C)  2011 CoreTek Systems Inc. All Rights Reserved.
***********************************************************************/

/*
 */

/*
* @file： init.c
* @brief：
*	    <li>实现单个分区的轮询打印。。</li>
* @implements： 
*/

/************************头 文 件******************************/
#include <stdarg.h>
#include <partition.h>
#include <consttype.h>
#include <imgHeader.h>
#include <rtl.h>
#include <vsep.h>
#include <ssm.h>
#include <ssmIo.h>
#include "const.h"
#include "vmsnconst.h"
#include "flr.h"

#include "vsepFaultLog.h"

/* header definition begin                   Don't remove this line*/
/* header definition end                     Don't remove this line*/ 


/************************外部声明******************************/

T_EXTERN T_VSEP_SysInfo vsepSysInfo;

#ifdef STACK_PROTECT
T_EXTERN T_CHAR init_stack_start[];
T_EXTERN T_CHAR init_stack_size[];
T_MODULE T_VMK_ReturnCode  partitionSetStackProtect(T_UWORD guardSize);
#endif

#ifdef TIME_TEST
T_UDWORD tt_begin;
T_UDWORD tt_end;
T_UWORD  tt_us;
T_UDWORD tt_sum;
T_UWORD  tt_startup;		/*启动时间*/
T_UWORD  tt_worst;			/*小帧最差执行时间(不含第0拍)*/
T_UWORD  tt_avg;			/*小帧平均执行时间*/
T_UWORD  tt_worst0;         /*小帧最差执行时间(包含第0拍)*/
#endif

/************************实   现*******************************/
/*
 * @brief:
 *    普通分区初始化。
 * @return: 
 *    无
 */
/*definition begin:partitionInit                         Don't remove this line*/
T_VOID partitionInit(T_VOID)			/*this_is_a_function*/
{
/*definition end:partitionInit                           Don't remove this line*/
	vsepInitialize();	
}/* end of partitionInit() procedure */


/*
 * @brief:
 *	  分区任务调度入库钩子
 * @return: 
 *	  无
 */
/*definition begin:AppTaskEntryHook                         Don't remove this line*/
T_VOID AppTaskEntryHook(T_VOID)			/*this_is_a_function*/
{
/*definition end:AppTaskEntryHook                           Don't remove this line*/
#ifdef TIME_TEST
	T_UWORD i;
	T_EXTERN T_VSEP_TaskGroupAttibute vsepSysTask[VSEP_GROUP_PERIODIC];
	
	/*若上次实时任务未执行完，则不更新开始时间戳，直接返回*/
	for(i=0;i<VSEP_BACKGROUND;i++)
	{
		if(vsepSysTask[i].ActFlag)
		{
			return;
		}
	}
	/*更新开始时间戳*/
	VMK_GetCPUTime(&tt_begin);
#endif
}/* end of AppTaskEntryHook() procedure */

/*
 * @brief:
 *	 分区任务调度退出钩子
 * @return: 
 *	  无
 */
/*definition begin:AppTaskExitHook                         Don't remove this line*/
T_VOID AppTaskExitHook(T_VOID)			/*this_is_a_function*/
{
/*definition end:AppTaskExitHook                           Don't remove this line*/

    word32 cnt;
    cnt = fcrm_sys_ccount;

#ifdef TIME_TEST
	 /*更新结束时间戳*/
	 VMK_GetCPUTime(&tt_end);
	 /*计算本次实时任务执行时间*/
     tt_us = (tt_end - tt_begin) / 25;
     /*计算平均执行时间*/
     tt_sum += tt_us;
     tt_avg = tt_sum/(cnt+1);
     /*更新最长执行时间*/
     if (cnt > 0)
     {
         if(tt_us > tt_worst)
         {
            tt_worst = tt_us;
         }
     }
     if(tt_us > tt_worst0)
     {
        tt_worst0 = tt_us;
     }
#endif
}/* end of AppTaskExitHook() procedure */


/*
 * @brief:
 *    普通分区的入口函数。
 * @return: 
 *    入口函数根据需要返回相应的值。
 */
 
/*definition begin:AppOverRun								Don't remove this line*/
UINT8 AppOverRun(UINT8 Rate,UINT32 SequentialOverruns)       /*this_is_a_function*/
{
/*definition end:AppOverRun								Don't remove this line*/

	flr_dcl_cod(FL_CF_ERR);

	if(SequentialOverruns < 3)
	{
		return VSEP_CONTINUE;
	}
	else
	{
		VMK_OutputDisBit(DCPUVAL,FALSE);

        //禁止本通道恢复
        rcv_blck_sng(FR_CPUFAIL + own_chan);
		
		return VSEP_CONTINUE;
	}
}/* END: AppOverRun() DEFINITION. */


/*definition begin:AppErrorHandler                         Don't remove this line*/
UINT8 AppErrorHandler(UINT8 Rate,UINT8 VsepError)		/*this_is_a_function*/
{
/*definition end:AppErrorHandler                           Don't remove this line*/
	return VSEP_CONTINUE;
} /* end of AppErrorHandler() procedure */

/******************************************************************************
 * 函数名称: AppInitialization  -  <在此处增加函数简短注释...>
 *
 * 摘    要:
 *     <在此处增加函数详细注释...>
 *
 *
 * 输入参数:
 *    sysInfo : <在此处增加参数1的注释...>
 *
 * 返 回 值:
 *     <在此处增加返回值的注释...>
 *
 * 宏 说 明:
 *     <macroName>  -  <在此处增加宏描述...>
 *
 *****************************************************************************/
/*definition begin:AppInitialization                    Don't remove this line*/
void AppInitialization(T_VSEP_SysInfo *sysInfo)           /*this_is_a_function*/
{
/*definition end:AppInitialization                      Don't remove this line*/

// 设计追踪:
// Implements DD-CSCI-XX

    /************************/
    /***     函数引用     ***/
    /************************/
    
    /************************/
    /***     输入变量     ***/
    /************************/
    
    /************************/
    /***   输入/输出变量  ***/
    /************************/
    
    /************************/
    /***     输出变量     ***/
    /************************/
    
    /************************/
    /***     常量引用     ***/
    /************************/
    
    /************************/
    /***     局部变量     ***/
    /************************/

		
	/*完成FCRM启动过程*/
	susd_startup();
    
} /* END: AppInitialization() DEFINITION. */


/*
 * @brief:
 *    普通分区的入口函数。
 * @return: 
 *    入口函数根据需要返回相应的值。
 */
/*definition begin:main                         Don't remove this line*/
T_WORD main(void)				/*this_is_a_function*/
{
/*definition end:main                           Don't remove this line*/

    partitionInit();
    AppInitialization(&vsepSysInfo);

    return(0);
}/* end of main() procedure */

