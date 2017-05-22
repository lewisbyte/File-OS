#pragma once

#include<stack>
#include<algorithm>

const static int BLOCK_SIZE = 4096/sizeof(bool);

using namespace std;

class FAT {
public:

	stack<int>freeDiskBlock;//空磁盘块栈

	stack<int>fullDiskBlock;//占用磁盘块



	void init(char blocks[][BLOCK_SIZE]);

	void init(string * blocks);

	int  getBlock();

	void addBlock(int block, string * blocks);

	void addBlock(int block, char blocks[][BLOCK_SIZE]);
	//获取一个空的磁盘块

};