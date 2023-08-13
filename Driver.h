#pragma once
#include "person.h"
#include "service.h"
using namespace std;

class Driver :public Person {
private:
	int dId;
	char** LicencesList;
	int noofLicences;
	float overallRanking;
	float salary;
	int experience;
	int status; // 1 for free, 2 if booked and 3 if canceled 
	Service** serviceHistory;
	int serviceHistoryCount;
public:
	Driver() :Person() {
		this->dId = 0;
		this->LicencesList = nullptr;
		this->noofLicences = 0;
		this->overallRanking = 0;
		this->salary = 0;
		this->experience = 0;
		this->status = 0;
		this->serviceHistory = nullptr;
		this->serviceHistoryCount = 0;
	}
	Driver(char* fN, char* lN, int day, int month, int year, int age, int id, int dId, int overallRanking, int salary, int experience, int status) : Person(fN, lN, day, month, year, age, id) {
		this->dId = dId;
		this->overallRanking = overallRanking;
		this->salary = salary;
		this->experience = experience;
		this->status = status;

		this->noofLicences = 0;
		this->LicencesList = nullptr;
		this->serviceHistory = nullptr;
		serviceHistoryCount = 0;
	}
	Driver(const Driver& d) : Person(d) {
		this->dId = d.dId;
		this->overallRanking = d.overallRanking;
		this->salary = d.salary;
		this->experience = d.experience;
		this->status = d.status;

		this->serviceHistoryCount = d.serviceHistoryCount;
		serviceHistory = new Service * [this->serviceHistoryCount];
		for (int i = 0; i < serviceHistoryCount; i++) {
			serviceHistory[i] = new Service;
			*(serviceHistory[i]) = *(d.serviceHistory[i]);
		}

		this->noofLicences = d.noofLicences;
		LicencesList = new char* [noofLicences];
		for (int i = 0; i < noofLicences; i++) {
			LicencesList[i] = new char[strlen(d.LicencesList[i]) + 1];
			strcpy(LicencesList[i], d.LicencesList[i]);
		}
	}
	~Driver() {
		for (int i = 0; i < serviceHistoryCount; i++)
			delete serviceHistory[i];
		delete[] serviceHistory;

		for (int i = 0; i < noofLicences; i++)
			delete[] LicencesList[i];
		delete[] LicencesList;
	}

	int getdId() { return this->dId; }
	void setdId(int dId) { this->dId = dId; }
	int getSalary() { return salary; }
	void setSalary(int salary) { this->salary = salary; }
	int getExperience() { return this->experience; }
	void setExperience(int experience) { this->experience = experience; }
	int getStatus() { return this->status; }
	void setStatus(int status) { this->status = status; }
	int getlicences_count() { return this->noofLicences; }
	float getRanking() { return this->overallRanking; }
	void fileIn(ifstream& in) {

		Person::fileIn(in);
		in >> dId
			>> salary
			>> overallRanking
			>> experience
			>> status;

		//licence list input
		if (LicencesList != nullptr) {
			for (int i = 0; i < noofLicences; i++)
				delete LicencesList[i];
			delete[] LicencesList;
			LicencesList = nullptr;
		}
		in >> noofLicences;
		in.ignore();

		if (noofLicences > 0)
			LicencesList = new char* [noofLicences];
		for (int i = 0; i < noofLicences; i++) {
			LicencesList[i] = new char[100];
			in.getline(LicencesList[i], 100, '\n');
		}


		//service history input
		if (serviceHistory != nullptr) {
			for (int i = 0; i < serviceHistoryCount; i++)
				delete serviceHistory[i];
			delete[] serviceHistory;
		}
		in >> serviceHistoryCount;
		if (serviceHistoryCount > 0)
			serviceHistory = new Service * [serviceHistoryCount];
		for (int i = 0; i < serviceHistoryCount; i++) {
			serviceHistory[i] = new Service;
			in >> *(serviceHistory[i]);
		}
	}

