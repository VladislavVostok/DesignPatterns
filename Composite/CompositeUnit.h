#pragma once
#include "Unit.h"
#include <vector>
using namespace std;

class CompositeUnit :
	public Unit
{
public:
	CompositeUnit();
	virtual ~CompositeUnit();
public:
	int GetPower()const;
	void AddUnit(Unit* p);
private:
	std::vector<Unit*> fleet;
};

CompositeUnit::CompositeUnit()
{
}


CompositeUnit::~CompositeUnit()
{
	for (int i = 0; i < fleet.size(); ++i)
		delete fleet[i];
}

int CompositeUnit::GetPower() const
{
	int amount = 0;
	for (int i = 0; i < fleet.size(); i++) {
		amount += fleet[i]->GetPower();
	}
	return amount;
}

void CompositeUnit::AddUnit(Unit* p)
{
	fleet.push_back(p);
}



