#include<cstring>
#include "FAT.h"


void FAT::init(string blocks[])//��ʼ������
{
	for (int i = 0; i < BLOCK_SIZE; i++) {
		this->freeDiskBlock.push(i);
		blocks[i].clear();
	}
}

int FAT::getBlock()//��ȡ�մ���
{
	if (this->freeDiskBlock.size() > 0) {
		int blockId = this->freeDiskBlock.top();
		this->freeDiskBlock.pop();
		this->fullDiskBlock.push(blockId);
		return blockId;
	}
	return -1;
}

void FAT::addBlock(int block, string  blocks[])//���մ��̿�
{
	this->freeDiskBlock.push(block);
	blocks[block].clear();
}

 