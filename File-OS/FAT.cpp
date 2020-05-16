#include "FAT.h"
#include <string>

void FAT::init(string blocks[])//初始化磁盘
{
    for (int i = 0; i < BLOCK_SIZE; i++) {
        this->freeDiskBlock.push(i);
        blocks[i].clear();
    }
}

int FAT::getBlock()//获取空磁盘
{
    if (this->freeDiskBlock.size() > 0) {
        int blockId = this->freeDiskBlock.top();
        this->freeDiskBlock.pop();
        this->fullDiskBlock.push(blockId);
        return blockId;
    }
    return -1;
}

void FAT::addBlock(int block, string blocks[])//回收磁盘块
{
    this->freeDiskBlock.push(block);
    blocks[block].clear();
}
