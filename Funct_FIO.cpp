#define _CRT_SECURE_NO_WARNINGS
#include "FIO.h"
#include <string>
#include <sstream>
#include <iomanip>

void FIO::SetFormat() {
	bool False_Input_Value;
	do {
		std::cout << " ФИО: ";
		False_Input_Value = this->SetBool();
		if (False_Input_Value) {
			std::cout << "\n <ФИО введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool FIO::SetBool() {
	std::getline(std::cin, this->fio[full_name]);
	std::cin.clear();
	std::stringstream Name_elements_stream(this->fio[full_name]);
	Name_elements_stream >> this->fio[last_name] >> this->fio[first_name] >> this->fio[patronynic];
	bool False_Input_Value = this->fio[patronynic].empty() || !Name_elements_stream.eof();

	return False_Input_Value;
}

std::array<std::string, 4> FIO::GetInfo() {
	return this->fio;
}