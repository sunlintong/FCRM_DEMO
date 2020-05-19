/************************************************************************
*				�����������ɼ������޹�˾ ��Ȩ����
* 	 Copyright (C)  2011 CoreTek Systems Inc. All Rights Reserved.
***********************************************************************/

/*
 */

/*
* @file�� init.c
* @brief��
*	    <li>ʵ�ֵ�����������ѯ��ӡ����</li>
* @implements�� 
*/

/************************ͷ �� ��******************************/
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


/************************�ⲿ����******************************/

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
T_UWORD  tt_startup;		/*����ʱ��*/
T_UWORD  tt_worst;			/*С֡���ִ��ʱ��(������0��)*/
T_UWORD  tt_avg;			/*С֡ƽ��ִ��ʱ��*/
T_UWORD  tt_worst0;         /*С֡���ִ��ʱ��(������0��)*/
#endif

/************************ʵ   ��*******************************/
/*
 * @brief:
 *    ��ͨ������ʼ����
 * @return: 
 *    ��
 */
/*definition begin:partitionInit                         Don't remove this line*/
T_VOID partitionInit(T_VOID)			/*this_is_a_function*/
{
/*definition end:partitionInit                           Don't remove this line*/
	vsepInitialize();	
}/* end of partitionInit() procedure */


/*
 * @brief:
 *	  �������������⹳��
 * @return: 
 *	  ��
 */
/*definition begin:AppTaskEntryHook                         Don't remove this line*/
T_VOID AppTaskEntryHook(T_VOID)			/*this_is_a_function*/
{
/*definition end:AppTaskEntryHook                           Don't remove this line*/
#ifdef TIME_TEST
	T_UWORD i;
	T_EXTERN T_VSEP_TaskGroupAttibute vsepSysTask[VSEP_GROUP_PERIODIC];
	
	/*���ϴ�ʵʱ����δִ���꣬�򲻸��¿�ʼʱ�����ֱ�ӷ���*/
	for(i=0;i<VSEP_BACKGROUND;i++)
	{
		if(vsepSysTask[i].ActFlag)
		{
			return;
		}
	}
	/*���¿�ʼʱ���*/
	VMK_GetCPUTime(&tt_begin);
#endif
}/* end of AppTaskEntryHook() procedure */

/*
 * @brief:
 *	 ������������˳�����
 * @return: 
 *	  ��
 */
/*definition begin:AppTaskExitHook                         Don't remove this line*/
T_VOID AppTaskExitHook(T_VOID)			/*this_is_a_function*/
{
/*definition end:AppTaskExitHook                           Don't remove this line*/

    word32 cnt;
    cnt = fcrm_sys_ccount;

#ifdef TIME_TEST
	 /*���½���ʱ���*/
	 VMK_GetCPUTime(&tt_end);
	 /*���㱾��ʵʱ����ִ��ʱ��*/
     tt_us = (tt_end - tt_begin) / 25;
     /*����ƽ��ִ��ʱ��*/
     tt_sum += tt_us;
     tt_avg = tt_sum/(cnt+1);
     /*�����ִ��ʱ��*/
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
 *    ��ͨ��������ں�����
 * @return: 
 *    ��ں���������Ҫ������Ӧ��ֵ��
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

        //��ֹ��ͨ���ָ�
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
 * ��������: AppInitialization  -  <�ڴ˴����Ӻ������ע��...>
 *
 * ժ    Ҫ:
 *     <�ڴ˴����Ӻ�����ϸע��...>
 *
 *
 * �������:
 *    sysInfo : <�ڴ˴����Ӳ���1��ע��...>
 *
 * �� �� ֵ:
 *     <�ڴ˴����ӷ���ֵ��ע��...>
 *
 * �� ˵ ��:
 *     <macroName>  -  <�ڴ˴����Ӻ�����...>
 *
 *****************************************************************************/
/*definition begin:AppInitialization                    Don't remove this line*/
void AppInitialization(T_VSEP_SysInfo *sysInfo)           /*this_is_a_function*/
{
/*definition end:AppInitialization                      Don't remove this line*/

// ���׷��:
// Implements DD-CSCI-XX

    /************************/
    /***     ��������     ***/
    /************************/
    
    /************************/
    /***     �������     ***/
    /************************/
    
    /************************/
    /***   ����/�������  ***/
    /************************/
    
    /************************/
    /***     �������     ***/
    /************************/
    
    /************************/
    /***     ��������     ***/
    /************************/
    
    /************************/
    /***     �ֲ�����     ***/
    /************************/

		
	/*���FCRM��������*/
	susd_startup();
    
} /* END: AppInitialization() DEFINITION. */


/*
 * @brief:
 *    ��ͨ��������ں�����
 * @return: 
 *    ��ں���������Ҫ������Ӧ��ֵ��
 */
/*definition begin:main                         Don't remove this line*/
T_WORD main(void)				/*this_is_a_function*/
{
/*definition end:main                           Don't remove this line*/

    partitionInit();
    AppInitialization(&vsepSysInfo);

    return(0);
}/* end of main() procedure */

