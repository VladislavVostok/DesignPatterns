#include<iostream>
#include<vector>
#include "CompositeUnit.h"
#include "MonoTubeShip.h"
#include "TwinTubeShip.h"
#include "TripleTubeShip.h"
#include "FourTubeShip.h"
using namespace std;



// ������� ��� �������� �����
CompositeUnit* CreateFleet()
{
	
	CompositeUnit* fleet = new CompositeUnit;
	// ������� 4 ����������� �������
	for (int i = 0; i<4; ++i)
		fleet->AddUnit(new MonoTubeShip());
	// ������� 3 ����������� �������
	for (int i = 0; i<3; ++i)
		fleet->AddUnit(new TwinTubeShip());
	// ������� 2 ����������� �������
	for (int i = 0; i<2; ++i)
		fleet->AddUnit(new TripleTubeShip());

	// ������� ���� �������������� ��������
	fleet->AddUnit(new FourTubeShip());

	return fleet;
}

int main()
{
	// ������� �������� ��� ����!
	CompositeUnit* fleet = CreateFleet();

	cout << "Full power of our fleet:" << fleet->GetPower()<<endl;
	delete fleet;

	return 0;
}