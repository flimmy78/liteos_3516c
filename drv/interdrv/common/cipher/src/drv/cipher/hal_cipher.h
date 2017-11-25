/******************************************************************************

  Copyright (C), 2011-2014, Hisilicon Tech. Co., Ltd.

 ******************************************************************************
  File Name     : hal_cipher.h
  Version       : Initial Draft
  Author        : Hisilicon hisecurity team
  Created       : 
  Last Modified :
  Description   : 
  Function List :
  History       :
******************************************************************************/

#ifndef __HAL_CIPHER_H__
#define __HAL_CIPHER_H__

#include "hi_osal.h"
#include "drv_cipher_reg.h"
#include "drv_cipher_ioctl.h"
#include "drv_cipher_define.h"
#include "hi_unf_cipher.h"

#ifdef __cplusplus
extern "C" {
#endif
/***************************** Macro Definition ******************************/

#define  CIPHER_CHAN_NUM                        (8)
#define  CIPHER_PKGx1_CHAN                      (0)
#define  CIPHER_PKGxN_CHAN_MIN                  (1)
#define  CIPHER_PKGxN_CHAN_MAX                  (7)
#define  CIPHER_HMAC_KEY_LEN                    (16)
  
/*************************** Structure Definition ****************************/
/** */
typedef enum hiCIPHER_INT_TYPE_E
{
    CIPHER_INT_TYPE_IN_BUF  = 					0x1,
    CIPHER_INT_TYPE_OUT_BUF = 					0x2,
} CIPHER_INT_TYPE_E;

typedef enum hiCIPHER_BUF_TYPE_E
{
    CIPHER_BUF_TYPE_IN  = 						0x1,
    CIPHER_BUF_TYPE_OUT = 						0x2,
} CIPHER_BUF_TYPE_E;

typedef enum hiCIPHER_RSA_DATA_TYPE_E
{
    CIPHER_RSA_DATA_TYPE_CONTEXT,
    CIPHER_RSA_DATA_TYPE_MODULE,
    CIPHER_RSA_DATA_TYPE_KEY,
} CIPHER_RSA_DATA_TYPE_E;

typedef enum hiCIPHER_RSA_KEY_WIDTH_E
{ 
    CIPHER_RSA_KEY_WIDTH_1K = 0x00,
    CIPHER_RSA_KEY_WIDTH_2K = 0x01,
    CIPHER_RSA_KEY_WIDTH_4K = 0x02,
}CIPHER_RSA_KEY_WIDTH_E;

/******************************* API declaration *****************************/

#ifdef CIPHER_MULTICIPHER_SUPPORT
HI_S32 HAL_Cipher_GetInBufCnt(HI_U32 chnId, HI_U32 *pNum);
HI_S32 HAL_Cipher_GetInBufEmpty(HI_U32 chnId, HI_U32 *pNum);
HI_S32 HAL_Cipher_GetInBufNum(HI_U32 chnId, HI_U32 *pNum);
HI_S32 HAL_Cipher_GetOutBufCnt(HI_U32 chnId, HI_U32 *pNum);
HI_S32 HAL_Cipher_GetOutBufFull(HI_U32 chnId, HI_U32 *pNum);
HI_S32 HAL_Cipher_GetOutBufNum(HI_U32 chnId, HI_U32 *pNum);
HI_S32 HAL_Cipher_SetInBufCnt(HI_U32 chnId, HI_U32 num);
HI_S32 HAL_Cipher_SetInBufEmpty(HI_U32 chnId, HI_U32 num);
HI_S32 HAL_Cipher_SetInBufNum(HI_U32 chnId, HI_U32 num);
HI_S32 HAL_Cipher_SetOutBufCnt(HI_U32 chnId, HI_U32 num);
HI_S32 HAL_Cipher_SetOutBufFull(HI_U32 chnId, HI_U32 num);
HI_S32 HAL_Cipher_SetOutBufNum(HI_U32 chnId, HI_U32 num);

HI_S32 HAL_Cipher_SetAGEThreshold(HI_U32 chnId, CIPHER_INT_TYPE_E intType, HI_U32 value);
HI_S32 HAL_Cipher_SetIntThreshold(HI_U32 chnId, CIPHER_INT_TYPE_E intType, HI_U32 value);
HI_VOID HAL_Cipher_DisableAllInt(HI_VOID);
HI_S32 HAL_Cipher_DisableInt(HI_U32 chnId, int intType);
HI_S32 HAL_Cipher_EnableInt(HI_U32 chnId, int intType);
HI_VOID HAL_Cipher_GetRawIntState(HI_U32 *pState);
HI_VOID HAL_Cipher_ClrIntState(HI_U32 intStatus);
HI_VOID HAL_Cipher_GetIntState(HI_U32 *pState);
HI_VOID HAL_Cipher_GetIntEnState(HI_U32 *pState);
HI_VOID HAL_Cipher_EnableAllSecChn(HI_VOID);
HI_VOID HAL_Cipher_SetHDMITxRxOtpSelReg(HI_VOID);
HI_S32 HAL_Cipher_Config(HI_U32 chnId, HI_BOOL bDecrypt, HI_BOOL bIVChange, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_Cipher_SetBufAddr(HI_U32 chnId, CIPHER_BUF_TYPE_E bufType, HI_U32 addr);
HI_S32 HAL_Cipher_SetInIV(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_Cipher_GetOutIV(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_Cipher_GetTag(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl, HI_U32 *pu32Tag);
HI_S32 HAL_Cipher_SetLen(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_Cipher_CleanAadEnd(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_Cipher_WaitAadEnd(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_Cipher_CleanTagVld(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_RSA_WaitTagVld(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_Cipher_SetKey(HI_U32 chnId, HI_UNF_CIPHER_CTRL_S* pCtrl);
HI_S32 HAL_CIPHER_LoadSTBRootKey(HI_U32 u32HwChID);

HI_S32 HAL_Cipher_SetDataSinglePkg(HI_DRV_CIPHER_DATA_INFO_S * info);
HI_S32 HAL_Cipher_StartSinglePkg(HI_U32 chnId);
HI_S32 HAL_Cipher_ReadDataSinglePkg(HI_U32 *pData);

#ifdef CIPHER_KLAD_SUPPORT
HI_S32 HAL_Cipher_KladConfig(HI_U32 chnId, 
                             HI_U32 u32OptId, 
                             HI_UNF_CIPHER_KLAD_TARGET_E enTarget, 
                             HI_BOOL bIsDecrypt);

HI_VOID HAL_Cipher_StartKlad(HI_VOID);
HI_VOID HAL_Cipher_SetKladData(HI_U32 *pu32DataIn);
HI_VOID HAL_Cipher_GetKladData(HI_U32 *pu32DataOut);
HI_S32 HAL_Cipher_WaitKladDone(HI_VOID);
#endif

HI_S32 HAL_Cipher_WaitIdle(HI_VOID);
HI_BOOL HAL_Cipher_IsIdle(HI_U32 chn);
HI_VOID HAL_Cipher_Reset(HI_VOID);
HI_VOID HAL_Cipher_Init(void);
HI_VOID HAL_Cipher_DeInit(void);
#endif

#ifdef CIPHER_RNG_SUPPORT
HI_S32 HAL_Cipher_GetRandomNumber(CIPHER_RNG_S *pstRNG);
#endif


HI_VOID HAL_CIPHER_ReadReg(HI_U32 addr, HI_U32 *pu32Val);
HI_VOID HAL_CIPHER_WriteReg(HI_U32 addr, HI_U32 u32Val);

HI_S32 HAL_CIPHER_ProcGetStatus(CIPHER_CHN_STATUS_S *pstCipherStatus);

#ifdef CIPHER_RSA_SUPPORT
HI_VOID HAL_RNG_Reset(HI_VOID);

HI_VOID HAL_RSA_Reset(HI_VOID);
HI_S32 HAL_RSA_WaitFree(HI_VOID);
HI_VOID HAL_RSA_Start(HI_VOID);
HI_VOID HAL_RSA_ClearRam(HI_VOID);
HI_VOID HAL_RSA_ConfigMode(CIPHER_RSA_KEY_WIDTH_E enKenWidth);
HI_VOID HAL_RSA_WriteData(CIPHER_RSA_DATA_TYPE_E enDataType, HI_U8 *pu8Data, HI_U32 u32DataLen, HI_U32 u32Len);
HI_VOID HAL_RSA_ReadData(HI_U8 *pu8Data, HI_U32 u32DataLen, HI_U32 u32Len);
HI_U32 HAL_RSA_GetErrorCode(HI_VOID);
#endif

#ifdef __cplusplus
}
#endif
#endif /* __HAL_CIPHER_H__ */


