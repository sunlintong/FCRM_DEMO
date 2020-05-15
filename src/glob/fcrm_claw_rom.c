//
// MODIFICATIONS:
//


#include <ssm.h>
#include "consttype.h"
#include "ioconst.h"
#include "const.h"
#include "Vmsnconst.h"



/*header definition begin            Don't remove this line*/
/*header definition end               Don't remove this line*/
/* declaration  begin                 Don't remove this line */
/* declaration  end                  Don't remove this line */

		/*--------------------------------------------------*/
		/*		中间层32位传送(余度到控制律)	*/
		/*--------------------------------------------------*/

    /*FCRM_CLAW_RAM32_LST[] 数组元素个数与FCRM_CLAW_LEN32值相等  */
	word32 *const FCRM_CLAW_RAM32_LST[] = 
	{
		(word32 *)&mo_cl_rcnf,				/*	控制律重构字1						*/
		(word32 *)&mo_cl_rcf2,				/*	控制律重构字2						*/
		(word32 *)&eq_ipequal,				/*	单拍均衡输出						*/
 				  NULL,
				  NULL,
				  NULL,
				  NULL,
				  NULL,
				  NULL
	};




		/*--------------------------------------------------*/
		/*		中间层16位传送(余度到控制律)	*/
		/*--------------------------------------------------*/



word16 *const FCRM_CLAW_RAM16_LST[] = 
{
(word16 *)&rcnf_scsflg,				/*	SCO flag							*/
(word16 *)&at_thrslow_lset,			/* 左油门台慢车PIU指令 */
(word16 *)&at_thrmax_lset,			/* 左油门台最大PIU指令 */
(word16 *)&at_thrslow_rset,			/* 右油门台慢车PIU指令 */
(word16 *)&at_thrmax_rset,			/* 右油门台最大PIU指令 */
(word16 *)&at_thr_cab,				/* 油门标定系数获取成功标志 */
NULL
};
