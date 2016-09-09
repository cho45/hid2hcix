@echo off
set command=Invoke-WebRequest -Uri "https://raw.githubusercontent.com/cho45/hid2hcix/master/etc/install-win.ps1" -OutFile "%TEMP%\install-win.ps1"
set command=%command:"=\"%
echo %command%
powershell -NoProfile -ExecutionPolicy Unrestricted -Command "%command%"
powershell -NoProfile -ExecutionPolicy Unrestricted %TEMP%/install-win.ps1
pause > nul
exit
