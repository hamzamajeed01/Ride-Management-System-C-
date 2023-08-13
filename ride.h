#pragma once
#include<iostream>
#include"service.h"
using namespace std;

class Ride : public Service 
{
private:
	int noofPassengers; 
	char * rideType; // intercity, intracity 
	float DriverRanking; // 0 to 5 scale (worst to best) 
	float VehicleRanking; // 0 to 5 scale (worst to best)
//you can add more members here if required //add member functions
public:
	Ride();
	Ride(int, char*, float, float);
	Ride(const Ride&);
	~Ride();
	float getVRanking();
	float getDRanking();
	int getNo_ofPassengers();
	char* getType();
	void setNo_ofPassengers(int);
	void setType(char*);
	void setDRanking(float);
	void setVRanking(float);

	virtual void userInput(istream& in) {
		Service::userInput(in);
		cout << "Enter number of passengers: ";
		in >> noofPassengers;

		int choice;
		cout << "Enter 1 to travel intercity and 2 for intracity: ";
		in >> choice;
		rideType = new char[10];
		switch (choice) {
		case 1:	 strcpy(rideType, "intercity");	break;
		case 2:	 strcpy(rideType, "intracity");	break;
		}

		DriverRanking = -1;
		VehicleRanking = -1;
	}
	virtual void userOutput(ostream& out) {
		Service::userOutput(out);

		out << "Service Type: Ride\n";
		out	<< "No. of Passengers: " << noofPassengers << endl
			<< "Ride Type: " << rideType << endl;

		if (DriverRanking >= 0)
			out << "Driver Ranking: " << DriverRanking << endl;
		else
			out << "Driver Ranking not given yet\n";

		if (VehicleRanking >= 0)
			out << "Vehicle Ranking: " << VehicleRanking << endl;
		else
			out << "Vehicle Ranking not given yet\n";
	}
	virtual void fileInput(ifstream& in) {
		Service::fileInput(in);
		in >> noofPassengers;
		in >> rideType;
		in >> DriverRanking; 
		in >> VehicleRanking;
	}
	virtual void fileOutput(ofstream& out) {
		Service::fileOutput(out);
		out << endl << noofPassengers << endl;
		out << rideType << endl;
		out << DriverRanking << endl;
		out << VehicleRanking ;
	}
	friend ostream& operator<<(ostream& out, Ride& r)
	{
		r.userOutput(out);
		return out;
	}
	friend istream& operator>>(istream& in, Ride& obj)
	{
		obj.userInput(in);
		return in;
	}
	friend ofstream& operator<<(ofstream& out, Ride& r)
	{
		r.fileOutput(out);
		return out;
	}
	friend ifstream& operator>>(ifstream& in, Ride& r)
	{
		r.fileInput(in);
		return in;
	}

};


Ride::Ride()
{
	noofPassengers = 0;
	rideType = nullptr;
	DriverRanking = -1;
	VehicleRanking = -1;
}

Ride::Ride(int passengers, char* type, float drank, float vrank)
{
	noofPassengers = passengers;
	DriverRanking = drank;
	VehicleRanking = vrank;
	rideType = new char[strlen(type) + 1];
	strcpy(rideType, type);
}

Ride::Ride(const Ride& r)
{
	noofPassengers = r.noofPassengers;
	DriverRanking = r.DriverRanking;
	VehicleRanking = r.VehicleRanking;
	if (r.rideType != nullptr)
	{
		rideType = new char[strlen(r.rideType) + 1];
		strcpy(rideType, r.rideType);
	}
	else
		rideType = nullptr;
}

Ride::~Ride()
{
	delete rideType;
	rideType = nullptr;
}

float Ride::getVRanking()
{
	return VehicleRanking;
}

float Ride::getDRanking()
{
	return DriverRanking;
}

int Ride::getNo_ofPassengers()
{
	return noofPassengers;
}

char* Ride::getType()
{
	return rideType;
}

void Ride::setNo_ofPassengers(int passengers)
{
	noofPassengers = passengers;
}

void Ride::setType(char* type)
{
	if (rideType != nullptr)
	{
		delete rideType;
		rideType = new char[strlen(type) + 1];
		strcpy(rideType, type);
	}
	else
	{
		rideType = new char[strlen(type) + 1];
		strcpy(rideType, type);
	}
}

void Ride::setDRanking(float drank)
{
	DriverRanking = drank;
}

void Ride::setVRanking(float vrank)
{
	VehicleRanking = vrank;
}




