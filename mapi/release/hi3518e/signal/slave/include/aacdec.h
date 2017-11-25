/*****************************************************************************
*             Copyright 2004 - 2050, Hisilicon Tech. Co., Ltd.
*                           ALL RIGHTS RESERVED
* FileName: aacdec.h
* Description:
*
* History:
* Version   Date         Author     DefectNum    Description
* 0.01      2006-11-01   z40717    NULL         Create this file.
*
*****************************************************************************/
/**
 * \file
 * \brief Describes the information about AACDEC. CNcomment:�ṩAACDEC�������Ϣ CNend
 */

#ifndef _AACDEC_H
#define _AACDEC_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif  /* __cpluscplus */
#endif  /* __cpluscplus */

#include "hi_type.h"


/********************************Macro Definition********************************/
/** \addtogroup      AACENC */
/** @{ */  /** <!-- ��AACENC�� */

#ifndef AAC_MAX_NCHANS
#define AAC_MAX_NCHANS      2
#endif
#define AAC_MAX_NSAMPS      1024
#define AAC_MAINBUF_SIZE    (768 * AAC_MAX_NCHANS)  /**<according to spec (13818-7 section 8.2.2, 14496-3 section 4.5.3),6144 bits =  768 bytes per SCE or CCE-I,12288 bits = 1536 bytes per CPE*/
/**<CNcomment: �������ݳ��ȣ�����Э�飬SCE:768 bytes, CPE:1536*/

#define AAC_NUM_PROFILES    3
#define AAC_PROFILE_MP      0
#define AAC_PROFILE_LC      1
#define AAC_PROFILE_SSR     2

#ifndef HI_SUCCESS
#define HI_SUCCESS          0
#endif
/** @} */  /** <!-- ==== Macro Definition end ==== */

/*************************** Structure Definition ****************************/
/** \addtogroup      AACDEC */
/** @{ */  /** <!-- [AACDEC] */

/**Defines AACDEC error code*/
/**CNcomment:������������*/
enum
{
    ERR_AAC_NONE                          =   0,        /**<no decode error*/ /**<CNcomment: �޽������ */
    ERR_AAC_INDATA_UNDERFLOW              =  -1,        /**<not enough input data*/ /**<CNcomment: �������ݲ���*/
    ERR_AAC_NULL_POINTER                  =  -2,        /**<null pointer*/ /**<CNcomment: ��⵽�Ƿ�������ָ�� */
    ERR_AAC_INVALID_ADTS_HEADER           =  -3,        /**<invalid adts header*/ /**<CNcomment: �������������ADTSͷ��Ϣ�Ƿ� */
    ERR_AAC_INVALID_ADIF_HEADER           =  -4,        /**<invalid adif header*/ /**<CNcomment: ��⵽����������ADIFͷ��Ϣ�Ƿ� */
    ERR_AAC_INVALID_FRAME                 =  -5,        /**<invalid frame*/ /**<CNcomment: ��⵽SetRawBlockParams����AACDecInfo��Ϣ�Ƿ� */
    ERR_AAC_MPEG4_UNSUPPORTED             =  -6,        /**<upsupport mpeg4 format*/ /**<CNcomment: ��⵽��֧�ֵ�MPEG4 AAC������ʽ */
    ERR_AAC_CHANNEL_MAP                   =  -7,        /**<channel map error*/ /**<CNcomment: ��⵽�Ƿ�����������Ϣ */
    ERR_AAC_SYNTAX_ELEMENT                =  -8,        /**<element error*/ /**<CNcomment: ��⵽�������������� */
    ERR_AAC_DEQUANT                       =  -9,        /**<dequant error*/ /**<CNcomment: ����������������ģ����� */
    ERR_AAC_STEREO_PROCESS                = -10,        /**<stereo process error*/ /**<CNcomment: ����������������ģ��ģ����� */
    ERR_AAC_PNS                           = -11,        /**<pns process error*/ /**<CNcomment: ������PNS����ģ��ģ����� */
    ERR_AAC_SHORT_BLOCK_DEINT             = -12,        /**<reserved*/ /**<CNcomment: ������չ */
    ERR_AAC_TNS                           = -13,        /**<TNS process error*/ /**<CNcomment: ������TNS����ģ��ģ����� */
    ERR_AAC_IMDCT                         = -14,        /**<IMDCT process error*/ /**<CNcomment: ������IMDCT����ģ��ģ�����     */
    ERR_AAC_NCHANS_TOO_HIGH               = -15,        /**<unsupport mutil channel*/ /**<CNcomment: ��֧�Ŷ��������룬���֧������������ */
    ERR_AAC_SBR_INIT                      = -16,        /**<SBR init error*/ /**<CNcomment: ������SBR����ģ���ʼ������ */
    ERR_AAC_SBR_BITSTREAM                 = -17,        /**<SBR bitstream error*/ /**<CNcomment: ��⵽SBR������Ϣ�Ƿ� */
    ERR_AAC_SBR_DATA                      = -18,        /**<SBR data error*/ /**<CNcomment: ������SBR���ݷǷ� */
    ERR_AAC_SBR_PCM_FORMAT                = -19,        /**<SBR pcm data error*/ /**<CNcomment: ������SBR���ݵ�PCM_FORMAT��Ϣ�Ƿ� */
    ERR_AAC_SBR_NCHANS_TOO_HIGH           = -20,        /**<unsupport SBR multi channel*/ /**<CNcomment: ��֧��SBR���������룬���֧������������ */
    ERR_AAC_SBR_SINGLERATE_UNSUPPORTED    = -21,        /**<SBR invalid samplerate*/ /**<CNcomment: SBR����Ƶ�ʷǷ� */
    ERR_AAC_RAWBLOCK_PARAMS               = -22,        /**<invalid RawBlock params*/ /**<CNcomment: ��⵽SetRawBlockParams��������Ƿ� */
    ERR_AAC_PS_INIT                       = -23,        /**<PS init error*/ /**<CNcomment: ������PS����ģ���ʼ������ */
    ERR_AAC_CH_MAPPING                    = -24,
    ERR_UNKNOWN               = -9999                   /**<reserved*/ /**<CNcomment: ������չ */
};

