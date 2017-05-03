#include "DiskMannger.h"

DiskMannger::DiskMannger()
{
	root =new File();
	//设置磁盘根为目录
	root->type = File::FOLDER;
	//设置根节点的父节点为自身
	root->father = root;
	cout << "欢迎！！~-----------您可输入help获得帮助------------" << endl<< "\n[root@localhost ~]# ";
	string opear,cmd;
	while (cin >> cmd) 
	{
		 if (cmd == "format") {
			this->format();
		}
		else if (cmd == "mkdir") {
			this->mkdir();
		}
		else if (cmd == "rmdir") {
			this->rmdir();
		}
		else if (cmd == "ls") {
			this->ls();
		}
		else if (cmd == "cd") {
			this->cd();
		}
		else if (cmd == "create") {
			this->create();
		}
		else if (cmd == "open") {
			this->open();
		}
		else if (cmd == "close") {
			this->close();
		}
		else if (cmd == "write") {
			this->write();
		}
		else if (cmd == "read") {
			this->read();
		}
		else if (cmd == "rm") {
			this->rm();
		}else if(cmd=="help"){
			cout << "\n●format:对文件存储器进行格式化，即按照文件系统的结构对虚拟磁盘空间进行布局，并在其上创建根目录以及用于管理文件存储空间等的数据结构。\n"<<
				"●mkdir:用于创建子目录\n" <<
				"●rmdir : 用于删除子目录\n" <<
				"●ls : 用于显示目录\n" <<
				"●cd : 用于更改当前目录\n" <<
				"●create : 用于创建文件\n" <<
				"●open : 用于打开文件\n" <<
				"●close : 用于关闭文件\n" <<
				"●write : 用于写文件\n" <<
				"●read : 用于读文件\n" <<
				"●rm : 用于删除文件\n" << endl;
		}
		else {
			cout << "输入指令错误，请重新输入！！" << endl;
		}
		cout << "\n[root@localhost ~]# ";

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
