
#include "consttype.h"
#include "const.h"

/*  declaration begin:                              Don't remove this line. */
/*  declaration end:                              	Don't remove this line. */


/*----------------------------*/
/*		32位传送		  */
/*----------------------------*/

int32	p_iintgout; 				/*	俯仰积分器输出整型值				*/


/*----------------------------*/
/*		16位传送		  */
/*----------------------------*/

	  
int16	out_cmd_lst[OUT_CMD_NUM];	/*	输出指令缓冲区						*/
/*------高/低液压模态切换控制指令-----*/
int16	miptr;						/*	俯仰配平指令						*/	
int16	mirtr;						/*	横向配平指令						*/
int16	miytr;						/*	航向配平指令						*/
/*------音响告警状态信息-----*/

