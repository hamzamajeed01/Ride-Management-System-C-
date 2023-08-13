#pragma once
#include "person.h"
#include "service.h"
using namespace std;

class Customer : public Person {
private:
	int cId; // Unique and assigned first time when customer makes first service request 
	Service **bookingHistory; //Maintain and Update history of customer for each service (ride or goods transportation order) by adding address of service in dynamic array.
	int bookingHistoryCount;
public:
	Customer() {
		cId = 0;
		bookingHistoryCount = 0;
		bookingHistory = nullptr;
	}

	Service** getService()
	{
		return bookingHistory;
	}

	int getbookingHistory_counts()
	{
		return bookingHistoryCount;
	}

	Customer(char* fN, char* lN, int day, int month, int year, int age, int id, int cId) :Person(fN, lN, day, month, year, age, id) {
		this->cId = cId;
		bookingHistory = nullptr;
		bookingHistoryCount = 0;
	}

	Customer(const Customer& c) :Person(c) {
		this->cId = c.cId;
		this->bookingHistoryCount = c.bookingHistoryCount;
		this->bookingHistory = new Service * [bookingHistoryCount];
		for (int i = 0; i < bookingHistoryCount - 1; i++) {
			this->bookingHistory[i] = new Service;
			*(this->bookingHistory[i]) = *(c.bookingHistory[i]);
		}
	}

	~Customer() {
		for (int i = 0; i < bookingHistoryCount; i++)
			delete bookingHistory[i];
		delete[] bookingHistory;
	}

	void setcId(int cId) {
		this->cId = cId;
	}

	int getcId() {
		return this->cId;
	}

	void addService(Service& s) {
		bookingHistoryCount++;
		Service** temp = new Service * [bookingHistoryCount];
		for (int i = 0; i < bookingHistoryCount - 1; i++) {
			temp[i] = new Service;
			*(temp[i]) = *(bookingHistory[i]);
			delete bookingHistory[i];
		}
		*(temp[bookingHistoryCount - 1]) = s;
		delete[] bookingHistory;
		bookingHistory = temp;
	}

	void fileIn(ifstream& in) {
		Person::fileIn(in);
		in >> cId;
		in >> bookingHistoryCount;
		if (bookingHistory != nullptr) {
			for (int i = 0; i < bookingHistoryCount; i++)
				delete bookingHistory[i];
			delete[] bookingHistory;
			bookingHistory = nullptr;
		}
		if (bookingHistoryCount > 0)
			bookingHistory = new Service * [bookingHistoryCount];
		for (int i = 0; i < bookingHistoryCount; i++) {
			bookingHistory[i] = new Service;
			in >> *(bookingHistory[i]);
		}
	}

	friend ostream& operator << (ostream& out, Customer& c) {
		Person p = static_cast<Person&>(c);
		out << p;
		out << "Customer ID: " << c.cId << endl
			<< "Booking History \n";
		if (c.bookingHistoryCount == 0)
			out << "No record\n";
		for (int i = 0; i < c.bookingHistoryCount; i++)
			out << "--Record " << i + 1 << "-- \n" << *(c.bookingHistory[i]) << endl;
		return out;
	}

	friend istream& operator >> (istream& in, Customer& c) {
		in >> (Person&)c;
		in.ignore();
		cout << "Enter customer ID: ";
		in >> c.cId;
		cout << "How many Booking history entries do you want to enter: ";

		if (c.bookingHistory != nullptr) {
			for (int i = 0; i < c.bookingHistoryCount; i++)
				delete c.bookingHistory[i];
			delete c.bookingHistory;
		}
		in >> c.bookingHistoryCount;
		c.bookingHistory = new Service * [c.bookingHistoryCount];
		for (int i = 0; i < c.bookingHistoryCount; i++) {
			c.bookingHistory[i] = new Service;
			in >> *(c.bookingHistory[i]);
		}
		return in;
	}

	friend ofstream& operator << (ofstream& out, Customer& c) {
		Person p = static_cast<Person&>(c);
		out << p;
		out << c.cId << endl;
		out << c.bookingHistoryCount << endl;
		for (int i = 0; i < c.bookingHistoryCount; i++)
			out << *(c.bookingHistory[i]) << endl;
		return out;
	}

	friend ifstream& operator >> (ifstream& in, Customer& c) {
		c.fileIn(in);
		return in;
	}
};