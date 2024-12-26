#include "Patient.h"
#include <sstream>
#include <vector>

Patient::Patient()
{
	this->name = "";
	this->diagnosis = "";
	this->specialization = "";
	this->doctor = "";
	this->date = "";
}

Patient::Patient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date)
{
	this->name = name;
	this->diagnosis = diagnosis;
	this->specialization = specialization;
	this->doctor = doctor;
	this->date = date;
}

Patient::~Patient()
{
}

const string& Patient::getName()
{
	return name;
}

const string& Patient::getDiagnosis()
{
	return diagnosis;
}

const string& Patient::getSpecialization()
{
	return specialization;
}

const string& Patient::getDoctor()
{
	return doctor;
}

const string& Patient::getDate()
{
	return date;
}

void Patient::setName(const string& name)
{
	this->name = name;
}

void Patient::setDiagnosis(const string& diagnosis)
{
	this->diagnosis = diagnosis;
}

void Patient::setSpecialization(const string& specialization)
{
	this->specialization = specialization;
}

void Patient::setDoctor(const string& doctor)
{
	this->doctor = doctor;
}

void Patient::setDate(const string& date)
{
	this->date = date;
}

void Patient::print()
{
	cout << name << "," << diagnosis << "," << specialization << "," << doctor << "," << date << endl;
}

istream& operator>>(istream& is, Patient& patient)
{
	string line;
	getline(is, line);

	vector<string> tokens;
	stringstream ss(line);

	string token;

	while (getline(ss, token, ','))
		tokens.push_back(token);

	if (tokens.size() != 5)
		return is;

	patient.name = tokens.at(0);
	patient.diagnosis = tokens.at(1);
	patient.specialization = tokens.at(2);
	patient.doctor = tokens.at(3);
	patient.date = tokens.at(4);

	return is;
}
