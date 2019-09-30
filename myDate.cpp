#include "myDate.h"
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
// Did it in one line based on the second page.  Might have issues with copysign at 0 but the paper didnt specify how their sign function behaved at 0 so I believe it is still to you spec.
int Greg2Julian(int month, int day, int year) {
    return (367*year)-trunc((7*(year+trunc(((month+9)/12))))/4)+trunc((275*month)/9)+day+1721013.5-(0.5*copysign(1,100*year+month-190002.5))+0.5+1;
}
void Julian2Greg(int JD, int & month, int & day, int & year){
    int i,j,k,l,n;

    //Copying straight out of the fortan implementation hoping that they do Order of Operations the same as c.
    //Seems like they do.
    l = JD + 68569;
    n = 4*l/146097;
    l = l -(146097*n+3)/4;
    i = 4000 * (l+1)/1461001;
    l = l-1461*i/4+31;
    j = 80*l/2447;
    k = l-2447*j/80;
    l = j/11;
    j = j+2-12*l;
    i = 100 * (n-49) + i + l;
    
    
    year = i;
    month = j;
    day = k;
}


myDate::myDate() {
	year = 1959;
	month = 5;
	day = 10;
}
myDate::myDate(int M,int D,int Y): day(D),month(M),year(Y){
    if(year<1801||year>2099){
        // month = 5;
        // day = 10;
        // year = 1959;
        myDate();
    }else if(day<1||day>31){
        myDate();
    }else if(month<1||month>12){
        myDate();
    }
}
        
void myDate::display(){
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
	cout << " " << to_string(day) << ", " << to_string(year) << ")";
}
void myDate::increaseDate(int N){
    int julian = Greg2Julian(month,day,year);
    julian += N;
    Julian2Greg(julian,month,day,year);

            
}
void myDate::decreaseDate(int N){
    int julian = Greg2Julian(month,day,year);
    julian -= N;
    Julian2Greg(julian,month,day,year);

            
}
int myDate::daysBetween(myDate D){
    return Greg2Julian(D.getMonth(),D.getDay(),D.getYear()) - Greg2Julian(day,month,year);
}
int myDate::getMonth(){
    return month;
}
int myDate::getDay(){
    return day;
}
int myDate::getYear(){
    return year;
}
int myDate::dayOfYear(){
    return Greg2Julian(day,month,year) - Greg2Julian(1,1,year);
}
        
string myDate::dayName(){
    // Kinda tricky we just get the offset of today and the date we are inspecting
    // Then we get that mod 7 and then set the day according to that.
    // It's easy to see how it works for values around today, ie yesterday will be
    // 9/29/2019 and our offset will = -1.
    // -1 mod 7 = 6 which is sunday in our switch so that works.
    // and the other days around are even easier then the previous example.
    int offset = (Greg2Julian(9,30,2019) - Greg2Julian(day,month,year));
    switch(offset % 7){
        case 0:
            return "Monday";
				
        case 1:
            return "Tuesday";
				
        case 2:
            return "Wednsesday";
				
        case 3:
            return "Thursday";
				
        case 4:
            return "Friday";
				
        case 5:
            return "Saturday";
        case 6:
            return "Sunday";
		default:
			return "ERROR IN DAYNAME";
				
    }

}






