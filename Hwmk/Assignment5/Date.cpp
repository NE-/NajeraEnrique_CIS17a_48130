/*
 * File:    Date.cpp
 * Author:  Enrique Najera
 * Purpose: Print month, day and year
 *          in multiple formats
 *          Throw exceptions
 * 02 December 2014
 */

//System Libraries
#include <iostream>
#include <string>

//Published Libraries
#include "Date.hpp"

//Namespaces
using namespace std; //iostream, string

//Start setMnth
void Date::setMnth(int m)
{
    if (m >= 1 && m <= 12)
        mnth = m;
    else
        throw InvalidMonth();
}//End setMnth

//Start setDay
void Date::setDay(int d)
{
    if (d >= 1 && d <= 31)
        day = d;
    else
        throw InvalidDay();
}//End setDay

//Start printNums mm/dd/yyyy format
void Date::printNums(int m, int d, int y)
{
	//If month < 10 output a '0' in front
	if(m  < 10)
	{
	    cout<<"0"<<m<<"/";
	}
	else cout<<m<<"/";

	//If day < 10 output a '0' in front
	if(d < 10)
	{
		cout<<"0"<<d<<"/";
	}
	else cout<<d<<"/";

	cout<<y<<endl;
}//end printNums

//Start printMnth m d y format
void Date::printMnth(int m, int d, int y)
{
	//Declare function variables
	//Displays month
    string month[] = {"January", "February", "March", "April",
	                    "May", "June", "July", "August", "September",
	                    "October","November","December"};

	cout<<month[m - 1]<<" "<<d<<", "<<y<<endl;
}//end printMth

//Start printDay d m y format
void Date::printDay(int m, int d, int y)
{
	//Declare function variables
	//Displays month
	string month[] = {"January", "February", "March", "April",
	                    "May", "June", "July", "August", "September",
	                    "October","November","December"};

    cout<<d<<" "<<month[m - 1]<<" "<<y<<endl;
}//end printDay
