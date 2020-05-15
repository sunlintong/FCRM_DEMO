/* file code/inc/systask.h (created by systask.awk program from code/sys/systaskinfo) */
//
/******************************************************************************/
/******************************************************************************/
//
// MODIFICATIONS:
//


#define NUM_RG_TASK (3)					/* number of rate group */
#define MAX_NUM_TASK (2)					/* max number of task in rate group */

#define SYS_RG15_TASKS_QTY	 (2)
#define SYS_RGDYN_TASKS_QTY	 (0)
#define SYS_RGBG_TASKS_QTY	 (1)

	// The  value RTC_MINOR_SURPLUS_USEC is the surplus over the 15ms nominal
	// value that was mesured in the test lab (usec).
#define RTC_MINOR_SURPLUS_USEC  (126)

/*-------------------------------------------------------------------------*/
#define  GROUP_15_ID             (0) /* 15 ms group number                    */
#define  GROUP_DYNAMIC_ID        (1) /* Dynamic task group number             */
#define  GROUP_BG_ID             (2) /* BG      task group number             */

//15ms速率组
#define SYS_TASK_io_input_RG (0)
#define SYS_TASK_io_input_IDX (0)

#define SYS_TASK_io_output_RG (0)
#define SYS_TASK_io_output_IDX (1)

//动态速率组
//无

//后台任务
#define SYS_TASK_copytonvm_RG (0)
#define SYS_TASK_copytonvm_IDX (0)



//
//
