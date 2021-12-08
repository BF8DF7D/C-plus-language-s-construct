#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>
#include <iomanip>

//Функция создания структуры "Талон"
bool SetBool(int*);
void Talon::SetTalon(Doctor* medic) {

	bool False_Input_Value;

	std::cout << " <Ввод информации о талоне>" << std::endl;
	this->Admission_Date.SetFormat();
	this->Admission_Time.SetFormat();

	do {
		std::cout << " Номер кабинета: ";
		False_Input_Value = SetBool(&this->kabinet);
		if (False_Input_Value) {
			std::cout << "\n <Номер кабинета введен некорректно>" << std::endl;
		}
	} while (False_Input_Value);

	this->medic = medic;

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
	return this->Admission_Date;
}

Time Talon::GetTime() {
	return this->Admission_Time;
}

int Talon::GetKabinet() {
	return this->kabinet;
}

Doctor Talon::GetDoctor() {
	return *this->medic;
}

void Talon::PrintInfo() {
	std::array <std::string, 4> name = this->GetDoctor().GetFIO().GetInfo();
	enum Value_number_im_info_array {
		full_name = 3
	};

	std::cout << " | "; 
	std::cout << std::setfill(' ') << std::setw(45) << name[full_name];
	std::cout << " | ";
	this->Admission_Date.PrintInfo();
	std::cout << " | ";
	this->Admission_Time.PrintInfo();
	std::cout << " | ";
	std::cout << std::setfill('0') << std::setw(3) << this->GetKabinet() << " |";
	std::cout.fill(' ');
}