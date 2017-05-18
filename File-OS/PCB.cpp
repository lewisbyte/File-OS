#pragma once
#include "PCB.H"

PCB::PCB() 
{
	this->access = Write;
	this->modifyDate = getTime();
	this->size = N;
}

PCB::~PCB()
{

}
string PCB::getTime()
{
	time_t t = time(0);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d %X", localtime(&t));
	return tmp;
}