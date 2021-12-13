#pragma once

#include "Folder.h"

class DiskManager {
public:


    void DiskWrite(File *file);

    bool DiskMkdir(string dirName);//创建磁盘文件夹
    bool DiskRmdir(string dirName);//删除磁盘文件夹
    bool DiskCkdir(string dirName);

    void DiskRmdir(Folder *f);

    //检查磁盘是否存在文件夹
    DiskManager();//磁盘构造函数
    ~DiskManager();    //磁盘类析构函数
    void format(string *blocks);//: 对文件存储器进行格式化。
    void Mkdir();

    void Rmdir();

    void ls(); //: 用于显示目录
    void cd(); //: 用于更改当前目录
    void create();//: 用于创建文件
    void open(); //: 用于打开文件
    void close(); //: 用于关闭文件
    void write(const char *s, File *file);//: 用于写文件
    void read(const char *s);//: 用于读文件
    void rm(); //: 用于删除文件
private:
    Folder *root;
};