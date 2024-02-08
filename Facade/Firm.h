#pragma once

#include<iostream>
#include<string>
using namespace std;

// ����� �����
class Firm
{
public:
	// ������������ � ����������
	Firm();
	Firm(string fName,bool bLicense,bool eLicense, bool cLicense);
	virtual ~Firm();

private:
	// �������� �����
	string name;
	// ���� �� ������������ �������� � �����
	bool builderLicense;
	// ���� �� ������������� ����������
	bool environmentalLicense;
	// ���� �� ���������� �� ������
	bool cityLicense;


public:
	// ������� ��� ������ � ������
	string GetName() {
		return name;
	}
	void SetName(string fName) {
		name = fName;
	}
	// ������� ��� ������ �� ������������ ��������
	bool GetBuilderLicense(){
		return builderLicense;
	}
	void SetBuilderLicense(bool bLicense){
		builderLicense = bLicense;
	}
	// ������� ��� ������ � ������������� �����������
	bool GetEnvironmentalLicense() {
		return environmentalLicense;
	}
	void SetEnvironmentalLicense(bool eLicense) {
		environmentalLicense = eLicense;
	}
	// ������� ��� ������ � ��������� �����������
	bool GetCityLicense() {
		return cityLicense;
	}
	void SetCityLicense(bool cLicense) {
		cityLicense = cLicense;
	}


};

