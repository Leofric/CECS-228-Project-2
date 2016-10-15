//
//  myDate.cpp
//  Project2
//
//  Created by Alex Berthon on 9/26/16.
//  Copyright © 2016 Alex Berthon. All rights reserved.
//

#include "myDate.hpp"
#include <iostream>
#include <cstring>

//default constructor, sets date to 5/11/1959
myDate::myDate(){
    month = 5;
    day = 11;
    year = 1959;
    JD = 367*year - (7*(year+(month+9)/12))/4 + (275*month)/9 + day + 1721013.5 - 0.5*sign(100*year+month-190002.5) + 0.5;
}

//overloaded constructor, sets date to arguments if valid, else sets to default, 5/11/1959
myDate::myDate(int m, int d, int y){
    if (m<1 || m>12 || d<1 || d>31 || y<1 || y>2099 || y<1801 || d>daysInMonth(m,y)){
        month = 5;
        day = 11;
        year = 1959;
    }
    else{
        month = m;
        day = d;
        year = y;
        JD = 367*y-(7*(y+(m+9)/12))/4 + (275*m)/9 + d + 1721013.5 - 0.5*sign(100*y+m-190002.5) + 0.5;
    }
}

//edited display fucntion, to work with student/cstring object for project 3
void myDate::display(char a[]){
    char f[20];
    switch (month) {
        case 1:
            strcpy(f,"January");
            break;
        case 2:
            strcpy(f,"Febuary");
            break;
        case 3:
            strcpy(f,"March");
            break;
        case 4:
            strcpy(f,"April");
            break;
        case 5:
            strcpy(f,"May");
            break;
        case 6:
            strcpy(f,"June");
            break;
        case 7:
            strcpy(f,"July");
            break;
        case 8:
            strcpy(f,"August");
            break;
        case 9:
            strcpy(f,"September");
            break;
        case 10:
            strcpy(f,"October");
            break;
        case 11:
            strcpy(f,"November");
            break;
        case 12:
            strcpy(f,"December");
            break;
    }
    char day[15];
    sprintf(day, " %d, %d", this->day, year);
    strcat(f , day);
    strcpy(a, f);
}

//Original display function to work with project 2
void myDate::displayReg(){
    std::string print;
    switch (month) {
        case 1:
            print = "January";
            break;
        case 2:
            print = "Febuary";
            break;
        case 3:
            print = "March";
            break;
        case 4:
            print = "April";
            break;
        case 5:
            print = "May";
            break;
        case 6:
            print = "June";
            break;
        case 7:
            print = "July";
            break;
        case 8:
            print = "August";
            break;
        case 9:
            print = "September";
            break;
        case 10:
            print = "October";
            break;
        case 11:
            print = "November";
            break;
        case 12:
            print = "December";
            break;
    }
    std::cout<<print<<" "<<day<<", "<<year<<std::endl;
}


//changes the date by +n number of days
void myDate::incrDate(int n){
    if(n<0){
        std::cout<<"Invalid input, please enter a positive int value"<<std::endl;
    }
    else{
        JD = JD + n;
        convertToGregorian(JD);
    }
}

//changes the date by -n number of days
void myDate::decrDate(int n){
    if(n<0){
        std::cout<<"Invalid input, please enter a positive int value"<<std::endl;
    }
    else{
        JD = JD - n;
        convertToGregorian(JD);
    }
}


//calculates the number of days between the given date and the current date
int myDate::daysBetween(myDate d){
    int inputDate = 367*d.getYear()-(7*(d.getYear()+(d.getMonth()+9)/12))/4 + (275*d.getMonth())/9 + d.getDay() + 1721013.5 - 0.5*sign(100*d.getYear()+d.getMonth()-190002.5) + 0.5;
    
    return inputDate - JD;

}

int myDate::getMonth() {
    return month;
}
int myDate::getDay() {
    return day;
}
int myDate::getYear() {
    return year;
}

void myDate::setDay(int d){
    day = d;
}

//returns the number of days since the start of the year
int myDate::getYearOffset(){
    myDate d(1,1,year);
    return daysBetween(d);
}

//used in the Julian date formula
int myDate::sign(int x){
    int sign = 1;
    if(x<0){
        sign = -1;
    }
    return sign;
}

//used to convert Julian date to calendar date
void myDate::convertToGregorian(int x){
    int l, n, i, j, k;
    l= x+68569;
    n= 4*l/146097;
    l= l-(146097*n+3)/4;
    i= 4000*(l+1)/1461001;
    l= l-1461*i/4+31;
    j= 80*l/2447;
    k= l-2447*j/80;
    l= j/11;
    j= j+2-12*l;
    i= 100*(n-49)+i+l;
    
    month = j;
    day = k+1;
    year = i;
}

int myDate::daysInMonth(int m, int y){
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            if(y % 4 != 0){
                return 28;
            }
            else if(y % 400 == 0){
                return 29;
            }
            else if(y % 100 == 0){
                return 28;
            }
            else return 29;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 0;
    }
}
    bool myDate::operator ==(const myDate& a)
    {
        if(this->daysBetween(a)==0){
            return true;
        }
        else return false;
    }
    
    bool myDate::operator !=(const myDate& a)
    {
        if(this->daysBetween(a)!=0){
            return true;
        }
        else return false;
    }
    
    bool myDate::operator <(const myDate& a)
    {
        if(this->daysBetween(a)<0){
            return true;
        }
        else return false;
    }
    
    bool myDate::operator >(const myDate& a)
    {
        if(this->daysBetween(a)>0){
            return true;
        }
        else return false;
    }
    
    bool myDate::operator >=(const myDate& a)
    {
        if(this->daysBetween(a)<=0){
            return true;
        }
        else return false;
    }
    
    bool myDate::operator <=(const myDate& a)
    {
        if(this->daysBetween(a)>=0){
            return true;
        }
        else return false;
    }