typedef struct _AACFrameInfo
{
    int bitRate;
    int nChans;                      /**<channels,range:1,2*/ /**<CNcomment: 1 �� 2 */
    int sampRateCore;                /**<inner sample rate*/ /**<CNcomment: �ں˽����������ʣ�������Ϣ������Ϊ�������ʹ�� */
    int sampRateOut;                 /**<output samplerate*/ /**<CNcomment: ������������� */
    int bitsPerSample;               /**<bitwidth ,range:16*/ /**<CNcomment: 16��Ŀǰ��֧��16����λ����� */
    int outputSamps;                 /**<output samples*/ /**<CNcomment: nChans*SamplePerFrame */
    int profile;                     /**<profile*/ /**<CNcomment: profile,   ������Ϣ������Ϊ�������ʹ�� */
    int tnsUsed;                     /**<tns tools*/ /**<CNcomment: TNS Tools��������Ϣ������Ϊ�������ʹ�� */
    int pnsUsed;                     /**<pns tools*/ /**<CNcomment: PNS Tools��������Ϣ������Ϊ�������ʹ�� */
} AACFrameInfo;

typedef enum
{
    AACDEC_ADTS = 0,
    AACDEC_LOAS = 1,
    AACDEC_LATM_MCP1 = 2,
} AACDECTransportType;
typedef void* HAACDecoder;

typedef struct hiAACDEC_VERSION_S
{
    HI_U8 aVersion[64];
} AACDEC_VERSION_S;


/** @} */  /** <!-- ==== Structure Definition End ==== */

/******************************* API declaration *****************************/
/** \addtogroup      AACDEC */
/** @{ */  /** <!--  ��AACDEC�� */

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
HI_S32 HI_AACDEC_GetVersion(AACDEC_VERSION_S* pVersion);

/**
\brief create and initial decoder device. CNcomment:���������� CNend
\attention \n
N/A
\param[in] enTranType    transport type CNcomment:�����ʽ CNend
\retval ::HAACDecoder   : Success       CNcomment:�ɹ������ؾ�� CNend
\retval ::HI_FAILURE          : FAILURE.      CNcomment:ʧ�� CNend
\see \n
N/A
*/
HAACDecoder AACInitDecoder(AACDECTransportType enTranType);

