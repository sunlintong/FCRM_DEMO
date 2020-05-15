
#include <partition.h>
#include <ssm.h>
#include "consttype.h"
#include "const.h"
#include "ioconst.h"
#include "ccdlconst.h"
#include "sig.h"
#include "simsig.h"
#include "macro.h"
#include "vmsnconst.h"
#include "vmsntype.h"
#include "anavmconst.h"
#include "flrconst.h"
#include "flr.h"
#include "bauconst.h"
#include "bautype.h"
#include "iotype.h"
#include "flrnvmmacro.h"
#include "flrtype.h"
#include "vmtype.h"
#include "ads2vmtype.h"


/* header definition begin                   Don't remove this line*/
#include "fdcl/io.fdcl.h"
#include "vdcl/claw_fcrm_ram.vdcl.h"
#include "vdcl/ram.vdcl.h"

/* header definition end                     Don't remove this line*/ 

/******************************************************************************
 * 函数名称: io_input  -  IO输入
 *
 * 摘    要:
 *     将非自主CCDL的信号放入本通道的CCDL缓冲区。
 *
 *
 * 输入参数:
 *    void : 无
 *
 * 返 回 值:
 *     无
 *
 * 宏 说 明:
 *     无
 *
 *****************************************************************************/
/*definition begin:io_input                             Don't remove this line*/
FTYP_io_input                           /**/
{
/*  外部函数调用声明   */
/*  输出变量   */
   VDCL_p_iintgout;                 /*俯仰积分器输出整型值                    */

/*  输入变量   */
/*  输入输出变量   */

/*definition end:io_input                               Don't remove this line*/

// 设计追踪:
// DD-CSCI-000001

    /************************/
    /***     局部变量     ***/
    /************************/

    /************************/
    /***      函数体      ***/
    /************************/

	/****************************************/
	/* 			接收本通道CLAW分区数据		*/
	/****************************************/


	/* 获取将本通道的积分器输出 */
	p_iintgout = *(int32*)(CCDL_LCLS_PTR[own_chan] + LPINTEG);

} /* END: io_input() DEFINITION. */


/******************************************************************************
 * 函数名称: io_output  -  数据输出
 *
 * 摘    要:
 *
 * 输入参数:
 *    void : 无
 *
 * 返 回 值:
 *     无
 *
 * 宏 说 明:
 *     无  
 *
 *****************************************************************************/
/*definition begin:io_output                         Don't remove this line*/
FTYP_io_output                           /**/
{
/*  外部函数调用声明   */
/*  输出变量   */
   VDCL_ads_scsflg_isr;     

/*  输入变量   */
/*  输入输出变量   */

/*definition end:io_output                           Don't remove this line*/

// 设计追踪:
// DD-CSCI-000001

    /************************/
    /***     局部变量     ***/
    /************************/
	word32	i;	

    /************************/
    /***      函数体      ***/
    /************************/
    i = 0;
	ads_scsflg_isr = TRUE;

	/****************************************/
	/* 		  		计算软件VPC				*/
	/****************************************/

} /* END: io_output() DEFINITION. */


