#pragma once

#include "PCB.H"
#include "File.h"
#include <vector>
#include<string>
using namespace std;



class Folder:public PCB
{
public:
	//文件夹包含的子内容
	vector<PCB *>child;
	

	//添加文件或文件夹
	void addChild(PCB* file);

	Folder(string _name, FileType _type);


	bool count(PCB *file);

	PCB* find(PCB *file);
	void erase(PCB* file);
};
