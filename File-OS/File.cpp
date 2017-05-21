#include "File.h"

File::File() 
{

}
File::File(string _name, FileType _type)
{
	this->name = _name;
	this->type = _type;
	this->size = 0;
}

File::~File()
{

}

void File::Serialization()
{
	
}

void File::Deserialization()
{
	
}

bool File::addContent(const char * content)
{
	int len = strlen(content);
	

	return false;
}

void File::release(FAT &fat,char blocks[][N])
{
	for (int i = 0;i<this->size;i++) {
		fat.addBlock(index[i],blocks);
	}
}

