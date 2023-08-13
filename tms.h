#pragma once
#include"Customer.h"
#include"date.h"
#include"delivery.h"
#include"ride.h"
#include"Driver.h"
#include"feature.h"
#include"Vehicle.h"

class tms {
	int temp;
	int vehicle_count;
	int customer_count;
	int driver_count;
	int service_count;
	Vehicle v;
	Driver d;
	Customer c;
	Service* tempService;
	ofstream customer_out;
	ofstream driver_out;
	ofstream vehicle_out;
	ifstream service_in;
	ofstream count_out;
	ifstream count_in;
	ifstream customer_in;
	ifstream vehicle_in;
	ifstream driver_in;
	ofstream service_out;
	bool found = false;
	char* tempCf;
	char* tempCl;
	Date date;
	int tempCount;
public:
	tms() {
		tempCount = 1;
		char* tempCf = new char[100];
		char* tempCl = new char[100];
		count_in.open("count.txt");
		count_in >> customer_count;
		count_in >> vehicle_count;
		count_in >> driver_count;
		count_in >> service_count;
		count_in.close();
	}

	~tms() {
		delete[] tempCf;
		delete[] tempCl;
		tempCf = nullptr;
		tempCl = nullptr;
	}

	void updateCount() {
		count_in.open("count.txt");
		count_in >> customer_count;
		count_in >> vehicle_count;
		count_in >> driver_count;
		count_in >> service_count;
		count_in.close();
	}

	void addCostumer() {
		cin >> c;
		customer_out.open("customer.txt", ios::app);
		customer_out << c << endl;
		customer_out.close();
		customer_count++;
		count_out.open("count.txt");
		count_out << customer_count << endl;
		count_out << vehicle_count << endl;
		count_out << driver_count << endl;
		count_out << service_count << endl;
		count_out.close();
		cout << "CUSTOMER ADDED!" << endl;
	}

	void addDriver() {
		cin >> d;
		driver_out.open("driver.txt", ios::app);
		driver_out << d;
		driver_out.close();
		driver_count++;
		count_out.open("count.txt");
		count_out << customer_count << endl;
		count_out << vehicle_count << endl;
		count_out << driver_count << endl;
		count_out << service_count << endl;
		count_out.close();
		cout << "DRIVER ADDED!" << endl;
	}

	void removeDriver() {
		cin.ignore();
		cout << "Enter the first name of the driver to remove: ";
		cin.getline(tempCf, 100);
		cout << "Enter the last name of the driver to remove: ";
		cin.getline(tempCl, 100);

		if (driver_count > 0)
		{
			driver_in.open("driver.txt");
			Driver* D = new Driver[driver_count];
			for (int i = 0; i < driver_count; i++)
				driver_in >> D[i];
			driver_in.close();

			driver_out.open("driver.txt");
			for (int i = 0; i < driver_count; i++)
				if ((strcmp(D[i].getfName(), tempCf) != 0) && (strcmp(D[i].getlName(), tempCl) != 0))
					driver_out << D[i];

			delete[] D;
			D = nullptr;
		}
		else
			cout << "No Record of Driver Found!" << endl;
		driver_count--;
		count_out.open("count.txt");
		count_out << customer_count << endl;
		count_out << vehicle_count << endl;
		count_out << driver_count << endl;
		count_out << service_count << endl;
		count_out.close();
		cout << "DRIVER REMOVED!" << endl;
	}

	void removeVehicle() {
		cin.ignore();
		int temp1, temp2;
		cout << "Enter Vehicle ID: ";
		cin >> temp1;
		cout << "Enter Registration Number: ";
		cin >> temp2;
		if (vehicle_count > 0)
		{
			vehicle_in.open("vehicle.txt");
			Vehicle* V = new Vehicle[vehicle_count];
			for (int i = 0; i < vehicle_count; i++)
				vehicle_in >> V[i];
			vehicle_in.close();

			vehicle_out.open("driver.txt");
			for (int i = 0; i < vehicle_count; i++)
				if (V[i].getID() != temp1 && V[i].getRegistrationNo() != temp2)
					driver_out << V[i];

			delete[] V;
			V = nullptr;
		}
		else
			cout << "No Record of Vehicle Found!" << endl;
		vehicle_count--;
		count_out.open("count.txt");
		count_out << customer_count << endl;
		count_out << vehicle_count << endl;
		count_out << driver_count << endl;
		count_out.close();
		cout << "VEHICLE REMOVED!" << endl;
	}

