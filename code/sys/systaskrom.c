// file code/sys/systaskrom.c (created by bin/cre_systask shell from code/sys/systaskinfo)
//




#include "consttype.h"
#include "systype.h"
#include "systask.h"
/* header definition begin                   Don't remove this line*/
#include "fdcl\nvmcopy.fdcl.h"
#include "fdcl\io.fdcl.h"

/* header definition end                     Don't remove this line*/ 
extern void flr_copy(void);

/*  declaration begin:                              Don't remove this line. */
FDCL_copytonvm;
FDCL_io_input;
FDCL_io_output;

/*  declaration end:                              	Don't remove this line. */
int16 const    SYS_NUM_TASKS[] =
					{	SYS_RG15_TASKS_QTY,
						SYS_RGDYN_TASKS_QTY,
						SYS_RGBG_TASKS_QTY };
/* pointers to the rate groups tasks and their inhibit flags */
sys_task_rec const TASK_PTR_LIST[NUM_RG_TASK][MAX_NUM_TASK] =
{
	/* 实时任务 */
	{
	{io_input,0},        //0
	{io_output,0}        //2
	},
	/* 动态任务 */
	{
    {NULL,1},            //0
	{NULL,1},            //1
	},
	/* 后台任务 */
	{
	{copytonvm,0},       //1
	{NULL,1}             //2
	},
};

