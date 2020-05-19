//
// MODIFICATIONS:
//
//A06-0001	2015-04-17	J.J.S.
//			�޸Ĺߵ�RAM�ṹ��vm_ins_ram_rec��
//

#include "consttype.h"
#include "vmsntype.h"
#include "insvmconst.h"

#ifndef VMTYPE_H_
#define VMTYPE_H_

               /* ģ��/��ɢ������RAM��¼���� */

typedef struct {
        word16		valid_signals;   /* number of current valid signals       */ 
        word16		signal_status;   /* signals status 4 bits, lsb is ch_A    */
		word16		hb_status;		 /* �źŶ�ӦRN������״̬ 				  */
		word16		sensor_status;	 /* �źŴ�����״̬���ɶ���ȱȽϵõ�	  */
        boolean		vot_sup;         /* voting suppress flag                  */
        boolean		mon_sup;         /* monitoring suppress flag              */
        word16		sig_ch_ind[4];   /* indexes of signal channels            */
        word16		sig_ch_cnt[4];   /* failure counters for the signals      */
/*ana*/ int16		tolerance;       /* tolerance                             */
        int16		voted;           /* voted value                           */
               } vm_ram_rec;

               /* ģ��/��ɢ������ROM��¼���� */
typedef struct {
        vm_ram_rec *ram_rec;     /* pointer to the RAM record             */
                                 /* for output commands - address of      */
                                 /* output command from Control Laws      */
        word16	*data_err;		 /* ����������Ч��						  */
        word16  *ccdl_status;	 /* CCDL��Ч״̬							  */
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
		word16	*sw_type;		 /* ��������:RCV_DISABLE ���ɸ�λ��RCV_ENABLE �ɸ�λ      */
	} vm_rom_rec;

					   //--------------------
					   // �ߵ�RAM�ṹ��
					   //--------------------
			   
typedef struct {
		boolean	mon_sup;			// ��ؽ�ֹ��־
		word16	sig_status;			// �ߵ��ź���Ч״̬����0λ����INS1����1λ����INS2
		word16	err_status;			// �ߵ��źű���״̬����0λ����INS1����1λ����INS2
		word16	ins_ms_vs;			// �ߵ��ź�״̬ǰ��ֵ
		word16	flr_cnt[2];			// �ߵ�������Ч�Լ�ؼ�����
		word16	flr_tol_cnt;		// �ߵ����������źűȽϼ�ؼ�����
		int16	voted[2];			// ���ֵ
		int16	tolerance;			// �������
	} vm_ins_ram_rec;
			   
						//--------------------
						// �ߵ�ROM�ṹ��
						//--------------------
			   
typedef struct {
		vm_ins_ram_rec	*ram_rec;	// ָ��RAM�ṹ���ָ��
		int16	*ival_ins[2];		// [0]:�ߵ�1������ֵ
									// [1]:�ߵ�2������ֵ
		int16	*ivot_dest;			// ���� (��ӦRSA�źű��ֵ); ���� (������Ҫ�õı��ֵ)
		word16	*valid_dest;		// ��Ч��
		int16	*sig_ch_ptr[4];		// CCDL��ָ��
		word16	ilm_bit;			// ILM�ź�λ����
		word16	ilm_num;			// ILM�ź��ֶ���
		word16	flr_code;			// �ߵ��ź���Ч������
		word16	flr_pers;			// �ߵ�����������
		word16	flr_tolerance;	    // �Ƚϼ������
	} vm_ins_rom_rec;


				/* ���4+2����ź�RAM��¼���� */
typedef struct {
		boolean vot_sup;
		boolean mon_sup;
		word16	signal_status;
		word16	valid_signals;
		word16	val_rsa_ch;
		word16	sig_ch_ind[3];
		word16	sig_ch_cnt[INS_NUM + 1];// �ߵ�����(0��1)��RSA(2)���޼�����
		int16   sig_ch_val[3];			// [0]:ins1; [1]:ins2; [2]:rsa;
		int16	voted_val;
		word16	ms_vs;					// �ź�״̬ǰ��ֵ����0λ����INS1����1λ����INS2����2λ����RSA
		} vm_axes_ram_rec;
							  

			   /* ���4+2����ź�ROM��¼���� */
