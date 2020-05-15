#include "vmsnconst.h"
#include "vmsntype.h"
#include "consttype.h"
#include "sig.h"
#include "simsig.h"
#include "flrconst.h"
#include "ccdlconst.h"
#include "const.h"
#include "flrconst.h"
#include "bittype.h"
#include "vmtype.h"
#include "vsepFaultLog.h"









/* header definition begin                   Don't remove this line*/ 
#include "vdcl\ram.vdcl.h"
#include "vdcl\vmsn_io_ram.vdcl.h"
#include "vdcl\busdatarom.vdcl.h"
#include "vdcl\sysram.vdcl.h"
#include "vdcl\flr_nvm.vdcl.h"
#include "vdcl\claw_fcrm_ram.vdcl.h"
#include "vdcl\fcrm_claw_ram.vdcl.h"
#include "vdcl\fcrm_nvm_ram.vdcl.h"

/* header definition end                   Don't remove this line*/ 
/* declaration  begin                  Don't remove this line */ 
VDCL_acon_ccdl_status;           /*辅助控制器数据CCDL有效状态               */
VDCL_ads_ccdl_status;        /*大气数据CCDL有效状态                  */
VDCL_ads_scsflg_isr;
VDCL_ccdl_buf;        /*总线数据缓冲区                       */
VDCL_etcl_ccdl_status;        /*ETCL数据CCDL有效状态                */
VDCL_etcr_ccdl_status;        /*ETCR数据CCDL有效状态                */
VDCL_FCRM_ACON;
VDCL_FCRM_ADS;
VDCL_FCRM_ETCL;
VDCL_FCRM_ETCR;
VDCL_FCRM_INS;
VDCL_FCRM_ISACB;
VDCL_FCRM_ISACF;
VDCL_FCRM_ISR;
VDCL_FCRM_MB_AMFD;
VDCL_FCRM_MB_DMP;
VDCL_FCRM_PIU;
VDCL_FCRM_PMA;
VDCL_fcrm_sys_ccount;        /*FCRM分区内的系统计数器值                */
VDCL_FCRM_VPU;
VDCL_flr_nvm_fcrm;
VDCL_ins_ccdl_status;        /*惯导数据CCDL有效状态                  */
VDCL_isacb_ccdl_status;        /*后作动器控制器数据CCDL有效状态             */
VDCL_isacf_ccdl_status;        /*前作动器控制器数据CCDL有效状态             */
VDCL_miptr;        /*俯仰配平指令                        */
VDCL_mirtr;        /*横向配平指令                        */
VDCL_miytr;        /*航向配平指令                        */
VDCL_mo_cl_rcf2;        /*控制律重构字2                       */
VDCL_mo_cl_rcnf;        /*控制律重构字1                       */
VDCL_piu_ccdl_status;        /*PIU数据CCDL有效状态                 */
VDCL_v_iaq;        /*俯仰速率表决值                       */
VDCL_v_vdltwowsw;        /*左轮载开关                         */
VDCL_vpu_ccdl_status;        /*VPU数据CCDL有效状态                 */

/* declaration  end                  Don't remove this line */ 




bus_pkg_element const FCRM_ACON[3] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&v_iady                                                     ,  32,  0,  0, 2, 0},
{(word16 *)&v_ianx                                                     ,  64,  0,  0, 2, 0}};

bus_pkg_element const FCRM_ADS[59] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word32 *)&mo_cl_rcnf                                                 , 188,  1, APS_RBIT, 0, 0}};

bus_pkg_element const FCRM_ETCL[4] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&mbt_etcl_ram.pl_start                                      ,  32,  6,  0, 0, 2},
{(word16 *)&mbt_etcl_ram.pb_start                                      ,  32,  4,  0, 0, 2},
{(word16 *)&mbt_etcl_ram.nvm_clr                                       ,  32,  3,  0, 0, 2}};

bus_pkg_element const FCRM_ETCR[4] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&mbt_etcr_ram.nvm_clr                                       ,  32,  3,  0, 0, 2},
{(word16 *)&mbt_etcr_ram.pb_start                                      ,  32,  4,  0, 0, 2},
{(word16 *)&mbt_etcr_ram.pl_start                                      ,  32,  6,  0, 0, 2}};

