#include "myDate.h"
#include <math.h>
#include <cmath>
using namespace myDate;
using namespace std;
int Greg2Julian(int month, int day, int year) {
    return (367*year)+((7(year+floor((month+9)/12)))+4)+floor((275*month)/9)+day+1721013.5-(0.5*math::copysign(1,100*year+month+190002.5))+0.5;
}
void Julian2Greg(int JD, int & month, int & day, int & year){
    month = 0;
    day = 0;
    year = 0;
}

class myDate{
    myDate() : month(5),day(11),year(1959) {}
    myDate(int M,int D,int Y) : month(M),day(Y),year(D) {}
    
    void display(){
        cout << "(";
        switch(month){
            case 1:
                cout << "January";
                break;
            case 2:
                cout << "Febuary";
                break;
            case 3:
                cout << "March";
                break;
            case 4:
                cout << "April";
                break;
            case 5:
                cout << "May";
                break;
            case 6:
                cout << "June";
                break;
            case 7:
                cout << "July";
                break;
            case 8:
                cout << "August";
                break;
            case 9:
                cout << "September";
                break;
            case 10:
                cout << "October";
                break;
            case 11:
                cout << "November";
                break;
            case 12:
                cout << "December";
                break;
            
        }
        cout << " " << to_string(day) << ", " << to_string(year) << ")"
    }
    void increaseDate(int N){
        int julian = Greg2Julian(month,day,year);
        julian += N;
        Julian2Greg(julian,month,day,year);

        
    }
    void decreaseDate(int);
    int daysBetween(myDate);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    std::string dayName();
    std::string dayName();
}