
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
void copytonvm(void)                                   /*this_is_a_function*/
{
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
void copyfromnvm(void)                                   /*this_is_a_function*/
{
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


/*  nvmtoram end   Don't remove this line. */

}


