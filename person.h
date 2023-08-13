#pragma once
#include<iostream>
#include <fstream>
#include"name.h"
#include"date.h"
using namespace std;

class Person {
private:
	Name pName;
	Date DOB;
	int Age;
	int Nid;
public:
	Person();  //default constructor
	Person(char*, char*, int, int, int, int, int);  //parametrized constructor
	Person(Name& pname, Date& dob, int& age, int& Nid);
	Person(const Person&);  //copy constructor
	//getters
	char* getfName();
	char* getlName();
	int getDay();
	int getMonth();
	int getYear();
	int getAge();
	int getID();
	//setters
	void setName(char*, char*);
	void setfName(char*);
	void setlName(char*);
	void setDOB(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setAge(int);
	void setID(int);

	virtual void fileIn(ifstream& in) {
		in >> pName >> DOB >> Age >> Nid;
	}

	//output operator
	friend ostream& operator<<(ostream&, Person&);
	friend istream& operator >> (istream& in, Person& p);
	friend ofstream& operator <<(ofstream&, Person&);
	friend ifstream& operator >> (ifstream& in, Person& p);

};


//Constructors
Person::Person() : pName(), DOB()
{
	Age = 0;
	Nid = 0;
}

Person::Person(char* fN, char* lN, int day, int month, int year, int age, int id) :
	pName(fN, lN), DOB(day, month, year)
{
	Age = age;
	Nid = id;
}

Person::Person(Name& pname, Date& dob, int& age, int& Nid) {
	this->pName = pname;
	this->DOB = dob;
	this->Age = age;
	this->Nid = Nid;
}

Person::Person(const Person& obj) : pName(obj.pName), DOB(obj.DOB)
{
	Age = obj.Age;
	Nid = obj.Nid;
}
//Getters
char* Person::getfName()
{
	return pName.getfName();
}

char* Person::getlName()
{
	return pName.getlName();
}

int Person::getDay()
{
	return DOB.getDay();
}

int Person::getMonth()
{
	return DOB.getMonth();
}

int Person::getYear()
{
	return DOB.getYear();
}

int Person::getAge()
{
	return Age;
}

int Person::getID()
{
	return Nid;
}
//Setters
void Person::setName(char* fN, char* lN)
{
	pName.setfName(fN);
	pName.setlName(lN);
}

void Person::setfName(char* fN)
{
	pName.setfName(fN);
}

void Person::setlName(char* lN)
{
	pName.setlName(lN);
}

void Person::setDOB(int d, int m, int y)
{
	DOB.setDay(d);
	DOB.setMonth(m);
	DOB.setYear(y);
}

void Person::setDay(int d)
{
	DOB.setDay(d);
}

void Person::setMonth(int m)
{
	DOB.setMonth(m);
}

void Person::setYear(int y)
{
	DOB.setYear(y);
}

void Person::setAge(int age)
{
	Age = age;
}

void Person::setID(int id)
{
	Nid = id;
}

ostream& operator<<(ostream& out, Person& p)
{

	out << "Name: " << p.pName << endl
		<< "DOB: " << p.DOB << endl
		<< "Age: " << p.Age <<" Years"<< endl
		<< "ID: " << p.Nid << endl;
	return out;
}

inline istream& operator>>(istream& in, Person& p)
{
	in >> p.pName;
	in >> p.DOB;
	cout << "Enter age: ";
	in >> p.Age;
	cout << "Enter Nid: ";
	in >> p.Nid;
	return in;
}

inline ofstream& operator<<(ofstream& out, Person& p)
{
	out << p.pName
		<< p.DOB
		<< p.Age << endl
		<< p.Nid << endl;
	return out;
}

inline ifstream& operator>>(ifstream& in, Person& p)
{
	p.fileIn(in);
	return in;
}