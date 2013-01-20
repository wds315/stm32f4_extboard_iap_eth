@if exist .\..\TrueSTUDIO\STM324xG_EVAL\Debug\STM324xG_EVAL.elf ("arm-elf-objcopy.exe" -O binary ".\..\TrueSTUDIO\STM324xG_EVAL\Debug\STM324xG_EVAL.elf" "STM324xG_EVAL_SysTick.bin")

pause

