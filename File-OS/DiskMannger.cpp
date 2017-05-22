#include <windows.h> 
#include<stack>
#include<iostream>
#include<iomanip>
#include<queue>
#include <fstream>  
#include<direct.h>  
#include<io.h> 
#include "DiskMannger.h"
#include "Folder.h"
#include "FileType.h"
#include "Access.h"
#include "FAT.h"


const string ACCESS[] = { "只读","可修改","可执行" };
const string rootPath = "A:/";
queue<FCB*> persistQueue;//持久化队列
FAT fat;
string blocks[N];
ofstream *out = NULL;
ifstream *in = NULL;



using namespace std;


void DiskMannger::DiskWrite(File * file)
{
	//文件输出流

	printf("%s\n", file->path.c_str());

	//freopen(file->name.c_str(), "w", stdout);

	out = new ofstream(file->path.c_str());
	if (out->is_open())
	{
		out->close();
	}

	//cout << "hello world" << endl;

   // fclose(stdout);//关闭文件

}

bool DiskMannger::DiskMkdir(string dirName)
{
	printf("%s\n",dirName.c_str());
	return _mkdir(dirName.c_str()) == 0;


}

bool DiskMannger::DiskRmdir(string dirName)
{
	 
	return rmdir(dirName.c_str()) == 0;
}

bool DiskMannger::DiskCkdir(string dirName)
{
	
	if (_access(dirName.c_str(), 0) == -1)
	{
		return  _mkdir(dirName.c_str()) == 0;
	}
	return false;
}

void DiskMannger::DiskRmdir(Folder *f)
{
	//DFS删除
	for (int i = 0; i < f->child.size(); i++) {
		if (f->child[i]->type == DOCUMENT) {
			remove(f->child[i]->path.c_str());
		}else {
			this->DiskRmdir((Folder*)f->child[i]);
		}
	}
	this->DiskRmdir(f->path.c_str());
}


DiskMannger::DiskMannger()
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);


	root = new Folder("/",FileType::FOLDER);
	root->path = rootPath;
	//设置磁盘根为目录
	//设置根节点的父节点为自身
	root->father = root;
	cout << "欢迎！！-----------您可输入help获得帮助------------" << endl<< "\n[root@localhost A:/]# ";
	string opear,cmd;
	while (cin >> cmd) 
	{
		 if (cmd == "format") {
			this->format(blocks);
		}
		else if (cmd == "mkdir") {
			this->Mkdir();
		}
		else if (cmd == "rmdir") {
			this->Rmdir();
		}
		else if (cmd == "ls") {
			this->ls();
		}
		else if (cmd == "cd") {
			this->cd();
		}
		else if (cmd == "create") {
			this->create();
		}
		else if (cmd == "open") {
			this->open();
		}
		else if (cmd == "close") {
			this->close();
		}
		else if (cmd == "rm") {
			this->rm();
		}
		else if (cmd == "exit") {
			printf("%s\n", "再见！");
			break;
		}
		else if(cmd=="help"){
			cout << "\n●format:对文件存储器进行格式化.\n"<<
				"●mkdir:用于创建子目录\n" <<
				"●rmdir : 用于删除子目录\n" <<
				"●ls : 用于显示目录\n" <<
				"●cd : 用于更改当前目录\n" <<
				"●create : 用于创建文件\n" <<
				"●open : 用于打开文件\n" <<
				"●close : 用于关闭文件\n" <<
				"●write : 用于写文件\n" <<
				"●read : 用于读文件\n" <<
				"●rm : 用于删除文件\n" <<
				"●exit : 退出系统\n"
				<<endl;
		}
		else {
			cout << "输入指令错误，请重新输入！！" << endl;
		}
		cout << "\n[root@localhost "+this->root->path+" ]# ";

	}
}

DiskMannger::~DiskMannger()
{

}

void DiskMannger::format(string *blocks)
{
	fat.init(blocks);

	//回退到根目录
	while (root->father != root) {
		this->root = (Folder*)(this->root->father);
	}

	this->DiskRmdir(this->root);


	printf("%s\n", "磁盘格式化成功！");
}

void DiskMannger::Mkdir()
{
	string name;
	cin >> name;

	Folder *childFile = new Folder(name,FileType::FOLDER);
	
	//设置父节点
	childFile->father = (this->root);
	childFile->path = this->root->path + name + "/" ;
	//判断是否文件重复
	
	if (this->root->count(childFile)) {
		//文件重复报错
		cout << "创建文件夹失败，文件夹名出现重复" << endl;
	}else {
		cout << "创建文件夹成功" << endl;
		this->DiskMkdir(childFile->path);
		this->root->addChild(childFile);

	}
}

