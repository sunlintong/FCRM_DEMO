// file vmstram.c

/************************************************************/
/************************************************************/
//Modifications：
//

#include "vmkTypes.h"
#include "consttype.h"
#include "vmtype.h"

/*  declaration begin:                              Don't remove this line. */
/*  declaration end:                              	Don't remove this line. */

			/************************************/
			/*        本通道离散输入RAM结构      */
			/************************************/
	
	vm_ram_rec	dltwowsw_ram;		/*	左轮载开关				*/
	vm_ram_rec 	aq_ram;				/*	俯仰速率					*/


			/************************************/
			/*		信号是否可复位						*/
			/************************************/	
	word16		aq_rcv_sw;				/* 重构不可复位 */
	word16		dltwowsw_rcv_sw;		/* 重构不可复位 */

