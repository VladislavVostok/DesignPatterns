#include<iostream>

#include "human.h"
#include "CareTaker.h"
using namespace std;



int main()
{
	// ������� ������ ��������
	Human h("Piter", "Dymos", 44);

	MemoryState obj;

	// ��������� ���������
	obj.SetMemento(h.SaveMemento());
	// �������� ������
	h.SetSurname("Dixy");
	h.SetName("Oliver");
	h.SetAge(45);
	// ���������� ���������
	h.RestoreMemento(obj.GetMemento());
	
	cout << endl << h.GetName().c_str() << " " << h.GetSurname().c_str() << " " << h.GetAge()<<endl;

	return 0;
}