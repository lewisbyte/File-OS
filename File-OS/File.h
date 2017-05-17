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

	
	//文件内容
	string content;
	
	//上一级文件夹
	PCB* father;


};





