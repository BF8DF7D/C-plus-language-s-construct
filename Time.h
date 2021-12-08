#include <iostream>
#include <array>

class Time {
private: std::array<int, 2> time;
public: enum Value_number_in_time_array {
	hour = 0,
	minutes
};

public: void SetFormat();
public: bool SetBool();
public: void PrintInfo();

public: std::array<int, 2> GetInfo();
	   
public: Time() {};
public: ~Time() {};
};