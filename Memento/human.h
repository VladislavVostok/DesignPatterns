#pragma once
#include <string>

#include "Memento.h"

using namespace std;

// ����� Originator
// � ����� ������� �� ����� �������� � ����������� � ��������
// � ��������� ��� ���������
class Human
{
private:
	string name;
	string surname;
	int age;
public:
	Human(string pName, string pSurname, int pAge)
	{
		name = pName;
		surname = pSurname;
		age = pAge;
	}
	Human() :Human("Oleg", "Kukushkin", 25) {}

	string GetName() const
	{
		return name;
	}
	void SetName(string pName)
	{
		name = pName;
	}

	string GetSurname() const
	{
		return surname;
	}
	void SetSurname(string pSurname)
	{
		surname = pSurname;
	}
	int GetAge() const
	{
		return age;
	}
	void SetAge(int pAge)
	{
		age = pAge;
	}
	// �������� ������ ���������
	Memento* SaveMemento() const
	{
		cout << "\nSaving state\n";
		return new Memento(name, surname, age);
	}
	// ��������������� ���������
	void RestoreMemento(Memento* pMemento)
	{
		cout << "\nRestoring state\n";
		name = pMemento->GetName();
		surname = pMemento->GetSurname();
		age = pMemento->GetAge();
	}
};

