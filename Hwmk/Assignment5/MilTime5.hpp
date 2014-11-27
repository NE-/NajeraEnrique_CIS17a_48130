/*
 * File:    MilTime5.hpp
 * Author:  Enrique Najera
 * Purpose: Stores properties
 *          of military times
 * 02 December 2014
 */

#ifndef MILTIME_HPP
#define MILTIME_HPP

//System Libraries
#include <iostream>
#include <string>

//Published Libraries
#include "Time5.hpp"

//Namespaces
using namespace std; //iostream, string

class MilTime5 : public Time5
{
    protected:
        int milHours;   // Holds military hours
        int milSeconds; // Holds military seconds
        string aOp;     // Stores AM or PM
    public:
        //Constructors
        //Default
        MilTime5()
            { milHours = 0; milSeconds = 0; aOp = " ";}

        //Convert military to std time
        MilTime5(int, int);

        //Mutator Functions
        void setTime(int, int); // Stores milHours and milSeconds then converts

        //Accessor Functions
        int getHour() const     // Returns hour in military format
            {return milHours;}
        int getStandHr() const  // Returns hour in standard format
            {return hour;}
        int getStandMin() const // Returns minute
            {return min;}
        string getAoP() const   // Returns AM or PM
            {return aOp;}
};

#endif // MILTIME_HPP
