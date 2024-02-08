#pragma once
#include "Device.h"

/*
 * ���������� ������� ���������� ����� Car
 */
class Car : public Device {
private:
	// �������� ������
	string manufacturer;
	string description;
	string color;

	int year;

public:
	// ������������
	Car():Car("No information","No description","No color",0){
		SetName("Car");
	}
	Car(string cmanufacturer, string cdescription, string ccolor, int cyear); 
public:
	// ��������������� �������
	int GetYear()const{
		return year;
	}
	string GetManufacturer()const{
		return manufacturer;
	}
	string GetDescription()const{
		return description;
	}
	string GetColor()const{
		return manufacturer;
	}

	void SetYear(int cyear){
		year = cyear;
	}
	void SetManufacturer(string cmanufacturer) {
		manufacturer = cmanufacturer;
	}
	void SetColor(string ccolor) {
		color = ccolor;
	}
	void SetDescription(string cdescription) {
		description = cdescription;
	}

	// ���������� ����������� ������� � �������
	Device* Clone()const;
	void Show() const;
};

// ���������� ������������
Car::Car(string cmanufacturer, string cdescription, string ccolor, int cyear) {
	SetName("Car");

	SetManufacturer(cmanufacturer);
	SetDescription(cdescription);
	SetColor(ccolor);
	SetYear(cyear);
}

// ������� ������������
Device* Car::Clone() const{
	Car* tempCar = new Car();

	/* �������� ��������!
	 * ��� ��� ������ � ������������ ������� ����� ����������
	 * ����������� �����������, ����������� ��������
	 * � ����������� �������� = 
	 */	

	*tempCar = *this;
	return tempCar;
}

// ����������� �� ����� ������
void Car::Show() const{
	Device::Show();
	cout << "\nDescription of car is\n" << GetDescription() << "\n";
	cout << "\nManufacturer of car is\n" << GetManufacturer() << "\n";
	cout << "\nYear of car is\n" << GetYear() << "\n";
	cout << "\nColor of car is\n" << GetColor() << "\n";
}