	void addVehicle() {
		cin >> v;
		customer_out.open("vehicle.txt", ios::app);
		customer_out << v;
		customer_out.close();
		vehicle_count++;
		count_out.open("count.txt");
		count_out << customer_count << endl;
		count_out << vehicle_count << endl;
		count_out << driver_count << endl;
		count_out << service_count << endl;
		count_out.close();
		cout << "VEHICLE ADDED!" << endl;
	}

	void displayAllCostumers() {
		cout << "LIST OF ALL CUSTOMERS" << endl;
		cout << endl;
		customer_in.open("customer.txt");
		if (customer_count > 0)
		{
			Customer* C = new Customer[customer_count];
			for (int i = 0; i < customer_count; i++)
			{
				customer_in >> C[i];
				cout << "----CUSTOMER " << i + 1 << "'s Data----" << endl << C[i];
			}
			delete[] C;
			C = nullptr;
		}
		else
			cout << "No Record of Customers Found!" << endl;
		customer_in.close();
	}

	void displayAllDrivers() {
		cout << endl;
		driver_in.open("driver.txt");
		if (driver_count > 0)
		{
			Driver* D = new Driver[driver_count];
			for (int i = 0; i < driver_count; i++)
			{
				driver_in >> D[i];

				cout << "----DRIVER " << i + 1 << "'s Data----" << endl << D[i];
				cout << endl;
			}
			delete[] D;
			D = nullptr;
		}
		else
			cout << "No Record of Drivers Found!" << endl;
		driver_in.close();
	}

	void displayAllVehicles() {
		cout << "LIST OF ALL VEHICLES" << endl;
		cout << endl;
		vehicle_in.open("vehicle.txt");
		if (vehicle_count > 0)
		{
			Vehicle* V = new Vehicle[vehicle_count];
			for (int i = 0; i < vehicle_count; i++)
			{
				vehicle_in >> V[i];

				cout << "----VEHICLE " << i + 1 << "'s Data----" << endl << V[i];
				cout << endl;
			}
			delete[] V;
			V = nullptr;
		}
		else
			cout << "No Record of Vehicle Found!" << endl;
		vehicle_in.close();
	}

	void detailHistoryOfVehicle() {
		cout << "DETAILS AND HISTORY OF VEHICLE" << endl;
		cout << endl;
		cout << "Enter Required Vehicle ID: ";
		cin >> temp;
		vehicle_in.open("vehicle.txt");
		if (vehicle_count > 0)
		{
			Vehicle* V = new Vehicle[vehicle_count];
			for (int i = 0; i < vehicle_count; i++)
			{
				vehicle_in >> V[i];
				if (V[i].getID() == temp)
				{
					found = true;
					cout << V[i];
				}
			}
			cout << endl;
			if (found == false)
				cout << "No Record of Vehicle Found!" << endl;
			delete[] V;
			V = nullptr;
		}
		else
			cout << "No Record of Vehicle Found!" << endl;
		vehicle_in.close();
	}

	void historyOfcostumer() {
		cout << "HISTORY OF A CUSTOMER" << endl;
		cout << endl;
		temp = 0;
		found = false;
		cout << "Enter Customer ID: ";
		cin >> temp;
		customer_in.open("customer.txt");
		if (customer_count > 0)
		{
			Customer* C = new Customer[customer_count];
			for (int i = 0; i < customer_count; i++)
			{
				customer_in >> C[i];
				if (C[i].getcId() == temp)
				{
					found = true;
					cout << C[i];
				}
			}
			cout << endl;
			if (found == false)
				cout << "No Record of Customer Found!" << endl;
			delete[] C;
			C = nullptr;
		}
		else
			cout << "No Record of Customer Found!" << endl;
		customer_in.close();
	}

