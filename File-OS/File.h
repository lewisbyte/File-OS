#pragma once
#include<string>
#include<iostream>
#include<set>
using namespace std;

class File
{
public:
	//构造函数
	File();

	//析构函数
	~File();
	
	//序列化
	void Serialization();
	
	//反序列化
	void Deserialization();

	//文件是否相同
	bool operator<(File &t)const;



private:
	//文件名
	string name;
	//文件内容
	string content;
	//文件类型
	bool type;
	//文件夹包含的子内容
	set<File*> child;
	//上一级文件夹
	File* father;

};





