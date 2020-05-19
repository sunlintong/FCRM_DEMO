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
		/*		�м��32λ����(��ȵ�������)	*/
		/*--------------------------------------------------*/

    /*FCRM_CLAW_RAM32_LST[] ����Ԫ�ظ�����FCRM_CLAW_LEN32ֵ���  */
	word32 *const FCRM_CLAW_RAM32_LST[] = 
	{
		(word32 *)&mo_cl_rcnf,				/*	�������ع���1						*/
		(word32 *)&mo_cl_rcf2,				/*	�������ع���2						*/
		(word32 *)&eq_ipequal,				/*	���ľ������						*/
 				  NULL,
				  NULL,
				  NULL,
				  NULL,
				  NULL,
				  NULL
	};




		/*--------------------------------------------------*/
		/*		�м��16λ����(��ȵ�������)	*/
		/*--------------------------------------------------*/



word16 *const FCRM_CLAW_RAM16_LST[] = 
{
(word16 *)&rcnf_scsflg,				/*	SCO flag							*/
(word16 *)&at_thrslow_lset,			/* ������̨����PIUָ�� */
(word16 *)&at_thrmax_lset,			/* ������̨���PIUָ�� */
(word16 *)&at_thrslow_rset,			/* ������̨����PIUָ�� */
(word16 *)&at_thrmax_rset,			/* ������̨���PIUָ�� */
(word16 *)&at_thr_cab,				/* ���ű궨ϵ����ȡ�ɹ���־ */
NULL
};
