//
// MODIFICATIONS:
//
//A06-0001	2015-04-17	J.J.S.
//			修改惯导RAM结构体vm_ins_ram_rec。
//

#include "consttype.h"
#include "vmsntype.h"
#include "insvmconst.h"

#ifndef VMTYPE_H_
#define VMTYPE_H_

               /* 模拟/离散表决监控RAM记录类型 */

typedef struct {
        word16		valid_signals;   /* number of current valid signals       */ 
        word16		signal_status;   /* signals status 4 bits, lsb is ch_A    */
		word16		hb_status;		 /* 信号对应RN的心跳状态 				  */
		word16		sensor_status;	 /* 信号传感器状态，由多余度比较得到	  */
        boolean		vot_sup;         /* voting suppress flag                  */
        boolean		mon_sup;         /* monitoring suppress flag              */
        word16		sig_ch_ind[4];   /* indexes of signal channels            */
        word16		sig_ch_cnt[4];   /* failure counters for the signals      */
/*ana*/ int16		tolerance;       /* tolerance                             */
        int16		voted;           /* voted value                           */
               } vm_ram_rec;

               /* 模拟/离散表决监控ROM记录类型 */
typedef struct {
        vm_ram_rec *ram_rec;     /* pointer to the RAM record             */
                                 /* for output commands - address of      */
                                 /* output command from Control Laws      */
        word16	*data_err;		 /* 总线数据有效字						  */
        word16  *ccdl_status;	 /* CCDL有效状态							  */
        int16   *ivot_dest;      /* NVM address for the integer voted     */
                                 /* value                                 */
        int16   *sig_ch_ptr[4];  /* pointers to channel din/ain/aout word */
        word16    din_bit;         /* bit number in din word for discrete   */
                                 /* element or for ILM discrete of analog */
                                 /* element                               */
/*ana*/ word16  ilm_num;         /* ILM din number in the CCDL buffer     */
        word16  mo_flr_code;     /* failure code                          */
/*ana*/ word16  mo_flr_code_tl;  /* failure code for MAX/MIN tol. failure */
        word16    reconf_bit;      /* bit nmb. in CL reconfiguration dword  */
        word16    pers;            /* persistence                           */
        boolean val_rep_wnm;     /* flag for report of signal values      */
        word16    chan_involv;     /* nibble of chan. sampling this signal  */
        word16    fs_code;         /* kind of fail safe value               */
        word16    fs_num_sig;      /* minimum of valid chan. before reconf. */
        int16   fs_val;          /* fail safe value                       */
		word16	*sw_type;		 /* 开关类型:RCV_DISABLE 不可复位；RCV_ENABLE 可复位      */
	} vm_rom_rec;

					   //--------------------
					   // 惯导RAM结构体
					   //--------------------
			   
typedef struct {
		boolean	mon_sup;			// 监控禁止标志
		word16	sig_status;			// 惯导信号有效状态，第0位代表INS1，第1位代表INS2
		word16	err_status;			// 惯导信号报故状态，第0位代表INS1，第1位代表INS2
		word16	ins_ms_vs;			// 惯导信号状态前拍值
		word16	flr_cnt[2];			// 惯导数据有效性监控计数器
		word16	flr_tol_cnt;		// 惯导数据三轴信号比较监控计数器
		int16	voted[2];			// 表决值
		int16	tolerance;			// 监控容限
	} vm_ins_ram_rec;
			   
						//--------------------
						// 惯导ROM结构体
						//--------------------
			   
typedef struct {
		vm_ins_ram_rec	*ram_rec;	// 指向RAM结构体的指针
		int16	*ival_ins[2];		// [0]:惯导1的整型值
									// [1]:惯导2的整型值
		int16	*ivot_dest;			// 三轴 (对应RSA信号表决值); 导航 (控制律要用的表决值)
		word16	*valid_dest;		// 有效性
		int16	*sig_ch_ptr[4];		// CCDL字指针
		word16	ilm_bit;			// ILM信号位定义
		word16	ilm_num;			// ILM信号字定义
		word16	flr_code;			// 惯导信号无效故障码
		word16	flr_pers;			// 惯导超差监控容限
		word16	flr_tolerance;	    // 比较监控容限
	} vm_ins_rom_rec;


				/* 组合4+2余度信号RAM记录类型 */
