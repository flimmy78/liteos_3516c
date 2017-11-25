#ifndef __HI_UNF_CIPHER_H__
#define __HI_UNF_CIPHER_H__

#include "hi_type.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */
/*************************** Structure Definition ****************************/
/** \addtogroup      CIPHER */
/** @{ */  /** <!-- [CIPHER] */

/** min length of encrypt, unit: byte */
/** CNcomment: ��С�ӽ��ܳ��ȣ���λbyte */
#define HI_UNF_CIPHER_MIN_CRYPT_LEN      1

/** max length of encrypt, unit: byte */
/** CNcomment: ���ӽ��ܳ��ȣ���λbyte */
#define HI_UNF_CIPHER_MAX_CRYPT_LEN      0xfffff

#define HI_UNF_CIPHER_MAX_RSA_KEY_LEN    (512)

/** Cipher work mode */
/** CNcomment:CIPHER����ģʽ */
typedef enum hiHI_UNF_CIPHER_WORK_MODE_E
{
    HI_UNF_CIPHER_WORK_MODE_ECB,        /**<Electronic codebook (ECB) mode*/    /**< CNcomment:ECBģʽ */
    HI_UNF_CIPHER_WORK_MODE_CBC,        /**<Cipher block chaining (CBC) mode*/  /**< CNcomment:CBCģʽ */
    HI_UNF_CIPHER_WORK_MODE_CFB,        /**<Cipher feedback (CFB) mode*/        /**< CNcomment:CFBģʽ */
    HI_UNF_CIPHER_WORK_MODE_OFB,        /**<Output feedback (OFB) mode*/        /**< CNcomment:OFBģʽ */
    HI_UNF_CIPHER_WORK_MODE_CTR,        /**<Counter (CTR) mode*/                /**< CNcomment:CTRģʽ */
    HI_UNF_CIPHER_WORK_MODE_CCM,
    HI_UNF_CIPHER_WORK_MODE_GCM,
    HI_UNF_CIPHER_WORK_MODE_CBC_CTS,    /**<Cipher block chaining CipherStealing mode*/  /**< CNcomment:CBC-CTSģʽ */
    HI_UNF_CIPHER_WORK_MODE_BUTT    = 0xffffffff
}HI_UNF_CIPHER_WORK_MODE_E;

/** Cipher algorithm */
/** CNcomment:CIPHER�����㷨 */
typedef enum hiHI_UNF_CIPHER_ALG_E
{
    HI_UNF_CIPHER_ALG_DES           = 0x0,  /**< Data encryption standard (DES) algorithm */     /**< CNcomment: DES�㷨 */
    HI_UNF_CIPHER_ALG_3DES          = 0x1,  /**< 3DES algorithm */                               /**< CNcomment: 3DES�㷨 */
    HI_UNF_CIPHER_ALG_AES           = 0x2,  /**< Advanced encryption standard (AES) algorithm */ /**< CNcomment: AES�㷨 */
    HI_UNF_CIPHER_ALG_BUTT          = 0x3
}HI_UNF_CIPHER_ALG_E;

/** Key length */
/** CNcomment: ��Կ���� */
typedef enum hiHI_UNF_CIPHER_KEY_LENGTH_E
{
    HI_UNF_CIPHER_KEY_AES_128BIT    = 0x0,  /**< 128-bit key for the AES algorithm */ /**< CNcomment:AES���㷽ʽ�²���128bit��Կ���� */
    HI_UNF_CIPHER_KEY_AES_192BIT    = 0x1,  /**< 192-bit key for the AES algorithm */ /**< CNcomment:AES���㷽ʽ�²���192bit��Կ���� */
    HI_UNF_CIPHER_KEY_AES_256BIT    = 0x2,  /**< 256-bit key for the AES algorithm */ /**< CNcomment:AES���㷽ʽ�²���256bit��Կ���� */
    HI_UNF_CIPHER_KEY_DES_3KEY      = 0x2,  /**< Three keys for the DES algorithm */  /**< CNcomment:DES���㷽ʽ�²���3��key */
    HI_UNF_CIPHER_KEY_DES_2KEY      = 0x3,  /**< Two keys for the DES algorithm */    /**< CNcomment: DES���㷽ʽ�²���2��key  */
}HI_UNF_CIPHER_KEY_LENGTH_E;

/** Cipher bit width */
/** CNcomment: ����λ�� */
typedef enum hiHI_UNF_CIPHER_BIT_WIDTH_E
{
    HI_UNF_CIPHER_BIT_WIDTH_64BIT   = 0x0,  /**< 64-bit width */   /**< CNcomment:64bitλ�� */
    HI_UNF_CIPHER_BIT_WIDTH_8BIT    = 0x1,  /**< 8-bit width */    /**< CNcomment:8bitλ�� */
    HI_UNF_CIPHER_BIT_WIDTH_1BIT    = 0x2,  /**< 1-bit width */    /**< CNcomment:1bitλ�� */
    HI_UNF_CIPHER_BIT_WIDTH_128BIT  = 0x3,  /**< 128-bit width */  /**< CNcomment:128bitλ�� */
}HI_UNF_CIPHER_BIT_WIDTH_E;

/** Cipher control parameters */
/** CNcomment:���ܿ��Ʋ��������־ */
typedef struct hiHI_UNF_CIPHER_CTRL_CHANGE_FLAG_S
{
    HI_U32   bit1IV:1;              /**< Initial Vector change or not */ /**< CNcomment:������� */
    HI_U32   bitsResv:31;           /**< Reserved */                     /**< CNcomment:���� */
}HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S;

