#include<iostream>
#include <map>

using namespace std;



class Trainee;
// класс Mediator
class AbstractClassroom
{
public:
	virtual void Send(string from, string to, string message) = 0;
	virtual void Register(Trainee* trainee) = 0;
};

// Это реализация ConcreteMediator
class Classroom :public AbstractClassroom
{
private:
	map<string, Trainee*> trainees;
public:
	void Register(Trainee* trainee)
	{
		if (trainees.find(trainee->GetName()) == trainees.end())
		{
			trainees[trainee->GetName()] = trainee;
		}
		trainee->SetClassroom(this);
	}
	void Send(string from, string to, string message)
	{
		auto ptrTrainee = trainees.find(to);
		if (ptrTrainee != trainees.end())
		{
			(*ptrTrainee).second->Receive(from, message);
		}

	}
};


class Classroom;
class Trainee
{
private:
	string name;
	Classroom* classroom;
public:
	Trainee(string pName)
	{
		name = pName;
	}
public:
	string GetName() const
	{
		return name;
	}
	void SetName(string pName)
	{
		name = pName;
	}
	Classroom* GetClasroom() const
	{
		return classroom;
	}
	void SetClassroom(Classroom* pClassroom)
	{
		classroom = pClassroom;
	}
public:
	// Отсылка сообщения
	void Send(string to, string message)
	{
		classroom->Send(name, to, message);
	}

	virtual void Receive(string from, string message)
	{
		cout << "\nMessage from " << from << " to " << name << " : " << message << endl;
	}
};

class MathClass : public Trainee
{
public:
	MathClass(string name) :Trainee(name)
	{}
	void Receivee(string from, string message)
	{
		cout << "\nMessage in Math class\n";
		Trainee::Receive(from, message);
	}
};

int main()
{
	// создаем объект классная комнатьа
	Classroom *classroom = new Classroom();

	// ученики математического класса
	Trainee* piter = new MathClass("Piter");
	Trainee* tim = new MathClass("Tim");
	Trainee* brad = new MathClass("Brad");
	Trainee* joana = new MathClass("Joana");

	// регистрируем их в классе
	classroom->Register(piter);
	classroom->Register(tim);
	classroom->Register(brad);
	classroom->Register(joana);

	// посылаем сообщения
	piter->Send("Brad", "3*3+7");
	joana->Send("Tim", "21-78*3");
	
	// очистка
	delete piter;
	delete tim;
	delete brad;
	delete joana;

	delete classroom;

	return 0;
}