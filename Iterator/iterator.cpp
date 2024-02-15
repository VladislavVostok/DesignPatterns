#include <iostream>

using namespace std;


// базовый класс итератора
// в нем определены функции для прохода по массиву
class BaseIterator
{

public:
	BaseIterator()
	{
	}
	BaseIterator::~BaseIterator()
	{
	}


	virtual int* First() = 0;
	virtual int* Next() = 0;
	virtual int* CurrentItem() = 0;

	virtual bool IsFinished() = 0;


};

// базовый класс в котором будет храниться внутренний массив
class Aggregate
{
public:
	Aggregate()
	{
	}


	~Aggregate()
	{
	}

	virtual  BaseIterator* CreateIterator() = 0;
};


class ConcreteAggregate;
// реализация итератора
class ConcreteIterator :
	public BaseIterator
{
	ConcreteAggregate* pCurrent;
	int currentIndex = 0;
public:
	ConcreteIterator(ConcreteAggregate* ptr)
	{
		pCurrent = ptr;
	}

	~ConcreteIterator()
	{
	}

	int* First()
	{
		return (*pCurrent)[0];
	}
	int* Next()
	{
		if (currentIndex >= (*pCurrent).GetCount()) {
			return nullptr;
		}
		return (*pCurrent)[++currentIndex];
	}
	int* CurrentItem()
	{
		return (*pCurrent)[currentIndex];
	}

	bool IsFinished()
	{
		return currentIndex >= (*pCurrent).GetCount();
	}

};


class BaseIterator;
// реализация класса для хранения массива
class ConcreteAggregate : public Aggregate
{
	enum { size = 4 };
	int arr[size] = { 0 };

public:
	ConcreteAggregate()
	{
	}
	~ConcreteAggregate()
	{
	}

	BaseIterator* CreateIterator()
	{
		return new ConcreteIterator(this);
	};


	int GetCount()
	{
		return size;
	}
	int* operator[](int index)
	{
		if (index >= size) {
			return nullptr;
		}
		return &arr[index];
	}
};




int main()
{
	// создаем объект класса внутри которого находится наш массив
	ConcreteAggregate* ptr = new ConcreteAggregate();

	*(*ptr)[0] = 5;
	*(*ptr)[1] = 7;
	*(*ptr)[2] = 8;

	// создаем итератор для прохода по внутреннему массиву
	BaseIterator* iterator = ptr->CreateIterator();

	// получаем доступ к первому элементу
	int *a = iterator->First();

	// цикл показа всех элементов
	while(a)
	{
		cout << *a << " ";
		a = iterator->Next();
	}
	// чистим за собой
	delete ptr;
	delete iterator;

	return 0;
}