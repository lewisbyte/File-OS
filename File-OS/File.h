#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>
#include<map>
#include "PCB.H"
using namespace std;

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

	//文件是否相同
	bool operator<(const File &t)const;

	//添加文件或文件夹
	void addChild(File file);

	

	
	//文件内容
	string content;
	//文件类型
	FileType type;
	//文件夹包含的子内容
	map<File,File> child;
	//上一级文件夹
	File* father;
	//文件路径
	string path;

};





