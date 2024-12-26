#include "Doctor.h"
#include <sstream>
#include <vector>

Doctor::Doctor()
{
}

Doctor::Doctor(const string& name, const string& specialization)
{
	this->name = name;
	this->specialization = specialization;
}

Doctor::~Doctor()
{
}

const string& Doctor::getName()
{
	return name;
}

const string& Doctor::getSpecialization()
{
	return specialization;
}

void Doctor::setName(const string& name)
{
	this->name = name;
}

void Doctor::setSpecialization(const string& specialization)
{
	this->specialization = specialization;
}

void Doctor::print()
{
	cout << name << "," << specialization << endl;
}

istream& operator>>(istream& is, Doctor& doctor)
{
	//istream& operator>>(istream & is, Person & p) {
	//	string line;
	//	getline(is, line);

	//	vector<string> tokens;
	//	stringstream ss(line);

	//	string token;

	//	while (getline(ss, token, ','))
	//		tokens.push_back(token);

	//	if (tokens.size() != 4)
	//		return is;

	//	p.name = tokens[0];
	//	p.location.latitude = stoi(tokens[1]);
	//	p.location.longitude = stoi(tokens[2]);
	//	p.status = stoi(tokens[3]);

	//	return is;
	//}

	string line;
	getline(is, line);

	vector<string> tokens;
	stringstream ss(line);

	string token;

	while (getline(ss, token, ','))
		tokens.push_back(token);

	if (tokens.size() != 2)
		return is;

	doctor.name = tokens[0];
	doctor.specialization = tokens[1];
	
	return is;
	
}
