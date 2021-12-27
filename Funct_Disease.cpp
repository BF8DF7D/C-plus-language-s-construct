#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <conio.h>
#include <string>
#include <iomanip>

//�������� ��������� "�����������"
void Disease::SetDisease() {

	std::cout << " <���� ���������� � �����������>" << std::endl;
	std::cout << " ������������: ";
	std::getline(std::cin, Name_Disease);
	std::cin.clear();
	
	std::cout << " ��������.\n ������� ������ ����� ������� � ����� ������.\n ��� ����������� �������� ������� Enter" << std::endl;
	std::string symptom;
	do {
		std::cout << " : ";
		std::getline(std::cin, symptom);
		if (!symptom.empty())
			Disease_Symptoms.push_back(symptom);
	} while (!symptom.empty());
}

std::string Disease::GetName() {
	return Name_Disease;
}

std::vector<std::string> Disease::GetSymptoms() {
	return Disease_Symptoms;
}

//������ ��������� "�����������"
void Disease::PrintInfo() {
	std::cout << " ������������: " << GetName() << std::endl;
	std::cout << " ��������: " << std::endl;
	
	int Input_value_number = 0;
	std::string Empty_value_of_symptom = "";
	std::vector<std::string> Disease_Symptoms = GetSymptoms();
	for (std::string symptom : Disease_Symptoms) {
		if (symptom == Empty_value_of_symptom)
			break;
		std::cout << " [" << std::setfill('0') << std::setw(2) << ++Input_value_number << "] ";
		std::cout << symptom << std::endl;
	}
	std::cout.fill(' ');
}