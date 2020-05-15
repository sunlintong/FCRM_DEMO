#ifndef VM_MSG_RAM_VDCL_H_
#define VM_MSG_RAM_VDCL_H_
#define  VTYP_fcrm_claw_buf(x)   int16    x[FCRM_CLAW_MSG_LEN]
#define  VDCL_fcrm_claw_buf    extern   VTYP_fcrm_claw_buf(fcrm_claw_buf)

#define  VTYP_fcrm_sim_buf(x)   int16    x[FCRM_SIM_MSG_LEN]
#define  VDCL_fcrm_sim_buf    extern   VTYP_fcrm_sim_buf(fcrm_sim_buf)

#endif /*VM_MSG_RAM_VDCL_H_*/
