/*
 * File:    DayOfYear.cpp
 * Author:  Enrique Najera
 * Purpose: Prints the day in
 *          month-day format
 */

//System Libraries
#include <iostream>
#include <string>

//Published Libraries
#include "DayOfYear.hpp"

//Namespaces
using namespace std; //iostream

void DayOfYear::print()
{
    //Declare Function Variables
    //Holds month names
    const string month[12] = {"January", "February", "March", "April",
                              "May", "June", "July", "August", "September",
                              "October", "November", "December"};

    //If dayYr <=  31,          January
    if(dayYr <= 31 && dayYr > 0)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[0]<<" "<<dayYr<<endl;
    }

    //If dayYr >=  32 && <=  59 February
    else if( dayYr >= 32 && dayYr <= 59)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[1]<<" "<<dayYr - 31<<endl;
    }

    //If dayYr >=  60 && <=  90 March
    else if( dayYr >= 60 && dayYr <= 90)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[2]<<" "<<dayYr - 59<<endl;
    }

    //If dayYr >=  91 && <= 120 April
    else if( dayYr >= 91 && dayYr <= 120)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[3]<<" "<<dayYr - 90<<endl;
    }

    //If dayYr >= 121 && <= 151 May
    else if( dayYr >= 121 && dayYr <= 151)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[4]<<" "<<dayYr - 120<<endl;
    }

    //If dayYr >= 152 && <= 181 June
    else if( dayYr >= 152 && dayYr <= 181)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[5]<<" "<<dayYr - 151<<endl;
    }

    //If dayYr >= 182 && <= 212 July
    else if( dayYr >= 182 && dayYr <= 212)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[6]<<" "<<dayYr - 181<<endl;
    }

    //If dayYr >= 213 && <= 243 August
    else if( dayYr >= 213 && dayYr <= 243)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[7]<<" "<<dayYr - 212<<endl;
    }

    //If dayYr >= 244 && <= 273 September
    else if( dayYr >= 244 && dayYr <= 273)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[8]<<" "<<dayYr - 243<<endl;
    }

    //If dayYr >= 274 && <= 304 October
    else if( dayYr >= 274 && dayYr <= 304)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[9]<<" "<<dayYr - 273<<endl;
    }

    //If dayYr >= 305 && <= 334 November
    else if( dayYr >= 305 && dayYr <= 334)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[10]<<" "<<dayYr - 304<<endl;
    }

    //If dayYr >= 335 && <= 365 December
    else if( dayYr >= 335 && dayYr <= 365)
    {
        cout<<"Day "<<dayYr<<" would be "<<month[11]<<" "<<dayYr - 334<<endl;
    }

    //If dayYr > 365 || < 0 error
    else cout<<"Invalid input or system error detected"<<endl;
}
