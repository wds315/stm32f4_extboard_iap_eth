/**
  ******************************************************************************
  * @file    main.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    31-October-2011
  * @brief   This file contains all the functions prototypes for the main.c 
  *          file.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4x7_eth_bsp.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* IAP options selection ******************************************************/
#define USE_IAP_TFTP   /* enable IAP using TFTP */
#define USE_IAP_HTTP   /* enable IAP using HTTP */
#define USE_LCD        /* enable LCD  */  
//#define USE_DHCP       /* enable DHCP, if disabled static address is used */

/* Flash user area definition *************************************************/   
/* 
   IMPORTANT NOTE:
   ==============
   Be sure that USER_FLASH_FIRST_PAGE_ADDRESS do not overlap with IAP code.
   For example, with all option enabled the total readonly memory size using EWARM
   compiler v6.10, with high optimization for size, is 39928 bytes (32894 bytes
   of readonly code memory and 7034 bytes of readonly data memory).
   However, with TrueSTUDIO, RIDE and TASKING toolchains the total readonly memory
   size exceeds 48 Kbytes, with this result four sectors of 16 Kbytes each will
   be used to store the IAP code, so the user Flash address will start from Sector4. 

   In this example the define USER_FLASH_FIRST_PAGE_ADDRESS is set to 64K boundary,
   but it can be changed to any other address outside the 1st 64 Kbytes of the Flash.
   */
#define USER_FLASH_FIRST_PAGE_ADDRESS 0x08010000 /* Only as example see comment */
#define USER_FLASH_LAST_PAGE_ADDRESS  0x080E0000
#define USER_FLASH_END_ADDRESS        0x080FFFFF  
   
/* UserID and Password definition *********************************************/
#define USERID       "user"
#define PASSWORD     "stm32"
#define LOGIN_SIZE   (15+ sizeof(USERID) + sizeof(PASSWORD))

/* MAC Address definition *****************************************************/
#define MAC_ADDR0   0
#define MAC_ADDR1   0
#define MAC_ADDR2   0
#define MAC_ADDR3   0 
#define MAC_ADDR4   0
#define MAC_ADDR5   2
 
/* Static IP Address definition ***********************************************/
#define IP_ADDR0   192
#define IP_ADDR1   168
#define IP_ADDR2   0
#define IP_ADDR3   12
   
/* NETMASK definition *********************************************************/
#define NETMASK_ADDR0   255
#define NETMASK_ADDR1   255
#define NETMASK_ADDR2   255
#define NETMASK_ADDR3   0

/* Gateway Address definition *************************************************/
#define GW_ADDR0   192
#define GW_ADDR1   168
#define GW_ADDR2   0
#define GW_ADDR3   1  

/* MII and RMII mode selection, for STM324xG-EVAL Board(MB786) RevB ***********/
#define RMII_MODE  // User have to provide the 50 MHz clock by soldering a 50 MHz
                     // oscillator (ref SM7745HEV-50.0M or equivalent) on the U3
                     // footprint located under CN3 and also removing jumper on JP5. 
                     // This oscillator is not provided with the board. 
                     // For more details, please refer to STM3240G-EVAL evaluation
                     // board User manual (UM1461).

                                     
//#define MII_MODE

/* Uncomment the define below to clock the PHY from external 25MHz crystal (only for MII mode) */
#ifdef 	MII_MODE
 #define PHY_CLOCK_MCO
#endif

/* STM324xG-EVAL jumpers setting
    +==========================================================================================+
    +  Jumper |       MII mode configuration            |      RMII mode configuration         +
    +==========================================================================================+
    +  JP5    | 2-3 provide 25MHz clock by MCO(PA8)     |  Not fitted                          +
    +         | 1-2 provide 25MHz clock by ext. Crystal |                                      +
    + -----------------------------------------------------------------------------------------+
    +  JP6    |          2-3                            |  1-2                                 +
    + -----------------------------------------------------------------------------------------+
    +  JP8    |          Open                           |  Close                               +
    +==========================================================================================+
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */  
/* Exported function prototypes ----------------------------------------------*/
void Time_Update(void);
void Delay(uint32_t nCount);
void LCD_LOG_SetFooter(uint8_t *Status);
void LCD_LOG_SetHeader (uint8_t *Title);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

