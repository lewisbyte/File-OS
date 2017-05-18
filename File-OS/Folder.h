#pragma once

#include "PCB.h"
#include "File.h"
#include<string>


class Folder:public PCB
{
public:
	PCB * child[N];
	void addChild(PCB* file);
	Folder(string _name, FileType _type);
	bool count(PCB *file);
	PCB* find(PCB *file);
	void erase(PCB* file);
	int size();
private:
	int childSize;
};
