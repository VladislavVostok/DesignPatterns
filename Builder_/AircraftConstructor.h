#pragma once
#include "AircraftBuilder.h"

// ����� ��������� ����� ��������� ���������� ������� � ������� ���������
class AircraftConstructor
{
public:
	AircraftConstructor();
	virtual ~AircraftConstructor();
	void Construct(AircraftBuilder* aircraftBuilder);
};

