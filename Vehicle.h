#include<iostream>
#include"date.h"
#include"feature.h"
#include"service.h"
using namespace std;

class Vehicle
{
private:
	int vId;
	int registrationNo;
	float avgMileage;
	char* LicenceType; // License required for driving the vehicle 
	bool status; // false for free, true if booked in a service already 
	char* fueltype;
	char* vehicleType;
	float overallRanking;
	Date manufacturingDate;
	Feature* list;
	Service** serviceHistory;
	int features_count;
	int services_count;
	//Add services address in the array for tracking complete information of service.
	//you can add more members here if required //add member functions 
public:
	Vehicle();
	Vehicle(int, int, float, char*, bool, char*, float, Date, char*);
	Vehicle(Vehicle&);
	~Vehicle();
	void setID(int);
	void setRegistrationNo(int);
	void setmilage(float);
	void setLicenceType(char*);
	void setVehicleType(char*);
	void setStatus(bool);
	void setFuelType(char*);
	void setRanking(float);
	void setDate(Date&);
	int getID();
	int getRegistrationNo();
	float getMileage();
	float getRanking();
	char* getVehicleType();
	char* getLicenceType();
	char* getFuelType();
	void addFeature(Feature&);
	void addService(Service&);
	Vehicle& operator=(const Vehicle&);
	friend ostream& operator<<(ostream& out, Vehicle&);
	friend istream& operator>>(istream& in, Vehicle& obj)
	{
		cout << "Enter vehicle ID: ";
		in >> obj.vId;
		cout << "Enter Registration NO: ";
		in >> obj.registrationNo;
		cout << "Enter Average Mileage: ";
		in >> obj.avgMileage;
		cout << "Enter 1 if vehicle is free now and 0 if not: ";
		in >> obj.status;
		cout << "Enter Overall Ranking: ";
		in >> obj.overallRanking;
		in.ignore();
		cout << "Enter Vehicle type(Big or small): ";
		char* temp = new char[1000];
		in.getline(temp, 1000);
		obj.setVehicleType(temp);
		delete[] temp;
		temp = new char[1000];
		cout << "Enter licence Type: ";
		in.ignore();
		in.getline(temp, 1000);
		obj.setLicenceType(temp);
		delete[] temp;
		temp = new char[1000];
		cout << "Enter Fuel Type: ";
		in.getline(temp, 1000);
		obj.setFuelType(temp);
		cout << "Enter Manufacturing Date" << endl;
		in >> obj.manufacturingDate;
		cout << "Add Number of features: ";
		in >> obj.features_count;
		if (obj.list != nullptr)
			delete[] obj.list;
		obj.list = new Feature[obj.features_count];
		for (int i = 0; i < obj.features_count; i++)
			in >> obj.list[i];

		if (obj.list != nullptr)
		{
			for (int i = 0; i < obj.services_count; i++)
			{
				delete[] obj.serviceHistory[i];
			}
			delete[] obj.serviceHistory;
		}
		cout << "Enter Number of Services: ";
		in >> obj.services_count;
		if (obj.services_count > 0)
			obj.serviceHistory = new Service * [obj.services_count];
		for (int i = 0; i < obj.services_count; i++)
		{
			obj.serviceHistory[i] = new Service;
			in >> *(obj.serviceHistory[i]);
		}
		return in;
	}
	friend ifstream& operator>>(ifstream&, Vehicle&);
	friend ofstream& operator<<(ofstream&, Vehicle&);

	void fileIn(ifstream& in) {

		in >> vId;
		in >> registrationNo;
		in >> avgMileage;
		vehicleType = new char[100];
		in.ignore();
		in.getline(vehicleType, 100, '\n');
		LicenceType = new char[100];
		in.getline(LicenceType, 100, '\n');
		fueltype = new char[100];
		in.getline(fueltype, 100, '\n');
		in >> status;
		in >> overallRanking;
		in >> manufacturingDate;
		in >> features_count;
		list = new Feature[features_count];
		for (int i = 0; i < features_count; i++)
			in >> list[i];
		in >> services_count;
		serviceHistory = new Service * [services_count];
		for (int i = 0; i < services_count; i++) {
			serviceHistory[i] = new Service;
			in >> *(serviceHistory[i]);
		}
	}
};

