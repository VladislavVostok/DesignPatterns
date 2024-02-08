#include<iostream>
#include "MathProxy.h"
using namespace std;

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