	void HistoryOfDriver() {
		cout << "HISTORY OF A DRIVER" << endl;
		cout << endl;
		temp = 0;
		found = false;
		cout << "Enter Driver ID: ";
		cin >> temp;
		driver_in.open("driver.txt");
		if (driver_count > 0)
		{
			Driver* D = new Driver[driver_count];
			for (int i = 0; i < driver_count; i++)
			{
				driver_in >> D[i];
				if (D[i].getdId() == temp)
				{
					found = true;
					cout << D[i];
				}
			}
			cout << endl;
			if (found == false)
				cout << "No Record of Driver Found!" << endl;
			delete[] D;
			D = nullptr;
		}
		else
			cout << "No Record of Driver Found!" << endl;
		driver_in.close();
	}

	void driverWithRating() {
		cout << "DRIVERS WITH RANKING 4.5+" << endl;
		cout << endl;

		found = false;
		driver_in.open("driver.txt");
		if (driver_count > 0)
		{
			Driver* D = new Driver[driver_count];
			for (int i = 0; i < driver_count; i++)
			{
				driver_in >> D[i];
				if (D[i].getRanking() >= 4.5)
				{
					found = true;
					cout << D[i];
				}
			}
			cout << endl;
			if (found == false)
				cout << "No Driver with Ranking 4.5 OR Above!!" << endl;
			delete[] D;
			D = nullptr;
		}
		else
			cout << "No Driver with Ranking 4.5 OR Above!!" << endl;
		driver_in.close();
	}

	void driversWithMultipleLiscences() {
		cout << "DRIVERS WITH MULTIPLE LICENCES" << endl;
		cout << endl;

		found = false;
		driver_in.open("driver.txt");
		if (driver_count > 0)
		{
			Driver* D = new Driver[driver_count];
			for (int i = 0; i < driver_count; i++)
			{
				driver_in >> D[i];
				if (D[i].getlicences_count() > 1)
				{
					found = true;
					cout << D[i];
				}
			}
			cout << endl;
			if (found == false)
				cout << "No Driver with Multiple Licences!!" << endl;
			delete[] D;
			D = nullptr;
		}
		else
			cout << "No Driver with Multiple Licences!!" << endl;
		driver_in.close();
	}

	void printSalary(){
		cout << "SALARY OF DRIVERS" << endl;
		cout << endl;
		driver_in.open("driver.txt");
		if (driver_count > 0)
		{
			Driver* D = new Driver[driver_count];
			for (int i = 0; i < driver_count; i++)
			{
				driver_in >> D[i];
				float salry = D[i].getSalary();
				float rate = D[i].getRanking();
				cout << "Ranking of Driver (" << i + 1 << ") : " << rate << endl
					<< "Salary of Driver (" << i + 1 << ") : " << salry << " Rupees" << endl;
				cout << endl;
			}
			delete[] D;
			D = nullptr;
		}
		else
			cout << "No Record of Drivers Found!" << endl;
		driver_in.close();
	}

	void addService(){
		int choice;
		cout << "Enter 1 if you want a delivery service and 2 if you want to ride: ";
		cin >> choice;
		if (choice == 1)
			tempService = new Delivery;
		else if (choice == 2)
			tempService = new Ride;


		cin >> *(tempService);
		service_out.open("service.txt", ios::app);
		service_out << choice << endl;
		service_out << *tempService ;
		service_out.close();

		service_count++;
		count_out.open("count.txt");
		count_out << customer_count << endl;
		count_out << vehicle_count << endl;
		count_out << driver_count << endl;
		count_out << service_count << endl;
		count_out.close();
		delete tempService;
		tempService = nullptr;
	}

	void cancelService() {
		int tempCID, tempDID;
		cout << "Enter the costumer ID who booked: ";
		cin >> tempCID;
		cout << "Enter the driver ID who was booked: ";
		cin >> tempDID;
		Service** tempS= new Service*[service_count];
		int* temparr = new int[service_count];
		service_in.open("service.txt");
		for (int i = 0; i < service_count; i++) {
			service_in >> temparr[i];
			switch (temparr[i]) {
			case 1: tempS[i] = new Delivery;	break;
			case 2: tempS[i] = new Ride;		break;
			}
			service_in >> *(tempS[i]);
			if (tempS[i]->getCID() == tempCID && tempS[i]->getDID() == tempDID)
				tempS[i]->setStatus(2);
		}
		service_in.close();
		service_out.open("service.txt");
		for (int i = 0; i < service_count; i++) {
			service_out << temparr[i] << endl;
			service_out << *(tempS[i]);
		}
		service_out.close();
		for (int i = 0; i < service_count; i++)
			delete tempS[i];
		delete[] tempS;
		delete[] temparr;
	}

