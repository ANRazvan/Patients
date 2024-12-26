#pragma once
#include "Doctor.h"
#include "Patient.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "Observer.h"
class Repository: public Subject
{
private:
	vector <Doctor> doctors;
	vector <Patient> patients;
public:
	Repository();
	~Repository();
	void addDoctor(Doctor doctor);
	void addPatient(Patient patient);
	void removeDoctor(Doctor doctor);
	void removePatient(Patient patient);
	void updateDoctor(Doctor doctor, string name, string specialization);
	void updatePatient(Patient patient, string name, string diagnosis, string specialization, string doctor, string date);
	vector <Doctor> getDoctors();
	vector <Patient> getPatients();
	void readFromFile();
	void writeToFile();
};

