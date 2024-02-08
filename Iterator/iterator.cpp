#include <iostream>
#include "ConcreteAggregate.h"
#include "BaseIterator.h"

using namespace std;

int main()
{
	// ������� ������ ������ ������ �������� ��������� ��� ������
	ConcreteAggregate* ptr = new ConcreteAggregate();

	*(*ptr)[0] = 5;
	*(*ptr)[1] = 7;
	*(*ptr)[2] = 8;

	// ������� �������� ��� ������� �� ����������� �������
	BaseIterator* iterator = ptr->CreateIterator();

	// �������� ������ � ������� ��������
	int *a = iterator->First();

	// ���� ������ ���� ���������
	while(a)
	{
		cout << *a << " ";
		a = iterator->Next();
	}
	// ������ �� �����
	delete ptr;
	delete iterator;

	return 0;
}