/** Encryption/Decryption type selecting */
/** CNcomment:CIPHE KEY ����ѡ�� */
typedef enum hiHI_UNF_CIPHER_KEY_SRC_E
{
    HI_UNF_CIPHER_KEY_SRC_USER       = 0x0,  /**< User Key*/     /**< CNcomment: �û����õ�Key*/
    HI_UNF_CIPHER_KEY_SRC_EFUSE_0,          /**< Efuse Key 0*/ /**< CNcomment: Efuse�ĵ�0��Key*/
    HI_UNF_CIPHER_KEY_SRC_EFUSE_1,          /**< Efuse Key 1*/ /**< CNcomment: Efuse�ĵ�1��Key*/
    HI_UNF_CIPHER_KEY_SRC_EFUSE_2,          /**< Efuse Key 2*/ /**< CNcomment: Efuse�ĵ�2��Key*/
    HI_UNF_CIPHER_KEY_SRC_EFUSE_3,          /**< Efuse Key 3*/ /**< CNcomment: Efuse�ĵ�3��Key*/
    HI_UNF_CIPHER_KEY_SRC_KLAD_1,           /**< KLAD Key 1*/ /**< CNcomment: KLAD�ĵ�1��Key, ��Root KeyΪEfuse�ĵ�1��Key*/
    HI_UNF_CIPHER_KEY_SRC_KLAD_2,           /**< KLAD Key 2*/ /**< CNcomment: KLAD�ĵ�2��Key, ��Root KeyΪEfuse�ĵ�2��Key*/
    HI_UNF_CIPHER_KEY_SRC_KLAD_3,           /**< KLAD Key 3*/ /**< CNcomment: KLAD�ĵ�3��Key, ��Root KeyΪEfuse�ĵ�3��Key*/
    HI_UNF_CIPHER_KEY_SRC_BUTT,
}HI_UNF_CIPHER_KEY_SRC_E;

typedef struct hiUNF_CIPHER_CCM_INFO_S
{
    HI_U8  u8Nonce[16];
    HI_U8 *pu8Aad;
    HI_U32 u32ALen;
    HI_U32 u32MLen;
    HI_U8  u8NLen;
    HI_U8  u8TLen;
    HI_U8  u8Reserve[2];
}HI_UNF_CIPHER_CCM_INFO_S;

typedef struct hiUNF_CIPHER_GCM_INFO_S
{
    HI_U8 *pu8Aad;
    HI_U32 u32ALen;
    HI_U32 u32MLen;
    HI_U32 u32IVLen;
}HI_UNF_CIPHER_GCM_INFO_S;

/** Structure of the cipher control information */
/** CNcomment:���ܿ�����Ϣ�ṹ */
typedef struct hiHI_UNF_CIPHER_CTRL_S
{
    HI_U32 u32Key[8];                               /**< Key input */                                                                                                     /**< CNcomment:������Կ */
    HI_U32 u32IV[4];                                /**< Initialization vector (IV) */                                                                                    /**< CNcomment:��ʼ���� */
    HI_UNF_CIPHER_ALG_E enAlg;                      /**< Cipher algorithm */                                                                                              /**< CNcomment:�����㷨 */
    HI_UNF_CIPHER_BIT_WIDTH_E enBitWidth;           /**< Bit width for encryption or decryption */                                                                        /**< CNcomment:���ܻ���ܵ�λ�� */
    HI_UNF_CIPHER_WORK_MODE_E enWorkMode;           /**< Operating mode */                                                                                                /**< CNcomment:����ģʽ */
    HI_UNF_CIPHER_KEY_LENGTH_E enKeyLen;            /**< Key length */                                                                                                    /**< CNcomment:��Կ���� */
    HI_UNF_CIPHER_CTRL_CHANGE_FLAG_S stChangeFlags; /**< control information exchange choices, we default all woulde be change except they have been in the choices */    /**< CNcomment:������Ϣ���ѡ�ѡ����û�б�ʶ����Ĭ��ȫ����� */
    HI_UNF_CIPHER_KEY_SRC_E enKeySrc;             /**< Key source */ /**< CNcomment:Key����Դ��������CPU���ã�Ҳ���Դ�EFUSE����*/
    union
    {
        HI_UNF_CIPHER_CCM_INFO_S stCCM;
        HI_UNF_CIPHER_GCM_INFO_S stGCM;
    }unModeInfo;
} HI_UNF_CIPHER_CTRL_S;

/** Cipher data */
/** CNcomment:�ӽ������� */
typedef struct hiHI_UNF_CIPHER_DATA_S
{
    HI_U32 u32SrcPhyAddr;     /**< phy address of the original data */   /**< CNcomment:Դ���������ַ */
    HI_U32 u32DestPhyAddr;    /**< phy address of the purpose data */    /**< CNcomment:Ŀ�����������ַ */
    HI_U32 u32ByteLength;     /**< cigher data length*/                 /**< CNcomment:�ӽ������ݳ��� */
} HI_UNF_CIPHER_DATA_S;

/** Hash algrithm type */
/** CNcomment:��ϣ�㷨���� */
typedef enum hiHI_UNF_CIPHER_HASH_TYPE_E
{
    HI_UNF_CIPHER_HASH_TYPE_SHA1,
    HI_UNF_CIPHER_HASH_TYPE_SHA256,
    HI_UNF_CIPHER_HASH_TYPE_HMAC_SHA1,
    HI_UNF_CIPHER_HASH_TYPE_HMAC_SHA256,
    HI_UNF_CIPHER_HASH_TYPE_BUTT,
}HI_UNF_CIPHER_HASH_TYPE_E;

/** Hash init struct input */
/** CNcomment:��ϣ�㷨��ʼ������ṹ�� */
typedef struct
{
    HI_U8 *pu8HMACKey;
    HI_U32 u32HMACKeyLen;
    HI_UNF_CIPHER_HASH_TYPE_E eShaType;
}HI_UNF_CIPHER_HASH_ATTS_S;

