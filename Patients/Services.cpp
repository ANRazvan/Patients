#include "Services.h"

Services::~Services()
{
}

void Services::addDoctor(const string& name, const string& specialization)
{
	for (auto d: repo.getDoctors())
		if (d.getName() == name)
			throw std::exception("Doctor already exists");
	this->repo.addDoctor(Doctor(name, specialization));

}

void Services::addPatient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date)
{
	for (auto p : repo.getPatients())
		if (p.getName() == name)
			throw std::exception("Patient already exists");
	this->repo.addPatient(Patient(name, diagnosis, specialization, doctor, date));
}

void Services::removeDoctor(const string& name)
{
}

void Services::removePatient(const string& name)
{
}

void Services::updateDoctor(const string& name, const string& specialization)
{
}

void Services::updatePatient(const string& name, const string& diagnosis, const string& specialization, const string& doctor, const string& date)
{
	int i = 0;
	while(i < this->repo.getPatients().size() && this->repo.getPatients()[i].getName() != name)
		i++;
	Patient p = this->repo.getPatients()[i];

	this->repo.updatePatient(p,name, diagnosis, specialization, doctor, date);

}

vector<Doctor> Services::getDoctors()
{
	return this->repo.getDoctors();
}

vector<Patient> Services::getPatients()
{
	return this->repo.getPatients();
}

void Services::readFromFile()
{
	this->repo.readFromFile();
}

void Services::writeToFile()
{
	this->repo.writeToFile();
}
