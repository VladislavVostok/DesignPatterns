#pragma once
#include<iostream>
using namespace std;

#include"EnvironmentalService.h"
#include"CityService.h"
#include"CountryService.h"

// ����� Facade. ������������ ����������� ��������
// �� ������� ���� �������� � ������� � �����-���������
class Construction
{
	EnvironmentalService eService;
	CityService cService;
	CountryService coService;

public:
	Construction();
	virtual ~Construction();
	bool IsAllowed(Firm* pFirm);
};

