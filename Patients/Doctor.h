#pragma once
#include <string>
#include <iostream>
using namespace std;


class Doctor
{
private:
	string name;
	string specialization;
public:
	Doctor();
	Doctor(const string& name, const string& specialization);
	~Doctor();
	const string& getName();
	const string& getSpecialization();
	void setName(const string& name);
	void setSpecialization(const string& specialization);
	void print();

	friend istream& operator>>(istream& is, Doctor& doctor);
};

