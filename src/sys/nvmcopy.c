
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
void copytonvm(void)                                   /*this_is_a_function*/
{
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
void copyfromnvm(void)                                   /*this_is_a_function*/
{
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


/*  nvmtoram end   Don't remove this line. */

}


