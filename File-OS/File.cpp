#include "File.h"

File::File() 
{

}
File::File(string _name, FileType _type)
{
	this->name = _name;
	this->type = _type;
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

bool File::operator<(const File & t) const
{
	
	return this->name<t.name;
}

void File::addChild(File  file)
{
	this->child[file]=file;
}
