#include <iostream>
#include <array>

class FIO {
private: std::array<std::string,4> fio;
public: enum Value_number_in_FIO_array{
	last_name = 0,
	first_name,
	patronynic,
	full_name
};

public: bool SetBool();
public: void SetFormat();

public: std::array<std::string, 4> GetInfo();

public: FIO() {};
public: ~FIO() {};
};
