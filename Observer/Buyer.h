#pragma once
#include <string>
#include "Product.h"

using namespace std;


// ����� Observer
// ����� �������������� ����������
class Buyer
{
public:
	// �������������� �� ��������� ���������
	virtual void Update(Product*)=0;
};
// ����� ConcreteObserver
// ����� ��� ���������� �����������
class UkrainianBuyer:public Buyer
{
private:
	Product* ptr;
	string name;
public:
	UkrainianBuyer(string pName)
	{
		name = pName;
	}
	Product* GetProduct() const
	{
		return ptr;
	}
	void SetProduct(Product* pProduct)
	{
		ptr = pProduct;
	}
	void Update(Product* pProduct)
	{
		cout << "\nChanges for " << name << " in product " << pProduct->GetName() << " " << pProduct->GetPrice();
	}
};
