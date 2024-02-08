#pragma once
class BaseIterator;

// ������� ����� � ������� ����� ��������� ���������� ������
class Aggregate
{
public:
	Aggregate();
	~Aggregate();

	virtual  BaseIterator* CreateIterator() =0;
};

