#pragma once
#include<iostream>
#include <fstream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	//Constructors
	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date(const Date& obj)
	{
		this->day = obj.day;
		this->month = obj.month;
		this->year = obj.year;
	}
	Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	//Getters
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
	//Setters
	void setDay(int d)
	{
		day = d;
	}
	void setMonth(int m)
	{
		month = m;
	}
	void setYear(int y)
	{
		year = y;
	}
	Date& operator = (const Date& d) {
		this->day = d.day;
		this->month = d.month;
		this->year = d.year;
		return *this;
	}
	bool operator == (const Date& d) {
		if (this->day == d.day && this->month == d.month && this->year == d.year)
			return true;
		return false;
	}

	//Date Output
	friend ostream& operator <<(ostream& out, Date& n) {
		out << n.day << '/' << n.month << '/' << n.year;
		return out;
	}


	friend istream& operator >> (istream& in, Date& d) {
		int temp = 0;
		cout << "Enter the date: ";
		in >> d.day;

		cout << "Enter the Month: ";
		in >> d.month;

		cout << "Enter the Year: ";
		in >> d.year;
		return in;
	}
	friend ofstream& operator <<(ofstream& out, Date& n) {
		out << n.day << ' ' << n.month << ' ' << n.year << endl;
		return out;
	}
	friend ifstream& operator >> (ifstream& in, Date& d) {
		in >> d.day;
		in >> d.month;
		in >> d.year;
		return in;
	}
};
