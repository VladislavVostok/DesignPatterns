#include<iostream>
#include"AircraftBuilder.h"
#include"AircraftConstructor.h"
#include"HangGliderBuilder.h"
#include"GliderBuilder.h"

using namespace std;

int main() {
	try {
		AircraftBuilder* builder;

		// —оздаем объект класса директора
		AircraftConstructor* shop = new AircraftConstructor();

		// —оздаем объект класса строител¤. Ётот объект умеет создавать дельтапланы
		builder = new HangGliderBuilder();

		// сооружаем дельтаплан
		shop->Construct(builder);

		// показываем информацию о дельтаплане
		builder->GetAircraft()->Show();

		// —оздаем объект класса строител¤. Ётот объект умеет создавать планеры
		delete builder;

		builder = new GliderBuilder();

		// сооружаем планер
		shop->Construct(builder);

		// показываем информацию о планере
		builder->GetAircraft()->Show();

		delete builder;
		delete shop;
	}
	catch (char* str) {
		cout << endl << str << endl;
	}


	return 0;
}