void DiskMannger::Rmdir()//TODO fix 不能删除含有文件的文件夹
{
	string name;
	cin >> name;
	Folder *childFile =new Folder(name, FOLDER);
	childFile = (Folder*) this->root->find(childFile);
	if (this->root->erase(childFile)) {
		//文件重复报错
		this->DiskRmdir(childFile);
		cout << "删除文件夹成功" << endl;
	}else {
		cout << "无此文件夹 ，删除文件夹失败" << endl;
		
	}
}

void DiskMannger::ls()
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_BLUE);
	cout << setw(10) << "访问权限"
		<< setw(20) <<"文件大小"
		<< setw(25) << "修改日期"
		<< setw(20) << "文件名"
		<< endl;
	int size = this->root->size();
	
	for(int i= 0;i<size;i++)
	{
		
		if (this->root->child[i]->type==FOLDER){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN);
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//白色
		}
		cout << setw(10)<< ACCESS[this->root->child[i]->access]
			<< setw(20)<<this->root->child[i]->size
			<< setw(25)<<this->root->child[i]->modifyDate
			<< setw(20)<<this->root->child[i]->name
			<<endl;
		
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void DiskMannger::cd()
{
	string name;
	cin >> name;
	if (name == "..") {
		this->root = (Folder*)(this->root->father);
	}
	else {
		if (this->root->count(new Folder(name, FOLDER))) {
			
			if (this->root->find(new Folder(name, FOLDER))->type != FOLDER)
			{
				cout << "无此文件夹" << endl;
			}
			else
			{
				root = (Folder*)this->root->find(new Folder(name, FOLDER));
			}
		}
		else {
			cout << "无此文件夹 " << endl;
		}
	}
	
}

void DiskMannger::create()
{
	string name;
	cin >> name;
	
	File *childFile =  new File( name, DOCUMENT);
	//设置父节点
	childFile->father = (this->root);
	childFile->path = this->root->path + name;
	//判断是否文件重复
	if (this->root->count(childFile)) {
		//文件重复报错
		cout << "创建文件失败，文件名出现重复！！" << endl;
	}
	else {
		cout << "创建文件成功！" << endl;
		this->root->addChild(childFile);
		this->DiskWrite(childFile);
	}
}

void DiskMannger::open()
{
	string name,cmd;
	cin >> name;
	
    File * file = (File*)this->root->find(new File(name, DOCUMENT));
	if (file!=NULL) {
		
		printf("%s\n", "文件读写流打开成功!");
		cout << "\n[root@localhost " + this->root->path + " ]# ";
		while (cin>>cmd) {
			cout << "\n[root@localhost " + this->root->path + " ]# ";
			if (cmd == "write") {
				this->write(file->path.c_str(), file);
			}
			else if (cmd == "read") {
				this->read(file->path.c_str());
			}
			else if (cmd == "close") {
				this->close();
				break;
			}
		}
	}
	else {
		printf("%s\n", "无法打开文件读写流，无此文件！");
	}
}

void DiskMannger::close()
{
	if (out == NULL||in==NULL) {
		printf("%s\n", "无文件读写流需要关闭!");
	}else {
		out->close();
		in->close();
		printf("%s\n", "文件读写流关闭成功!");
	}
}

void DiskMannger::write(const char *s, File* file)
{
	string content;
	cin >> content;
	if (in != NULL)in->close();
	file->addContent(content.c_str(),blocks);//添加内容到文件中
	out = new ofstream(s);
	if (out->is_open())
	{
		*out << content;
	}
	out->close();
}

void DiskMannger::read(const char *s)
{
	char *content = new char[N];
	if (out != NULL)out->close();
	in =  new ifstream(s);
	if (in->is_open())
	{
		*in >> content;
	}
	in->close();
	cout << content << endl;

}

void DiskMannger::rm()
{
	string name;
	cin >> name;
	File *childFile = new File(name, DOCUMENT);
	if (this->root->count(childFile)) {
		//文件重复报错
		childFile =(File*) this->root->find(childFile);
		remove(childFile->path.c_str());
		childFile->release(fat,blocks);
		this->root->erase(childFile);
		
		cout << "删除文件成功！" << endl;
	}
	else {
		cout << "无此文件 ，删除文件失败" << endl;
	}

}
