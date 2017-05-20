#include<cstring>
#include "FAT.h"


void FAT::init()
{
	memset(this->DiskBlock, false, sizeof(this->DiskBlock));
}

int FAT::getBlock()
{
	for (int i = 0; i < BLOCK_SIZE; i++) {
		if (!this->DiskBlock[i]) {
			this->DiskBlock[i] = true;
			return i;
		}
	}
	return -1;
}