Vehicle::Vehicle() : manufacturingDate()
{
	list = nullptr;
	serviceHistory = nullptr;
	fueltype = nullptr;
	LicenceType = nullptr;
	vehicleType = nullptr;
	vId = 0;
	registrationNo = 0;
	avgMileage = 0;
	status = NULL;
	overallRanking = 0;
	features_count = 0;
	services_count = 0;
}

Vehicle::Vehicle(Vehicle& obj) : manufacturingDate(obj.manufacturingDate)
{
	//make copy and parametrized constructors
	this->vId = obj.vId;
	this->registrationNo = obj.registrationNo;
	this->avgMileage = obj.avgMileage;

	this->vehicleType = new char[strlen(obj.vehicleType) + 1];
	strcpy(this->vehicleType, obj.vehicleType);

	this->LicenceType = new char[strlen(obj.LicenceType) + 1];
	strcpy(this->LicenceType, obj.LicenceType); // License required for driving the vehicle 

	this->status = obj.status; // false for free, true if booked in a service already 
	this->fueltype = new char[strlen(obj.fueltype) + 1];
	strcpy(this->fueltype, obj.fueltype);

	this->overallRanking = obj.overallRanking;
	this->manufacturingDate = obj.manufacturingDate;
	this->features_count = obj.features_count;
	this->services_count = obj.services_count;
	this->list = new Feature[features_count];
	for (int i = 0; i < features_count; i++)
		this->list[i] = obj.list[i];
	this->serviceHistory = new Service * [services_count];
	for (int i = 0; i < services_count; i++) {
		serviceHistory[i] = new Service;
		*(serviceHistory[i]) = *(obj.serviceHistory[i]);
	}
}

Vehicle::Vehicle(int vId, int registrationNo, float avgMileage, char* LicenceType, bool status, char* fueltype, float overallRanking, Date manufacturingDate, char* vehicleType)
{
	this->vId = vId;
	this->registrationNo = registrationNo;
	this->avgMileage = avgMileage;
	this->vehicleType = new char[strlen(vehicleType) + 1];
	strcpy(this->vehicleType, vehicleType);
	this->LicenceType = new char[strlen(LicenceType) + 1];
	strcpy(this->LicenceType, LicenceType);
	this->status = status;
	this->fueltype = new char[strlen(fueltype) + 1];
	strcpy(this->fueltype, fueltype);
	this->overallRanking = overallRanking;
	this->manufacturingDate = manufacturingDate;
	list = nullptr;
	serviceHistory = nullptr;
	this->features_count = 0;
	this->services_count = 0;
}

Vehicle::~Vehicle()
{
	delete[] LicenceType;
	delete[] fueltype;
	delete[] list;
	delete[] vehicleType;
	//delete list;
	for (int i = 0; i < services_count; i++)
		delete serviceHistory[i];
	delete[] serviceHistory;
	serviceHistory = nullptr;
	list = nullptr;
	fueltype = nullptr;
	LicenceType = nullptr;
	vehicleType = nullptr;
}

inline void Vehicle::setID(int id)
{
	this->vId = id;
}

inline void Vehicle::setRegistrationNo(int r)
{
	this->registrationNo = r;
}

inline void Vehicle::setmilage(float m)
{
	this->avgMileage = m;
}

