#pragma once
#include "AircraftBuilder.h"

// ����� ��������. ����� ��������� �������
class GliderBuilder : public AircraftBuilder
{
public:
	GliderBuilder();
	virtual ~GliderBuilder();
public:
	void BuildFrame();

	void BuildEngine();

	void BuildWheels();

	void BuildDoors();

	void BuildWings();
};

