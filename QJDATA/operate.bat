@echo off
cls
echo ========== 开始运行 ==========
echo 正在检查文件...

if not exist INPUT.in (
    echo 缺少 INPUT.in
    pause
    exit
)
if not exist 1.exe (
    echo 缺少 1.exe
    pause
    exit
)
if not exist 2.exe (
    echo 缺少 2.exe
    pause
    exit
)
echo 文件齐全，开始运行程序

echo.
echo ========== 运行 1.exe ==========
start /B cmd /c "1.exe < INPUT.in > 1.out"
timeout /t 5 /nobreak >nul
taskkill /f /im 1.exe /t >nul 2>&1
echo 1.exe 运行完成或超时结束

echo.
echo ========== 运行 2.exe ==========
start /B cmd /c "2.exe < INPUT.in > 2.out"
timeout /t 5 /nobreak >nul
taskkill /f /im 2.exe /t >nul 2>&1
echo 2.exe 运行完成或超时结束

pause