inline void Vehicle::setLicenceType(char* l)
{
	if (this->LicenceType != nullptr && l != nullptr)
	{
		delete this->LicenceType;
		this->LicenceType = new char[strlen(l) + 1];
		strcpy(this->LicenceType, l);
	}
	else if (this->LicenceType != nullptr && l == nullptr)
	{
		delete this->LicenceType;
		LicenceType = nullptr;
	}
	else if (this->LicenceType == nullptr && l != nullptr)
	{
		this->LicenceType = new char[strlen(l) + 1];
		strcpy(this->LicenceType, l);
	}
}

inline void Vehicle::setVehicleType(char* type) {
	if (this->vehicleType != nullptr && type != nullptr)
	{
		delete this->vehicleType;
		this->vehicleType = new char[strlen(type) + 1];
		strcpy(this->vehicleType, type);
	}
	else if (this->vehicleType != nullptr && type == nullptr)
	{
		delete this->vehicleType;
		this->vehicleType = nullptr;
	}
	else if (this->vehicleType == nullptr && type != nullptr)
	{
		this->vehicleType = new char[strlen(type) + 1];
		strcpy(this->vehicleType, type);
	}
}

inline void Vehicle::setStatus(bool s)
{
	this->status = s;
}

inline void Vehicle::setFuelType(char* fuel)
{
	if (this->fueltype != nullptr && fuel != nullptr)
	{
		delete this->fueltype;
		this->fueltype = new char[strlen(fuel) + 1];
		strcpy(this->fueltype, fuel);
	}
	else if (this->fueltype != nullptr && fuel == nullptr)
	{
		delete this->fueltype;
		fueltype = nullptr;
	}
	else if (this->fueltype == nullptr && fuel != nullptr)
	{
		this->fueltype = new char[strlen(fuel) + 1];
		strcpy(this->fueltype, fuel);
	}
}

inline void Vehicle::setRanking(float r)
{
	this->overallRanking = r;
}

inline void Vehicle::setDate(Date& date)
{
	this->manufacturingDate = date;
}

void Vehicle::addService(Service& s) {
	this->services_count++;
	Service** temp = new Service * [services_count];
	for (int i = 0; i < services_count - 1; i++) {
		temp[i] = new Service;
		*(temp[i]) = *(serviceHistory[i]);
		delete serviceHistory[i];
	}
	*(temp[services_count - 1]) = s;
	delete[] serviceHistory;
	serviceHistory = temp;
}

void Vehicle::addFeature(Feature& f) {
	this->features_count++;
	Feature* temp = new Feature[features_count];
	for (int i = 0; i < features_count - 1; i++)
		temp[i] = list[i];
	temp[features_count - 1] = f;
	delete list;
	list = temp;
}

inline int Vehicle::getID()
{
	return vId;
}

inline int Vehicle::getRegistrationNo()
{
	return registrationNo;
}

inline float Vehicle::getMileage()
{
	return avgMileage;
}

inline float Vehicle::getRanking()
{
	return overallRanking;
}

inline char* Vehicle::getVehicleType()
{
	return this->vehicleType;
}

inline char* Vehicle::getLicenceType()
{
	return LicenceType;
}

inline char* Vehicle::getFuelType()
{
	return fueltype;
}

