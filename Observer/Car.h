#pragma once
#include"Product.h"

// ����� ConcreteSubject
// ����� ����������� ��������
// � ����� ������ ������
class Car:public Product
{
public: 
	Car(string name, double price):Product(name, price){}
};