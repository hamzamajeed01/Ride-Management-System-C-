#pragma once
#include<iostream>
#include <fstream>
using namespace std;

class mTime
{
    int hour;
    int min;
    int sec;
public:
    //Constructors
    mTime()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }
    mTime(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }
    mTime(mTime& obj)
    {
        this->hour = obj.hour;
        this->min = obj.min;
        this->sec = obj.sec;
    }
    //Getters
    int getHour()
    {
        return hour;
    }
    int getMin()
    {
        return min;
    }
    int getSec()
    {
        return sec;
    }
    //Setters
    void setHour(int h)
    {
        hour = h;
    }
    void setMin(int m)
    {
        min = m;
    }
    void setSec(int s)
    {
        sec = s;
    }
    mTime& operator = (const mTime& t) {
        this->hour = t.hour;
        this->min = t.min;
        this->sec = t.sec;
        return *this;
    }

    //Time Output
    friend ostream& operator <<(ostream& out, mTime& n) {
        out << n.hour << ":" << n.min << ":" << n.sec << endl;
        return out;
    }

    friend istream& operator >> (istream& in, mTime& n) {

        cout << "Enter the hour: ";
        in >> n.hour;

        cout << "Enter the minute: ";
        in >> n.min;

        cout << "Enter the second: ";
        in >>n.sec;
        return in;
    }

    friend ofstream& operator << (ofstream& out, mTime& n) {
        out << n.hour << ' ' << n.min << ' ' << n.sec << endl;
        return out;
    }

    friend ifstream& operator >> (ifstream& in, mTime& n) {
        in >> n.hour >> n.min >> n.sec;
        return in;
    }

};
