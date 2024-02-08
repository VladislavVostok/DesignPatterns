#include <iostream>
#include "Car.h"
#include "Buyer.h"

using namespace std;

int main()
{
	// ������� ������ ������ � ��������� ����� 100 000
	Car* bmw = new Car("bmw X9", 100000);

	// ������� ������� ������������� ����������� ������
	UkrainianBuyer* firstBuyer = new UkrainianBuyer("Petr Mikolaenko");
	UkrainianBuyer* secondBuyer = new UkrainianBuyer("Oleg Kononenko");

	// ���������� ������������ ���������� �������
	bmw->Attach(firstBuyer);
	bmw->Attach(secondBuyer);

	// �������� ���� ������, ���������������� ���������� ��� �� ������ �� ����
	bmw->SetPrice(80000);
	bmw->SetPrice(70000);
	bmw->SetPrice(60000);

	delete firstBuyer;
	delete secondBuyer;
	delete bmw;

	return 0;
}