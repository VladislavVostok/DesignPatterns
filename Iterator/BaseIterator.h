#pragma once

// ������� ����� ���������
// � ��� ���������� ������� ��� ������� �� �������
class BaseIterator
{
	
public:
	BaseIterator();
	~BaseIterator();

	virtual int* First() = 0;
	virtual int* Next() = 0;
	virtual int* CurrentItem() = 0;

	virtual bool IsFinished() = 0;
	

};


