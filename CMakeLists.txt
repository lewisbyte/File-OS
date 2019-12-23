cmake_minimum_required(VERSION 3.15)
project(File-OS)

set(CMAKE_CXX_STANDARD 11)

add_executable(File-OS
        File-OS/main.cpp
        File-OS/FileType.h
        File-OS/DiskManager.h
        File-OS/DiskMannger.cpp
        File-OS/FAT.h
        File-OS/FAT.cpp
        File-OS/FCB.h
        File-OS/FCB.cpp
        File-OS/File.h
        File-OS/File.cpp
        File-OS/Folder.h
        File-OS/Folder.cpp
        )