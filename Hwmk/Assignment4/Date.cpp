/*
 * File:    Date.cpp
 * Author:  Enrique Najera
 * Purpose: Print month, day and year
 *          in multiple formats
 */

//System Libraries
#include <iostream>
#include <string>

//Published Libraries
#include "Date.hpp"

//Namespaces
using namespace std; //iostream, string

void Date::getVals()
{
    while(true)
    {
        //Prompt for the month
        cout<<"Enter the digit of the month ";
        cin>>mnth;

        //If month > 12 or < 1 bad input
        if(mnth > 12 || mnth < 1)
        {
            cout<<"Month should be between 1 - 12!\n";
        }
        //If good input, continue
        else break;
    }

    while(true)
    {
        //Prompt for the day
        cout<<"Enter the day ";
        cin>>day;

        //If day > 12 or < 1 bad input
        if(day  > 31 || day < 1)
        {
            cout<<"Day should be between 1 - 31!\n";
        }
        //If good input, continue
        else break;
    }

    //Prompt for the year
    cout<<"Enter the year ";
    cin>>yr;

    //Print data
    Date::printNums(mnth, day, yr); // Prints mm/dd/yyyy format
    Date::printMnth(mnth, day, yr); // Prints month day, year format
    Date::printDay(mnth, day, yr);  // Prints day month year format
}

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
