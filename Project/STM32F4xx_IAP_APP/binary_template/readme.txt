/**
  @page binary_template Binary Template Readme file
  
  @verbatim
  ******************** (C) COPYRIGHT 2011 STMicroelectronics *******************
  * @file    STM32F4xx_IAP/binary_template/readme.txt 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    10-October-2011
  * @brief   Description of the binary_template directory.
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

This directory contains a set of sources files that build the application to be
loaded into Flash memory using In-Application Programming (IAP, through USART).

To build such application, some special configuration has to be performed:
1. Set the program load address at 0x08004000, using your toolchain linker file
2. Relocate the vector table at address 0x08004000, using the "NVIC_SetVectorTable"
   function from the misc.h/.c driver or by modifying the value of the constant
   "VECT_TAB_OFFSET" defined in system_stm32f4xx.c file. 

The SysTick example provided within the STM32F4xx Standard Peripherals library 
examples is used as illustration.
This example configures the SysTick to generate a time base equal to 1 ms.
The system clock is set to the maximum system frequency, the SysTick is clocked by 
the AHB clock (HCLK). A "Delay" function is implemented based on the SysTick 
end-of-count event.
Four LEDs are toggled with a timing defined by the Delay function.


@par Directory contents 

 - "STM32F4xx_IAP\binary_template\EWARM"
 - "STM32F4xx_IAP\binary_template\MDK-ARM"
 - "STM32F4xx_IAP\binary_template\RIDE"
 - "STM32F4xx_IAP\binary_template\TASKING"
 - "STM32F4xx_IAP\binary_template\TrueSTUDIO" 
     - These folders contains a pre-configured project that produces a binary
       image of SysTick example to be loaded with IAP.

  - "STM32F4xx_IAP\binary_template\inc": contains the binary_template firmware header files 
     - IAP/binary_template/inc/stm32f4xx_conf.h    Library Configuration file
     - IAP/binary_template/inc/stm32f4xx_it.h      Header for stm32f4xx_it.c
     - IAP/binary_template/inc/main.h              Header for main.c

 - "STM32F4xx_IAP\binary_template\src": contains the binary_template firmware source files 
     - IAP/binary_template/src/main.c              Main program
     - IAP/binary_template/src/stm32f4xx_it.c      Interrupt handlers
     - IAP/binary_template/src/system_stm32f4xx.c  STM32F4xx system source file

     
@par Hardware and Software environment 

  - This example runs on STM32F4xx Devices.
  
  - This example has been tested with STM324xG-EVAL RevB and can be easily 
    tailored to any other development board.
    
  - STM324xG-EVAL Set-up
    - Use LED1, LED2, LED3 and LED4 connected respectively to PG.06, PG.08, PI.09
      and PC.07 pins


@par How to use it ?  

In order to load the SysTick example with the IAP, you must do the following:

 - EWARM
    - Open the Project.eww workspace
    - Rebuild all files: Project->Rebuild all
    - A binary file "STM324xG_EVAL_SysTick.bin" will be generated under 
      "STM324xG_EVAL\Exe" folder.  
    - Finally load this image with the IAP application

 - RIDE
    - Open the Project.rprj project
    - Rebuild all files: Project->build project
    - Go to "\binary_template\Binary" directory and run "RIDE7_hextobin.bat"
    - A binary file "STM324xG_EVAL_SysTick.bin" will be generated under this
      directory location. 
    - Finally load this image with IAP application

 - MDK-ARM
    - Open the Project.uvproj project
    - Rebuild all files: Project->Rebuild all target files
    - Go to "\binary_template\Binary" directory and run "axftobin.bat"
    - A binary file "STM324xG_EVAL_SysTick.bin" will be generated under this
      directory location. 
    - Finally load this image with IAP application

 - TASKING
    - Open TASKING toolchain.
    - Click on File->Import, select General->'Existing Projects into Workspace' 
      and then click "Next". 
    - Browse to  TASKING workspace directory and select the project: 
        - STM324xG-EVAL: to configure the project for STM32F4xx devices.
    - Under Windows->Preferences->General->Workspace->Linked Resources, add 
      a variable path named "Cur_Path" which points to the folder containing
      "Libraries", "Project" and "Utilities" folders.
    - Rebuild all project files: Select the project in the "Project explorer" 
      window then click on Project->build project menu.
    - Go to "\binary_template\Binary" directory and run "TASKING_hextobin.bat".
    - A binary file "STM324xG-EVAL.bin" will be generated under this
      directory location. 
    - Finally load this image with IAP application
    
 - TrueSTUDIO
    - Open the TrueSTUDIO toolchain.
    - Click on File->Switch Workspace->Other and browse to TrueSTUDIO workspace directory.
    - Click on File->Import, select General->'Existing Projects into Workspace' and then click "Next". 
    - Browse to the TrueSTUDIO workspace directory, select the project:
        - STM324xG_EVAL: to configure the project for STM32F4xx devices
    - Under Windows->Preferences->General->Workspace->Linked Resources, add 
      a variable path named "CurPath" which points to the folder containing
      "Libraries", "Project" and "Utilities" folders.
    - Rebuild all project files: Select the project in the "Project explorer" 
      window then click on Project->build project menu.
    - Go to "\binary_template\Binary" directory and run "TrueSTUDIO_elf2bin.bat"
    - A binary file "STM324xG_EVAL_SysTick.bin" will be generated under this
      directory location.
    - Finally load this image with IAP application


 * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
 */
