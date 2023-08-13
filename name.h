#pragma once
#include<iostream>
using namespace std;

class Name {
private:
	char* fName;
	char* lName;
public:
	//Constructors
	Name()
	{
		fName = nullptr;
		lName = nullptr;
	}
	Name(const char* fN, const char* lN)
	{
		fName = new char[strlen(fN) + 1];
		strcpy(fName, fN);
		lName = new char[strlen(lN) + 1];
		strcpy(lName, lN);
	}
	Name(const Name& obj)
	{
		if (obj.fName != nullptr && obj.lName != nullptr)
		{
			fName = new char[strlen(obj.fName) + 1];
			strcpy(fName, obj.fName);
			lName = new char[strlen(obj.lName) + 1];
			strcpy(lName, obj.lName);
		}
		else if (obj.fName == nullptr && obj.lName != nullptr)
		{
			fName = nullptr;
			lName = new char[strlen(obj.lName) + 1];
			strcpy(lName, obj.lName);
		}
		else if (obj.fName != nullptr && obj.lName == nullptr)
		{
			fName = new char[strlen(obj.fName) + 1];
			strcpy(fName, obj.fName);
			lName = nullptr;
		}
		else
		{
			fName = nullptr;
			lName = nullptr;
		}
	}
	//Setters
	void setfName(const char* name)
	{
		if (fName != nullptr)
		{
			delete fName;
			fName = nullptr;
			fName = new char[strlen(name) + 1];
			strcpy(fName, name);
		}
		else
		{
			fName = new char[strlen(name) + 1];
			strcpy(fName, name);
		}
	}
	void setlName(const char* name)
	{
		if (fName != nullptr)
		{
			delete lName;
			lName = nullptr;
			lName = new char[strlen(name) + 1];
			strcpy(lName, name);
		}
		else
		{
			lName = new char[strlen(name) + 1];
			strcpy(lName, name);
		}
	}
	//Getters
	char* getfName()
	{
		return fName;
	}
	char* getlName()
	{
		return lName;
	}
	//Destructor
	~Name()
	{
		delete fName;
		delete lName;
		fName = nullptr;
		lName = nullptr;
	}

	Name& operator = (const Name& n) {
		if (fName != nullptr) {
			delete fName;
			fName = nullptr;
		}
		if (lName != nullptr) {
			delete lName;
			lName = nullptr;
		}
		fName = new char[strlen(n.fName) + 1];
		lName = new char[strlen(n.lName) + 1];
		strcpy(this->fName, n.fName);
		strcpy(this->lName, n.lName);
		return *this;
	}
	//Name output
	friend ostream& operator<<(ostream& out, Name& n) {
		out << n.fName << " " << n.lName;
		return out;
	}

	friend istream& operator >> (istream& in, Name& n) {
		if (n.fName != nullptr)
			delete n.fName;
		if (n.lName != nullptr)
			delete n.lName;

		n.fName = new char[100];
		n.lName = new char[100];
		in.ignore();
		cout << "Enter First Name: ";
		in.getline(n.fName, 100);
		cout << "Enter Last Name: ";
		in.getline(n.lName, 100);
		return in;
	}
	friend ofstream& operator<<(ofstream& out, Name& n) {
		out << n.fName << " " << n.lName << endl;
		return out;
	}
	friend ifstream& operator >> (ifstream& in, Name& n) {
		if (n.fName != nullptr)
			delete n.fName;
		if (n.lName != nullptr)
			delete n.lName;
		n.fName = new char[100];
		n.lName = new char[100];
		in >> n.fName;
		in >> n.lName;

		return in;
	}



};
