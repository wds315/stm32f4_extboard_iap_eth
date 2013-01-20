
These 2 binary images are provided to be loaded with the IAP over Ethernet, they
are compiled to run at address 0x08010000:
   - STM324xG_EVAL_SysTick.bin: binary image of systick example, refer to the "STM32F4xx
                                Standard Peripherals Firmware Library" for the source code 
   - STM324xG_EVAL_httpserver.bin: binary image of httpserver demo, refer to the 
                                   "LwIP TCP/IP stack demonstration for STM32F407/STM32F417
                                    microcontrollers" for the source code

    @Note In order to make the STM324xG_EVAL_httpserver demo works, please ensure
          that the STM324xG_EVAL board RevB jumpers are connected as bellow:
             - JP5 in position 1-2
             - JP6 in position 2-3
             - JP8 not fitted   

