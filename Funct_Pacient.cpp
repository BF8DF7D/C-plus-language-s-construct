#define _CRT_SECURE_NO_WARNINGS
#include "Pacient.h"
#include <iostream>
#include <iomanip>


bool BoolFormatCard(int* number);

void Pacient::SetPacient() {

	std::cout << " <Ввод информации о пацинте>" << std::endl;
	
	this->Fio.SetFormat();
	this->Date_Brith.SetFormat();
	this->pasport.SetFormat();

	bool False_Input_Value;
	do {
		False_Input_Value = BoolFormatCard(&this->Medical_Card);
		if (False_Input_Value) {
			std::cout << "\n < Номер мед. карты введён некорректно>" << std::endl;
		}
	} while (False_Input_Value);

	enum Limit_Value {
		Maximum_quantity_values = 51
	};
	this->Diagnosis_History = new Diagnosis*[51];
	for (int dignosis_number = 0; dignosis_number < Maximum_quantity_values; dignosis_number++)
		this->Diagnosis_History[dignosis_number] = nullptr;

	this->Diagnosis_point = 0;
	
	std::cout << " <Ввод завершён>" << std::endl;
}

bool BoolFormatCard(int* number) {
	enum Limit_Value {
		Minimum_number = 0x1,
		Maximum_number = 0xFFFFFFF,
		Clean_input_stream = '\n'
	};
	bool False_Input_Value;

	std::cout << " Номер мед. карты: ";
	std::cin >> *number;
	False_Input_Value = (*number < Minimum_number || *number > Maximum_number)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

FIO Pacient::GetFIO() {
	return this->Fio;
}

Date Pacient::GetDate() {
	return this->Date_Brith;
}

Pasport Pacient::GetPasport() {
	return this->pasport;
}

int Pacient::GetCard() {
	return this->Medical_Card;
}

std::array<Diagnosis, 51> Pacient::GetHistory() {
	std::array<Diagnosis, 51> diagnosis_history;
	for (int dignosis_number = 0; true; dignosis_number++) {
		if (this->Diagnosis_History[dignosis_number]) 
			diagnosis_history[dignosis_number] = *this->Diagnosis_History[dignosis_number];
		else 
			break;
	}
	return diagnosis_history;
}

void Pacient::GiveDiagnosis(Diagnosis* diagnos) {
	enum Limit_Value {
		Maximum_value_for_array = 51
	};
	if (this->Diagnosis_point < Maximum_value_for_array) {
		this->Diagnosis_History[this->Diagnosis_point] = diagnos;
		this->Diagnosis_point++;
	}
}

void Pacient::PrintInfo() {
	std::array<std::string, 4> name = this->GetFIO().GetInfo();
	std::cout << " <Персональные данные>" << std::endl;
	std::cout << " ФИО пациента            : " << name[FIO::full_name] << std::endl;
	std::cout << " Серия и номер паспорта  : ";
	this->GetPasport().PrintInfo();
	std::cout << std::endl;
	std::cout << " Дата рождения           : ";
	this->GetDate().PrintInfo();
	std::cout << std::endl;
	std::cout << " Номер медецинской карты : ";
	std::cout << std::uppercase << std::hex << this->GetCard() << std::endl;
	std::cout << " <Краткая история болезни>" << std::endl;
	std::cout << std::dec;
	if (this->Diagnosis_point> 0) {
		std::cout << " Общее число зарегистрированных заболеваний: " << this->Diagnosis_point << std::endl;
		std::cout << "    Наименование болезни :       Дата : Время :" << std::endl;
		std::array<Diagnosis, 51> diagnosis_history = this->GetHistory();
		for (Diagnosis diagnosis : diagnosis_history) {
			if (!diagnosis.Empty()) {
				std::cout << " ";
				std::cout << std::setw(23) << diagnosis.GetDisease().GetName();
				std::cout << " : ";
				diagnosis.GetTalon().GetDate().PrintInfo();
				std::cout << " : ";
				diagnosis.GetTalon().GetTime().PrintInfo();
				std::cout << " :" << std::endl;
			}
			else
				break;
		}
	}
	else
		std::cout << " Нет заригестрированных заболеваний " << std::endl;
}

bool Pacient::DiseaseOf(std::string Name_Disease) {
	std::array<Diagnosis, 51> diagnosis_history = this->GetHistory();
	bool Serched_disease_is_present = false;
	for (Diagnosis diagnosis : diagnosis_history) {
		if (diagnosis.Empty())
			break;
		if (diagnosis.GetDisease().GetName() == Name_Disease) {
			Serched_disease_is_present = true;
			break;
		}
	}

	return Serched_disease_is_present;
}

void Pacient::DeleteDiagnosis(int number_diagnosis) {
	if (number_diagnosis < this->Diagnosis_point) {
		delete this->Diagnosis_History[number_diagnosis];
		for (; number_diagnosis < this->Diagnosis_point - 1; number_diagnosis++)
			this->Diagnosis_History[number_diagnosis] = this->Diagnosis_History[number_diagnosis + 1];
		this->Diagnosis_History[number_diagnosis] = nullptr;
		this->Diagnosis_point--;
	}
}

void Pacient::DeleteAll() {
	delete[] this->Diagnosis_History;

	enum Limit_Value {
		Maximum_quantity_values = 51
	};
	this->Diagnosis_History = new Diagnosis * [51];
	for (int dignosis_number = 0; dignosis_number < Maximum_quantity_values; dignosis_number++)
		this->Diagnosis_History[dignosis_number] = nullptr;

	this->Diagnosis_point = 0;
}