/*     here is piris arch .
*
*
*  This file defines piris micro-definitions for user.
*
* History:
*     03-Mar-2016 Start of Hi351xx Digital Camera,H6
*
*/

#ifndef __PIRIS_HAL_H__
#define __PIRIS_HAL_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */


/***************����ַ***********************/

#define PIRISI_ADRESS_BASE     0x20210000        // Piris use GPIO13
#define PIRISI_REG_LEN         0x10000

#define  HI_IO_PIRISI_ADDRESS(base_va, x)  (base_va + ((x)-(PIRISI_ADRESS_BASE)))
#define  PIRIS_WRITE_REG(Addr, Value) ((*(volatile unsigned int *)(Addr)) = (Value))
#define  PIRIS_READ_REG(Addr)         (*(volatile unsigned int *)(Addr))


#define PIRIS_CFG_REG(base_va)        HI_IO_PIRISI_ADDRESS(base_va, PIRISI_ADRESS_BASE + 0x007C)
#define PIRIS_CTRL_REG(base_va)       HI_IO_PIRISI_ADDRESS(base_va, PIRISI_ADRESS_BASE + 0x0400)


/***************PIRIS_DRV_Write REG value***********************/

#define PIRIS_HAL_PHASE0(base_va)                       \
    do                                                  \
    {                                                   \
        PIRIS_WRITE_REG(PIRIS_CTRL_REG(base_va), 0x1F); \
        PIRIS_WRITE_REG(PIRIS_CFG_REG(base_va), 0x15);  \         
    } while ( 0 );


#define PIRIS_HAL_PHASE1(base_va)                       \
    do                                                  \
    {                                                   \
        PIRIS_WRITE_REG(PIRIS_CTRL_REG(base_va), 0x1F); \
        PIRIS_WRITE_REG(PIRIS_CFG_REG(base_va), 0x16);  \         
    } while ( 0 );

#define PIRIS_HAL_PHASE2(base_va)                       \
    do                                                  \
    {                                                   \
        PIRIS_WRITE_REG(PIRIS_CTRL_REG(base_va), 0x1F); \
        PIRIS_WRITE_REG(PIRIS_CFG_REG(base_va), 0x1A);  \         
    } while ( 0 );    

#define PIRIS_HAL_PHASE3(base_va)                       \
    do                                                  \
    {                                                   \
        PIRIS_WRITE_REG(PIRIS_CTRL_REG(base_va), 0x1F); \
        PIRIS_WRITE_REG(PIRIS_CFG_REG(base_va), 0x19);  \         
    } while ( 0 ); 

    

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /*__PIRIS_HAL_H__*/




