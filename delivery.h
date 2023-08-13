#pragma once
#include<iostream>
#include<fstream>
#include"service.h"
using namespace std;

class Delivery : public Service 
{
private:
	float goodsWeight; // Weight of goods in Kg 
	char * goodsType; //type of goods food, furniture, petroleum, chemicals, etc. 
	//you can add more members here if required //add member functions 
public:
	Delivery();
	Delivery(float, char*);
	Delivery(const Delivery&);
	~Delivery();
	void setWeigt(float);
	void setType(char*);
	float getWeigt();
	char* getType();

	virtual void userInput(istream& in) {
		Service::userInput(in);
		cout << "Enter Weight: ";
		in >> goodsWeight;
		in.ignore();
		char* temp = new char[1000];
		cout << "Enter Good Type: ";
		in.getline(temp, 1000);
		setType(temp);
		delete[] temp;
	}
	virtual void userOutput(ostream& out) {
		out << "Service Type: Delivery\n";
		Service::userOutput(out);
		out << "Good Weight: " << goodsWeight << endl
			<< "Good Type: " << goodsWeight << endl;
	}
	virtual void fileInput(ifstream& in) {
		Service::fileInput(in);
		in >> goodsWeight;
		char* temp = new char[1000];
		in.getline(temp, 1000,'\n');
		setType(temp);
	}
	virtual void fileOutput(ofstream& out) {
		Service::fileOutput(out);
		out << goodsWeight << endl;
		out << goodsType;
	}

	friend ostream& operator<<(ostream& out, Delivery& r)
	{
		r.userOutput(out);
		return out;
	}
	friend istream& operator>>(istream& in, Delivery& obj)
	{
		obj.userInput(in);
		return in;
	}
	friend ofstream& operator<<(ofstream& out, Delivery& r)
	{
		r.fileOutput(out);
		return out;
	}
	friend ifstream& operator>>(ifstream& in, Delivery& r)
	{
		r.fileInput(in);
		return in;
	}
};


Delivery::Delivery()
{
	goodsWeight = 0;
	goodsType = nullptr;
}

Delivery::Delivery(float weight, char* type)
{
	goodsType = new char[strlen(type) + 1];
	strcpy(goodsType, type);
	goodsWeight = weight;
}

Delivery::Delivery(const Delivery& d)
{
	goodsWeight = d.goodsWeight;
	if (d.goodsType != nullptr)
	{
		goodsType = new char[strlen(d.goodsType) + 1];
		strcpy(goodsType, d.goodsType);
	}
	else
		goodsType = nullptr;
}

Delivery::~Delivery()
{
	delete goodsType;
	goodsType = nullptr;
}

void Delivery::setWeigt(float weight)
{
	goodsWeight = weight;
}

void Delivery::setType(char* type)
{
	if (goodsType != nullptr)
	{
		delete goodsType;
		goodsType = new char[strlen(type) + 1];
		strcpy(goodsType, type);
	}
	else
	{
		goodsType = new char[strlen(type) + 1];
		strcpy(goodsType, type);
	}
}

float Delivery::getWeigt()
{
	return goodsWeight;
}

char* Delivery::getType()
{
	return goodsType;
}