/** RSA encryption scheme*/
/** CNcomment:RSA�㷨���ݼ�����䷽ʽ*/
typedef enum hiHI_UNF_CIPHER_RSA_ENC_SCHEME_E
{ 
    HI_UNF_CIPHER_RSA_ENC_SCHEME_NO_PADDING,            /**< without padding */             /**< CNcomment: ����� */
    HI_UNF_CIPHER_RSA_ENC_SCHEME_BLOCK_TYPE_0,          /**< PKCS#1 block type 0 padding*/  /**< CNcomment: PKCS#1��block type 0��䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_BLOCK_TYPE_1,          /**< PKCS#1 block type 1 padding*/  /**< CNcomment: PKCS#1��block type 1��䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_BLOCK_TYPE_2,          /**< PKCS#1 block type 2 padding*/  /**< CNcomment: PKCS#1��block type 2��䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_OAEP_SHA1,  /**< PKCS#1 RSAES-OAEP-SHA1 padding*/    /**< CNcomment: PKCS#1��RSAES-OAEP-SHA1��䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_OAEP_SHA256,/**< PKCS#1 RSAES-OAEP-SHA256 padding*/  /**< CNcomment: PKCS#1��RSAES-OAEP-SHA256��䷽ʽ*/
    HI_UNF_CIPHER_RSA_ENC_SCHEME_RSAES_PKCS1_V1_5,      /**< PKCS#1 RSAES-PKCS1_V1_5 padding*/   /**< CNcomment: PKCS#1��PKCS1_V1_5��䷽ʽ*/
    HI_UNF_CIPHER_RSA_SCHEME_BUTT,
}HI_UNF_CIPHER_RSA_ENC_SCHEME_E;

/** RSA signature algorithms*/
/** CNcomment:RSA����ǩ���㷨*/
typedef enum hiHI_UNF_CIPHER_RSA_SIGN_SCHEME_E
{ 
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_V15_SHA1 = 0x100, /**< PKCS#1 RSASSA_PKCS1_V15_SHA1 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_V15_SHA1ǩ���㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_V15_SHA256,       /**< PKCS#1 RSASSA_PKCS1_V15_SHA256 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_V15_SHA256ǩ���㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_PSS_SHA1,         /**< PKCS#1 RSASSA_PKCS1_PSS_SHA1 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_PSS_SHA1ǩ���㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_RSASSA_PKCS1_PSS_SHA256,       /**< PKCS#1 RSASSA_PKCS1_PSS_SHA256 signature*/   /**< CNcomment: PKCS#1 RSASSA_PKCS1_PSS_SHA256ǩ���㷨*/
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_BUTT,
}HI_UNF_CIPHER_RSA_SIGN_SCHEME_E;

/** RSA public key struct */
/** CNcomment:RSA��Կ�ṹ�� */
typedef struct
{
    HI_U8  *pu8N;              /**< point to public modulus  */   /**< CNcomment: ָ��RSA��ԿN��ָ��*/
	HI_U8  *pu8E;			   /**< point to public exponent */   /**< CNcomment: ָ��RSA��ԿE��ָ��*/
    HI_U16 u16NLen;            /**< length of public modulus */  /**< CNcomment: RSA��ԿN�ĳ���*/
    HI_U16 u16ELen;            /**< length of public exponent */  /**< CNcomment: RSA��ԿE�ĳ���*/
}HI_UNF_CIPHER_RSA_PUB_KEY_S;

/** RSA private key struct */
/** CNcomment:RSA˽Կ�ṹ�� */
typedef struct
{
    HI_U8 *pu8N;                      /*!<  public modulus    */ /**< CNcomment: ָ��RSA��ԿN��ָ��*/
    HI_U8 *pu8E;                      /*!<  public exponent   */ /**< CNcomment: ָ��RSA��ԿE��ָ��*/
    HI_U8 *pu8D;                      /*!<  private exponent  */ /**< CNcomment: ָ��RSA˽ԿD��ָ��*/
    HI_U8 *pu8P;                      /*!<  1st prime factor  */ /**< CNcomment: ָ��RSA˽ԿP��ָ��*/
    HI_U8 *pu8Q;                      /*!<  2nd prime factor  */ /**< CNcomment: ָ��RSA˽ԿQ��ָ��*/
    HI_U8 *pu8DP;                     /*!<  D % (P - 1)       */ /**< CNcomment: ָ��RSA˽ԿDP��ָ��*/
    HI_U8 *pu8DQ;                     /*!<  D % (Q - 1)       */ /**< CNcomment: ָ��RSA˽ԿDQ��ָ��*/
    HI_U8 *pu8QP;                     /*!<  1 / (Q % P)       */ /**< CNcomment: ָ��RSA˽ԿQP��ָ��*/
    HI_U16 u16NLen;                   /**< length of public modulus */   /**< CNcomment: RSA��ԿN�ĳ���*/
    HI_U16 u16ELen;                   /**< length of public exponent */  /**< CNcomment: RSA��ԿE�ĳ���*/
    HI_U16 u16DLen;                   /**< length of private exponent */ /**< CNcomment: RSA˽ԿD�ĳ���*/
    HI_U16 u16PLen;                   /**< length of 1st prime factor */ /**< CNcomment: RSA˽ԿP�ĳ���*/
    HI_U16 u16QLen;                   /**< length of 2nd prime factor */ /**< CNcomment: RSA˽ԿQ�ĳ���*/
    HI_U16 u16DPLen;                  /**< length of D % (P - 1) */      /**< CNcomment: RSA˽ԿDP�ĳ���*/
    HI_U16 u16DQLen;                  /**< length of D % (Q - 1) */      /**< CNcomment: RSA˽ԿDQ�ĳ���*/
    HI_U16 u16QPLen;                  /**< length of 1 / (Q % P) */      /**< CNcomment: RSA˽ԿQP�ĳ���*/
}HI_UNF_CIPHER_RSA_PRI_KEY_S;

/** RSA public key encryption struct input */
/** CNcomment:RSA ��Կ�ӽ����㷨��������ṹ�� */
typedef struct
{
    HI_UNF_CIPHER_RSA_ENC_SCHEME_E enScheme;   /** RSA encryption scheme*/ /** CNcomment:RSA���ݼӽ����㷨*/
    HI_UNF_CIPHER_RSA_PUB_KEY_S stPubKey;      /** RSA private key struct */ /** CNcomment:RSA˽Կ�ṹ�� */
}HI_UNF_CIPHER_RSA_PUB_ENC_S;