inline Vehicle& Vehicle::operator=(const Vehicle& obj)
{
	this->manufacturingDate = obj.manufacturingDate;
	this->vId = obj.vId;
	this->registrationNo = obj.registrationNo;
	this->avgMileage = obj.avgMileage;
	this->status = obj.status;
	this->overallRanking = obj.overallRanking;
	this->features_count = obj.features_count;
	this->services_count = obj.services_count;


	/////////////////////////////////////////////////////////////////////////

	if (this->vehicleType != nullptr && obj.vehicleType != nullptr)
	{
		delete this->vehicleType;
		this->vehicleType = new char[strlen(obj.vehicleType) + 1];
		strcpy(this->vehicleType, obj.vehicleType);
	}
	else if (this->vehicleType != nullptr && obj.vehicleType == nullptr)
	{
		delete this->vehicleType;
		this->vehicleType = nullptr;
	}
	else if (this->vehicleType == nullptr && obj.vehicleType != nullptr)
	{
		this->vehicleType = new char[strlen(obj.vehicleType) + 1];
		strcpy(this->vehicleType, obj.vehicleType);
	}

	/////////////////////////////////////////////////////////////////////////////////
	if (this->LicenceType != nullptr && obj.LicenceType != nullptr)
	{
		delete this->LicenceType;
		this->LicenceType = new char[strlen(obj.LicenceType) + 1];
		strcpy(this->LicenceType, obj.LicenceType);
	}
	else if (this->LicenceType != nullptr && obj.LicenceType == nullptr)
	{
		delete this->LicenceType;
		LicenceType = nullptr;
	}
	else if (this->LicenceType == nullptr && obj.LicenceType != nullptr)
	{
		this->LicenceType = new char[strlen(obj.LicenceType) + 1];
		strcpy(this->LicenceType, obj.LicenceType);
	}



	/////////////////////////////////////////////////////////////////////////
	if (this->fueltype != nullptr && obj.fueltype != nullptr)
	{
		delete this->fueltype;
		this->fueltype = new char[strlen(obj.fueltype) + 1];
		strcpy(this->fueltype, obj.fueltype);
	}
	else if (this->fueltype != nullptr && obj.fueltype == nullptr)
	{
		delete this->fueltype;
		fueltype = nullptr;
	}
	else if (this->fueltype == nullptr && obj.fueltype != nullptr)
	{
		this->fueltype = new char[strlen(obj.fueltype) + 1];
		strcpy(this->fueltype, obj.fueltype);
	}

	///////////////////////////////////////////////////////////////////////////
	if (features_count > 0)
		this->list = new Feature[features_count];
	for (int i = 0; i < features_count; i++)
	{
		this->list[i] = obj.list[i];
	}
	return *this;


	///////////////////////////////////////////////////////////////////////////
	if (services_count > 0)
		this->serviceHistory = new Service * [obj.services_count];
	for (int i = 0; i < obj.services_count; i++) {
		this->serviceHistory[i] = new Service;
		*(serviceHistory[i]) = *(obj.serviceHistory[i]);
	}
}

ostream& operator<<(ostream& out, Vehicle& obj)
{
	out << "Vehicle ID: " << obj.vId << endl
		<< "Registration No: " << obj.registrationNo << endl
		<< "Vehicle Type: " << obj.vehicleType << endl
		<< "License Type: " << obj.LicenceType << endl
		<< "Fuel Type: " << obj.fueltype << endl
		<< "Overall Ranking: " << obj.overallRanking << endl
		<< "Manufacturing Date: " << obj.manufacturingDate << endl;

	out << "Features: \n";
	for (int i = 0; i < obj.features_count; i++)
		out << obj.list[i] << endl;

	out << "--Services History-- \n";
	if (obj.services_count == 0)
		out << "No record\n";
	for (int i = 0; i < obj.services_count; i++)
		out << *(obj.serviceHistory[i]) << endl;
	return out;
}

inline ifstream& operator>>(ifstream& in, Vehicle& obj)
{
	obj.fileIn(in);
	return in;
}

inline ofstream& operator<<(ofstream& out, Vehicle& obj)
{
	out << obj.vId << endl;
	out << obj.registrationNo << endl;
	out << obj.avgMileage << endl;
	out << obj.vehicleType << endl;
	out << obj.LicenceType << endl;
	out << obj.fueltype << endl;
	out << obj.status << endl;
	out << obj.overallRanking << endl;
	out << obj.manufacturingDate;
	out << obj.features_count << endl;
	for (int i = 0; i < obj.features_count; i++)
	{
		out << obj.list[i] << " ";
	}
	out << obj.services_count << endl;
	for (int i = 0; i < obj.services_count; i++)
	{
		out << *(obj.serviceHistory[i]) << " ";
	}
	out << endl;
	return out;
}