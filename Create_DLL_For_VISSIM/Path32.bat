if "%VS_DIR%" == "" set VS_DIR=D:\vissim30
if "%MSDevDir%" == "" set MSDevDir=c:\progra~1\devstu~1\vc
set PATH=%PATH%;C:\DOS;%MSDevDir%\bin;%MSDevDir%\..\sharedIDE\bin
if "%lib%" == "" set lib=%MSDevDir%\lib
if "%include%" == "" set include=%MSDevDir%\include;%VS_DIR%\cg\include;%VS_DIR%\vsdk;
