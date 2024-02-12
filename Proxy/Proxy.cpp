#include<iostream>
#include "MathProxy.h"
using namespace std;

class IMathematics {
public:
	virtual double Addition(double x, double y) = 0;
	virtual double Subtraction(double x, double y) = 0;
	virtual double Multiplication(double x, double y) = 0;
	virtual double Division(double x, double y) = 0;
};


// класс, чьи операции будут скрыты
class Mathematics : public IMathematics
{
public:
	double Addition(double x, double y) { return x + y; }
	double Subtraction(double x, double y) { return x - y; }
	double Multiplication(double x, double y) { return x * y; }
	double Division(double x, double y) { return x / y; }

};

// класс прокси
class MathematicsProxy : public IMathematics {
private:
	// математический объект, чьи математические операции скрываются
	Mathematics* math;
public:

	MathematicsProxy() {
		math = new Mathematics();
	}

	// вызываем скрытые операции
	double Addition(double x, double y) {
		return math->Addition(x, y);
	}
	double Subtraction(double x, double y) {
		return math->Subtraction(x, y);
	}
	double Multiplication(double x, double y) {
		return math->Multiplication(x, y);
	}
	double Division(double x, double y) {
		return math->Division(x, y);
	}
	virtual ~MathematicsProxy() {
		delete math;
	}
};


int main() {
	
	
	// Создаем прокси
	MathematicsProxy* proxy = new MathematicsProxy();

	// Вызываем математические функции
	// сложение
	cout <<"7 + 11 = " << proxy->Addition(7, 11)<<endl;
	// вычитание
	cout << "6 - 8 = " << proxy->Subtraction(6, 8) << endl;
	// умножение
	cout << "5 * 7 = " << proxy->Multiplication(5, 7) << endl;
	// деление
	cout << "33 / 11 = " << proxy->Division(33, 11) << endl;

	delete proxy;

	return 0;
}