typedef struct {
		vm_axes_ram_rec			*ram_rec;
		vm_rom_rec const		*rsa_rom;
		vm_ins_rom_rec const	*ins_rom;
		int16					*hi_rate_flg;  // �����ʱ�־
		float	sig_fctr;					// ת������
		float	sig_bias;					// ƫ��
		float	sig_lim;					// �޷�
		float	vo_tolerance;				// �������
		float	tol_radix;					// ������޼������
		float	tol_dvsr;					// ������޼���Լ��
		word16	pers;						// ��������
		word16	rcnf_bit;					// �ع�λ
		word16  fs_num_sig;					// �ع�ǰ��С�ź���(������RSA/INS����źţ���ֹ���������߼�)
		boolean	sel_flag;					// ѡ���߼���־ - TRUE:ִ��ѡ���߼���FALSE:��ִ��
		int16	hi_rate_pmax;				// �����ʱ�־�ж����ޣ�������� positive_max
		int16   hi_rate_nmax;				// �����ʱ�־�ж����ޣ�������� negative_max
		int16   hi_rate_pmin;				// �����ʱ�־�ж����ޣ�������С positive_min
		int16	hi_rate_nmin;				// �����ʱ�־�ж����ޣ�������� negative_min
	   } vm_axes_rom_rec;

                //--------------------
                // ETC/ISAC����RAM�ṹ��
                //--------------------

typedef struct {
    boolean		vot_sup;            	// �����ֹ��־
    boolean		mon_sup;            	// ��ؽ�ֹ��־
    word16		valid_signals_ch[4];   	// ��Ч�źŸ�����[0]�������ӵ�ISAC��Ʒ��Aͨ���Ŀ���
    word16		signal_status_ch[4];   	// �ź���Ч״̬��[0]�������ӵ�ISAC��Ʒ��Aͨ���Ŀ��أ�
                                		//               ��0λ����ÿ���ֵ���䵽VMCA��CCDL��
    word16		sensor_status_ch[4];	// �Ƚϼ��״̬
    word16		fail_cnt_ch[4][4];   // �źŹ��ϼ�������[0]�������ӵ�ISAC��Ʒ��Aͨ���Ŀ��أ�
                                	//                 [0]����ÿ���ֵ���䵽VMCA��CCDL��
    int16		voted_ch[4];        // ���ֵ��      [0]�������ӵ�ISAC��Ʒ��Aͨ���Ŀ���
	word16		signal_status;		//	DCBA 4ͨ�����ֵ
} vm_etac_ram_rec;
                
                //--------------------
                // ETC/ISAC����ROM�ṹ��
                //--------------------
                
typedef struct {
    vm_etac_ram_rec *ram_rec;   // ָ��RAM�ṹ���ָ��
    int16   *ivot_dest;         // ���ֵ
    int16   *sig_ch_ptr[4];     // ָ��CCDL��������ָ��
    word16  din_word[4];        // 4ͨ��������ƫ��
    word16  din_type;           // ƫ������
    word16  mo_flr_code;        // ������
    word16	rbit;				// �ع�λ
    word16    *dsrc_err;        // ��ϢԴ����״̬
    word16	  *ccdl_status;		// RN_BUS_ILM
    word16    pers;             // �������
    word16    fs_num_sig;       // �ع�ǰ��С��Чͨ������
    int16   fs_val;             // ���ϰ�ȫֵ
} vm_etac_rom_rec;
				
				//--------------------
                // ISAC��ETC��ϢԴRAM�ṹ��
                //--------------------
                
typedef struct {
	word16	cse_status;				/* ������CSE״̬ */
	word16	mode_status;			/* ����������ģʽ״̬ */
    int16   mode_fail_cnt[4];		/* ����ģʽ���ϼ����� */
} vm_dsrc_ram_rec;

				//--------------------
                // ISAC��ETC��ϢԴROM�ṹ��
                //--------------------
                
