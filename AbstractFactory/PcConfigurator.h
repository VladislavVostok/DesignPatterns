#pragma once

#include<iostream>
#include "PC.h"
#include "Devices.h"
#include "Factories.h"

using namespace std;

// ����� ������������ 
class PcConfigurator
{
	/*
	*  ������� ������������ ������������� ����������
	*/
	IPCFactory* pcFactory;
public:
	PcConfigurator() {
		pcFactory = NULL;
	}
	virtual ~PcConfigurator() {
		if(pcFactory)
			delete pcFactory;
	}
	IPCFactory* GetPCFactory() {
		return pcFactory;
	}
	void SetPCFactory(IPCFactory* pcCurrentFactory) {
		pcFactory = pcCurrentFactory;
	}
	/*
	*  ����� ���������������� ���������� �����
	*/
	void Configure(PC* pc)
	{
		pc->SetBox(pcFactory->CreateBox());
		pc->SetMainBoard(pcFactory->CreateMainBoard());
		pc->SetHdd(pcFactory->CreateHdd());
		pc->SetMemory(pcFactory->CreateMemory());
		pc->SetProcessor(pcFactory->CreateProcessor());
	}
};

