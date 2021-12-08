#include "FIO.h"

class Talon;

class Doctor {

private: FIO Fio;
private: std::string dolgnost;

public: void SetDoctor();
public: void PrintInfo();

public: Talon* CreateTalon();
public: void ChangeTime(Talon*);

public: FIO GetFIO();
public: std::string GetDolgnost();

public: Doctor() {};
public: ~Doctor() {};
};