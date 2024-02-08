#pragma once
#include<iostream>
#include<string>
using namespace std;

/* 
 *  ��� ����������� ������� ����� Device.
 *  �� ���������� ������� Clone, ������� ���������� 
 *  ������ �������� Prototype
 */
class Device {
private:
	// �������� ����������
	string name;
public:
	// ������������
	Device() : Device("Unknown device") {}
	Device(string dname){
		SetName(dname);
	}
	// ��������������� �������
	string GetName() const{
		return name;
	}
	void SetName(string dname) {
		name = dname;
	}
	// ����� ����������� �������
	// ��� ����� �������������� ��� �������� �����
	virtual Device* Clone() const = 0;

	// ����������� ������
	void Show() const{
		cout << "\nName is\n" << GetName() << "\n";
	}
};
