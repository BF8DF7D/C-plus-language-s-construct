#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <iomanip>
#include <string>

void Doctor::SetDoctor() {

	printf(" <���� ���������� � �������>\n");
	this->Fio.SetFormat();

	std::cout << " ���������: ";
	std::getline(std::cin, dolgnost);
	
	std::cout << " <���� ��������>" << std::endl;
}

FIO Doctor::GetFIO() {
	return Fio;
}

std::string Doctor::GetDolgnost() {
	return dolgnost;
}

void Doctor::PrintInfo() {
	std::array<std::string, 4> fio = GetFIO().GetInfo();
	std::cout << " | ";
	std::cout << std::setfill(' ') << std::setw(45) << fio[FIO::full_name];
	std::cout << " | ";
	std::cout << std::setw(20) << GetDolgnost() << " |" << std::endl;
}