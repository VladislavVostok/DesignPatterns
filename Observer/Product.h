#pragma once
#include <string>
#include<list>
#include<iostream>


using namespace std;


class Buyer;

// ����� Subject
// � ����� ������ ��� ����� Product, ������� ��������� ����������� �������

class Product
{
private:
	// �������� 
	string name;
	// ����
	double price;
	list<Buyer*> buyers;

public:

	Product(string, double);
	~Product();

public:
	// ���������� ����������� ���������� 
	void Attach(Buyer*);
	// �������� ����������� ����������
	void Detach(Buyer*);
	// ��������� ���� ����������� �� ��������� ���������
	void Notify();

public:

	string GetName() const
	{
		return name;
	}

	double GetPrice() const
	{
		return price;
	}
	// ��������� ����� ���� � �������������� ����������� �� ����
	void SetPrice(double pPrice)
	{
		if(price != pPrice)
		{
			price = pPrice;
			Notify();
		}
	}
};

