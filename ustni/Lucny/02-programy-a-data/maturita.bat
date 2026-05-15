@echo off
cls
echo ZALOHOVACI DAVKOVY SOUBOR
pause

if "%1"=="" goto CHYBA

mkdir C:\%1
copy C:\WINDOWS\*.LOG C:\%1
dir C:\%1 > C:\%1\obsah.txt
notepad C:\%1\obsah.txt

echo ZALOHA USPESNE PROVEDENA.
goto KONEC

:CHYBA
echo NEBYL ZADAN PARAMETR.
echo ZALOHU NELZE PROVEST.

:KONEC
pause