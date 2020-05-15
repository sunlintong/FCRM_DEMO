//
// MODIFICATIONS:
//
//A04-0001	2014-09-10	N.Q.
//			×ÜÏß¼à¿ØÆ÷½á¹¹ÌåÔö¼ÓPUBITÏà¹Ø±äÁ¿¡£

#ifndef VMSNTYPE_H_
#define VMSNTYPE_H_

#include "consttype.h"
#include "const.h"
/*--------------------------------------------------------------------------*/
/*                        RNÊý¾Ý¼à¿ØRAM¼ÇÂ¼ÀàÐÍ                            	*/
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
/*						 RNÊý¾Ý¼à¿ØROM¼ÇÂ¼ÀàÐÍ								*/
/*--------------------------------------------------------------------------*/

typedef struct {
		rn_ram_rec *ram_rec;	/* Ö¸Ïò×Ü		*/		
		int16 	*io_base_ptr[4];/* ±¾°üÊý		*/
		word16 *data_err_dest;	/* Ö¸Ïò×Ü		*/
		word16 *ccdl_status_dest; /* Ö¸Ïò		*/
		word32 *sverr_cnt_dest[4];	/* Èí			*/		
		word32 *hberr_cnt_dest[4];	/* ÐÄ		*/
		word16	chan_involv;	/* ²É¼¯µÄ		*/
		/* Èí¼þVPC¼à¿ØÆ÷ÊôÐÔ */ 		
		word16	svpc_bias;		/* Èí¼þVP		*/
		word16	svpc_pers;		/* Èí¼þVP		*/
		word16	svpc_flr_code;	/* Èí¼þVP		*/	
		/* ÐÄÌø×Ö¼à¿ØÆ÷ÊôÐÔ */
		word16	heart_lowlim;	/* Ç°ÅÄÐÄ		*/
		word16	heart_uplim;	/* Ç°ÅÄÐÄ		*/
		word16  heart_lowlim2;	/* Ç°Á½ÅÄ			*/
		word16  heart_uplim2;	/* Ç°Á½ÅÄ			*/
		word16	heart_pers; 	/* ÐÄÌø×Ö		*/
		word16	heart_flr_code; /* ÐÄÌø×Ö		*/
		word16	rn_pubit_flr_code;	/* ¿Ø			*/
		/* ·¢ËÍÁ´Â·¼à¿ØÆ÷ÊôÐÔ */
		word16	send_flr_code;	/* ·¢ËÍÁ´		*/	
		/* RNµÄÉÏµç³õÊ¼»¯¼à¿ØÆ÷	*/
		word32	predefined_head;/* Ô¤¶¨Òå		*/
		word16  head_flr_code;	/* °üÍ·¼ì		*/
		word32	lruid1_bias;	/* LRU ID		*/
		word32	lruid1_bit;		/* LRU ID		*/		
		word32	lruid2_bias;	/* LRU ID		*/
		word32	lruid2_bit;		/* LRU ID		*/		
		word16  lruid_flr_code;	/* RNµÄLR		*/
		//word16	recv_base;		/* ÔÚ			*/
		//word16	recv_num;		/* ½Ó			*/
		word32	pubit_bias;		/* PUBIT½		*/
		word32	pubit_bit;		/* PUBIT½		*/
		word32	pubit_pass;		/* PUBITÍ		*/
	} rn_rom_rec;

/*--------------------------------------------------------------------------*/
/*                        ·Ç×ÔÖ÷CCDLÊý¾Ý¼à¿ØRAM¼ÇÂ¼ÀàÐÍ                            	*/
/*--------------------------------------------------------------------------*/

typedef struct {
	word16	valid_signals;	/* 	*/
	word32	pre_heart[4];	/* 	*/
	boolean svpc_dcl_flg[4];/* ªÔÊÐí±¨¹Ê£¬0Îª½ûÖ¹±¨¹Ê */
	boolean hb_dcl_flg[4]; 	/* 1ÎªÔÊÐí±¨¹Ê£¬0Îª½ûÖ¹±¨¹Ê */
	word16	svpc_cnt[4];	/* 	*/		
	word16	heart_cnt[4];	/* 	*/	
	word16  svpc_err;		/* 	*/
	word16	hb_err;			/* 	*/	
	word16	svpc_ilm;		/* 	*/
	word16	hb_ilm;			/* 	*/	
	}ccdl_ram_rec;

/*--------------------------------------------------------------------------*/
/*                        ·Ç×ÔÖ÷CCDLÊý¾Ý¼à¿ØROM¼ÇÂ¼ÀàÐÍ                            	*/
/*--------------------------------------------------------------------------*/

typedef struct {
	ccdl_ram_rec *ram_rec;	/* Ö¸		*/	
	int16	*io_base_ptr[4];/* ±¾		*/
	word16 *ccdl_status_dest; /* 			*/
	word16	chan_involv;	/* ²É		*/
	/* Èí¼þVPC¼à¿ØÆ÷ÊôÐÔ */ 	
	word16	svpc_bias;		/* Èí		*/
	word16	svpc_pers;		/* Èí		*/
	word16	svpc_flr_code;	/* Èí		*/	
	/* ÐÄÌø×Ö¼à¿ØÆ÷ÊôÐÔ */
	word16	heart_pers; 	/* ÐÄ		*/
	word16	heart_flr_code; /* ÐÄ		*/
	}ccdl_rom_rec;

	
/*×ÜÏßÊý¾Ý°üÔªËØ½á¹¹Ìå*/
typedef struct{
		void *psrc_value;	    
		word16 des_byteoffset;	
		                        
		byte des_bitoffset; 	
		                        
		byte src_bitoffset; 	
		                        
		byte elementtype;		
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		                        
		byte src_type;			
		                        
		                        
		                        
		                        
} bus_pkg_element, *pbus_pkg_element;

/*--------------------------------------------------------------------------*/
/*                        º½µçÊý¾Ý°ü¼à¿Ø¼ÇÂ¼ÀàÐÍ                          	*/
/*--------------------------------------------------------------------------*/

typedef struct {
    word32      rn_pre_hb[TOT_CHAN_NUM];    //Ç
    int32       rn_hb_cnt[TOT_CHAN_NUM];    //Ð
    int32       rn_svpc_cnt[TOT_CHAN_NUM];  //S
}ms_ram_rec;

typedef struct {
	ms_ram_rec  *rn_ram;                // RAM½
 	int16       *dt_addr[TOT_CHAN_NUM]; //Ô¶³Ì½
 	int16       *hb_err;                //ÐÄÌø¹
 	int16       *svpc_err;              //SVPC¹
 	int16       *hb_ilm;                //ÐÄÌøÔ
 	int16       *svpc_ilm;              //SVPCÔ
 	int16       *bus_ilm;               //½Úµã±
 	word32      svpc_off;               //SVPCÆ
 	word32      ch_mask;                //¼à¿ØÍ
} ms_rom_rec;

#endif /*VMSNTYPE_H_*/
