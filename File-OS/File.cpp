#include "File.h"

File::File() 
{

	cout << "File init" << endl;
}

File::~File()
{

}

void File::Serialization()
{
	freopen(name.c_str(), "r", stdin);
}

void File::Deserialization()
{
	freopen(name.c_str(), "w", stdout);
}

bool File::operator<(File & t) const
{
	return false;
}
