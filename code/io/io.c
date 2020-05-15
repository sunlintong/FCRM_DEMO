
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
 * ��������: io_input  -  IO����
 *
 * ժ    Ҫ:
 *     ��������CCDL���źŷ��뱾ͨ����CCDL��������
 *
 *
 * �������:
 *    void : ��
 *
 * �� �� ֵ:
 *     ��
 *
 * �� ˵ ��:
 *     ��
 *
 *****************************************************************************/
/*definition begin:io_input                             Don't remove this line*/
FTYP_io_input                           /**/
{
/*  �ⲿ������������   */
/*  �������   */
   VDCL_p_iintgout;                 /*�����������������ֵ                    */

/*  �������   */
/*  �����������   */

/*definition end:io_input                               Don't remove this line*/

// ���׷��:
// DD-CSCI-000001

    /************************/
    /***     �ֲ�����     ***/
    /************************/

    /************************/
    /***      ������      ***/
    /************************/

	/****************************************/
	/* 			���ձ�ͨ��CLAW��������		*/
	/****************************************/


	/* ��ȡ����ͨ���Ļ�������� */
	p_iintgout = *(int32*)(CCDL_LCLS_PTR[own_chan] + LPINTEG);

} /* END: io_input() DEFINITION. */


/******************************************************************************
 * ��������: io_output  -  �������
 *
 * ժ    Ҫ:
 *
 * �������:
 *    void : ��
 *
 * �� �� ֵ:
 *     ��
 *
 * �� ˵ ��:
 *     ��  
 *
 *****************************************************************************/
/*definition begin:io_output                         Don't remove this line*/
FTYP_io_output                           /**/
{
/*  �ⲿ������������   */
/*  �������   */
   VDCL_ads_scsflg_isr;     

/*  �������   */
/*  �����������   */

/*definition end:io_output                           Don't remove this line*/

// ���׷��:
// DD-CSCI-000001

    /************************/
    /***     �ֲ�����     ***/
    /************************/
	word32	i;	

    /************************/
    /***      ������      ***/
    /************************/
    i = 0;
	ads_scsflg_isr = TRUE;

	/****************************************/
	/* 		  		�������VPC				*/
	/****************************************/

} /* END: io_output() DEFINITION. */


