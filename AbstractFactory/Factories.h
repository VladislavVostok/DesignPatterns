#pragma once
#include<iostream>
#include "Devices.h"
using namespace std;

/*
* ��������� ������� ��� �������� ������������
* ���������� ����� ������������� ����������
*/

class IPCFactory {
public:
	virtual Box* CreateBox() = 0;
	virtual Processor* CreateProcessor() = 0;
	virtual MainBoard* CreateMainBoard() = 0;
	virtual Hdd* CreateHdd() = 0;
	virtual Memory* CreateMemory() = 0;
};

/*
* ������� ��� �������� "��������" ������������
* ���������� ����� ������������� ����������
*/
class HomePcFactory : public IPCFactory {
public:
	Box* CreateBox()
	{
		return new SilverBox();
	}
	Processor* CreateProcessor()
	{
		return new IntelProcessor();
	}
	MainBoard* CreateMainBoard()
	{
		return new MSIMainBord();
	}
	Hdd* CreateHdd()
	{
		return new SamsungHDD();
	}
	Memory* CreateMemory()
	{
		return new Ddr2Memory();
	}
};

/*
* ������� ��� �������� "�������" ������������
* ���������� ����� ������������� ����������
*/
class OfficePcFactory : public IPCFactory {
public:
	Box* CreateBox()
	{
		return new BlackBox();
	}
	Processor* CreateProcessor()
	{
		return new AmdProcessor();
	}
	MainBoard* CreateMainBoard()
	{
		return new AsusMainBord();
	}
	Hdd* CreateHdd()
	{
		return new LGHDD();
	}
	Memory* CreateMemory()
	{
		return new DdrMemory();
	}
};
