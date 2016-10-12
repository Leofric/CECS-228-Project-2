    //============================================================================
    // Name        : ADT-demo.cpp
    // Author      : huberthuynh
    // Version     :
    // Copyright   : common creative - attribute
    // Description : Hello World in C++, Ansi-style
    //============================================================================
    
#include <iostream>
#include "myDate.hpp"
    using namespace std;
    
    void testDefaultDate();
    void testOverloadedConstructor();
    void testIncrDecr();
    void testDaysInBetween();
    void testGetFunctions();
    void testYearOffset();
    void testBadDates();
    
    int main() {
        
        //*****test default date
        testDefaultDate();
        
        // Test try to construct with illegal date
        testOverloadedConstructor();
        
        // Test incDate and decDate
        testIncrDecr();
        
        // Test get methods
        testGetFunctions();
        
        // Test daysInBetween method
        testDaysInBetween();
        
        // Test yearOffset method
        testYearOffset();
        
        // test overload constructor again bad day, month or year
        testBadDates();
        
        return 0;
    }
    
    void testDefaultDate() {
        myDate testDate;
        cout << "\n****** Testing default constructor ********" << endl;
        cout << "The Date should display May 11, 1959 -> ";
        testDate.display();
        cout << " - is it?\n\n";
    }
    
    void testOverloadedConstructor() {
        myDate testDate = myDate( 2, 29, 2016);// ñ overloaded constructor. This will set the date to the values
								//passed in through the parameter list represented by Month, Day and Year.
        cout << "\n****** Testing overloaded constructor ********" << endl;
        cout << "The Date should display February 29, 2016 -> ";
        testDate.display(); cout << " - is it?\n\n";
        
        testDate= myDate( 2, 29, 2015);
        cout << "The Date should display May 11, 1959 -> ";
        testDate.display(); cout << " - is it?\n\n";
        
    }
    
    
    void testIncrDecr() {
        myDate testDate(2, 29, 2016);
        testDate.decrDate( (365 * 4 + 1) ); // go back 4 years
        
        cout << "\n****** Testing increment and decrement method ********" << endl;
        cout << "The Date should display February 29, 2012 -> ";
        testDate.display(); cout << " - is it?\n\n";
        
        testDate.incrDate(365);
        testDate.incrDate(371);
        testDate.incrDate(360);
        testDate.incrDate(365);
        
        
        cout << "The Date should display February 29, 2016 -> ";
        testDate.display(); cout << " - is it?\n\n";
        
    }
    
    void testDaysInBetween() {
        myDate testDate(2,29, 2008), testDate2(2,29, 2012);
        
        cout << "\n****** Testing daysInBetween ********" << endl;
        cout << "The number of day should display " << (365*4+1);
        
        cout << " -> ";
        cout << testDate.daysBetween(testDate2);
        cout << " - is it?\n\n";
    }
    
    void testGetFunctions() {
        myDate testDate, testDate2(testDate.getMonth(), testDate.getDay(), testDate.getYear());
        
        cout << "\n****** Testing getMonth, getDay, and getYear ********" << endl;
        cout << "The Date should display ";
        testDate.display();
        cout << " -> ";
        testDate2.display();
        cout << " - is it?\n\n";
        
    }
    
    void testYearOffset() {
        myDate testDate(12,12, 2016), testDate2(1,1,2016);
        
        cout << "\n****** Testing yearoffset ********" << endl;
        cout << "The number of day should display " << testDate2.daysBetween(testDate);
        
        cout << " -> ";
        cout << testDate.getYearOffset();
        cout << " - is it?\n\n";
    }
    
    void testBadDates(){
        /*You can never have a date that is invalid. The only opportunity for this to happen
         * 	 will be with the overloaded constructor. Therefore if any invalid data is passed
         * 	 to this constructor, ignore all data and set the values to the default date
         */
        myDate badD1(14, 01, 2016), badD2(10, -1, 2016), badD3(2, 33, 2016);
        
        cout << "\n****** Testing additional bad dates ********" << endl;
        cout << "The Date should display May 11, 1959 -> ";
        badD1.display();
        cout << " - is it?\n\n";
        
        cout << "The Date should display May 11, 1959 -> ";
        badD2.display();
        cout << " - is it?\n\n";
        
        cout << "The Date should display May 11, 1959 -> ";
        badD3.display();
        cout << " - is it?\n\n";
    }

