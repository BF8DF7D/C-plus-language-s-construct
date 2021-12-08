#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <iomanip>
#include <string>

void Doctor::SetDoctor() {

	printf(" <Ввод информации о докторе>\n");
	this->Fio.SetFormat();

	std::cout << " Должность: ";
	std::getline(std::cin, this->dolgnost);
	
	std::cout << " <Ввод завершён>" << std::endl;
}

FIO Doctor::GetFIO() {
	return this->Fio;
}

std::string Doctor::GetDolgnost() {
	return this->dolgnost;
}

void Doctor::PrintInfo() {
	std::array<std::string, 4> fio = this->GetFIO().GetInfo();
	std::cout << " | ";
	std::cout << std::setfill(' ') << std::setw(45) << fio[FIO::full_name];
	std::cout << " | ";
	std::cout << std::setw(20) << this->GetDolgnost() << " |" << std::endl;
}