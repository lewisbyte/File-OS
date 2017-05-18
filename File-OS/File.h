#pragma once

#include "PCB.H"
#include<string>

class File:public PCB
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

	
	//文件内容
	char content[N];
	
	//上一级文件夹
	PCB* father;


};





