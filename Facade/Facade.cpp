#include<iostream>
#include "Construction.h"

using namespace std;

// Класс фирмы
class Firm
{
public:
	// конструктора и деструктор
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
	// название фирмы
	string name;
	// есть ли строительная лицензия у фирмы
	bool builderLicense;
	// есть ли экологическое разрешение
	bool environmentalLicense;
	// есть ли разрешение от города
	bool cityLicense;

public:
	// функции для работы с именем
	string GetName() {
		return name;
	}
	void SetName(string fName) {
		name = fName;
	}
	// функции для работы со строительной лицензии
	bool GetBuilderLicense() {
		return builderLicense;
	}
	void SetBuilderLicense(bool bLicense) {
		builderLicense = bLicense;
	}
	// функции для работы с экологическим разрешением
	bool GetEnvironmentalLicense() {
		return environmentalLicense;
	}
	void SetEnvironmentalLicense(bool eLicense) {
		environmentalLicense = eLicense;
	}
	// функции для работы с городским разрешением
	bool GetCityLicense() {
		return cityLicense;
	}
	void SetCityLicense(bool cLicense) {
		cityLicense = cLicense;
	}
};

// класс, отвечающий за проверку экологической части строительства
class EnvironmentalService
{
public:
	EnvironmentalService() {}
	virtual ~EnvironmentalService() {}
	// есть ли у фирмы разрешение на строительство со стороны экологической службы
	bool HasEnvironmentalAccess(Firm* pFirm) {
		return pFirm->GetEnvironmentalLicense() ? true : false;
	}
};

// класс, отвечающий за проверку прав на строительство от городских служб
class CityService
{
public:
	CityService() {}
	virtual ~CityService() {}
	// есть ли у фирмы разрешение на строительство со города
	bool HasCityAccess(Firm* pFirm) {
		return pFirm->GetCityLicense() ? true : false;
	}
};

// класс, отвечающий за проверку наличия лицензии на строительство у фирмы
class CountryService
{
public:
	CountryService() {}
	virtual ~CountryService() {};
	// есть ли у фирмы лицензия на строительство со стороны страны
	bool HasBuildingLicense(Firm* pFirm) {
		return pFirm->GetBuilderLicense() ? true : false;
	}
};


// Класс Facade. Осуществляет комплексную проверку
// на наличие всех лицензий и доступа у фирмы-строителя
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

	// Создаем объект фасада Facade
	Construction constructor;

	// Создаем объект фирмы
	Firm myfirm("DreamBuilder", true, true, false);
	
	// Проверяем все ли разрешения есть у фирмы на строительство
	bool allowable = constructor.IsAllowed(&myfirm);

	cout << myfirm.GetName() << ((allowable) ? " will build\n\n" : " won't build\n\n");

	return 0;
}