	void addService(Service& s) {
		serviceHistoryCount++;
		Service** temp = new Service * [serviceHistoryCount];
		for (int i = 0; i < serviceHistoryCount - 1; i++) {
			temp[i] = new Service;
			*(temp[i]) = *(serviceHistory[i]);
			delete serviceHistory[i];
		}
		*(temp[serviceHistoryCount - 1]) = s;
		delete[] serviceHistory;
		serviceHistory = temp;
	}
	void addLicence(char* licence) {
		noofLicences++;
		char** temp = new char* [noofLicences];
		for (int i = 0; i < noofLicences - 1; i++) {
			temp[i] = new char[strlen(LicencesList[i]) + 1];
			strcpy(temp[i], LicencesList[i]);
			delete[] LicencesList[i];
		}
		temp[noofLicences - 1] = new char[strlen(licence) + 1];
		strcpy(temp[noofLicences - 1], licence);
		delete[] LicencesList;
		LicencesList = temp;
	}

	friend ostream& operator << (ostream& out, Driver& d) {
		out << static_cast <Person&> (d);
		out << "Driver ID: " << d.dId << endl
			<< "Salary: " << d.salary <<" Rupees"<< endl
			<< "Rating: " << d.overallRanking << endl
			<< "Experince " << d.experience <<" Years"<< endl << "Status: ";
		switch (d.status) {
		case 1: out << "Free\n";		break;
		case 2: out << "Booked\n";		break;
		case 3: out << "Canceled\n";	break;
		}
		out << "Licences: ";
		for (int i = 0; i < d.noofLicences; i++)
			out << d.LicencesList[i] << " ";
		out << endl;
		out << "--History of Services-- \n";
		for (int i = 0; i < d.serviceHistoryCount; i++)
			out << *(d.serviceHistory[i])<<endl;
		return out;
	}
	friend istream& operator >> (istream& in, Driver& d) {
		in >> (Person&)d;
		cout << "Driver ID: ";
		in >> d.dId;
		cout << "Salary: ";
		in >> d.salary;
		cout << "Rating: ";
		in >> d.overallRanking;
		cout << "Experince: ";
		in >> d.experience;
		cout << "Enter 1 if driver is free, 2 if booked and 3 if his ride is cancelled: ";
		in >> d.status;

		char* temp;
		if (d.LicencesList != nullptr) {
			for (int i = 0; i < d.noofLicences; i++)
				delete d.LicencesList[i];
			delete d.LicencesList;
		}
		cout << "How many licences driver has? Enter no. ";
		in >> d.noofLicences;
		//in.ignore();
		if (d.noofLicences > 0)
			d.LicencesList = new char* [d.noofLicences];
		for (int i = 0; i < d.noofLicences; i++) {
			temp = new char[100];
			cout << "\tLicence no. " << i + 1 << " : ";
			
			in.getline(temp, 100);
			d.LicencesList[i] = new char[strlen(temp) + 1];
			strcpy(d.LicencesList[i], temp);
			delete[] temp;
		}

		if (d.serviceHistory != nullptr) {
			for (int i = 0; i < d.serviceHistoryCount; i++)
				delete d.serviceHistory[i];
			delete d.serviceHistory;
		}

		cout << "Enter Number of Services: ";
		in >> d.serviceHistoryCount;

		if (d.serviceHistoryCount > 0)
			d.serviceHistory = new Service * [d.serviceHistoryCount];
		for (int i = 0; i < d.serviceHistoryCount; i++) {
			d.serviceHistory[i] = new Service;
			cout << "Enter service# " << i + 1 << " details:\n";
			in >> *(d.serviceHistory[i]);
		}
		return in;
	}

	friend ofstream& operator << (ofstream& out, Driver& d) {
		out << static_cast <Person&> (d)
			<< d.dId << endl
			<< d.salary << endl
			<< d.overallRanking << endl
			<< d.experience << endl
			<< d.status << endl
			<< d.noofLicences << endl;
		for (int i = 0; i < d.noofLicences; i++)
			out << d.LicencesList[i] << endl;
		out << d.serviceHistoryCount << endl;
		for (int i = 0; i < d.serviceHistoryCount; i++)
			out << *(d.serviceHistory[i]) << endl;
		return out;
	}
	friend ifstream& operator >> (ifstream& in, Driver& d) {
		d.fileIn(in);
		return in;
	}
};
