#pragma once
#include<iostream>
#include<string>
using namespace std;

// ����������� ����� ����������
class Device {
public:
	virtual string ToString() = 0;
};

// ����������� ����� ���������� �����
class Box : public Device{

};

// ����������� ����� �������� �����
class Hdd : public Device {

};

// ����������� ����� ����������� �����
class MainBoard : public Device {
};

// ����������� ����� ����������
class Processor : public Device {
};

// ����������� ����� ������
class Memory : public Device {
};

// ���������� ����� ����������. ��������� AMD
class AmdProcessor : public Processor
{
public:
	string ToString()
	{
		return "AmdProcessor";
	}
};

// ���������� ����� ����������� �����. ����������� ����� Asus
class AsusMainBord : public MainBoard
{
public:
	string ToString()
	{
		return "AsusMainBord";
	}
};
// ���������� ����� ���������� �����. ���������� ���� ������ �����
class SilverBox : public Box
{
public: 
	string ToString()
	{
		return "SilverBox";
	}
};

// ���������� ����� ����������. Intel ���������
class IntelProcessor : public Processor
{
public: 
	string ToString()
	{
		return "IntelProcessor";
	}
};

// ���������� ����� �������� �����. ������� ���� LG
class LGHDD : public Hdd
{
public: 
	string ToString()
	{
		return "LG hdd";
	}
};

// ���������� ����� ����������� �����. ����������� ����� MSI
class MSIMainBord : public MainBoard
{
public:
	string ToString()
	{
		return "MSIMainBord";
	}
};

class BlackBox : public Box
{
public: 
	string ToString()
	{
		return "BlackBox";
	}
};

// ���������� ����� ���. ��� DDR
class DdrMemory : public Memory
{
public: 
	string ToString()
	{
		return "DdrMemory";
	}
};

// ���������� ����� �������� �����. ������� ���� Samsung
class SamsungHDD : public Hdd
{
public:
	string ToString()
	{
		return "Samsung hdd";
	}
};

// ���������� ����� ���. ��� DDR2
class Ddr2Memory : public Memory
{
public: 
	string ToString()
	{
		return "Ddr2Memory";
	}
};

