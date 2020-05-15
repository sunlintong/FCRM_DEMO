              /*--------------------------------------*/
              /*       Include files directives       */
              /*--------------------------------------*/
#include <ssm.h>
#include "const.h"
#include "consttype.h"
#include "macro.h"
#include "sig.h"
#include "flr.h"
#include "splvmconst.h"
#include "sysconst.h"
#include "susdconst.h"
#include "systask.h"
#include "systype.h"
#include "vmsntype.h"
#include "vmtype.h"
#include "vmsnconst.h"
#include "vmsnmoconst.h"
#include "ioconst.h"
#include "anavmconst.h"
#include "insvmconst.h"
#include "bitconst.h"
#include "flrtype.h"
#include "flrconst.h"
#include "vsepFaultLog.h"
#include "ccdlconst.h"



/* header definition begin                   Don't remove this line*/
#include "fdcl/susd.fdcl.h"
#include "vdcl/vmstram.vdcl.h"
#include "vdcl/vmstrom.vdcl.h"
#include "vdcl/savedram.vdcl.h"
#include "fdcl/sys.fdcl.h"

/* header definition end                     Don't remove this line*/

/******************************************************************************
 * 函数名称: susd_startup  -  启动
 *
 * 摘    要:
 *     组合启动。
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
/*definition begin:susd_startup                         Don't remove this line*/
FTYP_susd_startup                           /**/
{
/*  外部函数调用声明   */
   FDCL_susd_gr_start;
   FDCL_sys_init;
/*  输出变量   */
/*  输入变量   */
/*  输入输出变量   */

/*definition end:susd_startup                           Don't remove this line*/

// 设计追踪:
// DD-CSCI-000001
	
    /************************/
    /***     局部变量     ***/
    /************************/  
     word32 msg_label;
	 int32	i;
    /************************/
    /***      函数体      ***/
    /************************/

	// 清除应急启动标志
	susd_emer_flg = 0;

	susd_air_gnd = ON_GROUND;
	/* Call Ground Startup procedure                                    */
    susd_gr_start();

    sys_init() ;
    
} /* END: susd_startup() DEFINITION. */


/******************************************************************************
 * 函数名称: susd_gr_start  -  地面启动
 *
 * 摘    要:
 *     对所有的任务进行地面初始化；
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
/*definition begin:susd_gr_start                        Don't remove this line*/
FTYP_susd_gr_start                           /**/
{
/*  外部函数调用声明   */
/*  输出变量   */
   VDCL_dltwowsw_ram;               /*左轮载开关                         */

   VDCL_LOC_DIS_INP_LST;    

   VDCL_mbt_datasaved_wrd;          /*维护模式退出后，保留构型等信息的标志，为特殊        */

/*  输入变量   */
/*  输入输出变量   */

/*definition end:susd_gr_start						Don't remove this line*/

// 设计追踪:
// DD-CSCI-000001

    /************************/
    /***     输入变量     ***/
    /************************/
    
    /************************/
    /***     局部变量     ***/
    /************************/   
	int16 i;
	vm_rom_rec const *rom_ptr;       /* pointer to ROM record                */
	vm_ram_rec *ram_ptr;       /* pointer to RAM record                */


	/************************/
    /***      函数体      ***/
    /************************/
	mbt_datasaved_wrd = 0x3861;
	dltwowsw_ram.hb_status = 0xF;

		      
	/* 禁止VMC自采离散输入表决监控*/
	while ((rom_ptr = LOC_DIS_INP_LST[i]) NE NULL)
	{
    	ram_ptr = rom_ptr->ram_rec;
    	ram_ptr->mon_sup = TRUE;
		i++;
	}

} /* END: susd_gr_start() DEFINITION. */

                                                                 
/****************************************************************************/
/******************************************************************************
 * 函数名称: susd_air_start
 *
 * 摘    要:
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
/*definition begin:susd_air_start                       Don't remove this line*/
FTYP_susd_air_start                           /**/
{
/*  外部函数调用声明   */
/*  输出变量   */
/*  输入变量   */
/*  输入输出变量   */

/*definition end:susd_air_start                         Don't remove this line*/

// 设计追踪:
// DD-CSCI-000001


} /* END: susd_air_start() DEFINITION. */

/******************************************************************************
 * 函数名称: susd_complet
 *
 * 摘    要:
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
/*definition begin:susd_complet                         Don't remove this line*/
FTYP_susd_complet                           /**/
{
/*  外部函数调用声明   */
/*  输出变量   */
/*  输入变量   */
/*  输入输出变量   */

/*definition end:susd_complet 						Don't remove this line*/

// 设计追踪:
// DD-CSCI-000001

    /************************/
    /***     局部变量     ***/
    /************************/   
    
} /* END: susd_complet() DEFINITION. */

