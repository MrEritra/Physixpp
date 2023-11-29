@echo off
gcc femboy.c physix.c -o femboy -O1 -Wall -std=c99 -Wno-missing-braces -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm -W
REM ,--subsystem,windows
strip femboy.exe
femboy