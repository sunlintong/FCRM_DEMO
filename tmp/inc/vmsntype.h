//
// MODIFICATIONS:
//
//A04-0001	2014-09-10	N.Q.
//			总线监控器结构体增加PUBIT相关变量。

#ifndef VMSNTYPE_H_
#define VMSNTYPE_H_

#include "consttype.h"
#include "const.h"
/*--------------------------------------------------------------------------*/
/*                        RN数据监控RAM记录类型                            	*/
/*--------------------------------------------------------------------------*/


typedef struct {
		boolean mon_sup;		
		boolean init_mon_sup;	
        word16  sig_ch_ind[4];  
		word16	pre_data_err;	
		word16  valid_signals;  
		word16  recv_err;   	
		word16  send_cnt[4];   	
		word16  send_err;   	
		word16	svpc_ilm;		
		word16  svpc_err;   	
		word16	heart_ilm;		
		word16	heart_ilm2;		
        word16  heart_err;   	
		word16  hb_change;               */
		word16  svpc_cnt[4];   	
		word16  heart_cnt[4];  	
		word32	pre_heart[4];	
		word32	pre_heart2[4];	
		word16	init_cnt[4];	
		word16	susd_status;	
		word16	pubit_err;		
               } rn_ram_rec;


/*--------------------------------------------------------------------------*/
/*						 RN数据监控ROM记录类型								*/
/*--------------------------------------------------------------------------*/

typedef struct {
		rn_ram_rec *ram_rec;	/* 指向总		*/		
		int16 	*io_base_ptr[4];/* 本包数		*/
		word16 *data_err_dest;	/* 指向总		*/
		word16 *ccdl_status_dest; /* 指向		*/
		word32 *sverr_cnt_dest[4];	/* 软			*/		
		word32 *hberr_cnt_dest[4];	/* 心		*/
		word16	chan_involv;	/* 采集的		*/
		/* 软件VPC监控器属性 */ 		
		word16	svpc_bias;		/* 软件VP		*/
		word16	svpc_pers;		/* 软件VP		*/
		word16	svpc_flr_code;	/* 软件VP		*/	
		/* 心跳字监控器属性 */
		word16	heart_lowlim;	/* 前拍心		*/
		word16	heart_uplim;	/* 前拍心		*/
		word16  heart_lowlim2;	/* 前两拍			*/
		word16  heart_uplim2;	/* 前两拍			*/
		word16	heart_pers; 	/* 心跳字		*/
		word16	heart_flr_code; /* 心跳字		*/
		word16	rn_pubit_flr_code;	/* 控			*/
		/* 发送链路监控器属性 */
		word16	send_flr_code;	/* 发送链		*/	
		/* RN的上电初始化监控器	*/
		word32	predefined_head;/* 预定义		*/
		word16  head_flr_code;	/* 包头检		*/
		word32	lruid1_bias;	/* LRU ID		*/
		word32	lruid1_bit;		/* LRU ID		*/		
		word32	lruid2_bias;	/* LRU ID		*/
		word32	lruid2_bit;		/* LRU ID		*/		
		word16  lruid_flr_code;	/* RN的LR		*/
		//word16	recv_base;		/* 在			*/
		//word16	recv_num;		/* 接			*/
		word32	pubit_bias;		/* PUBIT�		*/
		word32	pubit_bit;		/* PUBIT�		*/
		word32	pubit_pass;		/* PUBIT�		*/
	} rn_rom_rec;

/*--------------------------------------------------------------------------*/
/*                        非自主CCDL数据监控RAM记录类型                            	*/
/*--------------------------------------------------------------------------*/

typedef struct {
	word16	valid_signals;	/* 	*/
	word32	pre_heart[4];	/* 	*/
	boolean svpc_dcl_flg[4];/* 市肀ü剩�0为禁止报故 */
	boolean hb_dcl_flg[4]; 	/* 1为允许报故，0为禁止报故 */
	word16	svpc_cnt[4];	/* 	*/		
	word16	heart_cnt[4];	/* 	*/	
	word16  svpc_err;		/* 	*/
	word16	hb_err;			/* 	*/	
	word16	svpc_ilm;		/* 	*/
	word16	hb_ilm;			/* 	*/	
	}ccdl_ram_rec;

/*--------------------------------------------------------------------------*/
/*                        非自主CCDL数据监控ROM记录类型                            	*/
/*--------------------------------------------------------------------------*/

typedef struct {
	ccdl_ram_rec *ram_rec;	/* 指		*/	
	int16	*io_base_ptr[4];/* 本		*/
	word16 *ccdl_status_dest; /* 			*/
	word16	chan_involv;	/* 采		*/
	/* 软件VPC监控器属性 */ 	
	word16	svpc_bias;		/* 软		*/
	word16	svpc_pers;		/* 软		*/
	word16	svpc_flr_code;	/* 软		*/	
	/* 心跳字监控器属性 */
	word16	heart_pers; 	/* 心		*/
	word16	heart_flr_code; /* 心		*/
	}ccdl_rom_rec;

	
/*总线数据包元素结构体*/
typedef struct{
		void *psrc_value;	    
		word16 des_byteoffset;	
		                        
		byte des_bitoffset; 	
		                        
		byte src_bitoffset; 	
		                        
		byte elementtype;		
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		byte src_type;			
		                        
		                        
		                        
		                        
} bus_pkg_element, *pbus_pkg_element;

/*--------------------------------------------------------------------------*/
/*                        航电数据包监控记录类型                          	*/
/*--------------------------------------------------------------------------*/

typedef struct {
    word32      rn_pre_hb[TOT_CHAN_NUM];    //�
    int32       rn_hb_cnt[TOT_CHAN_NUM];    //�
    int32       rn_svpc_cnt[TOT_CHAN_NUM];  //S
}ms_ram_rec;

typedef struct {
	ms_ram_rec  *rn_ram;                // RAM�
 	int16       *dt_addr[TOT_CHAN_NUM]; //远程�
 	int16       *hb_err;                //心跳�
 	int16       *svpc_err;              //SVPC�
 	int16       *hb_ilm;                //心跳�
 	int16       *svpc_ilm;              //SVPC�
 	int16       *bus_ilm;               //节点�
 	word32      svpc_off;               //SVPC�
 	word32      ch_mask;                //监控�
} ms_rom_rec;

#endif /*VMSNTYPE_H_*/
