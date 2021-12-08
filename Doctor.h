#include "FIO.h"

class Doctor {
private: FIO Fio;
private: std::string dolgnost;

public: void SetDoctor();
public: void PrintInfo();

public: FIO GetFIO();
public: std::string GetDolgnost();

public: Doctor() {};
public: ~Doctor() {};
};