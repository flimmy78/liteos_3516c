#ifndef __HI_SENSOR_DEFINE_H__
#define __HI_SENSOR_DEFINE_H__

#include "hi_mipi.h"
#include "hi_type.h"
#include "hi_mapi_vcap_define.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

typedef enum
{
    HI_PHY_CMV_GE900MV    = 0x00,
    HI_PHY_CMV_LT900MV    = 0x01,
    HI_PHY_CMV_BUTT
} HI_PHY_CMV_E;

typedef struct
{
	HI_BOOL bSetPhyCmv;
    HI_PHY_CMV_E enPhyCmv;
} HI_PHY_CMV_S;

typedef enum
{
	HI_BAYER_RGGB = 0,
	HI_BAYER_GRBG,
	HI_BAYER_GBRG,
	HI_BAYER_BGGR
}HI_BAYERFORMAT;

typedef struct
{
	HI_BAYERFORMAT enBayerFormat;
	HI_S32 s32start_x;
	HI_S32 s32start_y;
} HI_SENSOR_INPUT_ATTR_S;

typedef enum{    
	HI_PHY_CLK_SHARE_NONE = 0x0,    
	HI_PHY_CLK_SHARE_PHY0 = 0x1,      /* PHY share clock with PHY0 */    
	HI_PHY_CLK_SHARE_BUTT = 0x2
} HI_PHY_CLK_SHARE_E;

typedef struct
{
	HI_PHY_CLK_SHARE_E   	phy_clk_share;
	HI_PHY_CMV_S            stPhyCmv;
	img_rect_t      img_rect;
	void*              ptr_dev_attr;           /*  pointer to user_mipi_dev_attr or user_lvds_dev_attr */
	HI_U32            	au32CompMask[2];			/*��ӦViDev������*/
}HI_SENSOR_MIPI_LVDS_INTF_S;

typedef struct
{
    HI_U32                  dev_attr_total_num;
    void* psensorIntf;					/*HI_SENSOR_MIPI_LVDS_INTF_S*/
}HI_SENSOR_MIPI_LVDS_INTF_CFG_S;
#if 0
/*�豸����ʱ���������Ϣ*/
typedef struct hiVIDEO_INPUT_TIMING_BLANK_S
{
    HI_U32 u32HsyncHfb ;                    //ˮƽǰ���������
    //    HI_U32 u32HsyncAct ;                    //ˮƽ��Ч���
    HI_U32 u32HsyncHbb ;                    //ˮƽ�����������
    HI_U32 u32VsyncOfb ;                    //֡ͼ����������ʱ�泡ͼ��Ĵ�ֱǰ�������߶�
    //    HI_U32 u32VsyncOAct ;                   //֡ͼ����������ʱ�泡��ֱ��Ч���
    HI_U32 u32VsyncObb ;                    //֡ͼ����������ʱ�泡��ֱ���������߶�
    HI_U32 u32VsyncEfb ;                    //��������ʱż����ֱǰ�������߶� (֡����ʱ��Ч)
    HI_U32 u32VsyncEAct ;                   //��������ʱż����ֱ��Ч��� (֡����ʱ��Ч)
    HI_U32 u32VsyncEbb ;                    //��������ʱż����ֱ���������߶�  (֡����ʱ��Ч)
} HI_VIDEO_INPUT_TIMING_BLANK_S;


/* ͬ��ʱ������ (BT601/DC �ӿڱ�������) */
typedef struct hiVIDEO_BT601_DC_SYNC_CFG_S
{
    HI_U32 uVsync;                          /*��ֱͬ��ģʽ��0:��ֱͬ����תģʽ��1:��ֱͬ������ģʽ*/
    HI_U32 uVsyncNeg;                       /* ��ֱͬ���źŵļ���,0:��ʾż������vsync�ź�Ϊ�ߵ�ƽ,���Ǳ�ʾ�������ʾvsyncͬ������,���Ǳ�ʾvsync��Ч�ź�Ϊ�ߵ�ƽ
                                                                       1:��ʾż������vsync�ź�Ϊ�͵�ƽ�����Ǳ�ʾ�������ʾvsyncͬ�����壬���Ǳ�ʾvsync��Ч�ź�Ϊ�͵�ƽ*/
    HI_U32 uHsync;                          /*ˮƽͬ������ ,0:ˮƽͬ����Ч�ź�ģʽ,1:ˮƽͬ������ģʽ:*/
    HI_U32 uHsyncNeg;                       /**ˮƽͬ���źż��ԣ�0:��ʾˮƽͬ������Ϊ������,���Ǳ�ʾ������Ч�ź�Ϊ�ߵ�ƽ
                                                                     1:��ʾˮƽͬ������Ϊ������,���Ǳ�ʾ������Ч�ź�Ϊ�͵�ƽ*/
    HI_U32 uVsyncValid;                     /* ��Ч��ֱͬ������,0:��ֱͬ����תģʽ��1:��ֱͬ������ģʽ*/
    HI_U32 uVsyncValidNeg;
    HI_VIDEO_INPUT_TIMING_BLANK_S stTimingBlank;/*�豸����ʱ���������Ϣ*/
} HI_VIDEO_BT601_DC_SYNC_CFG_S;

