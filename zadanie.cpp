#define _CRT_SECURE_NO_WARNINGS
#include "Pacient.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

int main()
{
    Disease* prosrtuda = new Disease, 
        *otravlenie = new Disease;

    prosrtuda->SetDisease();
    std::cout << std::endl;
    otravlenie->SetDisease();
    std::cout << std::endl;
    prosrtuda->PrintInfo();

    std::cout << std::endl << std::endl;

    Doctor* doctor = new Doctor;
    doctor->SetDoctor();
    std::cout << std::endl;
    doctor->PrintInfo();

    std::cout << std::endl << std::endl;

    Talon* talon = new Talon;
    talon->SetTalon(doctor);
    std::cout << std::endl;
    talon->PrintInfo();

    std::cout << std::endl << std::endl;

    Diagnosis *one = new Diagnosis, 
        *two = new Diagnosis;
    one->SetDiadnosis(talon, prosrtuda);
    two->SetDiadnosis(talon, otravlenie);
    two->PrintInfo();

    std::cout << std::endl << std::endl;

    Pacient* bolnoi = new Pacient;
    bolnoi->SetPacient();
    std::cout << std::endl;

    bolnoi->GiveDiagnosis(one);
    bolnoi->GiveDiagnosis(two);

    bolnoi->PrintInfo();

    std::cout << std::endl;
    bolnoi->DeleteDiagnosis(0);
    bolnoi->PrintInfo();

    std::string Name_Disease;
    std::cout << " Введите наименования болезни, чтобы узнать есть ли оно в истории болезни пациента" << std::endl;
    for (bool Exid_Value = false; !Exid_Value;) {
        std::cout << " Наименование : ";
        std::getline(std::cin, Name_Disease);
        if (Name_Disease.empty())
            Exid_Value = true;
        else {
            if (bolnoi->DiseaseOf(Name_Disease))
                std::cout << " В истории болезни пациента есть \"" << Name_Disease << "\"" << std::endl;
            else
                std::cout << " В истории блезни пациента не числится \"" << Name_Disease << "\"" << std::endl;
        }
    }

    bolnoi->DeleteAll();
    bolnoi->PrintInfo();

    _getch();
}