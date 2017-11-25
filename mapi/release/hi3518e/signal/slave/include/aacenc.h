/*****************************************************************************
*             Copyright 2004 - 2050, Hisilicon Tech. Co., Ltd.
*                           ALL RIGHTS RESERVED
* FileName: hi_spdif.h
* Description:
*
* History:
* Version   Date         Author     DefectNum    Description
* 0.01      2006-11-01   z40717    NULL         Create this file.
*
*****************************************************************************/
/**
 * \file
 * \brief Describes the information about AACENC. CNcomment:�ṩAACENC�������Ϣ CNend
 */

#ifndef _AACENC_H
#define _AACENC_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif     /* __cpluscplus */
#endif  /* __cpluscplus */

#include "hi_type.h"

/********************************Macro Definition********************************/
/** \addtogroup      AACENC */
/** @{ */  /** <!-- ��AACENC�� */

#ifdef MONO_ONLY
#define MAX_CHANNELS 1 /**<aacenc encoder channels*/ /**<CNcomment: AAC����֧��������*/
#else
#define MAX_CHANNELS 2
#endif

#define AACENC_BLOCKSIZE 1024 /**<aacenc blocksize*/ /**<CNcomment: AAC����֡��*/
/** @} */  /** <!-- ==== Macro Definition end ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      AACENC */
/** @{ */  /** <!-- [AACENC] */

/**Defines AACENC quality*/
/**CNcomment:�����������*/
typedef enum
{
    AU_QualityExcellent = 0,
    AU_QualityHigh   = 1,
    AU_QualityMedium = 2,
    AU_QualityLow = 3,
} AuQuality;

/**Defines AACENC format*/
/**CNcomment:��������ʽ*/
typedef enum
{
    AACLC = 0,              /**<AAC-LC format*/ /**<CNcomment:  AAC LC */
    EAAC = 1,               /**<HEAAC or AAC+  or aacPlusV1*/ /**<CNcomment: eAAC  (HEAAC or AAC+  or aacPlusV1) */
    EAACPLUS = 2,           /**<AAC++ or aacPlusV2*/ /**<CNcomment:  eAAC+ (AAC++ or aacPlusV2) */
    AACLD = 3,              /**<AAC LD(Low Delay)*/ /**<CNcomment: AAC LD(Low Delay) */
    AACELD = 4,             /**<AAC ELD(Low Delay)*/ /**<CNcomment: AAC ELD(Low Delay) */
} AuEncoderFormat;

/**Defines AACENC container*/
/**CNcomment:�������������ʽ*/
typedef enum
{
    AACENC_ADTS = 0,
    AACENC_LOAS = 1,
    AACENC_LATM_MCP1 = 2,
} AACENCTransportType;

/**Defines AACENC configuration*/
/**CNcomment:�����������ṹ��*/
typedef  struct
{
    AuQuality       quality;
    AuEncoderFormat coderFormat;
    HI_S16          bitsPerSample;
    HI_S32          sampleRate;    /**<audio file sample rate */ /**<CNcomment: �������ݲ�����*/
    HI_S32          bitRate;       /**<encoder bit rate in bits/sec */ /**<CNcomment: �������ݱ����� */
    HI_S16          nChannelsIn;   /**<number of channels on input (1,2) */ /**<CNcomment: ��������������*/
    HI_S16          nChannelsOut;  /**<number of channels on output (1,2) */ /**<CNcomment: �������������*/
    HI_S16          bandWidth;     /**<targeted audio bandwidth in Hz */ /**<CNcomment: ������ݴ�������*/
    AACENCTransportType transtype;
} AACENC_CONFIG;

typedef struct AAC_ENCODER AAC_ENCODER_S;

/**Defines AACENC version*/
/**CNcomment:����汾��Ϣ*/
typedef struct hiAACENC_VERSION_S
{
    HI_U8 aVersion[64];
} AACENC_VERSION_S;

/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API declaration *****************************/
/** \addtogroup      AACENC */
/** @{ */  /** <!--  ��AACENC�� */

/**
\brief Get version information. CNcomment:��ȡ�汾��Ϣ CNend
\attention \n
N/A
\param[in] pVersion       version describe struct CNcomment:�汾��Ϣ CNend
\retval ::HI_SUCCESS   : Success       CNcomment:�ɹ� CNend
\retval ::HI_FAILURE          : FAILURE.      CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32  HI_AACENC_GetVersion(AACENC_VERSION_S* pVersion);

/**
\brief get reasonable default configuration. CNcomment:��ȡĬ�����ò��� CNend
\attention \n
N/A
\param[in] pstConfig    pointer to an configuration information structure CNcomment:Ĭ�ϲ��� CNend
\retval ::HI_SUCCESS   : Success       CNcomment:�ɹ� CNend
\retval ::HI_FAILURE          : FAILURE.      CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32  AACInitDefaultConfig(AACENC_CONFIG* pstConfig);

/**
\brief allocate and initialize a new encoder instance. CNcomment:���������� CNend
\attention \n
N/A
\param[in] phAacPlusEnc    pointer to an configuration information structure CNcomment:��� CNend
\param[in] pstConfig    pointer to an configuration information structure CNcomment:���� CNend
\retval ::HI_SUCCESS   : Success       CNcomment:�ɹ� CNend
\retval ::HI_FAILURE   : FAILURE.      CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32  AACEncoderOpen(AAC_ENCODER_S** phAacPlusEnc, AACENC_CONFIG* pstConfig);

/**
\brief allocate and initialize a new encoder instance. CNcomment:���������� CNend
\attention \n
N/A
\param[in] hAacPlusEnc    pointer to an configuration information structure CNcomment:��� CNend
\param[in] ps16PcmBuf    BLOCKSIZE*nChannels audio samples, interleaved CNcomment:�������ݻ��� CNend
\param[in] pu8Outbuf    pointer to output buffer��(must be 6144/8*MAX_CHANNELS bytes large) CNcomment:������ݻ��� CNend
\param[in] ps32NumOutBytes    number of bytes in output buffer after processing CNcomment:���֡��CNend
\retval ::HI_SUCCESS   : Success       CNcomment:�ɹ� CNend
\retval ::HI_FAILURE   : FAILURE.      CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32  AACEncoderFrame(AAC_ENCODER_S* hAacPlusEnc, HI_S16* ps16PcmBuf,
                        HI_U8* pu8Outbuf, HI_S32* ps32NumOutBytes);

/**
\brief close encoder device. CNcomment:���ٽ����� CNend
\attention \n
N/A
\param[in] hAacPlusEnc    pointer to an configuration information structure CNcomment:��� CNend
\retval N/A
\see \n
N/A
*/
HI_VOID AACEncoderClose (AAC_ENCODER_S* hAacPlusEnc);
/** @} */  /** <!-- ==== API declaration end ==== */

#ifdef __cplusplus
#if __cplusplus
}
#endif     /* __cpluscplus */
#endif  /* __cpluscplus */

#endif  /* _AACENC_H */