typedef struct {
		boolean vot_sup;
		boolean mon_sup;
		word16	signal_status;
		word16	valid_signals;
		word16	val_rsa_ch;
		word16	sig_ch_ind[3];
		word16	sig_ch_cnt[INS_NUM + 1];// 惯导数据(0、1)与RSA(2)超限计数器
		int16   sig_ch_val[3];			// [0]:ins1; [1]:ins2; [2]:rsa;
		int16	voted_val;
		word16	ms_vs;					// 信号状态前拍值，第0位代表INS1，第1位代表INS2，第2位代表RSA
		} vm_axes_ram_rec;
							  

			   /* 组合4+2余度信号ROM记录类型 */
typedef struct {
		vm_axes_ram_rec			*ram_rec;
		vm_rom_rec const		*rsa_rom;
		vm_ins_rom_rec const	*ins_rom;
		int16					*hi_rate_flg;  // 大速率标志
		float	sig_fctr;					// 转换因子
		float	sig_bias;					// 偏置
		float	sig_lim;					// 限幅
		float	vo_tolerance;				// 表决容限
		float	tol_radix;					// 表决容限计算基数
		float	tol_dvsr;					// 表决容限计算约数
		word16	pers;						// 超限拍数
		word16	rcnf_bit;					// 重构位
		word16  fs_num_sig;					// 重构前最小信号数(仅用于RSA/INS混合信号，禁止用于其他逻辑)
		boolean	sel_flag;					// 选择逻辑标志 - TRUE:执行选择逻辑，FALSE:不执行
		int16	hi_rate_pmax;				// 大速率标志判断容限：正向最大 positive_max
		int16   hi_rate_nmax;				// 大速率标志判断容限：负向最大 negative_max
		int16   hi_rate_pmin;				// 大速率标志判断容限：正向最小 positive_min
		int16	hi_rate_nmin;				// 大速率标志判断容限：负向最大 negative_min
	   } vm_axes_rom_rec;

                //--------------------
                // ETC/ISAC开关RAM结构体
                //--------------------

typedef struct {
    boolean		vot_sup;            	// 表决禁止标志
    boolean		mon_sup;            	// 监控禁止标志
    word16		valid_signals_ch[4];   	// 有效信号个数，[0]代表连接到ISAC成品的A通道的开关
    word16		signal_status_ch[4];   	// 信号有效状态，[0]代表连接到ISAC成品的A通道的开关，
                                		//               第0位代表该开关值传输到VMCA的CCDL区
    word16		sensor_status_ch[4];	// 比较监控状态
    word16		fail_cnt_ch[4][4];   // 信号故障计数器，[0]代表连接到ISAC成品的A通道的开关，
                                	//                 [0]代表该开关值传输到VMCA的CCDL区
    int16		voted_ch[4];        // 表决值，      [0]代表连接到ISAC成品的A通道的开关
	word16		signal_status;		//	DCBA 4通道表决值
} vm_etac_ram_rec;
                
                //--------------------
                // ETC/ISAC开关ROM结构体
                //--------------------
                
typedef struct {
    vm_etac_ram_rec *ram_rec;   // 指向RAM结构体的指针
    int16   *ivot_dest;         // 表决值
    int16   *sig_ch_ptr[4];     // 指向CCDL缓冲区的指针
    word16  din_word[4];        // 4通道开关量偏移
    word16  din_type;           // 偏移类型
    word16  mo_flr_code;        // 故障码
    word16	rbit;				// 重构位
    word16    *dsrc_err;        // 信息源故障状态
    word16	  *ccdl_status;		// RN_BUS_ILM
    word16    pers;             // 监控容限
    word16    fs_num_sig;       // 重构前最小有效通道个数
    int16   fs_val;             // 故障安全值
} vm_etac_rom_rec;
				
				//--------------------
                // ISAC、ETC信息源RAM结构体
                //--------------------
                
