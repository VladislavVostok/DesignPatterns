#include <iostream>

using namespace std;


// ������� ����� ���������
// � ��� ���������� ������� ��� ������� �� �������
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

// ������� ����� � ������� ����� ��������� ���������� ������
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
// ���������� ���������
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
// ���������� ������ ��� �������� �������
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