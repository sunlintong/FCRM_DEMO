#ifndef PHMTYPE_H_
#define PHMTYPE_H_

#include "consttype.h"
#include "phmconst.h"

/**************************************************************************/
/*                             CC                                         */
/**************************************************************************/

typedef struct {
	int16 ed_load_one[ED_CC_SIZE];
}ed_load_type;

/*占用大小320*/
typedef struct {
    word32  ed_hmch;        //HMC码高32位				,byte40
    word32  ed_hmcl;        //HMC码低32位				,byte44
    word32  ed_day;         //故障发生时间-年月日			,byte48
    word32  ed_sec;         //故障发生时间-时分秒			,byte52
    word32  ed_len;         //负载数据长度				,byte56
    ed_load_type ed_load_all[PHM_PHA_SIZE];   //EVENT DATA负载			,byte60..byte360
} ed_type;

typedef struct {
	int32 recv_idx;
	int32 send_idx;
	int32 ed_num;
	ed_type ed_buf[PHM_BUF_SIZE];
} ed_pool_type;

typedef struct {
    word16  pre_flr;     	//上一拍故障状态
    int32   pre_idx;     	//前 5拍索引，初始化为0
    int32   nxt_idx;     	//后15拍索引，初始化为0
    ed_type evnt_data;
} phm_ram_rec;

typedef struct {
	void	*val_ptr;
	int16	val_src_type;
	int16	val_des_type;	//目标长度要大于等于源长度!!!
} phm_val_rec;

typedef struct {
    phm_ram_rec *ram_rec;   //事件数据组
    word32		flr_code;	//HMC码对应的故障码
    word32      flr_ch;     //HMC码对应的故障通道
    phm_val_rec val_arr[PHM_VAL_MAX];	//故障现场值
} phm_rom_rec;

#endif /*PHMTYPE_H_*/
