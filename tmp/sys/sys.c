//
// MODIFICATIONS:
//

             /*-----------------------------------------*/
             /*       Include files directives          */
             /*-----------------------------------------*/
#include <ssm.h>
#include "consttype.h"
#include "systask.h"
#include "sysconst.h"
#include "systype.h"
#include "const.h"
#include "macro.h"
#include "sig.h"
#include "flr.h"
#include "vmsnconst.h"
#include "susdconst.h"
#include "vmsntype.h"

/* header definition begin                   Don't remove this line*/
/* header definition end                     Don't remove this line*/

/***************************************************************************/
/***************************************************************************/
/*                                                                         */
/* PROCEDURE NAME : sys_exec -- Real Time Executive Procedure              */
/*                                                                         */
/* PROCEDURE DESCRIPTION :                                                 */
/*                                                                         */
/***************************************************************************/
/***************************************************************************/
			   
/****************************************************************************/
/****************************************************************************/
/*                                                                          */
/* PROCEDURE NAME :  sys_grp_actv  -- Rate group tasks activate             */
/*                                                                          */
/* PROCEDURE DESCRIPTION :                                                  */
/*                                                                          */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/

/*definition begin:sys_grp_actv                         Don't remove this line*/
void sys_grp_actv(int16  num_grp )                           /*this_is_a_function*/
{
/*definition end:sys_grp_actv                           Don't remove this line*/
                                                                 
                      /*----------------------*/                  
                      /* Formal   Parameters  */             
                      /*----------------------*/                  
                                                                 
/* int16        num_grp                                                     */
                                                                 
                      /*----------------------*/                  
                      /* T_EXTERNal Procedures  */             
                      /*----------------------*/                  
                                                                 

                 /*------------------------*/
                 /*  local   variables     */
                 /*------------------------*/


} /* end of sys_grp_actv() procedure */

/****************************************************************************/
/****************************************************************************/
/*                                                                          */
/* PROCEDURE NAME :  sys_init - executive initialization                    */
/*                                                                          */
/* PROCEDURE DESCRIPTION :                                                  */
/*                                                                          */
/*      This procedure is called to initialize the executive procedure      */
/*    parameters, then initialize RTC to be about TBD msec, enable          */
/*    interrupt and call the background task to run forever in a loop.      */
/*    This procedure must be called before the executive started, as        */
/*    the last operation of the Startup.                                    */
/*                                                                          */
/* Procedure used :                                                         */
/*                                                                          */
/*     sys_grp_actv                                                         */
/*                                                                          */
/****************************************************************************/
/****************************************************************************/
/*definition begin:sys_init                             Don't remove this line*/                                                            
void sys_init(void)                           /*this_is_a_function*/
{
/*definition end:sys_init                               Don't remove this line*/ 
                                                                 
                 /*------------------------*/
                 /*  local   variables     */
                 /*------------------------*/

   int16           i;                /* index variable                      */
   int16           j;                /* index variable                      */

 	/* B通道维护模式时禁止只保留输入输出任务 */ 
	for (i = 0; i < NUM_RG_TASK; i++)
	{
	    for (j = 0; j < MAX_NUM_TASK; j++)
	    {
	        sys_task_list[i][j].task  = TASK_PTR_LIST[i][j].task;
	        sys_task_list[i][j].inhib = TRUE;
	    }
	}
	
   fcrm_sys_ccount = 0xFFFFFFFF;	//--will be zero in first minor cycle.
   
}  /* end of sys_init() procedure */

/*definition begin:sys_grp_actv_15                         Don't remove this line*/
void sys_grp_actv_15(void)                           /*this_is_a_function*/
{
/*definition end:sys_grp_actv_15                           Don't remove this line*/

	/* 调度速率组任务  */
    sys_grp_actv(GROUP_15_ID);

} /* end of sys_grp_actv_15() procedure */

/*definition begin:sys_grp_actv_bg                         Don't remove this line*/
void sys_grp_actv_bg(void)                           /*this_is_a_function*/
{
/*definition end:sys_grp_actv_bg                           Don't remove this line*/

} /* end of sys_grp_actv_bg() procedure */

