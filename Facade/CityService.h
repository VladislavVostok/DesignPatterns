#pragma once
#include<iostream>
using namespace std;

#include "Firm.h"

// �����, ���������� �� �������� ���� �� ������������� �� ��������� �����
class CityService
{
public:
	CityService();
	virtual ~CityService();
	// ���� �� � ����� ���������� �� ������������� �� ������
	bool HasCityAccess(Firm* pFirm) {
		return pFirm->GetCityLicense() ? true : false;
	}
};

