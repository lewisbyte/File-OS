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

bool File::addContent(char * content)
{
	return false;
}

