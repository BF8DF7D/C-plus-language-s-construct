#include <iostream>
#include <array>

class Date {
private: std::array<int, 3> date;
public: enum Value_number_in_Date_array {
	day = 0,
	mounth,
	year
};

public: bool SetBool();
public: void SetFormat();
public: void PrintInfo();

public: std::array<int, 3> GetInfo();

public: Date() {};
public: ~Date() {};
};