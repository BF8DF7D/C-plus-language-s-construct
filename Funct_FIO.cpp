#define _CRT_SECURE_NO_WARNINGS
#include "FIO.h"
#include <string>
#include <sstream>
#include <iomanip>

void FIO::SetFormat() {
	bool False_Input_Value;
	do {
		std::cout << " ФИО: ";
		False_Input_Value = SetBool();
		if (False_Input_Value) {
			std::cout << "\n <ФИО введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool FIO::SetBool() {
	std::getline(std::cin, fio[full_name]);
	std::stringstream Name_elements_stream(fio[full_name]);
	Name_elements_stream >> fio[last_name] >> fio[first_name] >> fio[patronynic];
	bool False_Input_Value = fio[patronynic].empty() || !Name_elements_stream.eof();
	
	if (False_Input_Value) 
		fio.fill("\0");
	return False_Input_Value;
}

std::array<std::string, 4> FIO::GetInfo() {
	return fio;
}