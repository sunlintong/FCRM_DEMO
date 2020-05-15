#ifndef BUSDATAROM_VDCL_H_
#define BUSDATAROM_VDCL_H_
#define  VTYP_FCRM_ACON(x)   bus_pkg_element const    x[52]
#define  VDCL_FCRM_ACON    extern   VTYP_FCRM_ACON(FCRM_ACON)

#define  VTYP_FCRM_ADS(x)   bus_pkg_element const    x[59]
#define  VDCL_FCRM_ADS    extern   VTYP_FCRM_ADS(FCRM_ADS)

#define  VTYP_FCRM_ETCL(x)   bus_pkg_element const    x[4]
#define  VDCL_FCRM_ETCL    extern   VTYP_FCRM_ETCL(FCRM_ETCL)

#define  VTYP_FCRM_ETCR(x)   bus_pkg_element const    x[4]
#define  VDCL_FCRM_ETCR    extern   VTYP_FCRM_ETCR(FCRM_ETCR)

#define  VTYP_FCRM_INS(x)   bus_pkg_element const    x[35]
#define  VDCL_FCRM_INS    extern   VTYP_FCRM_INS(FCRM_INS)

#define  VTYP_FCRM_ISACB(x)   bus_pkg_element const    x[9]
#define  VDCL_FCRM_ISACB    extern   VTYP_FCRM_ISACB(FCRM_ISACB)

#define  VTYP_FCRM_ISACF(x)   bus_pkg_element const    x[9]
#define  VDCL_FCRM_ISACF    extern   VTYP_FCRM_ISACF(FCRM_ISACF)

#define  VTYP_FCRM_ISR(x)   bus_pkg_element const    x[386]
#define  VDCL_FCRM_ISR    extern   VTYP_FCRM_ISR(FCRM_ISR)

#define  VTYP_FCRM_MB_AMFD(x)   bus_pkg_element const    x[89]
#define  VDCL_FCRM_MB_AMFD    extern   VTYP_FCRM_MB_AMFD(FCRM_MB_AMFD)

#define  VTYP_FCRM_MB_DMP(x)   bus_pkg_element const    x[101]
#define  VDCL_FCRM_MB_DMP    extern   VTYP_FCRM_MB_DMP(FCRM_MB_DMP)

#define  VTYP_FCRM_PIU(x)   bus_pkg_element const    x[4]
#define  VDCL_FCRM_PIU    extern   VTYP_FCRM_PIU(FCRM_PIU)

#define  VTYP_FCRM_PMA(x)   bus_pkg_element const    x[117]
#define  VDCL_FCRM_PMA    extern   VTYP_FCRM_PMA(FCRM_PMA)

#define  VTYP_FCRM_VPU(x)   bus_pkg_element const    x[7]
#define  VDCL_FCRM_VPU    extern   VTYP_FCRM_VPU(FCRM_VPU)

#define  VTYP_totalbuspkg(x)   bus_pkg_element* const    x[13]
#define  VDCL_totalbuspkg    extern   VTYP_totalbuspkg(totalbuspkg)

#define  VTYP_totalbuspkgdesaddr(x)   word16* const    x[13]
#define  VDCL_totalbuspkgdesaddr    extern   VTYP_totalbuspkgdesaddr(totalbuspkgdesaddr)

#define  VTYP_totalbuspkgnum(x)   int const    x[13]
#define  VDCL_totalbuspkgnum    extern   VTYP_totalbuspkgnum(totalbuspkgnum)

#endif /*BUSDATAROM_VDCL_H_*/
