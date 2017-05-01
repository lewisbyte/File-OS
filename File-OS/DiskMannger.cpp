#include "DiskMannger.h"

DiskMannger::DiskMannger()
{
	root =new File();
	//设置磁盘根为目录
	root->type = File::FOLDER;
	//设置根节点的父节点为自身
	root->father = root;

	string cmd;
	while (cin >> cmd) 
	{

	}
}

DiskMannger::~DiskMannger()
{
}

void DiskMannger::format()
{
}

void DiskMannger::mkdir()
{
}

void DiskMannger::rmdir()
{
}

void DiskMannger::ls()
{
}

void DiskMannger::cd()
{
}

void DiskMannger::create()
{
}

void DiskMannger::open()
{
}

void DiskMannger::close()
{
}

void DiskMannger::write()
{
}

void DiskMannger::read()
{
}

void DiskMannger::rm()
{
}