/** RSA private key decryption struct input */
/** CNcomment:RSA ˽Կ�����㷨��������ṹ�� */
typedef struct
{
    HI_UNF_CIPHER_RSA_ENC_SCHEME_E enScheme; /** RSA encryption scheme */ /** CNcomment:RSA���ݼӽ����㷨*/
    HI_UNF_CIPHER_RSA_PRI_KEY_S stPriKey;    /** RSA public key struct */ /** CNcomment:RSA��Կ�ṹ�� */
    HI_UNF_CIPHER_KEY_SRC_E enKeySrc;
}HI_UNF_CIPHER_RSA_PRI_ENC_S;

/** RSA signature struct input */
/** CNcomment:RSAǩ���㷨��������ṹ�� */
typedef struct
{
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_E enScheme;  /** RSA signature scheme*/ /** CNcomment:RSA����ǩ���㷨*/
    HI_UNF_CIPHER_RSA_PRI_KEY_S stPriKey;      /** RSA private key struct */ /** CNcomment:RSA˽Կ�ṹ�� */
    HI_UNF_CIPHER_KEY_SRC_E enKeySrc;
 }HI_UNF_CIPHER_RSA_SIGN_S;

/** RSA signature verify struct input */
/** CNcomment:RSAǩ����֤�㷨��������ṹ�� */
typedef struct
{
    HI_UNF_CIPHER_RSA_SIGN_SCHEME_E enScheme; /** RSA signature scheme*/ /** CNcomment:RSA����ǩ���㷨*/
    HI_UNF_CIPHER_RSA_PUB_KEY_S stPubKey;     /** RSA public key struct */ /** CNcomment:RSA��Կ�ṹ�� */
 }HI_UNF_CIPHER_RSA_VERIFY_S;

/** @} */  /** <!-- ==== Structure Definition End ==== */


#define HI_UNF_CIPHER_Open(HI_VOID) HI_UNF_CIPHER_Init(HI_VOID);
#define HI_UNF_CIPHER_Close(HI_VOID) HI_UNF_CIPHER_DeInit(HI_VOID);