typedef struct {
	vm_dsrc_ram_rec			*ram_rec;
    vm_etac_rom_rec const 	*chv_rom_rec;	// ͨ��CHV ROM

    int16   *sig_ch_ptr[4];     // ָ��CCDL��������ָ��
    word16  *etac_err;      	// ��������������
    word16  *dsrc_err;          // ��ϢԴ����״̬
    word16	*data_err;			// RN_BUS_ERR
    word16	*scs_flg;			// ��ͨ����־
    word16  cse_offset;			// CSEƫ��
    word16  pbit_offset;		// PBITģʽƫ��
    word16  mbit_offset;		// MBITģʽƫ��
    word16  flr_code;			// ����������������
    word16  mode_flr_code;      // ����ģʽ������
    word16  mode_per;      		// ����ģʽ��������
} vm_dsrc_rom_rec;

				//--------------------
                // ETC PBIT���ROM�ṹ��
                //--------------------
                
typedef struct {
    int16   *sig_ch_ptr[4];     // ָ��CCDL��������ָ��
    word16  *in_pbit;      		// ETC��pbit��
    word16  *pbit_cnt;      	// ETC��pbit�е�ʱ��
    word16  *svpc_ilm;          // SVPC״̬
    word16  pbit_offset;		// PBITģʽƫ��
    word16  go_offset;			// PBIT���Խ��ƫ��
    word16  abn_offset;			// PBIT�쳣�˳�ƫ��
    word16  go_flr_code;		// PBIT����ͨ��������
    word16  nogo_flr_code;		// PBIT����δͨ��������
    word16  abn_flr_code;      	// PBIT�����쳣�˳�������
    word16  pbit_per;      		// PBIT�����ʱ��
    word16  enmo_delay;      	// �򿪼�صȴ�ʱ��
    void    (*enmo_task) ();    /* �򿪼�غ���ָ�� */
	void    (*dismo_task) ();   /* ��ֹ��غ���ָ�� */
} mo_pbit_rom_rec;


                //--------------------
                // ������ת�ٽṹ��
                //--------------------
                
typedef struct {
    int16   *sig_ch_ptr[4];     // �źŻ���ַ
    word16	sig1_offset;		// ת��1ƫ��    
    word16	ilm1_offset;		// ת��1��Ч��ƫ��    
    word16	sig2_offset;		// ת��2ƫ��
    word16	ilm2_offset;		// ת��2��Ч��ƫ��
    int16   *vot_ptr;        	// ������ת��ת�ٱ��ֵ
    int16   *pre_vot_ptr;       // ������ת��ת�����ı��ֵ
    int16	*n21_ptr;			// ת��1ѡ��ֵ
    int16	*n22_ptr;			// ת��2ѡ��ֵ
    word16	*ccdl_status;	 	// USIM������CCDL״̬
} vm_eng_rom_rec;


				//--------------------
                // ���⿪�ر������㷨�ṹ��
                //--------------------

typedef struct {
	vm_rom_rec      const *rom_rec;
	int16			*pvoted_type;	/* ���ֵ���� 			           */	
	int16			*state;			/* ״̬��				           */
	int16			*p5s_cnt;		/* 5s��ʱ�� 			   		   */
	word16			*pshort; 		/* ��·��־		     		       */
	word16			*pcut;			/* ��·��־						   */
	int16			*pcut_cnt;		/* ��·������ 					   */
	int16			*pvpre;			/* ǰһ��ͨ��ֵ					   */	
	byte			*health_src;	/* ��¼D״̬ͨ����Ч��    			   */
} spl_dis_rom_rec;


typedef struct {
	vm_rom_rec 		const *rom_rec1;	/* ����Կ���1 */
	vm_rom_rec		const *rom_rec2;    /* ����Կ���2 */
	int32				  *p_mutex_cnt; /* ���������       */
}vm_mutex_rom_grp; 

#endif /*VMTYPE_H_*/

