#include<iostream>
#include "Construction.h"

using namespace std;

// ����� �����
class Firm
{
public:
	// ������������ � ����������
	Firm()
	{
		builderLicense = false;
		name = "";
	}

	Firm(string fName, bool bLicense, bool eLicense, bool cLicense)
	{
		builderLicense = bLicense;
		name = fName;
		environmentalLicense = eLicense;
		cityLicense = cLicense;
	}

	virtual ~Firm()
	{
	}

private:
	// �������� �����
	string name;
	// ���� �� ������������ �������� � �����
	bool builderLicense;
	// ���� �� ������������� ����������
	bool environmentalLicense;
	// ���� �� ���������� �� ������
	bool cityLicense;

public:
	// ������� ��� ������ � ������
	string GetName() {
		return name;
	}
	void SetName(string fName) {
		name = fName;
	}
	// ������� ��� ������ �� ������������ ��������
	bool GetBuilderLicense() {
		return builderLicense;
	}
	void SetBuilderLicense(bool bLicense) {
		builderLicense = bLicense;
	}
	// ������� ��� ������ � ������������� �����������
	bool GetEnvironmentalLicense() {
		return environmentalLicense;
	}
	void SetEnvironmentalLicense(bool eLicense) {
		environmentalLicense = eLicense;
	}
	// ������� ��� ������ � ��������� �����������
	bool GetCityLicense() {
		return cityLicense;
	}
	void SetCityLicense(bool cLicense) {
		cityLicense = cLicense;
	}
};

// �����, ���������� �� �������� ������������� ����� �������������
class EnvironmentalService
{
public:
	EnvironmentalService() {}
	virtual ~EnvironmentalService() {}
	// ���� �� � ����� ���������� �� ������������� �� ������� ������������� ������
	bool HasEnvironmentalAccess(Firm* pFirm) {
		return pFirm->GetEnvironmentalLicense() ? true : false;
	}
};

// �����, ���������� �� �������� ���� �� ������������� �� ��������� �����
class CityService
{
public:
	CityService() {}
	virtual ~CityService() {}
	// ���� �� � ����� ���������� �� ������������� �� ������
	bool HasCityAccess(Firm* pFirm) {
		return pFirm->GetCityLicense() ? true : false;
	}
};

// �����, ���������� �� �������� ������� �������� �� ������������� � �����
class CountryService
{
public:
	CountryService() {}
	virtual ~CountryService() {};
	// ���� �� � ����� �������� �� ������������� �� ������� ������
	bool HasBuildingLicense(Firm* pFirm) {
		return pFirm->GetBuilderLicense() ? true : false;
	}
};


// ����� Facade. ������������ ����������� ��������
// �� ������� ���� �������� � ������� � �����-���������
class Construction
{
	EnvironmentalService eService;
	CityService cService;
	CountryService coService;

public:
	Construction() {}
	virtual ~Construction() {}
	bool IsAllowed(Firm* pFirm) {
		cout << "\nLet's check for all permissions!\n";
		if (cService.HasCityAccess(pFirm) && coService.HasBuildingLicense(pFirm) && eService.HasEnvironmentalAccess(pFirm)) {
			return true;
		}
		return false;
	}
};



int main() {

	// ������� ������ ������ Facade
	Construction constructor;

	// ������� ������ �����
	Firm myfirm("DreamBuilder", true, true, false);
	
	// ��������� ��� �� ���������� ���� � ����� �� �������������
	bool allowable = constructor.IsAllowed(&myfirm);

	cout << myfirm.GetName() << ((allowable) ? " will build\n\n" : " won't build\n\n");

	return 0;
}