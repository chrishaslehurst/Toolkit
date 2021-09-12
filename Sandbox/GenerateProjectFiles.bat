@ECHO OFF 
TITLE GenerateProjectFiles
ECHO Emptying build folder...

cd "build"
del /S/F/Q "*"
rmdir /Q/S "."

ECHO Stale build files removed, generating new project files.

cmake ../src

PAUSE