@echo off

cls

for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "date=%dt:~0,4%_%dt:~4,2%_%dt:~6,2%"

ROBOCOPY "src" "target\debug\%date%\source\src" /mir /nfl /ndl /njh /njs /np /ns /nc > nul


rgbasm  -L -o target\debug\%date%\HarvestMoonGB.o  src\entry.asm
rgblink -o    target\debug\%date%\HarvestMoonGB.gb target\debug\%date%\HarvestMoonGB.o
rgbfix  target\debug\%date%\HarvestMoonGB.gb -j -k E9 -l $33 -m MBC1+RAM+BATTERY -r 2 -s -t "HARVEST-MOON GB" -v -p $FF


del compared.txt
fc /b ROM\HarvestMoonGB.gb target\debug\%date%\HarvestMoonGB.gb >> compared.txt