/**
\brief destroy AAC-Decoder, free the memory.. CNcomment:���ٽ����� CNend
\attention \n
N/A
\param[in] hAACDecoder    AAC-Decoder handle CNcomment:��� CNend
\retval ::HAACDecoder   : Success       CNcomment:�ɹ������ؾ�� CNend
\retval ::HI_FAILURE          : FAILURE.      CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_VOID AACFreeDecoder(HAACDecoder hAACDecoder);

/**
\brief set RawMode before decode Raw Format aac bitstream. CNcomment:����rawģʽ CNend
\attention \n
N/A
\param[in] hAACDecoder   AAC-Decoder handle CNcomment:��� CNend
\param[in] nChans    inout channels CNcomment:���������� CNend
\param[in] sampRate    input sampelrate CNcomment:���������CNend
\retval ::HAACDecoder   : Success       CNcomment:�ɹ������ؾ�� CNend
\retval ::ERROR_CODE          : FAILURE.      CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32  AACSetRawMode(HAACDecoder hAACDecoder, HI_S32 nChans, HI_S32 sampRate);

/**
\brief look for valid AAC sync header. CNcomment:��֡ͬ���� CNend
\attention \n
N/A
\param[in] hAACDecoder   AAC-Decoder handle CNcomment:��� CNend
\param[in] ppInbufPtr    address of the pointer of start-point of the bitstream CNcomment:�������ݻ��� CNend
\param[in] pBytesLeft    pointer to BytesLeft that indicates bitstream numbers at input buffer CNcomment:�������ݳ��� CNend
\retval ::<0    : ERR_AAC_INDATA_UNDERFLOW     CNcomment:ʧ�� CNend
\retval ::other : Success, return number bytes of current frame.      CNcomment:�ɹ�������֡��CNend
\see \n
N/A
*/
HI_S32 AACDecodeFindSyncHeader(HAACDecoder hAACDecoder, HI_U8** ppInbufPtr, HI_S32* pBytesLeft);

/**
\brief decoding AAC frame and output 1024(LC) OR 2048(HEAAC/eAAC/eAAC+) 16bit PCM samples per channel. CNcomment:AAC���� CNend
\attention \n
\param[in] hAACDecoder    AAC-Decoder handle CNcomment:AAC��� CNend
\param[in] ppInbufPtr     address of the pointer of start-point of the bitstream CNcomment:��������С��ģʽ�׵�ַ CNend
\param[in] pBytesLeft     pointer to BytesLeft that indicates bitstream numbers at input buffer��indicates the left bytes CNcomment:��������ʣ�����ݳ��� CNend
\param[in] pOutPcm        the address of the out pcm buffer,pcm data in noninterlaced fotmat: L/L/L/... R/R/R/... CNcomment:�������С��ģʽ�׵�ַ���ǽ�֯ģʽ��� CNend
\param[in] nReserved      reserved CNcomment:���� CNend
\retval :: SUCCESS : Success CNcomment:�ɹ� CNend
\retval :: ERROR_CODE :FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32  AACDecodeFrame(HAACDecoder hAACDecoder, HI_U8** ppInbufPtr, HI_S32* pBytesLeft, HI_S16* pOutPcm);

/**
\brief get the frame information. CNcomment:��ȡ�����֡��Ϣ CNend
\attention \n
\param[in] hAACDecoder    AAC-Decoder handle CNcomment:AAC��� CNend
\param[out] aacFrameInfo  frame information CNcomment:����ṹ����Ϣ CNend
\retval \n
\see \n
N/A
*/
HI_VOID AACGetLastFrameInfo(HAACDecoder hAACDecoder, AACFrameInfo* aacFrameInfo);

/**
\brief set eosflag. CNcomment:���ý�����־ CNend
\attention \n
\param[in] hAACDecoder    AAC-Decoder handle CNcomment:AAC��� CNend
\param[out] s32Eosflag  end flag CNcomment:������־ CNend
\retval :: SUCCESS : Success CNcomment:�ɹ� CNend
\retval :: ERROR_CODE :FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32 AACDecoderSetEosFlag(HAACDecoder hAACDecoder, HI_S32 s32Eosflag);

/**
\brief flush internal codec state (after seeking, for example). CNcomment:ˢ�½����� CNend
\attention \n
\param[in] hAACDecoder    AAC-Decoder handle CNcomment:AAC��� CNend
\retval :: SUCCESS : Success CNcomment:�ɹ� CNend
\retval :: ERROR_CODE :FAILURE CNcomment:ʧ�� CNend
\see \n
N/A
*/
HI_S32  AACFlushCodec(HAACDecoder hAACDecoder);

/** @} */  /** <!-- ==== API declaration end ==== */


#ifdef __cplusplus
#if __cplusplus
}
#endif  /* __cpluscplus */
#endif  /* __cpluscplus */

#endif  /* _AACDEC_H */
