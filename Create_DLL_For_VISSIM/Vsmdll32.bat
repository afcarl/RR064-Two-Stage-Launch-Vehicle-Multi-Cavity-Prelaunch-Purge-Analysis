echo off
rem call c:\msdev\bin\vcvars32.bat x86
call path32
echo on
nmake -fdll32.mak T=%1
echo done creation of %1.dll
