#ifndef SYSTASKROM_VDCL_H_
#define SYSTASKROM_VDCL_H_
#define  VTYP_SYS_NUM_TASKS(x)   int16 const    x[]
#define  VDCL_SYS_NUM_TASKS    extern   VTYP_SYS_NUM_TASKS(SYS_NUM_TASKS)

#define  VTYP_TASK_PTR_LIST(x)   sys_task_rec const    x[NUM_RG_TASK][MAX_NUM_TASK]
#define  VDCL_TASK_PTR_LIST    extern   VTYP_TASK_PTR_LIST(TASK_PTR_LIST)

#endif /*SYSTASKROM_VDCL_H_*/
