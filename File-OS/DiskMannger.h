#pragma once

#include "Folder.h"

class DiskMannger
{
public:



	bool DiskMkdir(string dirName);//创建磁盘文件夹

	bool DiskRmdir(string dirName);//删除磁盘文件夹

	bool DiskCkdir(string dirName);//检查磁盘是否存在文件夹

	DiskMannger();//磁盘构造函数
	~DiskMannger();//磁盘类析构函数
	void format(); //: 对文件存储器进行格式化，即按照文件系统的结构对虚拟磁盘空间进行布局，并在其上创建根目录以及用于管理文件存储空间等的数据结构。
	void Mkdir();

	void Rmdir();
	
	
	void ls(); //: 用于显示目录
	void cd(); //: 用于更改当前目录
	void create();//: 用于创建文件
	void open(); //: 用于打开文件
	void close(); //: 用于关闭文件
	void write(); //: 用于写文件
	void read(); //: 用于读文件
	void rm(); //: 用于删除文件
private:
	Folder *root;
};


