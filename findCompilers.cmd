SET W=<WHERE mycommand

IF %ERRORLEVEL% NEQ 0 ECHO mycommand wasnt not found 
ECHO %W%
REM # $path = vswhere -latest -requires Microsoft.Component.MSBuild -find MSBuild\**\Bin\MSBuild.exe | select-object -first 1
REM # if ($path) {
REM #     & $path $args
REM # }

REM # Install-Module VSSetup -Scope CurrentUser