	void completeService() {
		int tempCID, tempDID;
		cout << "Enter the costumer ID who booked: ";
		cin >> tempCID;
		cout << "Enter the driver ID who was booked: ";
		cin >> tempDID;
		Service** tempS = new Service * [service_count];
		int* temparr = new int[service_count];
		service_in.open("service.txt");
		for (int i = 0; i < service_count; i++) {
			service_in >> temparr[i];
			switch (temparr[i]) {
			case 1: tempS[i] = new Delivery;	break;
			case 2: tempS[i] = new Ride;		break;
			}
			service_in >> *(tempS[i]);
			if (tempS[i]->getCID() == tempCID && tempS[i]->getDID() == tempDID)
				tempS[i]->setStatus(1);
			if (temparr[i] == 2) {
				cout << "Enter the driver ranking: ";
				cin >> temp;
				dynamic_cast<Ride*>(tempS[i])->setDRanking(temp);
				cout << "Enter the vehicle ranking: ";
				cin >> temp;
				dynamic_cast<Ride*>(tempS[i])->setVRanking(temp);
			}
		}
		service_in.close();
		service_out.open("service.txt");
		for (int i = 0; i < service_count; i++) {
			service_out << temparr[i] << endl;
			service_out << *(tempS[i]) << endl << endl;
		}
		service_out.close();
		for (int i = 0; i < service_count; i++)
			delete tempS[i];
		delete[] tempS;
		delete[] temparr;
	}

	void listOfCostumersWithSameVehicle() {
		int vID;
		cout << "LIST OF ALL CUSTOMERS WHO USE SAME VEHICLE" << endl;
		cout << endl;
		cout << "Enter the vehicle id: ";
		cin >> vID;
		customer_in.open("customer.txt");
		if (customer_count > 0)
		{
			Customer* C = new Customer[customer_count];
			for (int i = 0; i < customer_count; i++)
			{
				customer_in >> C[i];
				Service** s = C[i].getService();
				for (int j = 0; j < C[i].getbookingHistory_counts(); j++) {
					if (s[j]->getVID() == vID)
						cout << C[i];
				}
			}
			delete[] C;
			C = nullptr;
		}
		else
			cout << "No Record of Customers Found!" << endl;
		customer_in.close();
	}

	void pendingServices() {
		int tempDID;
		cout << "Enter the driver ID who was booked: ";
		cin >> tempDID;
		Service** tempS = new Service * [service_count];
		int* temparr = new int[service_count];
		service_in.open("service.txt");
		for (int i = 0; i < service_count; i++) {
			service_in >> temparr[i];
			switch (temparr[i]) {
			case 1: tempS[i] = new Delivery;	break;
			case 2: tempS[i] = new Ride;		break;
			}
			service_in >> *(tempS[i]);
			if (tempS[i]->getStatus() == 0 && tempS[i]->getDID() == tempDID)
				cout << *(tempS[i]);
		}
		service_in.close();
		for (int i = 0; i < service_count; i++)
			delete tempS[i];
		delete[] tempS;
		delete[] temparr;
	}
	void listOfServicesOnDate() {
		cout << "LIST OF ALL SERVICES ON THE PARTICULAR DATE" << endl;
		cout << endl;
		cout << "Enter the Booking date ";
		cin >> date;
		customer_in.open("customer.txt");
		if (customer_count > 0)
		{
			Customer* C = new Customer[customer_count];
			for (int i = 0; i < customer_count; i++)
			{
				customer_in >> C[i];
				Service** s = C[i].getService();
				for (int j = 0; j < C[i].getbookingHistory_counts(); j++) {
					if (s[j]->getDate() == date)
						cout << "Service # " << (tempCount)++ << endl << *(s[j]) << endl;
				}
			}
			if (tempCount == 1)
				cout << "No record found\n";
			tempCount = 1;
			delete[] C;
			C = nullptr;
		}
		else
			cout << "No Record of Customers Found!" << endl;
		customer_in.close();
	}
};