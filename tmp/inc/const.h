// file const.h
    
//
//               ####    ####   #    #   ####    #####
//              #    #  #    #  ##   #  #          #
//              #       #    #  # #  #   ####      #
//              #       #    #  #  # #       #     #
//              #    #  #    #  #   ##  #    #     #
//               ####    ####   #    #   ####      #
//
// CODED BY      : 
//
// DATE          :
//
// MODIFICATIONS:
//
//A01-0001	2014-04-21	N.Q.
//			�޸Ŀ�����ѡ�񿪹�2���ع�λ��
//A04-0001	2014-08-28	Z.B.
//			04/05��ADS��������1394����RN�ڵ������������



#ifndef CONST_H_
#define CONST_H_


			/*-----------------------------*/
			/*        ͨ����������        */
			/*-----------------------------*/

#define TOT_CHAN_NUM	 (4)		/* �ɹ�ϵͳͨ������*/
#define VMC_CHAN_NUM	 (3)		/* VMCͨ������			*/

               /*-----------------------------*/
               /* Channel constant definition */
               /*-----------------------------*/

#define CH_A_ID          (0)       /* identification number of channel A      */
#define CH_B_ID          (1)       /* identification number of channel B      */
#define CH_C_ID          (2)       /* identification number of channel C      */
#define CH_D_ID          (3)       /* identification number of channel D      */
#define CH_NO_DEF        (4)       /* δ����ͨ��      							  */

#define M2_CH_A			 (0)	   /* �ӵ�0λ��λ��Aͨ�� */
#define M2_CH_B			 (1)       /* �ӵ�0λ��λ��Bͨ�� */
#define M2_CH_C			 (2)	   /* �ӵ�0λ��λ��Cͨ�� */
#define M2_CH_D			 (3)       /* �ӵ�0λ��λ��Dͨ�� */

			   //--------------------
			   // ���ֳ������壬���ڱ���������
			   //--------------------
   
#define PERS_15MS           (1)     // 15ms * 1 = 15ms
#define PERS_30MS           (2)     // 15ms * 2 = 30ms
#define PERS_45MS           (3)     // 15ms * 3 = 45ms
#define PERS_60MS           (4)     // 15ms * 4 = 60ms
#define PERS_75MS           (5)     // 15ms * 5 = 75ms
#define PERS_90MS           (6)     // 15ms * 6 = 90ms
#define PERS_120MS          (8)     // 15ms * 8 = 120ms
#define PERS_135MS          (9)     // 15ms * 9 = 135ms
#define PERS_150MS          (10)    // 15ms * 10 = 150ms
#define PERS_180MS          (12)    // 15ms * 12 = 180ms
#define PERS_250MS			(17)    // 15ms * 17 = 255ms
#define PERS_300MS          (20)    // 15ms * 20 = 300ms
#define PERS_360MS          (24)    // 15ms * 24 = 360ms
#define PERS_450MS          (30)    // 15ms * 30 = 450ms
#define PERS_500MS          (34)    // 15ms * 34 = 510ms
#define PERS_600MS          (40)    // 15ms * 40 = 600ms
#define PERS_960MS          (64)    // 15ms * 64 = 960ms
#define PERS_1005MS         (67)    // 15ms * 67 = 1005ms
#define PERS_1080MS         (72)    // 15ms * 72 = 1080ms
#define PERS_2000MS			(133)	// 15ms * 133 = 1995ms
#define PERS_3000MS			(200)	// 15ms * 200 = 3000ms
#define PERS_5000MS         (334)   // 15ms * 334 = 5010ms
#define PERS_6000MS			(400)	// 15ms * 400 = 6000ms
#define PERS_10S            (667)   // 15ms * 667 = 10005ms
#define PERS_20S			(1333)	// 15ms * 1333 = 19995ms
#define PERS_25S            (1667)  // 15ms * 1667 = 25005ms
#define PERS_30S            (2000)  // 15ms * 2000 = 30000ms = 30s



               /*------------------------------*/
               /* common constants  definition */
               /*------------------------------*/


#define ONE                (1)     /* constant                                */
#define TWO                (2)     /* constant                                */
#define THREE              (3)     /* constant                                */
#define FOUR               (4)     /* constant                                */
#define FIVE               (5)     /* constant                                */
#define SIX                (6)     /* constant                                */
#define SEVEN              (7)     /* constant                                */
#define EIGHT              (8)     /* constant                                */
#define TWELVE            (12)     /* constant                                */
#define THIRTEEN          (13)     /* constant                                */
#define SIXTEEN           (16)     /* constant                                */
#define TWENTYFOUR		  (24)	 /* constant								*/
#define SEVENTYTWO        (72)     /* constant                                */
#define ONESIXSEVEN       (167)     /* constant                                */

#define TWO_LSB            (0x3)   /* mask for 2 least significant bits       */
#define MODULO_256         (0xFF)  /* mask for 16 least significant bits      */
#define ALL_VALID          (0xF)   /* 4 valid signals                         */
#define ALL_FAILED         (0xF)   /* 4 bad signals                           */
#define ABCD_SAMPLE         (0xF)   // ͨ��A,B,C,D�����ź�
#define ABC_SAMPLE          (0x7)   // ͨ��A,B,C�����ź�
#define AC_SAMPLE           (0x5)   // ͨ��A,C�����ź�
#define BD_SAMPLE           (0xA)   // ͨ��B,D�����ź�
#define CD_SAMPLE           (0xC)   // ͨ��C,D�����ź�
#define AD_SAMPLE		     (0x9)
#define BC_SAMPLE		   	 (0x6)
#define C_SAMPLE            (0x4)   /* channels C sample the signal      		 */
#define AB_SAMPLE           (0x3)   // ͨ��A,B�����ź�


#endif /* CONST_H_ */
