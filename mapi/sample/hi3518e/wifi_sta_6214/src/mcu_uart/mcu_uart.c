#include <stdio.h>
#include "sys/types.h"
#include "sys/time.h"
#include "hi_type.h"
#include "sys/prctl.h"
#include "eth_drv.h"

#include "fcntl.h"
#include "asm/io.h"
#include "hi_ext_hal_mcu.h"


#define himm(address, value) writel(value, address)


HI_S32 HI_Product_McuHost_Event_proc(HAL_MCUHOST_EVENT_E eMCUHOSTEVENT)
{
    HI_S32 s32Ret = HI_SUCCESS;

    switch (eMCUHOSTEVENT)
    {
        case MCUHOST_SYSTEMCLOSE:
        {
#ifdef CFG_SUPPORT_WIFI_STA

            //Wl scansuppress 1
            mhd_get_scansuppress();
            mhd_wifi_set_scansuppress(1); // set scansuppress to 1
            mhd_get_scansuppress();

            //Wl PM 1
            mhd_sta_set_powersave(1, 0);

            //Wl bcn_li_dtim 10
            mhd_sta_get_bcn_li_dtim();
            mhd_sta_set_bcn_li_dtim(10); // if ap router dtim is 2 seconds  
            mhd_sta_get_bcn_li_dtim(); 

            //wl host_sleep 1
            mhd_set_host_sleep(1);
			
			extern int wifi_info_suspend();
			wifi_info_suspend();
#endif

#ifdef CFG_SUPPORT_WIFI_AP
            extern void mhd_wowl_ap_enable(void);
            mhd_wowl_ap_enable();
#else
            mhd_wowl_sta_add("0x983B16F8F39C", 66);
			mhd_wowl_sta_enable();
#endif

            host_oob_interrupt_disable();


            break;
        }

        default:
            printf("err when switch eMCUHOSTEVENT\n");
            return HI_FAILURE;
    }

    return HI_SUCCESS;
}
int uart2_fd = -1;


void hi_uart2_open(void)
{
#if 0
		writew(0x04, IO_MUX_REG_BASE + 0x088);
		writew(0x04, IO_MUX_REG_BASE + 0x094);
#else
		writew(0x3, IO_MUX_REG_BASE + 0x0CC);	
		writew(0x3, IO_MUX_REG_BASE + 0x0D0);	
#endif
	printf(" -----%s line=%d \n",__FUNCTION__,__LINE__);


    uart2_fd = open("/dev/uartdev-2", O_RDWR);

    if (uart2_fd < 0)
    {
        uart2_fd = -1;
        printf("open %s with %d ret = %d\n", "/dev/uartdev-2", O_RDWR, uart2_fd);
    }
    else
    {
        printf("\nhi_uart2_open success\n");
    }
}
void hi_uart2_close(void)
{
    close(uart2_fd);
    uart2_fd = -1;
}
extern int g_bMcuHostInit;


void mcu_uart_proc()
{
    hi_uart2_open();
    HI_HAL_MCUHOST_WiFi_ON_Request(1);
    extern HI_S32 HI_Product_McuHost_Event_proc(HAL_MCUHOST_EVENT_E eMCUHOSTEVENT);
	dprintf("g_bMcuHostInit33 %d\n",g_bMcuHostInit);
    HI_HAL_MCUHOST_Init();
	printf(" >>>>>%s line=%d \n",__FUNCTION__,__LINE__);
    HI_HAL_MCUHOST_RegisterNotifyProc(HI_Product_McuHost_Event_proc);
}

