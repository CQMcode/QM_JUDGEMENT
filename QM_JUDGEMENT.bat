@echo off

set /p a="请输入数据数量："
if %a% LSS 0 (
    echo  不能是负数！
    pause
    exit /b
)

for /l %%i in (1,1,%a%) do (
    echo.
    echo 请输入第%%i组数据，完成后保存并关闭即可
    echo 即Ctrl+S再Ctrl+W
    echo 会自动给数据结尾添加换行符，防止出错
    echo 注意，数据必须是能够让程序终止（即return0）的！
    type nul > INPUT%%i.in
    notepad INPUT%%i.in
    echo.>>INPUT%%i.in
)

echo.
echo.

cd %~dp0QJDATA

DONOTTOUCH.exe
echo.
DONOTTOUCH2.exe

CALL copyfile.bat

for /l %%i in (1,1,%a%) do (
    echo.
    echo =====马上运行第%%i组数据=====
    pause
    copy "%~dp0INPUT%%i.in" "%~dp0QJDATA\INPUT.in" /Y
    CALL operate.bat
    CALL checkfile.bat
)

echo.
echo 全部运行结束。
pause