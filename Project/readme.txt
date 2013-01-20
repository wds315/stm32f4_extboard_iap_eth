/**
  @page Ethernet_IAP  IAP over Ethernet Readme file
 
  @verbatim
  ******************** (C) COPYRIGHT 2011 STMicroelectronics *******************
  * @file    IAP/readme.txt 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    31-October-2011    
  * @brief   Description of the STM32F4x7 in-application programming (IAP) over Ethernet.
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
   @endverbatim

@par Description

This directory contains a set of sources files that implement In-Application 
Programming (IAP) over Ethernet for STM32F4x7 devices. 
Two IAP options are provided: 
 - IAP using TFTP (Trivial File Transfer Protocol)
 - IAP using HTTP (Hypertext Transfer Protocol) 
User has select through compile options (in main.h file) to include one or both 
options.
Please note that for both IAP options, LwIP v1.3.2 is used as the TCP/IP stack. 


@par Project Directory contents 

 - "binary": contains two binary images to be loaded with the IAP code

 - "inc": contains the IAP firmware header files 
    - inc/main.h               main config file          
    - inc/flash_if.h           header for flash_if.c
    - inc/httpserver.h         header for httpserver.c
    - inc/tftpserver.h         header for tftpserver.c
    - inc/stm32f4x7_eth_bsp.h  header for stm32f4x7_eth_bsp.c
    - inc/netconf.h            header for netconf.c
    - inc/lwipopts.h           LwIP stack configuration options
    - inc/fsdata.h             header for fsdata.c  
    - inc/stm32f4xx_conf.h     Library Configuration file
    - inc/stm32f4x7_eth_conf.h STM32F4x7 Ethernet driver Configuration file
    - inc/stm32f4xx_it.h       Header for stm32f4xx_it.c    

 - "src": contains the IAP firmware source files
    - src/main.c               main program file          
    - src/flash_if.c           high level functions for flash access (erase, write)
    - src/httpserver.c         IAP http server functions
    - src/tftpserver.c         IAP tftpserver functions
    - src/stm32f4x7_eth_bsp.c  STM32F4x7 Ethernet hardware configuration
    - src/netconf.c            LwIP stack initializations
    - src/fsdata.c             ROM filesystem data (html pages)
    - src/system_stm32f4xx.c   STM32F4xx system clock configuration file
    - src/stm32f4xx_it.c       STM32F4xx Interrupt handlers   

 - "EWARM": contains preconfigured project for EWARM toolchain
 - "MDK-ARM": contains preconfigured project for MDK-ARM toolchain
 - "RIDE": contains preconfigured project for RIDE toolchain
 - "TASKING": contains preconfigured project for TASKING toolchain
 - "TrueSTUDIO": contains preconfigured project for TrueSTUDIO toolchain
 
 
@par Hardware and Software environment  
  
  - This example has been tested with the following environment: 
     - STM324xG-EVAL board RevB
     - Http clients: Firefox Mozilla (v3.6 and later) or Microsoft Internet Explorer (v8 and later) 
     - TFTP client: PC utility TFTPD32 (http://tftpd32.jounin.net/) is used as a DHCP server and a TFTP client
  
  - STM324xG-EVAL Set-up 
    - Connect STM324xG-EVAL board to remote PC (through a crossover ethernet cable)
      or to your local network (through a straight ethernet cable)
    - Use the Key push-button
    - STM324xG-EVAL jumpers setting
        +==========================================================================================+
        +  Jumper |       MII mode configuration            |     RMII mode configuration(*)       +
        +==========================================================================================+
        +  JP5    | 2-3 provide 25MHz clock by MCO(PA8)     |  Not fitted                          +
        +         | 1-2 provide 25MHz clock by ext. Crystal |                                      +
        + -----------------------------------------------------------------------------------------+
        +  JP6    |          2-3                            |  1-2                                 +
        + -----------------------------------------------------------------------------------------+
        +  JP8    |          Open                           |  Close                               +
        + -----------------------------------------------------------------------------------------+
        +  JP22   | 1-2: RS232 is enabled                                                          +
        +==========================================================================================+
    (*) User have to provide the 50 MHz clock by soldering a 50 MHz oscillator (ref SM7745HEV-50.0M or
        equivalent) on the U3 footprint located under CN3 and also removing jumper on JP5. This oscillator
        is not provided with the board. 
        For more details, please refer to STM3240G-EVAL evaluation board User manual (UM1461).
    @Note: the default setting is MII mode, to change it to RMII mode refer to main.h file.


@par How to use it ? 

In order to make the program work, you must do the following:
  1. Load the IAP code in the STM32F4x7 Flash memory (see below)
  2. Refer to "AN3968 STM32F4x7 In-Application Programming (IAP) over Ethernet"
     to know how to use the different IAP methods
 
  In order to load the IAP code, you have do the following:
   - EWARM
      - Open the Project.eww workspace
      - Rebuild all files: Project->Rebuild all
      - Load project image: Project->Debug
      - Run program: Debug->Go(F5)

   - RIDE
      - Open the Project.rprj project
      - Rebuild all files: Project->build project
      - Load project image: Debug->start(ctrl+D)
      - Run program: Debug->Run(ctrl+F9)

   - MDK-ARM
      - Open the Project.uvproj project
      - Rebuild all files: Project->Rebuild all target files
      - Load project image: Debug->Start/Stop Debug Session
      - Run program: Debug->Run (F5)

   - TASKING
      - Open TASKING toolchain.
      - Click on File->Import, select General->'Existing Projects into Workspace' 
        and then click "Next". 
      - Browse to TASKING workspace directory and select the project: 
          - STM324xG_EVAL: to configure the project for STM32F4xx devices.
      - Rebuild all project files: Select the project in the "Project explorer" 
        window then click on Project->build project menu.
      - Run program: Select the project in the "Project explorer" window then click 
        Run->Debug (F11)

   - TrueSTUDO
      - Open the TrueSTUDIO toolchain.
      - Click on File->Switch Workspace->Other and browse to TrueSTUDIO workspace directory.
      - Click on File->Import, select General->'Existing Projects into Workspace' and then click "Next". 
      - Browse to the TrueSTUDIO workspace directory, select the project:
          - STM324xG_EVAL: to configure the project for STM32F4xx devices
      - Rebuild all project files: Select the project in the "Project explorer" 
        window then click on Project->build project menu.
      - Run program: Run->Debug (F11)
 
 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 */
