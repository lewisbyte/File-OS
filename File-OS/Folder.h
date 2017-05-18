#pragma once

#include "PCB.h"
#include "File.h"
#include<vector>
#include<string>


class Folder:public PCB
{
public:
	vector<PCB * >child;
	void addChild(PCB* file);
	Folder(string _name, FileType _type);
	bool count(PCB *file);
	PCB* find(PCB *file);
	bool erase(PCB* file);
	int size();
private:
	int childSize;
};
