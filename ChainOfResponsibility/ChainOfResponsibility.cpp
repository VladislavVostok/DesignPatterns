#include<iostream>
using namespace std;


// Претензии
class Claim
{
	string typeOfClaim;
	string from;
	double amountOfMoney;

public:

	Claim(string t = "", string f = "", double a = 0.0) : typeOfClaim(t), from(f), amountOfMoney(a) {}
	~Claim() { }

	string GetTypeOfClaim() const
	{
		return typeOfClaim;
	}

	void SetTypeOfClaim(string t)
	{
		typeOfClaim = t;
	}

	string GetFrom() const
	{
		return from;
	}
	void SetFrom(string f)
	{
		from = f;
	}

	double GetAmount() const
	{
		return amountOfMoney;
	}
	void SetAmount(double a)
	{
		amountOfMoney = a;
	}

};

class Manager
{
protected:
	Manager* pSuccessor;
public:
	void SetSuccessor(Manager* pTemp)
	{
		pSuccessor = pTemp;
	}
	virtual void Process(const Claim& request) = 0;
	virtual ~Manager() {}
};


class LocalBranchManager :
	public Manager
{
public:

	LocalBranchManager()
	{
	}

	~LocalBranchManager()
	{
	}

	void Process(const Claim& request)
	{
		if (request.GetAmount() < 10000.0)
		{
			cout << "\nВаш запрос был одобрен менеджером местного филиала. Вот информация об этом\n";
			cout << request.GetTypeOfClaim() << " " << request.GetFrom() << " " << request.GetAmount() << "\n";
		}
		else
		{
			pSuccessor->Process(request);
		}
	}
};


class LocalManager : public Manager
{
public:

	LocalManager() {}

	~LocalManager()	{}

	void Process(const Claim& request)
	{
		if (request.GetAmount() < 1000.0)
		{
			cout << "\nВаш запрос был одобрен местным менеджером. Вот информация об этом\n";
			cout << request.GetTypeOfClaim() << " " << request.GetFrom() << " " << request.GetAmount() << "\n";
		}
		else
		{
			pSuccessor->Process(request);
		}
	}
};



class CEO :
	public Manager
{
public:

	CEO() {}

	~CEO() {}

	void Process(const Claim& request)
	{
		if (request.GetAmount() < 100000.0)
		{
			cout << "\nВаш запрос был одобрен генеральным директором. Вот информация об этом\n";
			cout << request.GetTypeOfClaim() << " " << request.GetFrom() << " " << request.GetAmount() << "\n";
		}
		else
		{
			cout << "\nМы не в состоянии одобрить вашу претензию\n";
		}
	}
};

int main()
{
	Manager* vasya = new LocalManager();
	Manager* petya = new LocalBranchManager();
	Manager* fedya = new CEO();

	// Устанавливаем преемник
	vasya->SetSuccessor(petya);
	petya->SetSuccessor(fedya);

	Claim first("Об обслуживании","Даша",500);
	vasya->Process(first);

	Claim second("О службе поддержки клиентов", "Игнат", 5000);
	vasya->Process(second);

	Claim third("Об Интернете", "Федор", 50000);
	vasya->Process(third);

	Claim fourth("Об авариях", "Миша", 150000);
	vasya->Process(fourth);

	delete vasya;
	delete petya;
	delete fedya;

	return 0;
}