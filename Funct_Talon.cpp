#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>
#include <iomanip>
#include <sstream>

//Функция создания структуры "Талон"
bool SetBool(int* kabinet) {
	enum Limit_Value_for_Number {
		Quantity_input_value = 1,
		Minimum_value_for_number = 0,
		Maximum_number = 999,
		Clean_input_stream = '\n'
	};
	bool False_Input_Value = scanf("%d", kabinet) != Quantity_input_value
		|| (*kabinet <= Minimum_value_for_number || *kabinet > Maximum_number)
		|| std::cin.get() != Clean_input_stream;

	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

void Talon::SetTalon(Doctor* medic) {

	bool False_Input_Value;

	std::cout << " <Ввод информации о талоне>" << std::endl;
	Admission_Date.SetFormat();
	Admission_Time.SetFormat();

	do {
		std::cout << " Номер кабинета: ";
		False_Input_Value = SetBool(&kabinet);
		if (False_Input_Value) {
			std::cout << "\n <Номер кабинета введен некорректно>" << std::endl;
		}
	} while (False_Input_Value);

	this->medic = medic;

	std::cout << " <Ввод завершён>" << std::endl;
}

void Talon::PrintInfo() {
	std::array <std::string, 4> name = GetDoctor().GetFIO().GetInfo();
	std::cout << " | "; 
	std::cout << std::setfill(' ') << std::setw(45) << name[FIO::full_name];
	std::cout << " | ";
	Admission_Date.PrintInfo();
	std::cout << " | ";
	Admission_Time.PrintInfo();
	std::cout << " | ";
	std::cout << std::setfill('0') << std::setw(3) << GetKabinet() << " |";
	std::cout.fill(' ');
	std::cout << std::endl;
}

Talon* Doctor::CreateTalon() {
	Talon* AdmissionDay = new Talon;
	AdmissionDay->SetTalon(this);
	return AdmissionDay;
}

void Doctor::ChangeTime(Talon* talon) {
	talon->Admission_Date.SetFormat();
}

void operator+(Talon* talon, std::string time) {
	for (int dot_position = 0; dot_position != -1;) {
		dot_position = time.find('.');
		if (dot_position != -1)
			time.replace(dot_position, 1, " ");
	}
	std::stringstream stream(time);
	int minutes = 0,
		hours = 0;
	stream >> hours >> minutes;
	
	std::array<int, 2> newtime = talon->Admission_Time.GetInfo();
	std::array<int, 3> newdate = talon->Admission_Date.GetInfo();
	
	enum Limit_Value {
		Quantity_minutes_for_hour = 60,
		Quantity_hours_for_days = 24,
		Quantity_days_for_mounths = 31,
		Quantity_mounth_for_year = 12,
	};

	newtime[Time::minutes] += minutes;
	newtime[Time::hour] += newtime[Time::minutes] / Quantity_minutes_for_hour + hours;
	newtime[Time::minutes] %= Quantity_minutes_for_hour;

	newdate[Date::day] += newtime[Time::hour] / Quantity_hours_for_days;
	newtime[Time::hour] %= Quantity_hours_for_days;
	newdate[Date::mounth] += newdate[Date::day] / Quantity_days_for_mounths;
	newdate[Date::mounth] %= Quantity_days_for_mounths;
	newdate[Date::year] += newdate[Date::mounth] / Quantity_mounth_for_year;

	talon->Admission_Time.ConstrTime(newtime);
	talon->Admission_Date.ConstrDate(newdate);
}

Talon operator++(Talon& talon) {
	talon.kabinet += 1;
	return talon;
}

Talon operator++(Talon& talon, int) {
	Talon OldValue = talon;
	talon.kabinet += 1;
	return OldValue;
}

Date Talon::GetDate() {
	return Admission_Date;
}

Time Talon::GetTime() {
	return Admission_Time;
}

int Talon::GetKabinet() {
	return kabinet;
}

Doctor Talon::GetDoctor() {
	return *medic;
}
