#pragma once

#include "Folder.h"



void Folder::addChild(PCB * file)
{
	this->child.push_back(file);
}

Folder::Folder(string _name, FileType _type)
{
	this->name = _name;
	this->type = _type;
}



bool Folder::count(PCB * file)
{
	int size = child.size();
	for (int i = 0; i < size; i++) {
		if (child[i]->type == file->type&&child[i]->name == file->name) {
			return true;
		}
	}
	return false;
}

PCB* Folder::find(PCB * file)
{
	int size = child.size();
	for (int i = 0; i < size; i++) {
		if (child[i]->type == file->type&&child[i]->name == file->name) {
			return child[i];
		}
	}
	return NULL;
}

bool Folder::erase(PCB * file)
{
	int size = child.size();
	vector<PCB*>::iterator  it;
	for (it = child.begin();it!=child.end();it++) {
		if ((*it)->type == file->type&&(*it)->name == file->name) {
			child.erase(it);
			return true;
		}
	}
	return false;
}

int Folder::size()
{
	return child.size();
}
