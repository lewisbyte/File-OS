#include "File.h"

File::File() 
{

}
File::File(string _name,bool _type)
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
	return t.name<this->name;
}

void File::addChild(File  file)
{
	this->child.insert(file);
}
