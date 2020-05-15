/* file fcrmrom.c     */
/************************************************************/
/************************************************************/
/*Copyright (c) 2012, Chengdu Aircraft Design&Research Institute */
//All rights reserved.
//
//File Name：fcrmrom.c
//File ID：VMC_101_SDTD_2 (任务书)
//Description：This package contains ROM variables definition for FCRM partition.
//
//Code By:Z.Y 
//Data：2012-5-10 
/************************************************************/
/************************************************************/
//Modifications：
//
//A06-0001	2015-04-23	N.Q.
//			修改复位类型ROM
//A01-0001	2014-04-17	N.Q.
//			VM_ELEM_TYPE[]中增加轮速复位类型ANA_REC
//

#include <ssm.h>
#include "consttype.h"
#include "vmsnconst.h"
#include "const.h"
/* header definition begin                   Don't remove this line*/

/* header definition end                     Don't remove this line*/ 

/* declaration  begin                  Don't remove this line */ 

/* declaration  end                  Don't remove this line */ 

              /********************************/
              /*  COMMON  ROM  CONSTANTS      */
              /********************************/

              /* number of set bits in the nibble */

	/* 信号状态和通道ID的对应关系 */
 word16 const CH_ID_REL[]	= { 
 		CH_NO_DEF,			/* signal_status = 0000 */
		CH_A_ID, 			/* signal_status = 0001 */
		CH_B_ID, 			/* signal_status = 0010 */
		CH_NO_DEF, 			/* signal_status = 0011 */
		CH_C_ID, 			/* signal_status = 0100 */
		CH_NO_DEF, 			/* signal_status = 0101 */
		CH_NO_DEF, 			/* signal_status = 0110 */
		CH_NO_DEF, 			/* signal_status = 0111 */
		CH_D_ID, 			/* signal_status = 1000 */
		CH_NO_DEF, 			/* signal_status = 1001 */
		CH_NO_DEF, 			/* signal_status = 1010 */
		CH_NO_DEF, 			/* signal_status = 1011 */
		CH_NO_DEF, 			/* signal_status = 1100 */
		CH_NO_DEF, 			/* signal_status = 1101 */
		CH_NO_DEF, 			/* signal_status = 1110 */
		CH_NO_DEF, 			/* signal_status = 1111 */
	 };

	word16 const AL_ID_REL[] = {
		CH_A_ID,			/* CH A */
		CH_C_ID				/* CH C */
	};
              /*********************************/
              /* CCDL buffers for the channels */
              /*********************************/


