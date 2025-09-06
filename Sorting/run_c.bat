@echo off
gcc %1 -o temp.exe
temp.exe
del temp.exe