/******************************* API Declaration *****************************/
/** \addtogroup      CIPHER */
/** @{ */  /** <!-- [CIPHER] */
/* ---CIPHER---*/
/**
\brief  Init the cipher device.  CNcomment:��ʼ��CIPHER�豸�� CNend
\attention \n
This API is used to start the cipher device.
CNcomment:���ô˽ӿڳ�ʼ��CIPHER�豸�� CNend
\param N/A                                                                      CNcomment:�� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                 CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_FAILED_INIT  The cipher device fails to be initialized. CNcomment:CIPHER�豸��ʼ��ʧ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Init(HI_VOID);

/**
\brief  Deinit the cipher device.
CNcomment:\brief  ȥ��ʼ��CIPHER�豸�� CNend
\attention \n
This API is used to stop the cipher device. If this API is called repeatedly, HI_SUCCESS is returned, but only the first operation takes effect.
CNcomment:���ô˽ӿڹر�CIPHER�豸���ظ��رշ��سɹ�����һ�������á� CNend

\param N/A                                                                      CNcomment:�� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                 CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER�豸δ��ʼ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DeInit(HI_VOID);

/**
\brief Obtain a cipher handle for encryption and decryption.
CNcomment������һ·Cipher����� CNend

\param[in] cipher attributes                                                    CNcomment:cipher ���ԡ� CNend
\param[out] phCipher Cipher handle                                              CNcomment:CIPHER����� CNend
\retval ::HI_SUCCESS Call this API succussful.                                  CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE Call this API fails.                                       CNcomment: APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_POINT  The pointer is null.                     CNcomment:ָ�����Ϊ�� CNend
\retval ::HI_ERR_CIPHER_FAILED_GETHANDLE  The cipher handle fails to be obtained, because there are no available cipher handles. CNcomment: ��ȡCIPHER���ʧ�ܣ�û�п��е�CIPHER��� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_CreateHandle(HI_HANDLE* phCipher);

/**
\brief Destroy the existing cipher handle. CNcomment:�����Ѵ��ڵ�CIPHER����� CNend
\attention \n
This API is used to destroy existing cipher handles.
CNcomment:���ô˽ӿ������Ѿ�������CIPHER����� CNend

\param[in] hCipher Cipher handle                                                CNcomment:CIPHER����� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                 CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER�豸δ��ʼ�� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DestroyHandle(HI_HANDLE hCipher);

/**
\brief Get the random number.
CNcomment:\brief ��ȡ������� CNend

\attention \n
This API is used to obtain the random number from the hardware.
CNcomment:���ô˽ӿ����ڻ�ȡ������� CNend

\param[out] pu32RandomNumber Point to the random number.                                        CNcomment:�������ֵ�� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                 CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                                                      CNcomment: APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_GetRandomNumber(HI_U32 *pu32RandomNumber);

/**
\brief Configures the cipher control information.
CNcomment:\brief ����CIPHER������Ϣ�� CNend
\attention \n
Before encryption or decryption, you must call this API to configure the cipher control information.
The first 64-bit data and the last 64-bit data should not be the same when using TDES algorithm.
CNcomment:���м��ܽ���ǰ������ʹ�ô˽ӿ�����CIPHER�Ŀ�����Ϣ��ʹ��TDES�㷨ʱ��������Կ��ǰ��64 bit���ݲ�����ͬ�� CNend

\param[in] hCipher Cipher handle.                                               CNcomment:CIPHER��� CNend
\param[in] pstCtrl Cipher control information.                                  CNcomment:CIPHER������Ϣ CNend
\retval ::HI_SUCCESS Call this API succussful.                                  CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE Call this API fails.                                       CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_POINT  The pointer is null.                     CNcomment:ָ�����Ϊ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:�������� CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                  CNcomment:����Ƿ� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_ConfigHandle(HI_HANDLE hCipher, HI_UNF_CIPHER_CTRL_S* pstCtrl);

/**
\brief Performs encryption.
CNcomment:\brief ���м��ܡ� CNend

\attention \n
This API is used to perform encryption by using the cipher module.
The length of the encrypted data should be a multiple of 8 in TDES mode and 16 in AES mode. Besides, the length can not be bigger than 0xFFFFF.After this operation, the result will affect next operation.If you want to remove vector, you need to config IV(config pstCtrl->stChangeFlags.bit1IV with 1) by transfering HI_UNF_CIPHER_ConfigHandle.
CNcomment:ʹ��CIPHER���м��ܲ�����TDESģʽ�¼��ܵ����ݳ���Ӧ����8�ı�����AES��Ӧ����16�ı��������⣬�������ݳ��Ȳ��ܳ���0xFFFFF�����β�����ɺ󣬴˴β�������������������������һ�β��������Ҫ�����������Ҫ���´μ��ܲ���֮ǰ����HI_UNF_CIPHER_ConfigHandle��������IV(��Ҫ����pstCtrl->stChangeFlags.bit1IVΪ1)�� CNend
\param[in] hCipher Cipher handle                                                CNcomment:CIPHER��� CNend
\param[in] u32SrcPhyAddr Physical address of the source data                    CNcomment:Դ���������ַ CNend
\param[in] u32DestPhyAddr Physical address of the target data                   CNcomment:Ŀ�����������ַ CNend
\param[in] u32ByteLength   Length of the encrypted data                         CNcomment:�������ݳ��� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                 CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                      CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:�������� CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                  CNcomment:����Ƿ� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Encrypt(HI_HANDLE hCipher, HI_U32 u32SrcPhyAddr, HI_U32 u32DestPhyAddr, HI_U32 u32ByteLength);

/**
\brief Performs decryption.
CNcomment:\brief ���н��� CNend

\attention \n
This API is used to perform decryption by using the cipher module.
The length of the decrypted data should be a multiple of 8 in TDES mode and 16 in AES mode. Besides, the length can not be bigger than 0xFFFFF.After this operation, the result will affect next operation.If you want to remove vector, you need to config IV(config pstCtrl->stChangeFlags.bit1IV with 1) by transfering HI_UNF_CIPHER_ConfigHandle.
CNcomment:ʹ��CIPHER���н��ܲ�����TDESģʽ�½��ܵ����ݳ���Ӧ����8�ı�����AES��Ӧ����16�ı��������⣬�������ݳ��Ȳ��ܳ���0xFFFFF�����β�����ɺ󣬴˴β�������������������������һ�β��������Ҫ�����������Ҫ���´ν��ܲ���֮ǰ����HI_UNF_CIPHER_ConfigHandle��������IV(��Ҫ����pstCtrl->stChangeFlags.bit1IVΪ1)�� CNend
\param[in] hCipher Cipher handle.                                               CNcomment:CIPHER��� CNend
\param[in] u32SrcPhyAddr Physical address of the source data.                   CNcomment:Դ���������ַ CNend
\param[in] u32DestPhyAddr Physical address of the target data.                  CNcomment:Ŀ�����������ַ CNend
\param[in] u32ByteLength Length of the decrypted data                           CNcomment:�������ݳ��� CNend
\retval ::HI_SUCCESS Call this API succussful.                                  CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE Call this API fails.                                       CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  The cipher device is not initialized.         CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  The parameter is invalid.                 CNcomment:�������� CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  The handle is invalid.                  CNcomment:����Ƿ� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Decrypt(HI_HANDLE hCipher, HI_U32 u32SrcPhyAddr, HI_U32 u32DestPhyAddr, HI_U32 u32ByteLength);

/**
\brief Encrypt multiple packaged data.
CNcomment:\brief ���ж�������ݵļ��ܡ� CNend
\attention \n
You can not encrypt more than 128 data package one time. When HI_ERR_CIPHER_BUSY return, the data package you send will not be deal, the custmer should decrease the number of data package or run cipher again.Note:When encrypting more than one packaged data, every one package will be calculated using initial vector configured by HI_UNF_CIPHER_ConfigHandle.Previous result will not affect the later result.
CNcomment:ÿ�μ��ܵ����ݰ�������಻�ܳ���128��������HI_ERR_CIPHER_BUSY��ʱ���������ݰ�һ��Ҳ���ᱻ�����û���Ҫ������������ݰ������������ٴγ��Լ��ܡ�ע��: ���ڶ�����Ĳ�����ÿ������ʹ��HI_UNF_CIPHER_ConfigHandle���õ������������㣬ǰһ����������������������������һ���������㣬ÿ�������Ƕ�������ġ�ǰһ�κ������õĽ��Ҳ����Ӱ���һ�κ������õ��������� CNend
\param[in] hCipher cipher handle                                                                  CNcomment:CIPHER����� CNend
\param[in] pstDataPkg data package ready for cipher                                               CNcomment:�����ܵ����ݰ��� CNend
\param[in] u32DataPkgNum  number of package ready for cipher                                      CNcomment:�����ܵ����ݰ������� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                   CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                                        CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  cipher device have not been initialized                         CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                             CNcomment:�������� CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                            CNcomment:����Ƿ� CNend
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time   CNcomment:Ӳ����æ���޷�һ���Դ���ȫ�������ݰ� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_EncryptMulti(HI_HANDLE hCipher, HI_UNF_CIPHER_DATA_S *pstDataPkg, HI_U32 u32DataPkgNum);


/**
\brief Decrypt multiple packaged data.
CNcomment:\brief ���ж�������ݵĽ��ܡ� CNend
\attention \n
You can not decrypt more than 128 data package one time.When HI_ERR_CIPHER_BUSY return, the data package you send will not be deal, the custmer should decrease the number of data package or run cipher again.Note:When decrypting more than one packaged data, every one package will be calculated using initial vector configured by HI_UNF_CIPHER_ConfigHandle.Previous result will not affect the later result.
CNcomment:ÿ�ν��ܵ����ݰ�������಻�ܳ���128��������HI_ERR_CIPHER_BUSY��ʱ���������ݰ�һ��Ҳ���ᱻ�����û���Ҫ������������ݰ������������ٴγ��Խ��ܡ�ע��: ���ڶ�����Ĳ�����ÿ������ʹ��HI_UNF_CIPHER_ConfigHandle���õ������������㣬ǰһ����������������������������һ���������㣬ÿ�������Ƕ�������ģ�ǰһ�κ������õĽ��Ҳ����Ӱ���һ�κ������õ��������� CNend
\param[in] hCipher cipher handle                                                                 CNcomment:CIPHER����� CNend
\param[in] pstDataPkg data package ready for cipher                                              CNcomment:�����ܵ����ݰ��� CNend
\param[in] u32DataPkgNum  number of package ready for cipher                                     CNcomment:�����ܵ����ݰ������� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                  CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                                       CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  cipher device have not been initialized                        CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                            CNcomment:�������� CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                           CNcomment:����Ƿ� CNend
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time  CNcomment:Ӳ����æ���޷�һ���Դ���ȫ�������ݰ� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DecryptMulti(HI_HANDLE hCipher, HI_UNF_CIPHER_DATA_S *pstDataPkg, HI_U32 u32DataPkgNum);

/**
\brief Encrypt multiple packaged data.
CNcomment:\brief ���ж�������ݵļ��ܡ� CNend
\attention \n
You can not encrypt more than 128 data package one time. When HI_ERR_CIPHER_BUSY return, the data package you send will not be deal, the custmer should decrease the number of data package or run cipher again.Note:When encrypting more than one packaged data, every one package will be calculated using initial vector configured by HI_UNF_CIPHER_ConfigHandle.Previous result will not affect the later result.
CNcomment:ÿ�μ��ܵ����ݰ�������಻�ܳ���128��������HI_ERR_CIPHER_BUSY��ʱ���������ݰ�һ��Ҳ���ᱻ�����û���Ҫ������������ݰ������������ٴγ��Լ��ܡ�ע��: ���ڶ�����Ĳ�����ÿ������ʹ��HI_UNF_CIPHER_ConfigHandle���õ������������㣬ǰһ����������������������������һ���������㣬ÿ�������Ƕ�������ġ�ǰһ�κ������õĽ��Ҳ����Ӱ���һ�κ������õ��������� CNend
\param[in] hCipher cipher handle                                                                  CNcomment:CIPHER����� CNend
\param[in] pstCtrl Cipher control information.                                  CNcomment:CIPHER������Ϣ CNend
\param[in] pstDataPkg data package ready for cipher                                               CNcomment:�����ܵ����ݰ��� CNend
\param[in] u32DataPkgNum  number of package ready for cipher                                      CNcomment:�����ܵ����ݰ������� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                   CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                                        CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  cipher device have not been initialized                         CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                             CNcomment:�������� CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                            CNcomment:����Ƿ� CNend
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time   CNcomment:Ӳ����æ���޷�һ���Դ���ȫ�������ݰ� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_EncryptMultiEx(HI_HANDLE hCipher, HI_UNF_CIPHER_CTRL_S* pstCtrl, HI_UNF_CIPHER_DATA_S *pstDataPkg, HI_U32 u32DataPkgNum);

/**
\brief Decrypt multiple packaged data.
CNcomment:\brief ���ж�������ݵĽ��ܡ� CNend
\attention \n
You can not decrypt more than 128 data package one time.When HI_ERR_CIPHER_BUSY return, the data package you send will not be deal, the custmer should decrease the number of data package or run cipher again.Note:When decrypting more than one packaged data, every one package will be calculated using initial vector configured by HI_UNF_CIPHER_ConfigHandle.Previous result will not affect the later result.
CNcomment:ÿ�ν��ܵ����ݰ�������಻�ܳ���128��������HI_ERR_CIPHER_BUSY��ʱ���������ݰ�һ��Ҳ���ᱻ�����û���Ҫ������������ݰ������������ٴγ��Խ��ܡ�ע��: ���ڶ�����Ĳ�����ÿ������ʹ��HI_UNF_CIPHER_ConfigHandle���õ������������㣬ǰһ����������������������������һ���������㣬ÿ�������Ƕ�������ģ�ǰһ�κ������õĽ��Ҳ����Ӱ���һ�κ������õ��������� CNend
\param[in] hCipher cipher handle                                                                 CNcomment:CIPHER����� CNend
\param[in] pstCtrl Cipher control information.                                  CNcomment:CIPHER������Ϣ CNend
\param[in] pstDataPkg data package ready for cipher                                              CNcomment:�����ܵ����ݰ��� CNend
\param[in] u32DataPkgNum  number of package ready for cipher                                     CNcomment:�����ܵ����ݰ������� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                  CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                                       CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  cipher device have not been initialized                        CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                            CNcomment:�������� CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                           CNcomment:����Ƿ� CNend
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time  CNcomment:Ӳ����æ���޷�һ���Դ���ȫ�������ݰ� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_DecryptMultiEx(HI_HANDLE hCipher, HI_UNF_CIPHER_CTRL_S* pstCtrl, HI_UNF_CIPHER_DATA_S *pstDataPkg, HI_U32 u32DataPkgNum);

/**
\brief get tag value.
CNcomment:\brief ��ȡTAG���ݡ� CNend
\attention \n
You can get the tag value after encrypt/decrypt with CCM/GCM mode.
CNcomment: CCM/GCM ģʽ�ӽ��ܺ��ȡTAGֵ�� CNend
\param[in] hCipher cipher handle                                                                 CNcomment:CIPHER����� CNend
\param[out] pstTag TAG data                                                                      CNcomment:TAGֵ��      CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                  CNcomment:APIϵͳ���óɹ� CNend
\retval ::HI_FAILURE  Call this API fails.                                                       CNcomment:APIϵͳ����ʧ�� CNend
\retval ::HI_ERR_CIPHER_NOT_INIT  cipher device have not been initialized                        CNcomment:CIPHER�豸δ��ʼ�� CNend
\retval ::HI_ERR_CIPHER_INVALID_PARA  parameter error                                            CNcomment:�������� CNend
\retval ::HI_ERR_CIPHER_INVALID_HANDLE  handle invalid                                           CNcomment:����Ƿ� CNend
\retval ::HI_ERR_CIPHER_BUSY  hardware is busy, it can not deal with all data package once time  CNcomment:Ӳ����æ���޷�һ���Դ���ȫ�������ݰ� CNend
\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_GetTag(HI_HANDLE hCipher,  HI_U8 *pstTag);

/**
\brief Init the hash module, if other program is using the hash module, the API will return failure.
CNcomment:\brief ��ʼ��HASHģ�飬�����������������ʹ��HASHģ�飬����ʧ��״̬�� CNend

\attention \n
N/A

\param[in] pstHashAttr: The hash calculating structure input.                                      CNcomment:���ڼ���hash�Ľṹ����� CNend
\param[out] pHashHandle: The output hash handle.                                                CNcomment:�����hash��� CNend
\retval ::HI_SUCCESS  Call this API succussful.                                                 CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                                                      CNcomment: APIϵͳ����ʧ�� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashInit(HI_UNF_CIPHER_HASH_ATTS_S *pstHashAttr, HI_HANDLE *pHashHandle);

/**
\brief Calculate the hash, if the size of the data to be calculated is very big and the DDR ram is not enough, this API can calculate the data one block by one block. Attention: The input block length must be 64bytes alingned except for the last block.
CNcomment:\brief ����hashֵ�������Ҫ������������Ƚϴ󣬸ýӿڿ���ʵ��һ��blockһ��block�ļ��㣬�����������Ƚϴ������£��ڴ治������⡣ �ر�ע�⣬�������һ��block��ǰ���ÿһ������ĳ��ȶ�������64�ֽڶ��롣CNend

\attention \n
N/A

\param[in] hHashHandl:  Hash handle.                                        CNcomment:Hash����� CNend
\param[in] pu8InputData:  The input data buffer.                            CNcomment:�������ݻ��� CNend
\param[in] u32InputDataLen:  The input data length, attention: the block length input must be 64bytes aligned except the last block!            CNcomment:�������ݵĳ��ȡ���Ҫ�� �������ݿ�ĳ��ȱ�����64�ֽڶ��룬���һ��block�޴����ơ� CNend
\retval ::HI_SUCCESS  Call this API succussful.                             CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                                  CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashUpdate(HI_HANDLE hHashHandle, HI_U8 *pu8InputData, HI_U32 u32InputDataLen);



/**
\brief Get the final hash value, after calculate all of the data, call this API to get the final hash value and close the handle.If there is some reason need to interupt the calculation, this API should also be call to close the handle.
CNcomment:��ȡhashֵ���ڼ��������е����ݺ󣬵�������ӿڻ�ȡ���յ�hashֵ���ýӿ�ͬʱ��ر�hash���������ڼ�������У���Ҫ�жϼ��㣬Ҳ������øýӿڹر�hash����� CNend

\attention \n
N/A

\param[in] hHashHandle:  Hash handle.                                       CNcomment:Hash����� CNend
\param[out] pu8OutputHash:  The final output hash value.                    CNcomment:�����hashֵ�� CNend

\retval ::HI_SUCCESS  Call this API succussful.                             CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_HashFinal(HI_HANDLE hHashHandle, HI_U8 *pu8OutputHash);

/**
\brief compute the hash module
CNcomment:\brief ����HASHֵ CNend

\attention \n
N/A

\param[in] pstHashAttr: The hash calculating structure input.              CNcomment:���ڼ���hash�Ľṹ����� CNend
\param[in] u32DataPhyAddr:  Physical address of input data.                CNcomment:�������������ַ CNend
\param[in] u32ByteLength:   The input data length                          CNcomment:�������ݵĳ��ȡ� CNend
\param[out] pu8OutputHash:  The final output hash value.                   CNcomment:�����hashֵ�� CNend
\retval ::HI_SUCCESS  Call this API succussful.                            CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                                 CNcomment: APIϵͳ����ʧ�� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_Hash(HI_UNF_CIPHER_HASH_ATTS_S *pstHashAttr, HI_U32 u32DataPhyAddr, HI_U32 u32ByteLength, HI_U8 *pu8OutputHash);

/**
\brief RSA encryption a plaintext with a RSA public key.
CNcomment:ʹ��RSA��Կ����һ�����ġ� CNend

\attention \n
N/A

\param[in] pstRsaEnc:   encryption struct.                                   CNcomment:�������Խṹ�塣 CNend
\param[in] pu8Input��   input data to be encryption                          CNcomment: �����ܵ����ݡ� CNend
\param[out] u32InLen:   length of input data to be encryption                CNcomment: �����ܵ����ݳ��ȡ� CNend
\param[out] pu8Output�� output data to be encryption                         CNcomment: ���ܽ�����ݡ� CNend
\param[out] pu32OutLen: length of output data to be encryption               CNcomment: ���ܽ�������ݳ��ȡ� CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaPublicEnc(HI_UNF_CIPHER_RSA_PUB_ENC_S *pstRsaEnc, 
								  HI_U8 *pu8Input, HI_U32 u32InLen, 
								  HI_U8 *pu8Output, HI_U32 *pu32OutLen);

/**
\brief RSA decryption a ciphertext with a RSA private key.
CNcomment:ʹ��RSA˽Կ����һ�����ġ� CNend

\attention \n
N/A

\param[in] pstRsaDec:   decryption struct.                                   CNcomment: ��Կ�������Խṹ�塣 CNend
\param[in] pu8Input��   input data to be decryption                          CNcomment: �����ܵ����ݡ� CNend
\param[out] u32InLen:   length of input data to be decryption                CNcomment: �����ܵ����ݳ��ȡ� CNend
\param[out] pu8Output�� output data to be decryption                         CNcomment: ���ܽ�����ݡ� CNend
\param[out] pu32OutLen: length of output data to be decryption               CNcomment: ���ܽ�������ݳ��ȡ� CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaPrivateDec(HI_UNF_CIPHER_RSA_PRI_ENC_S *pstRsaDec,								  
								   HI_U8 *pu8Input, HI_U32 u32InLen, 
								   HI_U8 *pu8Output, HI_U32 *pu32OutLen);

/**
\brief RSA encryption a plaintext with a RSA private key.
CNcomment:ʹ��RSA˽Կ����һ�����ġ� CNend

\attention \n
N/A

\param[in] pstRsaSign:   encryption struct.                                  CNcomment:�������Խṹ�塣 CNend
\param[in] pu8Input��   input data to be encryption                          CNcomment: �����ܵ����ݡ� CNend
\param[out] u32InLen:   length of input data to be encryption                CNcomment: �����ܵ����ݳ��ȡ� CNend
\param[out] pu8Output�� output data to be encryption                         CNcomment: ���ܽ�����ݡ� CNend
\param[out] pu32OutLen: length of output data to be encryption               CNcomment: ���ܽ�������ݳ��ȡ� CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaPrivateEnc(HI_UNF_CIPHER_RSA_PRI_ENC_S *pstRsaEnc, 
							 	   HI_U8 *pu8Input, HI_U32 u32InLen, 
								   HI_U8 *pu8Output, HI_U32 *pu32OutLen);

/**
\brief RSA decryption a ciphertext with a RSA public key.
CNcomment:ʹ��RSA��Կ����һ�����ġ� CNend

\attention \n
N/A

\param[in] pstRsaVerify:   decryption struct.                                CNcomment: �������Խṹ�塣 CNend
\param[in] pu8Input��   input data to be decryption                          CNcomment: �����ܵ����ݡ� CNend
\param[out] u32InLen:   length of input data to be decryption                CNcomment: �����ܵ����ݳ��ȡ� CNend
\param[out] pu8Output�� output data to be decryption                         CNcomment: ���ܽ�����ݡ� CNend
\param[out] pu32OutLen: length of output data to be decryption               CNcomment: ���ܽ�������ݳ��ȡ� CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaPublicDec(HI_UNF_CIPHER_RSA_PUB_ENC_S *pstRsaDec,
							   HI_U8 *pu8Input, HI_U32 u32InLen,
							   HI_U8 *pu8Output, HI_U32 *pu32OutLen);

/**
\brief RSA signature a context with appendix, where a signer��s RSA private key is used.
CNcomment:ʹ��RSA˽Կǩ��һ���ı��� CNend

\attention \n
N/A

\param[in] pstRsaSign:      signature struct.                                    CNcomment: ǩ�����Խṹ�塣 CNend
\param[in] pu8Input��       input context to be signature��maybe null            CNcomment: ��ǩ��������, ���pu8HashData��Ϊ�գ����ָ�տ���Ϊ�ա� CNend
\param[in] u32InLen:        length of input context to be signature              CNcomment: ��ǩ�������ݳ��ȡ� CNend
\param[in] pu8HashData��    hash value of context,if NULL, let pu8HashData = Hash(context) automatically   Ncomment: ��ǩ���ı���HASHժҪ�����Ϊ�գ����Զ������ı���HASHժҪ�� CNend                     
\param[out] pu8OutSign��    output message of signature                          CNcomment: ǩ����Ϣ�� CNend
\param[out] pu32OutSignLen: length of message of signature                       CNcomment: ǩ����Ϣ�����ݳ��ȡ� CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/								   
HI_S32 HI_UNF_CIPHER_RsaSign(HI_UNF_CIPHER_RSA_SIGN_S *pstRsaSign, 
							 HI_U8 *pu8InData, HI_U32 u32InDataLen,
							 HI_U8 *pu8HashData,
							 HI_U8 *pu8OutSign, HI_U32 *pu32OutSignLen);

/**
\brief RSA signature verification a context with appendix, where a signer��s RSA public key is used.
CNcomment:ʹ��RSA��Կǩ����֤һ���ı��� CNend

\attention \n
N/A

\param[in] pstRsaVerify:    signature verification struct.                         CNcomment: ǩ����֤���Խṹ�塣 CNend
\param[in] pu8Input��       input context to be signature verification��maybe null CNcomment: ��ǩ����֤������, ���pu8HashData��Ϊ�գ����ָ�տ���Ϊ�ա� CNend
\param[in] u32InLen:        length of input context to be signature                CNcomment: ��ǩ����֤�����ݳ��ȡ� CNend
\param[in] pu8HashData��    hash value of context,if NULL, let pu8HashData = Hash(context) automatically   Ncomment: ��ǩ���ı���HASHժҪ�����Ϊ�գ����Զ������ı���HASHժҪ�� CNend                     
\param[in] pu8InSign��      message of signature                                 CNcomment: ǩ����Ϣ�� CNend
\param[in] pu32InSignLen:   length of message of signature                       CNcomment: ǩ����Ϣ�����ݳ��ȡ� CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaVerify(HI_UNF_CIPHER_RSA_VERIFY_S *pstRsaVerify,
							   HI_U8 *pu8InData, HI_U32 u32InDataLen,
							   HI_U8 *pu8HashData,
							   HI_U8 *pu8InSign, HI_U32 u32InSignLen);


/**
\brief Generate a RSA private key.
CNcomment:����һ��RSA˽Կ�� CNend

\attention \n
N/A

\param[in] u32NumBits:     bit numbers of the integer public modulus.  CNcomment: RSA��ԿN��λ�� CNend
\param[in] u32Exponent:    value of public exponent.                   CNcomment: RSA��ԿEֵ�� CNend
\param[out] ptRsaPriKey:   private key struct.                         CNcomment: RSA˽Կ�� CNend

\retval ::HI_SUCCESS  Call this API succussful.                         CNcomment:APIϵͳ���óɹ��� CNend
\retval ::HI_FAILURE  Call this API fails.                              CNcomment:APIϵͳ����ʧ�ܡ� CNend

\see \n
N/A
*/
HI_S32 HI_UNF_CIPHER_RsaGenKey(HI_U32 u32NumBits, HI_U32 u32Exponent, HI_UNF_CIPHER_RSA_PRI_KEY_S *pstRsaPriKey);

/** @} */  /** <!-- ==== API declaration end ==== */
	
#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */

#endif /* __HI_UNF_CIPHER_H__ */
