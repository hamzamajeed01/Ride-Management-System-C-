#pragma once
#include<iostream>
#include"Vehicle.h"
using namespace std;

class SmallVehicles: public Vehicle
{
private:
	string type;
public:
	SmallVehicles();
	SmallVehicles();
	SmallVehicles(SmallVehicles&);
	friend ostream& operator<<(ostream&, SmallVehicles&);
	friend istream& operator>>(istream& in, SmallVehicles& obj)
	{
		cout << "Enter Car Type: ";
		in >> obj.type;
		in >> (Vehicle&)obj;
	}
	friend ifstream& operator>>(ifstream&, SmallVehicles&);
	friend ofstream& operator<<(ofstream&, SmallVehicles&);
	~SmallVehicles() {}
	SmallVehicles& operator=(const SmallVehicles&);
};

inline SmallVehicles::SmallVehicles()
{
	type = '\0';
}

SmallVehicles& SmallVehicles::operator=(const SmallVehicles& obj)
{
	this->type = obj.type;
	return *this;
}

ostream& operator<<(ostream& out, SmallVehicles& obj)
{
	out << "Vehicle Type: " << obj.type << endl;
	return out;
}

inline ifstream& operator>>(ifstream& in, SmallVehicles& obj)
{
	in >> obj.type;
	return in;
}

inline ofstream& operator<<(ofstream& out, SmallVehicles& obj)
{
	Vehicle v = static_cast<Vehicle&> (obj);
	out << v << endl;
	out << obj.type << endl;

	return out;
}
