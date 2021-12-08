#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iomanip>
#include <sstream>

void Date::SetFormat() {
	bool False_Input_Value;
	do {
		std::cout << " Дата: ";
		False_Input_Value = this->SetBool();
		if (False_Input_Value) {
			std::cout << "\n <Дата введена некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool Date::SetBool(){
	enum Limit_Value {
		Quantity_input_value = 3,
		Minimum_for_days_and_months = 0,
		Minimum_value_for_years = 999,
		Maximum_day = 31,
		Maximum_mounth = 12,
		Maximum_years = 9999,
		Clean_input_stream = '\n'
	};

	bool False_Input_Value = scanf("%d.%d.%d", &this->date[day], &this->date[mounth], &this->date[year]) != Quantity_input_value
		|| (this->date[day] <= Minimum_for_days_and_months || this->date[day] > Maximum_day)
		|| (this->date[mounth] <= Minimum_for_days_and_months || this->date[mounth] > Maximum_mounth)
		|| (this->date[year] <= Minimum_value_for_years || this->date[year] > Maximum_years)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

std::array<int, 3> Date::GetInfo() {
	return this->date;
}

void Date::PrintInfo() {
	std::array<int,3> date = this->GetInfo();

	std::cout << std::setfill('0') << std::setw(2) << date[day] << ".";
	std::cout << std::setfill('0') << std::setw(2) << date[mounth] << ".";
	std::cout << std::setw(4) << date[year];
	std::cout.fill(' ');
}
