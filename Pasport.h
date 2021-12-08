#include <iostream>
#include <array>

class Pasport {
private: std::array<int, 2> pasport;
public: enum Value_number_in_pasport_array {
		   series = 0,
		   number,
};
public: void SetFormat();
public: bool SetBool();
public: void PrintInfo();

public: std::array<int, 2> GetInfo();

public:	Pasport() {};
public:	~Pasport() {};
};