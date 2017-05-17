#pragma once

#include "PCB.H"
#include "File.h"

class Folder:public PCB
{
public:
	//文件夹包含的子内容
	map<PCB*, PCB*> child;

	//添加文件或文件夹
	void addChild(PCB* file);

};
