#ifndef CLAW_FCRM_RAM_VDCL_H_
#define CLAW_FCRM_RAM_VDCL_H_
#define  VTYP_miptr(x)   int16    x
#define  VDCL_miptr    extern   VTYP_miptr(miptr)

#define  VTYP_mirtr(x)   int16    x
#define  VDCL_mirtr    extern   VTYP_mirtr(mirtr)

#define  VTYP_miytr(x)   int16    x
#define  VDCL_miytr    extern   VTYP_miytr(miytr)

#define  VTYP_out_cmd_lst(x)   int16    x[OUT_CMD_NUM]
#define  VDCL_out_cmd_lst    extern   VTYP_out_cmd_lst(out_cmd_lst)

#define  VTYP_p_iintgout(x)   int32    x
#define  VDCL_p_iintgout    extern   VTYP_p_iintgout(p_iintgout)

#endif /*CLAW_FCRM_RAM_VDCL_H_*/
