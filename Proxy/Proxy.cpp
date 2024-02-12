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


// �����, ��� �������� ����� ������
class Mathematics : public IMathematics
{
public:
	double Addition(double x, double y) { return x + y; }
	double Subtraction(double x, double y) { return x - y; }
	double Multiplication(double x, double y) { return x * y; }
	double Division(double x, double y) { return x / y; }

};

// ����� ������
class MathematicsProxy : public IMathematics {
private:
	// �������������� ������, ��� �������������� �������� ����������
	Mathematics* math;
public:

	MathematicsProxy() {
		math = new Mathematics();
	}

	// �������� ������� ��������
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
	
	
	// ������� ������
	MathematicsProxy* proxy = new MathematicsProxy();

	// �������� �������������� �������
	// ��������
	cout <<"7 + 11 = " << proxy->Addition(7, 11)<<endl;
	// ���������
	cout << "6 - 8 = " << proxy->Subtraction(6, 8) << endl;
	// ���������
	cout << "5 * 7 = " << proxy->Multiplication(5, 7) << endl;
	// �������
	cout << "33 / 11 = " << proxy->Division(33, 11) << endl;

	delete proxy;

	return 0;
}