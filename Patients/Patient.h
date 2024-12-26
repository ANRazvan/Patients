#pragma once
#include <string>
#include <iostream>
using namespace std;

class Patient
{
private:
	string name;
	string diagnosis;
	string specialization;
	string doctor;
	string date; // DD.MM.YYYY
public:
	Patient();
	Patient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date);
	~Patient();
	const string& getName();
	const string& getDiagnosis();
	const string& getSpecialization();
	const string& getDoctor();
	const string& getDate();
	void setName(const string& name);
	void setDiagnosis(const string& diagonsis);
	void setSpecialization(const string& specialization);
	void setDoctor(const string& doctor);
	void setDate(const string& date);
	void print();

	friend istream& operator>>(istream& is, Patient& patient);
};

