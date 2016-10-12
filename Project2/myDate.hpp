//
//  myDate.hpp
//  Project2
//
//  Created by Alex Berthon on 9/26/16.
//  Copyright © 2016 Alex Berthon. All rights reserved.
//

#ifndef myDate_hpp
#define myDate_hpp

#include <stdio.h>
class myDate {
public:
    myDate();
    /*
     preconditions: none
     postconditions: creates an object myDate
     */
    myDate(int m, int d, int y);
    /*
     preconditions: none
     postconditions: creats an object myDate with given parameters
     */
    void display(char a[]);
    /*
     preconditions: none
     postconditions: displays the character array
     */
    void incrDate(int n);
    /*
     preconditions: none
     postconditions: increments the date
     */
    void decrDate(int n);
    /*
     preconditions: none
     postconditions: decrements the date
     */
    int daysBetween(myDate d);
    /*
     preconditions: none
     postconditions: returns the number of days between two dates
     */
    int getMonth();
    /*
     preconditions: none
     postconditions: returns the month
     */
    int getDay();
    /*
     preconditions: none
     postconditions: returns the day
     */
    int getYear();
    /*
     preconditions: none
     postconditions: returns the year
     */
    int getYearOffset();
    /*
     preconditions: none
     postconditions: 
     */
    void setDay(int d);
    /*
     preconditions: none
     postconditions: sets the day to given arguments
     */
    int sign(int x);
    /*
     preconditions: none
     postconditions: calculates positive or negative value
     */
    void convertToGregorian(int x);
    /*
     preconditions: 
     postconditions:
     */
   static int daysInMonth(int m, int y);
    /*
     preconditions:
     postconditions:
     */
    bool operator==(const myDate &a);
    bool operator!=(const myDate &a);
    bool operator<(const myDate &a);
    bool operator>(const myDate &a);
    bool operator<=(const myDate &a);
    bool operator>=(const myDate &a);
    
    
private:
    int day;
    int month;
    int year;
    int JD;
};

#endif /* myDate_hpp */
