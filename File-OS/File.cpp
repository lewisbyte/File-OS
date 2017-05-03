#include "File.h"

File::File() 
{

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

bool File::operator<(File & t) const
{
	return t.name<this->name;
}

void File::addChild(File * file)
{
}
