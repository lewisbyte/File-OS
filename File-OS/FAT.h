#pragma once

const static int BLOCK_SIZE = 4096/sizeof(bool);

class FAT {
public:

	bool DiskBlock[BLOCK_SIZE];//标记磁盘块是否占用
	void init();//初始化磁盘
	int  getBlock();//获取一个空的磁盘块

};