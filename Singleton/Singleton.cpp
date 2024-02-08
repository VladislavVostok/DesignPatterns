#include<iostream>
#include<fstream>
#include<time.h>

using namespace std;

/*
* ����� ������� ������� ���������.
* �������������� - ������ ������� � ����������� ��������� ����.
* � ��������� ����� ������������ ������ � ����� ����������.
*/
class Logger {
private:
	// ����������� ������, ����� ������ ���� ������� ����� ������� � ����� ����������� �������
	Logger() {}
	// ��������� �� ������� ������ ������
	static Logger* pObj;
public:
	// ����������� �������-���� ��� ��������� ������� � ������� �����������
	static Logger* GetInstance();
	// �������-���� ��� ������ ����� � ���-����
	void PutMessage(string message);
};

Logger* Logger::pObj = NULL;

// ���������� �������-����� ��� ��������� ������� � ������� �����������
// ������ ���������, ���� �� �� �����������. ���� �� ����������� ������������ ��������� �� ��� ��������� ������
Logger* Logger::GetInstance() {
	if (!pObj) {
		pObj = new Logger();
	}
	return pObj;
}

// ���������� ������� ������ ����� � ���-����
void Logger::PutMessage(string message) {

	const time_t timer = time(NULL);
	ofstream fObj("logsingleton.txt", ios::app);
	if (!fObj) {

		cout << "\nError with file\n";
		exit(EXIT_FAILURE);
	}
	fObj << message.c_str() << "\t" << ctime(&timer) << endl;
}

int main() {
	// �������� ������ � ������� �����������
	Logger* pLogger = Logger::GetInstance();
	// ���������� ������ � �����������
	pLogger->PutMessage("This is first");
	pLogger->PutMessage("This is second");

	return 0;
}