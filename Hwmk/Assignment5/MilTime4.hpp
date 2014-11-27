/*
 * File:    MilTime4.hpp
 * Author:  Enrique Najera
 * Purpose: Converts military time
 *          to standard time
 * 02 December 2014
 */

#ifndef MILTIME4_HPP
#define MILTIME4_HPP

//System Libraries
#include <string>

//Published Libraries
#include "Time4.hpp"

//Namespaces
using namespace std; //string

class MilTime4 : public Time4
{
    private:
        int milHours;   // Holds military hours
        int milSeconds; // Holds military seconds
        string aOp;     // Stores AM or PM
    public:
        //Constructors
        //Default
        MilTime4()
            { milHours = 0; milSeconds = 0; aOp = " ";}

        //Convert military to std time
        MilTime4(int, int);

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

#endif // MILTIME4_HPP
