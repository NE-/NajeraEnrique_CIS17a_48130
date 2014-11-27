/*
 * File:    MilTime2.hpp
 * Author:  Enrique Najera
 * Purpose: Set and get time
 *          Throws exceptions
 * 02 December 2014
 */

#ifndef MILTIME2_HPP
#define MILTIME2_HPP

//System Libraries
#include <iostream>
#include <string>

//Published Libraries
#include "Time2.hpp"

//Namespaces
using namespace std; //iostream, string

class MilTime2 : public Time2
{
    private:
        int milHours;   // Holds military hours
        int milSeconds; // Holds military seconds
        string aOp;     // Stores AM or PM
    public:
        //Constructors
        //Default
        MilTime2()
            { milHours = 0; milSeconds = 0; aOp = " ";}

        //Convert military to std time
        MilTime2(int, int);

        //Exception classes
        class BadHour
            {};
        class BadSeconds
            {};

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

#endif // MILTIME2_HPP
