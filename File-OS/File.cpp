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

bool File::addContent(const char * content,string *blocks)
{
	int len = strlen(content);
	for (int i = 0; i < len; i++) {
		
	}

	return false;
}

void File::release(FAT & fat, string * blocks)
{
	for (int i = 0;i<this->size;i++) {
		fat.addBlock(index[i],blocks);
	}
}


