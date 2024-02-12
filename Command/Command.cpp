#include <iostream>
#include "RemoteControl.h"
using namespace std;


// класс Receiver класс телевизора
class TV
{
	// включен телевизор или нет
	bool on;
public:
	// включить телевизор
	void TurnOn() {
		std::cout << "\nTurn on TV\n";
		on = true;
	}
	// выключить телевизор
	void TurnOff() {
		std::cout << "\nTurn off TV\n";
		on = false;
	}
};

// класс Command
class TVCommand
{
protected:
	TV* tvPlayer = nullptr;
public:
	TVCommand(TV* pTV)
	{
		tvPlayer = pTV;
	}
	virtual void Execute() = 0;
};

class TVOnCommand :public TVCommand
{
public:
	TVOnCommand(TV* ptr) :TVCommand(ptr) {}
	void Execute()
	{
		if (tvPlayer)
			tvPlayer->TurnOn();
	}
};

class TVOffCommand :public TVCommand
{
public:
	TVOffCommand(TV* ptr) :TVCommand(ptr) {}
	void Execute()
	{
		if (tvPlayer)
			tvPlayer->TurnOff();
	}
};


class RemoteControl {

private:
	TVCommand* command;
public:
	void SetCommand(TVCommand* pCommand) {
		command = pCommand;
	}
	void PressButton() {
		command->Execute();
	}
};


int main()
{
	RemoteControl control;
	TV* concreteTV = new TV();

	TVCommand* tvOn = new TVOnCommand(concreteTV);
	TVCommand* tvOff = new TVOffCommand(concreteTV);

	
	// включаем телевизор
	control.SetCommand(tvOn);

	control.PressButton();

	//выключаем телевизор

	control.SetCommand(tvOff);

	control.PressButton();

	delete tvOff;
	delete tvOn;
	delete concreteTV;

	return 0;
}