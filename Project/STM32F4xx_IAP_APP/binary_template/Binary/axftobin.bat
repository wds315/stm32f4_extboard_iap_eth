@echo off

if exist C:\Keil\ARM\BIN40\fromelf.exe (
if exist .\..\MDK-ARM\STM324xG_EVAL\STM324xG_EVAL.axf (C:\Keil\ARM\BIN40\fromelf.exe ".\..\MDK-ARM\STM324xG_EVAL\STM324xG_EVAL.axf" --bin --output ".\STM324xG_EVAL_SysTick.bin")

 )

pause

