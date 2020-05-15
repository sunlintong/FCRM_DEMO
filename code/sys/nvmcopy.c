
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
 * ��������: copytonvm - ��RAM����������NVM
 *
 * ժ    Ҫ:
 *    ��̨�������
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
/*definition begin:copytonvm                         Don't remove this line*/
FTYP_copytonvm                           /**/
{
/*  �ⲿ������������   */
/*  �������   */
   VDCL_axes_data_err;              /*�����ź�״̬ piu_data_err & gyro_status*/

   VDCL_axes_data_err_nvm;          /*�����ź�״̬ piu_data_err & gyro_status*/

   VDCL_eq_ipequal;                 /*���ľ������                        */

   VDCL_eq_ipequal_nvm;             /*���ľ������                        */

   VDCL_mo_cl_rcf2;                 /*�������ع���2                       */

   VDCL_mo_cl_rcf2_nvm;             /*�������ع���2                       */

   VDCL_mo_cl_rcnf;                 /*�������ع���1                       */

   VDCL_mo_cl_rcnf_nvm;             /*�������ع���1                       */

   VDCL_v_iaq;                      /*�������ʱ��ֵ                       */

   VDCL_v_iaq_nvm;                  /*�������ʱ��ֵ                       */

   VDCL_v_vdltwowsw;                /*�����ؿ���                         */

   VDCL_v_vdltwowsw_nvm;            /*�����ؿ���                         */

/*  �������   */
/*  �����������   */

/*definition end:copytonvm                           Don't remove this line*/

	/************************/
    /***     �ֲ�����     ***/
    /************************/
	
    /************************/
    /***      ������      ***/
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
 * ��������: copyfromnvm - ��NVM����������RAM
 *
 * ժ    Ҫ:
 *    ��ʼ��ʱ���á�
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
/*definition begin:copyfromnvm                         Don't remove this line*/
FTYP_copyfromnvm                           /**/
{
/*  �ⲿ������������   */
/*  �������   */
   VDCL_axes_data_err;              /*�����ź�״̬ piu_data_err & gyro_status*/

   VDCL_axes_data_err_nvm;          /*�����ź�״̬ piu_data_err & gyro_status*/

   VDCL_eq_ipequal;                 /*���ľ������                        */

   VDCL_eq_ipequal_nvm;             /*���ľ������                        */

   VDCL_mo_cl_rcf2;                 /*�������ع���2                       */

   VDCL_mo_cl_rcf2_nvm;             /*�������ع���2                       */

   VDCL_mo_cl_rcnf;                 /*�������ع���1                       */

   VDCL_mo_cl_rcnf_nvm;             /*�������ع���1                       */

   VDCL_v_iaq;                      /*�������ʱ��ֵ                       */

   VDCL_v_iaq_nvm;                  /*�������ʱ��ֵ                       */

   VDCL_v_vdltwowsw;                /*�����ؿ���                         */

   VDCL_v_vdltwowsw_nvm;            /*�����ؿ���                         */

/*  �������   */
/*  �����������   */

/*definition end:copyfromnvm                           Don't remove this line*/

	/************************/
    /***     �ֲ�����     ***/
    /************************/
	
    /************************/
    /***      ������      ***/
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


