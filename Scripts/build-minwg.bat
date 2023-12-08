@echo off
pushd ..
mkdir obj\Release
mkdir obj\Debug
mkdir bin\Release
mkdir bin\Debug
Scripts\premake5.exe gmake2
popd
pause