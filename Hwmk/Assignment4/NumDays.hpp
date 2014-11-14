/*
 * File:    NumDays.hpp
 * Author:  Enrique Najera
 * Purpose: Convert work hours to days
 */

#ifndef NUMDAYS_HPP
#define NUMDAYS_HPP

//Start class NumDays
class NumDays
{
    public:
        float wDays; // Holds number of work days
        float wHrs;  // Holds number of work hours
    public:
        //Constructir
        NumDays(float h)
        {
            wHrs  = h;      // Assign wHrs
            wDays = wHrs/8; // 8 hours is one work day
        }

        //Accessors
        float getWhrs()  const {return wHrs;}  // Gets work hours
        float getWdays() const {return wDays;} // Gets work days

        //Operator Overload Functions
        NumDays operator +  (const NumDays &); // Overload  +
        NumDays operator -  (const NumDays &); // Overload  -
        NumDays operator ++ ();                // Overload prefix  ++
        NumDays operator ++ (int);             // Overload postfix ++
        NumDays operator -- ();                // Overload prefix  --
        NumDays operator -- (int);             // Overload postfix --

};

#endif // NUMDAYS_HPP
