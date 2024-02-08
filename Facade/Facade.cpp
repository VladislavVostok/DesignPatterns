#include<iostream>
#include "Construction.h"
#include "Firm.h"

using namespace std;

int main() {

	// ������� ������ ������ Facade
	Construction constructor;

	// ������� ������ �����
	Firm myfirm("DreamBuilder", true, true, false);
	
	// ��������� ��� �� ���������� ���� � ����� �� �������������
	bool allowable = constructor.IsAllowed(&myfirm);

	cout << myfirm.GetName() << ((allowable) ? " will build\n\n" : " won't build\n\n");

	return 0;
}