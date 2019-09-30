#include "myDate.h"
#include <iostream>
#include <string>
using namespace std;


int main(){
    myDate today(9,30,2019);
    myDate nextMonth(10,30,2019);
    nextMonth.increaseDate(500);
    cout << today.daysBetween(nextMonth);
    
    
    
    
    
    return 0;
}