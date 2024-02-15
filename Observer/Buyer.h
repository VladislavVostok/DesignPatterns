#pragma once
#include <string>
#include "Product.h"

using namespace std;


// Класс Observer
// Класс потенциального покупателя
class Buyer
{
public:
	// информирование об изменении состояния
	virtual void Update(Product*)=0;
};
// Класс ConcreteObserver
// Класс для русских покупателей
class RussianBuyer:public Buyer
{
private:
	Product* ptr;
	string name;
public:
	RussianBuyer(string pName)
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
