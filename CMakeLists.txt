cmake_minimum_required(VERSION 3.15)
project(File-OS)

set(CMAKE_CXX_STANDARD 11)

add_executable(File-OS
        src/main.cpp
        src/FileType.h
        src/DiskManager.h
        src/DiskMannger.cpp
        src/FAT.h
        src/FAT.cpp
        src/FCB.h
        src/FCB.cpp
        src/File.h
        src/File.cpp
        src/Folder.h
        src/Folder.cpp
        )