bus_pkg_element const FCRM_INS[35] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word32 *)&io_ads_status                                              ,  36,  0,  0, 3, 0},
{(word16 *)&ccdl_buf[CCDL_ADS+ACALASPEST]                              , 126,  0,  0, 5, 0},
{(word16 *)&ccdl_buf[CCDL_ADS+AESTVT_CONF2]                            , 128,  0,  0, 5, 0}};

bus_pkg_element const FCRM_ISACB[9] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&ccdl_buf[CCDL_A_SIM1+SCF_DBG_PBT_ETCL_NVM_CLR_OFF]         ,  32, 27,  0, 4, 0}};

bus_pkg_element const FCRM_ISACF[9] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&ccdl_buf[CCDL_A_SIM1+SCF_DBG_PBT_ETCL_NVM_CLR_OFF]         ,  32, 21,  0, 4, 0}};

bus_pkg_element const FCRM_ISR[386] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&acid3_valid                                                , 468,  3,  0, 0, 2},
{(word16 *)&acid2_valid                                                , 468,  4,  0, 0, 2},
{(word16 *)&acid1_valid                                                , 468,  5,  0, 0, 2}};

bus_pkg_element const FCRM_MB_AMFD[89] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word32 *)&mmlf9                                                      , 152,  0,  0, 3, 0},
{(word32 *)&mmlf10                                                     , 156,  0,  0, 3, 0}};

bus_pkg_element const FCRM_MB_DMP[101] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&v_iinsalt                                                  , 224,  0,  0, 2, 0},
{(word16 *)&ins_mapwrd_vld                                             , 226,  0,  0, 2, 0}};

bus_pkg_element const FCRM_PIU[4] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&mbt_piu_ram.nvm_clr                                        ,  32,  4,  0, 0, 2},
{(word16 *)&mbt_piu_ram.pl_start                                       ,  32,  5,  0, 0, 2},
{(word16 *)&mbt_piu_ram.pb_start                                       ,  32,  7,  0, 0, 2}};

bus_pkg_element const FCRM_PMA[117] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word32 *)&mo_cl_rcnf                                                 , 204,  0,  0, 3, 0},
{(word32 *)&mo_cl_rcf2                                                 , 208,  0,  0, 3, 0}};

bus_pkg_element const FCRM_VPU[7] = {
{(word32 *)&fcrm_sys_ccount                                            ,  28,  0,  0, 3, 0},
{(word16 *)&v_vdfwowsw                                                 ,  32,  0,  0, 2, 0},
{(word16 *)&v_vdltwowsw                                                ,  34,  0,  0, 2, 0},
{(word16 *)&v_vdrtwowsw                                                ,  36,  0,  0, 2, 0},
{(word16 *)&mbt_vpu_ram.nvm_clr                                        ,  38,  0,  0, 2, 0},
{(word32 *)&vpu_ctl                                                    ,  40,  0,  0, 3, 0},
{(word16 *)&mbt_vpu_reset_cmd                                          ,  46,  0,  0, 2, 0}};


bus_pkg_element* const totalbuspkg[13] = { 
    (bus_pkg_element*)FCRM_ACON, 
    (bus_pkg_element*)FCRM_ADS, 
    (bus_pkg_element*)FCRM_ETCL, 
    (bus_pkg_element*)FCRM_ETCR, 
    (bus_pkg_element*)FCRM_INS, 

    (bus_pkg_element*)FCRM_ISACB, 
    (bus_pkg_element*)FCRM_ISACF, 
    (bus_pkg_element*)FCRM_ISR, 
    (bus_pkg_element*)FCRM_MB_AMFD, 
    (bus_pkg_element*)FCRM_MB_DMP, 

    (bus_pkg_element*)FCRM_PIU, 
    (bus_pkg_element*)FCRM_PMA, 
    (bus_pkg_element*)FCRM_VPU };

int const totalbuspkgnum[13] = { 
52, 59, 4, 4, 35, 
9, 9, 386, 89, 101, 
4, 117, 7 };

word16* const totalbuspkgdesaddr[13] = { 
    (word16 *)&ccdl_buf[CC_FCRM_OUT_ACON],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_ADS],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_ETCL],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_ETCR],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_INS],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_ISACB],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_ISACF],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_ISR],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_AMFD],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_DMP],

    (word16 *)&ccdl_buf[CC_FCRM_OUT_PIU],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_PMA],
    (word16 *)&ccdl_buf[CC_FCRM_OUT_VPU]};
