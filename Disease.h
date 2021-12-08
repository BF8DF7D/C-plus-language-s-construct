#include <iostream>
#include <vector>

class Disease{
private: std::string Name_Disease;
private: std::vector<std::string> Disease_Symptoms;

public: void SetDisease();
public: void PrintInfo();

public: std::string GetName();
public: std::vector<std::string> GetSymptoms();

public: Disease() {};
public: ~Disease() {};
};