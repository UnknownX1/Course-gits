#include <iostream>
#include <string>
using namespace std;

class Date {
protected:
	int year, month, day;
};

class Time{
protected:
	int hour, minute, second;
};

class Schedule : public Date, public Time {
protected:
	int ID;
public:
	friend bool before(const Schedule& s1, const Schedule& s2);
};

bool before(const Schedule& s1, const Schedule& s2) {
	return 
}