#ifndef VMSTROM_VDCL_H_
#define VMSTROM_VDCL_H_
#define  VTYP_AQ_ROM(x)   vm_rom_rec const    x
#define  VDCL_AQ_ROM    extern   VTYP_AQ_ROM(AQ_ROM)

#define  VTYP_DLTWOWSW_ROM(x)   vm_rom_rec const    x
#define  VDCL_DLTWOWSW_ROM    extern   VTYP_DLTWOWSW_ROM(DLTWOWSW_ROM)

#define  VTYP_LOC_DIS_INP_LST(x)   vm_rom_rec const  *const    x[]
#define  VDCL_LOC_DIS_INP_LST    extern   VTYP_LOC_DIS_INP_LST(LOC_DIS_INP_LST)

#define  VTYP_MO_PIU_SIG_LST(x)   vm_rom_rec const	*const    x[]
#define  VDCL_MO_PIU_SIG_LST    extern   VTYP_MO_PIU_SIG_LST(MO_PIU_SIG_LST)

#endif /*VMSTROM_VDCL_H_*/
