#pragma once
#include "Repository.h"
class Services
{
private:
	Repository& repo;
public:
	Services(Repository& repo) : repo{ repo } {}
	~Services();
	void addDoctor(const string& name, const string& specialization);
	void addPatient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date);
	void removeDoctor(const string& name);
	void removePatient(const string& name);
	void updateDoctor(const string& name, const string& specialization);
	void updatePatient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date);
	vector<Doctor> getDoctors();
	vector<Patient> getPatients();
	void readFromFile();
	void writeToFile();
};

