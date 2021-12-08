#include "Diagnosis.h"
#include "Pasport.h"

struct Pacient {
private: FIO Fio;
private: Date Date_Brith;
private: Pasport pasport;
private: int Medical_Card;

private: Diagnosis** Diagnosis_History;
private: int Diagnosis_point = 0;

public: void SetPacient();
public: void PrintInfo();
public: void GiveDiagnosis(Diagnosis*);
public: bool DiseaseOf(std::string);
public: void DeleteDiagnosis(int);
public: void DeleteAll();

public: FIO GetFIO();
public: Date GetDate();
public: Pasport GetPasport();
public: int GetCard();
public: std::array<Diagnosis, 51> GetHistory();

public: Pacient() {};
public: ~Pacient() {};
};