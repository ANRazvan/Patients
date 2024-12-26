#include "Repository.h"

Repository::Repository() {
	this->readFromFile();
}
Repository::~Repository()
{
}
void Repository::addDoctor(Doctor doctor)
{
	doctors.push_back(doctor);
}

void Repository::addPatient(Patient patient)
{
	patients.push_back(patient);
	this->notify();
	this->writeToFile();
}

void Repository::removeDoctor(Doctor doctor)
{
	int i = 0;
	while (doctors[i].getName() != doctor.getName())
		i++;
	doctors.erase(doctors.begin() + i);
	this->writeToFile();

}

void Repository::removePatient(Patient patient)
{
	int i = 0;
	while (patients[i].getName() != patient.getName())
		i++;
	patients.erase(patients.begin() + i);
	this->notify();
	this->writeToFile();

}

void Repository::updateDoctor(Doctor doctor, string name, string specialization)
{
	int i = 0;
	while(doctors[i].getName() != doctor.getName())
		i++;
	doctors[i].setName(name);
	doctors[i].setSpecialization(specialization);
	this->notify();
	this->writeToFile();

}

void Repository::updatePatient(Patient patient, string name, string diagnosis, string specialization, string doctor, string date)
{
	int i = 0;
	while (patients[i].getName() != patient.getName())
		i++;
	patients[i].setName(name);
	patients[i].setDiagnosis(diagnosis);
	patients[i].setSpecialization(specialization);
	patients[i].setDoctor(doctor);
	patients[i].setDate(date);
	this->notify();
	this->writeToFile();

}

void Repository::readFromFile()
{
	ifstream file("doctors.txt");
	Doctor d;
	while (file >> d)
	{
		doctors.push_back(d);
	}
	file.close();
	file.open("patients.txt");
	Patient patient;
	while (file >> patient)
	{
		patients.push_back(patient);
	}
	file.close();
}

void Repository::writeToFile()
{
	ofstream file("doctors.txt");
	for (auto doctor : doctors)
		file << doctor.getName() << "," << doctor.getSpecialization() << endl;
	file.close();
	file.open("patients.txt");
	for (auto patient : patients)
		file << patient.getName() << "," << patient.getDiagnosis() << "," << patient.getSpecialization() << "," << patient.getDoctor() << "," << patient.getDate() << endl;
	file.close();
}

vector<Doctor> Repository::getDoctors()
{
	return doctors;
}

vector<Patient> Repository::getPatients()
{
	return patients;
}


