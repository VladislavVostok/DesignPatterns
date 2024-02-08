#pragma once
#include "IMath.h"
#include "Math.h"

// ����� ������
class MathematicsProxy : public IMathematics{
private:
	// �������������� ������, ��� �������������� �������� ����������
	Mathematics* math;
public: 

	MathematicsProxy() {
		math = new Mathematics();
	}

	// �������� ������� ��������
	double Addition(double x, double y){
		return math->Addition(x, y);
	}
	double Subtraction(double x, double y){
		return math->Subtraction(x, y);
	}
	double Multiplication(double x, double y){
		return math->Multiplication(x, y);
	}
	double Division(double x, double y){
		return math->Division(x, y);
	}
	virtual ~MathematicsProxy() {
		delete math;
	}
};

