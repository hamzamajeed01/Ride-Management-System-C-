#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class Feature {
private:
	int fId; 
	char* description; 
	float cost; 
	//you can add more members here if required 
	//add member functions 
public:
	Feature();
	Feature(int, char*, float);
	Feature(Feature&);
	void setID(int);
	void setDescription(char*);
	void setCost(float);
	int getID();
	char* getDescription();
	float getCost();
	~Feature();
	friend ostream& operator<<(ostream&, Feature&);
	friend istream& operator>>(istream& in, Feature& obj)
	{
		cout << "Enter Feature ID: ";
		in >> obj.fId;
		cout << "Enter Cost: ";
		in >> obj.cost;
		cout << "Enter Description: ";
		char* temp = new char[1000];
		in.ignore();
		in.getline(temp, 1000);
		if (obj.description != nullptr)
			delete[] obj.description;

		obj.description = new char[strlen(temp) + 1];
		strcpy(obj.description, temp);
		delete[] temp;
		return in;
	}
	friend ifstream& operator>>(ifstream&, Feature&);
	friend ofstream& operator<<(ofstream&, Feature&);
	Feature& operator=(const Feature&);
};


Feature::Feature()
{
	fId = 0;
	cost = 0;
	description = nullptr;
}

Feature::Feature(int id, char* desc, float cost)
{
	this->cost = cost;
	fId = id;
	description = new char[strlen(desc) + 1];
	strcpy(description, desc);
}

Feature::Feature(Feature& f)
{
	fId = f.fId;
	cost = f.cost;
	if (f.description != nullptr)
	{
		this->description = new char[strlen(f.description) + 1];
		strcpy(this->description, f.description);
	}
	else
		this->description = nullptr;
}

void Feature::setID(int id)
{
	fId = id;
}

void Feature::setDescription(char* desc)
{
	if (description != nullptr)
	{
		delete [] description;
		description = nullptr;
		description = new char[strlen(desc) + 1];
		strcpy(description, desc);
	}
	else
	{
		delete[] description;
		description = nullptr;
	}
}

void Feature::setCost(float cost)
{
	this->cost = cost;
}

int Feature::getID()
{
	return fId;
}

char* Feature::getDescription()
{
	return description;
}

float Feature::getCost()
{
	return cost;
}

Feature::~Feature()
{
	delete description;
	description = nullptr;
}

Feature& Feature::operator=(const Feature& obj)
{
	this->fId = obj.fId;
	this->cost = obj.cost;
	if (this->description != nullptr && obj.description != nullptr)
	{
		delete this->description;
		this->description = new char[strlen(obj.description) + 1];
		strcpy(this->description, obj.description);
	}
	else if (this->description != nullptr && obj.description == nullptr)
	{
		delete this->description;
		description = nullptr;
	}
	else if (this->description == nullptr && obj.description != nullptr)
	{
		this->description = new char[strlen(obj.description) + 1];
		strcpy(this->description, obj.description);
	}
	return *this;
}

ostream& operator<<(ostream& out, Feature& obj)
{
	out << "Feature ID: " << obj.fId << endl
		<< "Cost: " << obj.cost << endl
		<< "Description: " << obj.description;
	return out;
}

inline ifstream& operator>>(ifstream& in, Feature& obj)
{
	in >> obj.fId;
	in >> obj.cost;
	in.ignore();
	obj.description = new char[100];
	in.getline(obj.description, 100, '\n');
	return in;
}

inline ofstream& operator<<(ofstream& out, Feature& obj)
{
	out << obj.fId << endl;
	out << obj.cost << endl;
	out << obj.description << endl;
	return out;
}
