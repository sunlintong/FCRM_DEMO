#ifndef VMSTRAM_VDCL_H_
#define VMSTRAM_VDCL_H_
#define  VTYP_aq_ram(x)   vm_ram_rec    x
#define  VDCL_aq_ram    extern   VTYP_aq_ram(aq_ram)

#define  VTYP_aq_rcv_sw(x)   word16    x
#define  VDCL_aq_rcv_sw    extern   VTYP_aq_rcv_sw(aq_rcv_sw)

#define  VTYP_dltwowsw_ram(x)   vm_ram_rec    x
#define  VDCL_dltwowsw_ram    extern   VTYP_dltwowsw_ram(dltwowsw_ram)

#define  VTYP_dltwowsw_rcv_sw(x)   word16    x
#define  VDCL_dltwowsw_rcv_sw    extern   VTYP_dltwowsw_rcv_sw(dltwowsw_rcv_sw)

#endif /*VMSTRAM_VDCL_H_*/
