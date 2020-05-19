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

/*ռ�ô�С320*/
typedef struct {
    word32  ed_hmch;        //HMC���32λ				,byte40
    word32  ed_hmcl;        //HMC���32λ				,byte44
    word32  ed_day;         //���Ϸ���ʱ��-������			,byte48
    word32  ed_sec;         //���Ϸ���ʱ��-ʱ����			,byte52
    word32  ed_len;         //�������ݳ���				,byte56
    ed_load_type ed_load_all[PHM_PHA_SIZE];   //EVENT DATA����			,byte60..byte360
} ed_type;

typedef struct {
	int32 recv_idx;
	int32 send_idx;
	int32 ed_num;
	ed_type ed_buf[PHM_BUF_SIZE];
} ed_pool_type;

typedef struct {
    word16  pre_flr;     	//��һ�Ĺ���״̬
    int32   pre_idx;     	//ǰ 5����������ʼ��Ϊ0
    int32   nxt_idx;     	//��15����������ʼ��Ϊ0
    ed_type evnt_data;
} phm_ram_rec;

typedef struct {
	void	*val_ptr;
	int16	val_src_type;
	int16	val_des_type;	//Ŀ�곤��Ҫ���ڵ���Դ����!!!
} phm_val_rec;

typedef struct {
    phm_ram_rec *ram_rec;   //�¼�������
    word32		flr_code;	//HMC���Ӧ�Ĺ�����
    word32      flr_ch;     //HMC���Ӧ�Ĺ���ͨ��
    phm_val_rec val_arr[PHM_VAL_MAX];	//�����ֳ�ֵ
} phm_rom_rec;

#endif /*PHMTYPE_H_*/
