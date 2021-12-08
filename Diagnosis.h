#include "Talon.h"
#include "Disease.h"

class Diagnosis {
private: Talon* talon;		
private: Disease* disease;

public: void SetDiadnosis(Talon*, Disease*);
public: void PrintInfo();
public: bool Empty();

public: Talon GetTalon();
public: Disease GetDisease();
public: Disease* GetAddressDisease();
public: Disease& GetLinkDisease();

public: Diagnosis();
public: ~Diagnosis() {};
};