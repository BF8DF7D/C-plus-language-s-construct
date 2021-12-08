#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include <iomanip>

void Time::SetFormat() {
	bool False_Input_Value;
	do {
		std::cout << " Время: ";
		False_Input_Value = SetBool();
		if (False_Input_Value) {
			std::cout << "\n <Время введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool Time::SetBool() {
	
	enum Limit_Value {
		Quantity_input_value = 2,
		Minimum_value_for_all = 0,
		Maximum_hour = 23,
		Maximum_minutes = 59,
		Clean_input_stream = '\n'
	};
	
	bool False_Input_Value = scanf("%d.%d", &time[hour], &time[minutes]) != Quantity_input_value
		|| (time[hour] < Minimum_value_for_all || time[hour] > Maximum_hour)
		|| (time[minutes] < Minimum_value_for_all || time[minutes] > Maximum_minutes)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

void Time::PrintInfo() {
	std::array<int, 2> time = GetInfo();

	std::cout << std::setfill('0') << std::setw(2) << time[hour] << ".";
	std::cout << std::setfill('0') << std::setw(2) << time[minutes];
	std::cout.fill(' ');
}

std::array<int, 2> Time::GetInfo() {
	return time;
}

void Time::ConstrTime(std::array<int, 2> newtime) {
	time = newtime;
}