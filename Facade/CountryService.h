#pragma once
#include<iostream>
#include"Firm.h"
using namespace std;

// �����, ���������� �� �������� ������� �������� �� ������������� � �����
class CountryService
{
public:
	CountryService();
	virtual ~CountryService();
	// ���� �� � ����� �������� �� ������������� �� ������� ������
	bool HasBuildingLicense(Firm* pFirm) {
		return pFirm->GetBuilderLicense() ? true : false;
	}
};

