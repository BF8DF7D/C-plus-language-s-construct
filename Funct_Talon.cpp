#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>
#include <iomanip>

//Функция создания структуры "Талон"
bool SetBool(int*);
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

	medic = medic;

	std::cout << " <Ввод завершён>" << std::endl;
}

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
}