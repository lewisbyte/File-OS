#pragma once

#include "FCB.H"
#include<string>

class File : public FCB {
public:

    //构造函数
    File();

    File(string _name, FileType _type, FAT &fat);

    //析构函数
    ~File();

    //序列化
    void Serialization();

    //反序列化
    void Deserialization();

    bool addContent(const char *content, string blocks[], FAT &fat);

    //文件索引
    int index[N];
    //上一级文件夹
    FCB *father;

    void release(FAT &fat, string *blocks);

    string toString(string blocks[]);
    //释放磁盘块

};