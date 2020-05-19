//
// MODIFICATIONS:
//
//A04-0001	2014-09-10	N.Q.
//			���߼�����ṹ������PUBIT��ر�����

#ifndef VMSNTYPE_H_
#define VMSNTYPE_H_

#include "consttype.h"
#include "const.h"
/*--------------------------------------------------------------------------*/
/*                        RN���ݼ��RAM��¼����                            	*/
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
/*						 RN���ݼ��ROM��¼����								*/
/*--------------------------------------------------------------------------*/

typedef struct {
		rn_ram_rec *ram_rec;	/* ָ����		*/		
		int16 	*io_base_ptr[4];/* ������		*/
		word16 *data_err_dest;	/* ָ����		*/
		word16 *ccdl_status_dest; /* ָ��		*/
		word32 *sverr_cnt_dest[4];	/* ��			*/		
		word32 *hberr_cnt_dest[4];	/* ��		*/
		word16	chan_involv;	/* �ɼ���		*/
		/* ���VPC��������� */ 		
		word16	svpc_bias;		/* ���VP		*/
		word16	svpc_pers;		/* ���VP		*/
		word16	svpc_flr_code;	/* ���VP		*/	
		/* �����ּ�������� */
		word16	heart_lowlim;	/* ǰ����		*/
		word16	heart_uplim;	/* ǰ����		*/
		word16  heart_lowlim2;	/* ǰ����			*/
		word16  heart_uplim2;	/* ǰ����			*/
		word16	heart_pers; 	/* ������		*/
		word16	heart_flr_code; /* ������		*/
		word16	rn_pubit_flr_code;	/* ��			*/
		/* ������·��������� */
		word16	send_flr_code;	/* ������		*/	
		/* RN���ϵ��ʼ�������	*/
		word32	predefined_head;/* Ԥ����		*/
		word16  head_flr_code;	/* ��ͷ��		*/
		word32	lruid1_bias;	/* LRU ID		*/
		word32	lruid1_bit;		/* LRU ID		*/		
		word32	lruid2_bias;	/* LRU ID		*/
		word32	lruid2_bit;		/* LRU ID		*/		
		word16  lruid_flr_code;	/* RN��LR		*/
		//word16	recv_base;		/* ��			*/
		//word16	recv_num;		/* ��			*/
		word32	pubit_bias;		/* PUBIT�		*/
		word32	pubit_bit;		/* PUBIT�		*/
		word32	pubit_pass;		/* PUBIT�		*/
	} rn_rom_rec;

/*--------------------------------------------------------------------------*/
/*                        ������CCDL���ݼ��RAM��¼����                            	*/
/*--------------------------------------------------------------------------*/

typedef struct {
	word16	valid_signals;	/* 	*/
	word32	pre_heart[4];	/* 	*/
	boolean svpc_dcl_flg[4];/* ������ʣ�0Ϊ��ֹ���� */
	boolean hb_dcl_flg[4]; 	/* 1Ϊ�����ʣ�0Ϊ��ֹ���� */
	word16	svpc_cnt[4];	/* 	*/		
	word16	heart_cnt[4];	/* 	*/	
	word16  svpc_err;		/* 	*/
	word16	hb_err;			/* 	*/	
	word16	svpc_ilm;		/* 	*/
	word16	hb_ilm;			/* 	*/	
	}ccdl_ram_rec;

/*--------------------------------------------------------------------------*/
/*                        ������CCDL���ݼ��ROM��¼����                            	*/
/*--------------------------------------------------------------------------*/

typedef struct {
	ccdl_ram_rec *ram_rec;	/* ָ		*/	
	int16	*io_base_ptr[4];/* ��		*/
	word16 *ccdl_status_dest; /* 			*/
	word16	chan_involv;	/* ��		*/
	/* ���VPC��������� */ 	
	word16	svpc_bias;		/* ��		*/
	word16	svpc_pers;		/* ��		*/
	word16	svpc_flr_code;	/* ��		*/	
	/* �����ּ�������� */
	word16	heart_pers; 	/* ��		*/
	word16	heart_flr_code; /* ��		*/
	}ccdl_rom_rec;

	
/*�������ݰ�Ԫ�ؽṹ��*/
typedef struct{
		void *psrc_value;	    
		word16 des_byteoffset;	
		                        
		byte des_bitoffset; 	
		                        
		byte src_bitoffset; 	
		                        
		byte elementtype;		
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		byte src_type;			
		                        
		                        
		                        
		                        
} bus_pkg_element, *pbus_pkg_element;

/*--------------------------------------------------------------------------*/
/*                        �������ݰ���ؼ�¼����                          	*/
/*--------------------------------------------------------------------------*/

typedef struct {
    word32      rn_pre_hb[TOT_CHAN_NUM];    //�
    int32       rn_hb_cnt[TOT_CHAN_NUM];    //�
    int32       rn_svpc_cnt[TOT_CHAN_NUM];  //S
}ms_ram_rec;

typedef struct {
	ms_ram_rec  *rn_ram;                // RAM�
 	int16       *dt_addr[TOT_CHAN_NUM]; //Զ�̽
 	int16       *hb_err;                //�����
 	int16       *svpc_err;              //SVPC�
 	int16       *hb_ilm;                //�����
 	int16       *svpc_ilm;              //SVPC�
 	int16       *bus_ilm;               //�ڵ�
 	word32      svpc_off;               //SVPC�
 	word32      ch_mask;                //����
} ms_rom_rec;

#endif /*VMSNTYPE_H_*/
