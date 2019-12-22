#pragma once

#include "Folder.h"

class DiskMannger
{
public:

	
	void DiskWrite(File * file);
	bool DiskMkdir(string dirName);//���������ļ���
	bool DiskRmdir(string dirName);//ɾ�������ļ���
	bool DiskCkdir(string dirName);
	void DiskRmdir(Folder * f);
	//�������Ƿ�����ļ���
	DiskMannger();//���̹��캯��
	~DiskMannger();	//��������������
	void format(string * blocks);//: ���ļ��洢�����и�ʽ����
	void Mkdir();
	void Rmdir();
	void ls(); //: ������ʾĿ¼
	void cd(); //: ���ڸ��ĵ�ǰĿ¼
	void create();//: ���ڴ����ļ�
	void open(); //: ���ڴ��ļ�
	void close(); //: ���ڹر��ļ�
	void write(const char * s, File * file);//: ����д�ļ�
	void read(const char * s);//: ���ڶ��ļ�
	void rm(); //: ����ɾ���ļ�
private:
	Folder *root;
};