typedef enum hiVIDEO_DATA_YUV_SEQ_E
{
    /*The input sequence of the second component(only contains u and v) in BT.1120 mode */
    HI_VIDEO_INPUT_DATA_VUVU = 0,
    HI_VIDEO_INPUT_DATA_UVUV,

    /* The input sequence for yuv */
    HI_VIDEO_INPUT_DATA_UYVY,
    HI_VIDEO_INPUT_DATA_VYUY,
    HI_VIDEO_INPUT_DATA_YUYV,
    HI_VIDEO_INPUT_DATA_YVYU,

    HI_VIDEO_INPUT_DATA_YUV_BUTT
} HI_VIDEO_DATA_YUV_SEQ_E;

typedef struct hiVIDEO_VI_PUB_ATTR_S
{
    HI_VIDEO_DATA_YUV_SEQ_E enDataSeq;       /* ��������˳�� */
    HI_VIDEO_BT601_DC_SYNC_CFG_S stSynCfg;     /* ͬ��ʱ������ (BT601/DC �ӿڱ�������) */
} HI_BT601_DC_INTF_S;
#endif

typedef struct
{
    HI_BOOL    bInitByFastboot;               		/* HI_TRUE: fastboot will do sensor init rather than RDK, make sure use correct fastboot, HI_FALSE: RDK do sensor init */
    HI_U32                  devno;                  		/* device number, select sensor0 and sensor 1 */
    input_mode_t            input_mode;             	/* input mode: MIPI/LVDS/SUBLVDS/HISPI/DC */
    void* pstIntf;							/*HI_SENSOR_MIPI_LVDS_INTF_CFG_S or HI_BT601_DC_INTF_S*/
}HI_SENSOR_INTF_S;

typedef struct
{
	HI_S32 s32Width;
	HI_S32 s32Height;
	HI_S32 s32FrameRate;
	HI_S32 s32SensorIntfSeqNo;
	HI_MPP_WDR_MODE_E enWdrMode;
}HI_SENSOR_MODE_S;

typedef struct
{
	HI_S32 s32SensorModeNum;
	void* pstSensorMode;			/*HI_SENSOR_MODE_S*/
}HI_SENSOR_MODE_INFO_S;

typedef enum hiSENSOR_COMMBUS_TYPE_E
{
	HI_SENSOR_COMMBUS_TYPE_I2C = 0,	
	HI_SENSOR_COMMBUS_TYPE_SPI,	
	HI_SENSOR_COMMBUS_TYPE_BUTT
}HI_SENSOR_COMMBUS_TYPE_E;

/*sensor interface description*/
typedef struct
{
    HI_SENSOR_INPUT_ATTR_S stSensorInputAttr;
	HI_SENSOR_INTF_S stSensorIntf;  
	HI_SENSOR_MODE_INFO_S stSensorMode;	
	HI_SENSOR_COMMBUS_TYPE_E enSensorCommBusType;
} HI_COMBO_DEV_ATTR_S;

typedef struct 
{
	HI_S32 s32TotalSensorNum;
	void* pstSensors;				/*HI_COMBO_DEV_ATTR_S*/
}HI_SENSOR_CFG_S;


/*************************VB********************************************/
typedef struct
{
    HI_U32 u32MaxPoolCnt;     /* max count of pools, (0,VB_MAX_POOLS]  */    
    struct hiPOOL_S
    {
        HI_U32 u32BlkSize;
        HI_U32 u32BlkCnt;
    }astCommPool[16];
} HI_VB_S;

typedef struct
{
	HI_S32 s32TotalOptNum;
	HI_U32 u32CurrentOpt;
	HI_VB_S* pstVBOpts;
}HI_VB_CFG_S;


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* ARGPARSER_H__ */
