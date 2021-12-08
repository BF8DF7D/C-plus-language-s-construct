#include "Diagnosis.h"
#include <iostream>
#include <iomanip>


Diagnosis::Diagnosis() {
	this->talon = nullptr;
	this->disease = nullptr;
}

bool Diagnosis::Empty() {
	bool Empty_Diagnosis = true;
	if (this->talon || this->disease)
		Empty_Diagnosis = false;
	return Empty_Diagnosis;
}

void Diagnosis::SetDiadnosis(Talon* talon, Disease* disease) {
	this->talon = talon;
	this->disease = disease;
}

Talon Diagnosis::GetTalon() {
	return *this->talon;
}

Disease Diagnosis::GetDisease() {
	return *this->disease;
}

void Diagnosis::PrintInfo() {
	Date date = this->talon->GetDate();
	Time time = this->talon->GetTime();
	std::array <std::string, 4> name = this->GetTalon().GetDoctor().GetFIO().GetInfo();

	std::cout << " Доктор: " << name[FIO::full_name] << std::endl;
	std::cout << " Дата приёма: ";
	date.PrintInfo();
	std::cout << std::endl;
	std::cout << " Время приёма: ";
	time.PrintInfo();
	std::cout << std::endl;
	std::cout << " Номер кабинета: ";
	std::cout << std::setfill('0') << std::setw(3) << this->GetTalon().GetKabinet() << std::endl;
	std::cout.fill(' ');
	this->GetDisease().PrintInfo();
}