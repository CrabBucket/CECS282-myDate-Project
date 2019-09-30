#ifndef MYDATE_H
#define MYDATE_H
#include <string>
 
class myDate {
private:
	int month;
	int day;
	int year;
public:
	myDate();
	myDate(int, int, int);
	void display();
	void increaseDate(int);
	void decreaseDate(int);
	int daysBetween(myDate);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	std::string dayName();
};




#endif