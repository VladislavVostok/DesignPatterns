#pragma once
#include "Firm.h"

// �����, ���������� �� �������� ������������� ����� �������������
class EnvironmentalService
{
public:
	EnvironmentalService();
	virtual ~EnvironmentalService();
	// ���� �� � ����� ���������� �� ������������� �� ������� ������������� ������
	bool HasEnvironmentalAccess(Firm* pFirm) {
		return pFirm->GetEnvironmentalLicense() ? true : false;
	}
};

