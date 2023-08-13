#pragma once
#include<iostream>
#include"Vehicle.h"
using namespace std;

class LargeVehicles: public Vehicle
{
private:
	string type;
public:
	LargeVehicles();
	LargeVehicles();
	LargeVehicles();
	~LargeVehicles(){}
	friend ostream& operator<<(ostream&, LargeVehicles&);
	friend istream& operator>>(istream& in, LargeVehicles& obj)
	{
		cout << "Enter Car Type: ";
		in >> obj.type;
		in >> (Vehicle&)obj;
	}
	friend ifstream& operator>>(ifstream&, LargeVehicles&);
	friend ofstream& operator<<(ofstream&, LargeVehicles&);
	LargeVehicles& operator=(const LargeVehicles&);
};

inline LargeVehicles::LargeVehicles()
{
	type = '\0';
}

LargeVehicles& LargeVehicles::operator=(const LargeVehicles& obj)
{
	this->type = obj.type;
	return *this;
}

ostream& operator<<(ostream& out, LargeVehicles& obj)
{
	out << "Vehicle Type: " << obj.type << endl;
	return out;
}

inline ifstream& operator>>(ifstream& in, LargeVehicles& obj)
{
	in >> obj.type;
	return in;
}

inline ofstream& operator<<(ofstream& out, LargeVehicles& obj)
{
	Vehicle v = static_cast<Vehicle&> (obj);
	out << v << endl;
	out << obj.type << endl;
	return out;
}
