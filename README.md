hid2hcix
========

Switch CSR Bluetooth Dongle to HCI mode.

# Install

## Windows

 1. Download following bat: https://github.com/cho45/hid2hcix/blob/master/install-win.bat
 2. Rename it to install-win.bat surely.
 3. Right click the downloaded script
 4. Do "Run as Administrator"

This batch download hid2hcix.exe and copy it to system startup folder (C:\ProgramData\Microsoft\Windows\Start Menu\Programs\StartUp).

## Mac

  1. Download https://github.com/cho45/hid2hcix/blob/master/install-mac.sh
  2. sh install-mac.sh
  
install-mac.sh requires sudo.

# Build

Build on OS X with mingw:

```
PATH="/usr/local/gcc-4.8.0-qt-4.8.4-for-mingw32/win32-gcc/bin:$PATH" make -f Makefile.mingw
```

# hidapi

Modified one-line for this project: https://github.com/cho45/hid2hcix/commit/5bf116509feb160a202537a1279d77cf2203d659

