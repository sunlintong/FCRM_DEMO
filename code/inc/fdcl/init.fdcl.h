#ifndef INIT_FDCL_H_
#define INIT_FDCL_H_
#define   FTYP_AppErrorHandler  UINT8 AppErrorHandler(UINT8 Rate,UINT8 VsepError)
#define   FTYP_AppInitialization  void AppInitialization(T_VSEP_SysInfo *sysInfo)
#define   FTYP_AppOverRun  UINT8 AppOverRun(UINT8 Rate,UINT32 SequentialOverruns)
#define   FTYP_AppTaskEntryHook  T_VOID AppTaskEntryHook(T_VOID)
#define   FTYP_AppTaskExitHook  T_VOID AppTaskExitHook(T_VOID)
#define   FTYP_main  T_WORD main(void)
#define   FTYP_partitionInit  T_VOID partitionInit(T_VOID)

#define   FDCL_AppErrorHandler   extern    FTYP_AppErrorHandler
#define   FDCL_AppInitialization   extern    FTYP_AppInitialization
#define   FDCL_AppOverRun   extern    FTYP_AppOverRun
#define   FDCL_AppTaskEntryHook   extern    FTYP_AppTaskEntryHook
#define   FDCL_AppTaskExitHook   extern    FTYP_AppTaskExitHook
#define   FDCL_main   extern    FTYP_main
#define   FDCL_partitionInit   extern    FTYP_partitionInit
#endif /*INIT_FDCL_H_*/
