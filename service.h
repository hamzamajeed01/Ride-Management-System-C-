#pragma once
#include<iostream>
#include<fstream>
#include"date.h"
#include"time.h"
using namespace std;

class Service {
private:
	char* source;
	char* destination;
	float distance; //in km 
	Date bookingDate;
	mTime bookingTime;
	int status;
	// false for pending, true if complete 
	float fuelrate;
	int cId; // Customer Id who booked the ride 
	int dId; // Driver Id 
	int vId; // vehicle Id 
	//you can add more members here if required 
	//add member functions
public:
	//Constructors
	Service();
	Service(char*, char*, float, int, int, int, int, int, int, int, float, int, int, int);
	Service(Service&);
	//Getters
	int getDay();
	int getMonth();
	int getYear();
	Date getDate();
	int getSec();
	int getMin();
	int getHour();
	char* getSource();
	char* getDestination();
	int getStatus();
	float getDistance();
	float getFuelrate();
	int getCID();
	int getVID();
	int getDID();
	//Setters
	void setTime(int, int, int);
	void setSec(int);
	void setMin(int);
	void setHour(int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setSource(char*);
	void setDestination(char*);
	void setStatus(int);
	void setDistance(float);
	void setFuelrate(float);
	void setCID(int);
	void setVID(int);
	void setDID(int);
	//Destructor
	~Service();
	//Output Operator
	virtual void userInput(istream& in) {
		cout << "Enter Source: ";
		char* temp = new char[1000];
		in.ignore();
		in.getline(temp, 1000);
		setSource(temp);
		delete[] temp;
		temp = new char[1000];
		cout << "Enter Destination: ";
		in.getline(temp, 1000);
		setDestination(temp);
		delete[] temp;
		cout << "Enter Booking Date" << endl;
		in >> bookingDate;
		cout << "Enter Booking Time" << endl;
		in >> bookingTime;
		cout << "Enter Distance: ";
		in >> distance;
		cout << "Enter Status: (0 if Pending, 1 if Complete, 2 if Canceled): ";
		in >> status;
		cout << "Fuel Rate: ";
		in >> fuelrate;
		cout << "Enter Customer ID: ";
		in >> cId;
		cout << "Enter Driver ID: ";
		in >> dId;
		cout << "Enter Vehicle ID: ";
		in >> vId;
	}
	virtual void userOutput(ostream& out) {
		out << "Source: " << source << endl
			<< "Destination: " << destination << endl
			<< "Booking Time: " << bookingTime
			<< "Booking Date: " << bookingDate
			<< "\nDistance: " << distance << " km" << endl;
		if (status == 0)
			out << "Status: Pending" << endl;
		else if (status == 1)
			out << "Status: Completed" << endl;
		else if (status == 2)
			out << "Status: Canceled" << endl;
		out << "Fuel Rate: " << fuelrate << " Rupees" << endl
			<< "Customer ID: " << cId << endl
			<< "Driver ID: " << dId << endl
			<< "Vehicle ID: " << vId << endl;
	}
	virtual void fileInput(ifstream& in) {
		source = new char[100];
		in.ignore();
		in.getline(source, 100, '\n');
		destination = new char[100];
		in.getline(destination, 100, '\n');
		in >> bookingDate;
		in >> bookingTime;
		in >> distance;
		in >> status;
		in >> fuelrate;
		in >> cId;
		in >> dId;
		in >> vId;
	}
	virtual void fileOutput(ofstream& out) {
		out << source << endl;
		out << destination << endl;
		out << bookingDate;
		out << bookingTime;
		out << distance << endl;
		out << status << endl;
		out << fuelrate << endl;
		out << cId << endl;
		out << dId << endl;
		out << vId;
	}
	friend ostream& operator<<(ostream& out, Service& s)
	{
		s.userOutput(out);
		return out;
	}

	friend istream& operator>>(istream& in, Service& obj)
	{
		obj.userInput(in);
		return in;
	}

	friend ifstream& operator>>(ifstream& in, Service& obj)
	{
		obj.fileInput(in);
		return in;
	}

	friend ofstream& operator<<(ofstream& out, Service& obj)
	{
		obj.fileOutput(out);
		return out;
	}


	Service& operator=(const Service&);
};


Service::Service() : bookingDate(), bookingTime()
{
	source = nullptr;
	destination = nullptr;
	distance = 0;
	status = NULL;
	fuelrate = 0;
	cId = 0;
	vId = 0;
	dId = 0;
}

Service::Service(char* src, char* dest, float d, int day, int month, int year, int hour, int min, int sec,
	int status, float rate, int cid, int did, int vid) : bookingDate(day, month, year), bookingTime(hour, min, sec)
{
	distance = d;
	this->status = status;
	fuelrate = rate;
	cId = cid;
	vId = vid;
	dId = did;
	source = new char[strlen(src) + 1];
	strcpy(source, src);
	destination = new char[strlen(dest) + 1];
	strcpy(destination, dest);
}

Service::Service(Service& obj) : bookingDate(obj.bookingDate), bookingTime(obj.bookingTime)
{
	distance = obj.distance;
	this->status = obj.status;
	fuelrate = obj.fuelrate;
	cId = obj.cId;
	vId = obj.vId;
	dId = obj.dId;
	source = new char[strlen(obj.source) + 1];
	strcpy(source, obj.source);
	destination = new char[strlen(obj.destination) + 1];
	strcpy(destination, obj.destination);
}

int Service::getDay()
{
	return bookingDate.getDay();
}

int Service::getMonth()
{
	return bookingDate.getMonth();
}

int Service::getYear()
{
	return bookingDate.getYear();
}

inline Date Service::getDate()
{
	return this->bookingDate;
}

int Service::getSec()
{
	return bookingTime.getSec();
}

int Service::getMin()
{
	return bookingTime.getMin();
}

int Service::getHour()
{
	return bookingTime.getHour();
}

char* Service::getSource()
{
	return source;
}

char* Service::getDestination()
{
	return destination;
}

int Service::getStatus()
{
	return status;
}

float Service::getDistance()
{
	return distance;
}

float Service::getFuelrate()
{
	return fuelrate;
}

int Service::getCID()
{
	return cId;
}

int Service::getVID()
{
	return vId;
}

int Service::getDID()
{
	return dId;
}

void Service::setTime(int hour, int min, int sec)
{
	bookingTime.setHour(hour);
	bookingTime.setMin(min);
	bookingTime.setSec(sec);
}

void Service::setSec(int sec)
{
	bookingTime.setSec(sec);
}

void Service::setMin(int min)
{
	bookingTime.setMin(min);
}

void Service::setHour(int hour)
{
	bookingTime.setHour(hour);
}

void Service::setDate(int day, int month, int year)
{
	bookingDate.setYear(year);
	bookingDate.setMonth(month);
	bookingDate.setDay(day);
}

void Service::setDay(int day)
{
	bookingDate.setDay(day);
}

void Service::setMonth(int month)
{
	bookingDate.setMonth(month);
}

void Service::setYear(int year)
{
	bookingDate.setYear(year);
}

void Service::setSource(char* source)
{
	if (this->source != nullptr)
	{
		delete this->source;
		this->source = new char[strlen(source) + 1];
		strcpy(this->source, source);
	}
	else
	{
		this->source = new char[strlen(source) + 1];
		strcpy(this->source, source);
	}
}

void Service::setDestination(char* destination)
{
	if (this->destination != nullptr)
	{
		delete this->destination;
		this->destination = new char[strlen(destination) + 1];
		strcpy(this->destination, destination);
	}
	else
	{
		this->destination = new char[strlen(destination) + 1];
		strcpy(this->destination, destination);
	}

}

void Service::setStatus(int status)
{
	this->status = status;
}

void Service::setDistance(float d)
{
	distance = d;
}

void Service::setFuelrate(float rate)
{
	fuelrate = rate;
}

void Service::setCID(int id)
{
	cId = id;
}

void Service::setVID(int id)
{
	vId = id;
}

void Service::setDID(int id)
{
	dId = id;
}

Service::~Service()
{
	delete destination;
	delete source;
	source = nullptr;
	destination = nullptr;
}

Service& Service::operator=(const Service& s)
{
	this->distance = s.distance;
	this->fuelrate = s.fuelrate;
	this->status = s.status;
	this->vId = s.vId;
	this->dId = s.dId;
	this->cId = s.cId;
	if (this->source != nullptr && s.source != nullptr)
	{
		delete this->source;
		this->source = new char[strlen(s.source) + 1];
		strcpy(this->source, s.source);
	}
	else if (this->source != nullptr && s.source == nullptr)
	{
		delete this->source;
		this->source = nullptr;
	}
	else if (this->source == nullptr && s.source != nullptr)
	{
		this->source = new char[strlen(s.source) + 1];
		strcpy(this->source, s.source);
	}
	if (this->destination != nullptr && s.destination != nullptr)
	{
		delete this->destination;
		this->destination = new char[strlen(s.destination) + 1];
		strcpy(this->destination, s.destination);
	}
	else if (this->destination != nullptr && s.destination == nullptr)
	{
		delete this->destination;
		this->destination = nullptr;
	}
	else if (this->destination == nullptr && s.destination != nullptr)
	{
		this->destination = new char[strlen(s.destination) + 1];
		strcpy(this->destination, s.destination);
	}
	this->bookingDate = s.bookingDate;
	this->bookingTime = s.bookingTime;
	return *this;
}