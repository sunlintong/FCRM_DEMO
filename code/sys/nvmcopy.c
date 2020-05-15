
              /*--------------------------------------*/
              /*       Include files directives       */
              /*--------------------------------------*/


#include "consttype.h"
#include "const.h"
#include "flrconst.h"
#include "flrtype.h"   
#include "vsepFaultLog.h"
#include "simonconst.h"
/* header definition begin                   Don't remove this line*/
#include "fdcl/nvmcopy.fdcl.h"
#include "vdcl/fcrm_nvm_ram.vdcl.h"
#include "vdcl/fcrm_nvm.vdcl.h"
#include "vdcl/fcrm_claw_ram.vdcl.h"

/* header definition end                     Don't remove this line*/ 



/******************************************************************************
 * 函数名称: copytonvm - 将RAM变量拷贝至NVM
 *
 * 摘    要:
 *    后台任务调度
 *    
 *
 * 输入参数:
 *    void : 无
 *
 * 返 回 值:
 *     无
 *
 * 宏 说 明:
 *     <macroName>  -  <在此处增加宏描述...>
 *
 *****************************************************************************/
/*definition begin:copytonvm                         Don't remove this line*/
FTYP_copytonvm                           /**/
{
/*  外部函数调用声明   */
/*  输出变量   */
   VDCL_axes_data_err;              /*三轴信号状态 piu_data_err & gyro_status*/

   VDCL_axes_data_err_nvm;          /*三轴信号状态 piu_data_err & gyro_status*/

   VDCL_eq_ipequal;                 /*单拍均衡输出                        */

   VDCL_eq_ipequal_nvm;             /*单拍均衡输出                        */

   VDCL_mo_cl_rcf2;                 /*控制律重构字2                       */

   VDCL_mo_cl_rcf2_nvm;             /*控制律重构字2                       */

   VDCL_mo_cl_rcnf;                 /*控制律重构字1                       */

   VDCL_mo_cl_rcnf_nvm;             /*控制律重构字1                       */

   VDCL_v_iaq;                      /*俯仰速率表决值                       */

   VDCL_v_iaq_nvm;                  /*俯仰速率表决值                       */

   VDCL_v_vdltwowsw;                /*左轮载开关                         */

   VDCL_v_vdltwowsw_nvm;            /*左轮载开关                         */

/*  输入变量   */
/*  输入输出变量   */

/*definition end:copytonvm                           Don't remove this line*/

	/************************/
    /***     局部变量     ***/
    /************************/
	
    /************************/
    /***      函数体      ***/
    /************************/
	if (inh_wri_nvm EQ FALSE)
	{
        mo_cl_rcnf_nvm = mo_cl_rcnf;
        mo_cl_rcf2_nvm = mo_cl_rcf2;
	}
	
/*  ramtonvm begin   Don't remove this line. */
int16 i;
eq_ipequal_nvm = eq_ipequal;
v_iaq_nvm = v_iaq;
axes_data_err_nvm = axes_data_err;
v_vdltwowsw_nvm = v_vdltwowsw;


/*  ramtonvm end   Don't remove this line. */

}

/******************************************************************************
 * 函数名称: copyfromnvm - 将NVM变量拷贝至RAM
 *
 * 摘    要:
 *    初始化时调用。
 *    
 *
 * 输入参数:
 *    void : 无
 *
 * 返 回 值:
 *     无
 *
 * 宏 说 明:
 *     <macroName>  -  <在此处增加宏描述...>
 *
 *****************************************************************************/
/*definition begin:copyfromnvm                         Don't remove this line*/
FTYP_copyfromnvm                           /**/
{
/*  外部函数调用声明   */
/*  输出变量   */
   VDCL_axes_data_err;              /*三轴信号状态 piu_data_err & gyro_status*/

   VDCL_axes_data_err_nvm;          /*三轴信号状态 piu_data_err & gyro_status*/

   VDCL_eq_ipequal;                 /*单拍均衡输出                        */

   VDCL_eq_ipequal_nvm;             /*单拍均衡输出                        */

   VDCL_mo_cl_rcf2;                 /*控制律重构字2                       */

   VDCL_mo_cl_rcf2_nvm;             /*控制律重构字2                       */

   VDCL_mo_cl_rcnf;                 /*控制律重构字1                       */

   VDCL_mo_cl_rcnf_nvm;             /*控制律重构字1                       */

   VDCL_v_iaq;                      /*俯仰速率表决值                       */

   VDCL_v_iaq_nvm;                  /*俯仰速率表决值                       */

   VDCL_v_vdltwowsw;                /*左轮载开关                         */

   VDCL_v_vdltwowsw_nvm;            /*左轮载开关                         */

/*  输入变量   */
/*  输入输出变量   */

/*definition end:copyfromnvm                           Don't remove this line*/

	/************************/
    /***     局部变量     ***/
    /************************/
	
    /************************/
    /***      函数体      ***/
    /************************/
    mo_cl_rcnf = mo_cl_rcnf_nvm;
    mo_cl_rcf2 = mo_cl_rcf2_nvm;

/*  nvmtoram begin   Don't remove this line. */
int16 i;
eq_ipequal = eq_ipequal_nvm;
v_iaq = v_iaq_nvm;
axes_data_err = axes_data_err_nvm;
v_vdltwowsw = v_vdltwowsw_nvm;


/*  nvmtoram end   Don't remove this line. */

}


