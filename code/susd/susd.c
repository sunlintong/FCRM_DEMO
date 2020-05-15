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
 * ��������: susd_startup  -  ����
 *
 * ժ    Ҫ:
 *     ���������
 *
 *
 * �������:
 *    void : ��
 *
 * �� �� ֵ:
 *     ��
 *
 * �� ˵ ��:
 *     <macroName>  -  <�ڴ˴����Ӻ�����...>
 *
 *****************************************************************************/
/*definition begin:susd_startup                         Don't remove this line*/
FTYP_susd_startup                           /**/
{
/*  �ⲿ������������   */
   FDCL_susd_gr_start;
   FDCL_sys_init;
/*  �������   */
/*  �������   */
/*  �����������   */

/*definition end:susd_startup                           Don't remove this line*/

// ���׷��:
// DD-CSCI-000001
	
    /************************/
    /***     �ֲ�����     ***/
    /************************/  
     word32 msg_label;
	 int32	i;
    /************************/
    /***      ������      ***/
    /************************/

	// ���Ӧ��������־
	susd_emer_flg = 0;

	susd_air_gnd = ON_GROUND;
	/* Call Ground Startup procedure                                    */
    susd_gr_start();

    sys_init() ;
    
} /* END: susd_startup() DEFINITION. */


/******************************************************************************
 * ��������: susd_gr_start  -  ��������
 *
 * ժ    Ҫ:
 *     �����е�������е����ʼ����
 *
 *
 * �������:
 *    void : ��
 *
 * �� �� ֵ:
 *     ��
 *
 * �� ˵ ��:
 *     <macroName>  -  <�ڴ˴����Ӻ�����...>
 *
 *****************************************************************************/
/*definition begin:susd_gr_start                        Don't remove this line*/
FTYP_susd_gr_start                           /**/
{
/*  �ⲿ������������   */
/*  �������   */
   VDCL_dltwowsw_ram;               /*�����ؿ���                         */

   VDCL_LOC_DIS_INP_LST;    

   VDCL_mbt_datasaved_wrd;          /*ά��ģʽ�˳��󣬱������͵���Ϣ�ı�־��Ϊ����        */

/*  �������   */
/*  �����������   */

/*definition end:susd_gr_start						Don't remove this line*/

// ���׷��:
// DD-CSCI-000001

    /************************/
    /***     �������     ***/
    /************************/
    
    /************************/
    /***     �ֲ�����     ***/
    /************************/   
	int16 i;
	vm_rom_rec const *rom_ptr;       /* pointer to ROM record                */
	vm_ram_rec *ram_ptr;       /* pointer to RAM record                */


	/************************/
    /***      ������      ***/
    /************************/
	mbt_datasaved_wrd = 0x3861;
	dltwowsw_ram.hb_status = 0xF;

		      
	/* ��ֹVMC�Բ���ɢ���������*/
	while ((rom_ptr = LOC_DIS_INP_LST[i]) NE NULL)
	{
    	ram_ptr = rom_ptr->ram_rec;
    	ram_ptr->mon_sup = TRUE;
		i++;
	}

} /* END: susd_gr_start() DEFINITION. */

                                                                 
/****************************************************************************/
/******************************************************************************
 * ��������: susd_air_start
 *
 * ժ    Ҫ:
 *
 *
 * �������:
 *    void : ��
 *
 * �� �� ֵ:
 *     ��
 *
 * �� ˵ ��:
 *     <macroName>  -  <�ڴ˴����Ӻ�����...>
 *
 *****************************************************************************/
/*definition begin:susd_air_start                       Don't remove this line*/
FTYP_susd_air_start                           /**/
{
/*  �ⲿ������������   */
/*  �������   */
/*  �������   */
/*  �����������   */

/*definition end:susd_air_start                         Don't remove this line*/

// ���׷��:
// DD-CSCI-000001


} /* END: susd_air_start() DEFINITION. */

/******************************************************************************
 * ��������: susd_complet
 *
 * ժ    Ҫ:
 *
 *
 * �������:
 *    void : ��
 *
 * �� �� ֵ:
 *     ��
 *
 * �� ˵ ��:
 *     <macroName>  -  <�ڴ˴����Ӻ�����...>
 *
 *****************************************************************************/
/*definition begin:susd_complet                         Don't remove this line*/
FTYP_susd_complet                           /**/
{
/*  �ⲿ������������   */
/*  �������   */
/*  �������   */
/*  �����������   */

/*definition end:susd_complet 						Don't remove this line*/

// ���׷��:
// DD-CSCI-000001

    /************************/
    /***     �ֲ�����     ***/
    /************************/   
    
} /* END: susd_complet() DEFINITION. */

