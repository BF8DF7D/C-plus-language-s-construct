#include "Doctor.h"
#include "Time.h"
#include "Date.h"

class Talon{
private: Date Admission_Date;
private: Time Admission_Time;
private: int kabinet;
private: Doctor* medic;

public: void SetTalon(Doctor*);
public: void PrintInfo();

public: Date GetDate();
public: Time GetTime();
public: int GetKabinet();
public: Doctor GetDoctor();

public: Talon() {};
public: ~Talon() {};
};
