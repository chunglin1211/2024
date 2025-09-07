REM Platform-specific regasm
REM %1 = Full path to Assembly = 

IF NOT [%PROCESSOR_ARCHITEW6432%]==[] GOTO platform64
IF %PROCESSOR_ARCHITECTURE%==AMD64 GOTO platform64

:platform32
REM Register32-bit.
"%WINDIR%\Microsoft.NET\Framework\v4.0.30319\regasm" /codebase %1
GOTO :eof

:platform64
REM Register32-bit.
"%WINDIR%\Microsoft.NET\Framework64\v4.0.30319\regasm" /codebase %1