typedef struct {
	word16	cse_status;				/* 控制器CSE状态 */
	word16	mode_status;			/* 控制器工作模式状态 */
    int16   mode_fail_cnt[4];		/* 工作模式故障计数器 */
} vm_dsrc_ram_rec;

				//--------------------
                // ISAC、ETC信息源ROM结构体
                //--------------------
                
typedef struct {
	vm_dsrc_ram_rec			*ram_rec;
    vm_etac_rom_rec const 	*chv_rom_rec;	// 通道CHV ROM

    int16   *sig_ch_ptr[4];     // 指向CCDL缓冲区的指针
    word16  *etac_err;      	// 二级控制器故障
    word16  *dsrc_err;          // 信息源故障状态
    word16	*data_err;			// RN_BUS_ERR
    word16	*scs_flg;			// 单通道标志
    word16  cse_offset;			// CSE偏移
    word16  pbit_offset;		// PBIT模式偏移
    word16  mbit_offset;		// MBIT模式偏移
    word16  flr_code;			// 二级控制器故障码
    word16  mode_flr_code;      // 工作模式故障码
    word16  mode_per;      		// 工作模式故障容限
} vm_dsrc_rom_rec;

				//--------------------
                // ETC PBIT监控ROM结构体
                //--------------------
                
typedef struct {
    int16   *sig_ch_ptr[4];     // 指向CCDL缓冲区的指针
    word16  *in_pbit;      		// ETC在pbit中
    word16  *pbit_cnt;      	// ETC在pbit中的时间
    word16  *svpc_ilm;          // SVPC状态
    word16  pbit_offset;		// PBIT模式偏移
    word16  go_offset;			// PBIT测试结果偏移
    word16  abn_offset;			// PBIT异常退出偏移
    word16  go_flr_code;		// PBIT测试通过故障码
    word16  nogo_flr_code;		// PBIT测试未通过故障码
    word16  abn_flr_code;      	// PBIT测试异常退出故障码
    word16  pbit_per;      		// PBIT测试最长时间
    word16  enmo_delay;      	// 打开监控等待时间
    void    (*enmo_task) ();    /* 打开监控函数指针 */
	void    (*dismo_task) ();   /* 禁止监控函数指针 */
} mo_pbit_rom_rec;


                //--------------------
                // 发动机转速结构体
                //--------------------
                
typedef struct {
    int16   *sig_ch_ptr[4];     // 信号基地址
    word16	sig1_offset;		// 转速1偏移    
    word16	ilm1_offset;		// 转速1有效性偏移    
    word16	sig2_offset;		// 转速2偏移
    word16	ilm2_offset;		// 转速2有效性偏移
    int16   *vot_ptr;        	// 发动机转子转速表决值
    int16   *pre_vot_ptr;       // 发动机转子转速上拍表决值
    int16	*n21_ptr;			// 转速1选择值
    int16	*n22_ptr;			// 转速2选择值
    word16	*ccdl_status;	 	// USIM非自主CCDL状态
} vm_eng_rom_rec;


				//--------------------
                // 特殊开关表决监控算法结构体
                //--------------------

typedef struct {
	vm_rom_rec      const *rom_rec;
	int16			*pvoted_type;	/* 表决值类型 			           */	
	int16			*state;			/* 状态机				           */
	int16			*p5s_cnt;		/* 5s计时器 			   		   */
	word16			*pshort; 		/* 短路标志		     		       */
	word16			*pcut;			/* 开路标志						   */
	int16			*pcut_cnt;		/* 开路计数器 					   */
	int16			*pvpre;			/* 前一拍通道值					   */	
	byte			*health_src;	/* 记录D状态通道有效性    			   */
} spl_dis_rom_rec;


typedef struct {
	vm_rom_rec 		const *rom_rec1;	/* 互斥对开关1 */
	vm_rom_rec		const *rom_rec2;    /* 互斥对开关2 */
	int32				  *p_mutex_cnt; /* 互斥计数器       */
}vm_mutex_rom_grp; 

#endif /*VMTYPE_H_*/

