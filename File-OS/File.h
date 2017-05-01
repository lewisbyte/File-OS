#pragma once
#include<string>
#include<iostream>
using namespace std;

class File
{
public:
	File();
	~File();
	void Serialization();
	void Deserialization();

private:
	string name;
	string content;
	bool type;

};





