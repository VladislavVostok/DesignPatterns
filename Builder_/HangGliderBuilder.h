#pragma once
#include "AircraftBuilder.h"

//  Класс строител¤. ”меет создавать дельтапланы

class HangGliderBuilder :public AircraftBuilder
{
public:

	HangGliderBuilder();
	virtual ~HangGliderBuilder();

public:

	void BuildFrame();

	void BuildEngine();

	void BuildWheels();

	void BuildDoors();

	void BuildWings();

};

