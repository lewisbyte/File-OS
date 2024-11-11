## Stargazers over time
[![Stargazers over time](https://starchart.cc/lewisbyte/File-OS.svg?variant=adaptive)](https://starchart.cc/lewisbyte/File-OS)


# clion 使用说明
* 1. 将项目导入，按照提示选择CMakeLists文件，即可完成项目空间的构建


# macos/linux  平台使用、编译说明
* 1. 控制台输入：`cmake ./CMakeLists.txt ` 
* 2. 控制台输入：`make `
* 3. 编译成功之后，会有如下可执行文件`File-OS`生成:
```
total 464
-rw-r--r--   1 lewis  staff    13K 12 13 18:15 CMakeCache.txt
drwxr-xr-x  13 lewis  staff   416B 12 13 18:15 CMakeFiles
-rw-r--r--   1 lewis  staff   373B 12 13 18:11 CMakeLists.txt
-rwxr-xr-x   1 lewis  staff   185K 12 13 18:15 File-OS
-rw-r--r--   1 lewis  staff   1.0K 12 23  2019 LICENSE
-rw-r--r--   1 lewis  staff   9.0K 12 13 18:15 Makefile
-rw-r--r--   1 lewis  staff   2.3K 12 13 18:15 README.md
-rw-r--r--   1 lewis  staff   1.5K 12 13 18:15 cmake_install.cmake
drwxr-xr-x  15 lewis  staff   480B  5 16  2020 src
```
* 4.控制台输入：` ./File-OS ` 即可执行系统

# Q & A
* 1.会出现cmake的低版本问题，按照建议直接升级CMake版本即可
```
[root@VM-0-2-centos File-OS]# cmake ./CMakeLists.txt 
CMake Error at CMakeLists.txt:1 (cmake_minimum_required):
  CMake 3.15 or higher is required.  You are running version 2.8.12.2


-- Configuring incomplete, errors occurred!
```



# File-OS
File Operating System
# 简单文件系统的实现
## 1).目的
* 通过具体的文件存储空间的管理及文件的物理结构、目录结构和文件操作的实现，
加深对文件系统内部功能和实现过程的理解。

## 2).内容
* （1）在内存中开辟一个虚拟磁盘空间作为文件存储器，在其上实现一个简单的单用户文件系统。
在退出这个简单的文件系统时，应将该虚拟文件系统保存到磁盘上，以便下次可以再将它恢复到内存的虚拟磁盘空间中。

* （2）文件存储空间的分配可采用显示链接分配或者其他的办法。

* （3）空闲空间的管理可选择位示图或其他的办法。如果采用位示图来管理文件存储空间，并采用显式链接分配方式，
那么可以将位示图合并到FAT中。

* （4）文件目录结构采用多级目录结构。为了简单起见，可以不使用索引结点，其中的每个目录项应包含文件名、
物理地址、长度等信息，还可以通过目录项实现对文件的读写保护。

* （5）要求提供以下有关操作：

* format:对文件存储器进行格式化，即按照文件系统	的结构对虚拟磁盘空间进行布局，并在其上创建根目录以及用于管理文件存储空间的数据结构。
* mkdir:用于创建子目录
* rmdir:用于删除子目录
* ls:用于显示目录
* cd:用于更改当前目录
* create:用于创建文件
* open:用于打开文件
* close:用于关闭文件
* write:用于写文件
* read:用于读文件
* rm:用于删除文件
