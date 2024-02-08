#pragma once
#include "AircraftBuilder.h"

// класс строител¤. ”меет создавать планеры
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

