#include<iostream>

using namespace std;


class Device
{
public:

	Device()
	{
	}

	virtual ~Device()
	{
	}
public:
	virtual void MakeEngine() = 0;
	virtual void MakeWheels() = 0;
	virtual void MakeCabin() = 0;
	virtual void MakeWings() = 0;

	virtual void Assemble()
	{
		MakeEngine();
		MakeWheels();
		MakeCabin();
		MakeWings();
	}
};


class Car :
	public Device
{
public:

	Car()
	{
	}

	virtual ~Car()
	{
	}
public:
	void MakeEngine()
	{
		cout << "\nMake Engine for Car\n";
	}
	void MakeWheels()
	{
		cout << "\nMake Wheels for Car\n";
	}
	void MakeCabin()
	{
		cout << "\nMake Cabin for Car\n";
	}
	void MakeWings()
	{
		cout << "\nNo wings for Car\n";
	}
};

class Airplane :
	public Device
{
public:

	Airplane()
	{
	}

	virtual ~Airplane()
	{
	}
public:
	void MakeEngine()
	{
		cout << "\nMake Engine for Airplane\n";
	}
	void MakeWheels()
	{
		cout << "\nMake Wheels for Airplane\n";
	}
	void MakeCabin()
	{
		cout << "\nMake Cabin for Airplane\n";
	}
	void MakeWings()
	{
		cout << "\nMake Wings for Airplane\n";
	}
};

int main()
{
	Device* device = new Car();
	device->Assemble();
	delete device;

	cout << "\n\n=====================\n\n";
	device = new Airplane();
	device->Assemble();
	delete device;

	return 0;
}