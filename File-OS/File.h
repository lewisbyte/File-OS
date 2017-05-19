#pragma once

#include "FCB.H"
#include<string>

class File:public FCB
{
public:
	//构造函数
	File();

	File::File(string _name, FileType _type);
	//析构函数
	~File();
	
	//序列化
	void Serialization();
	
	//反序列化
	void Deserialization();

	
	//文件索引
	char *index[N];
	
	//上一级文件夹
	FCB* father;


};





