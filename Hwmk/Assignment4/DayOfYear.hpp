/*
 * File:    DayOfYear.hpp
 * Author:  Enrique Najera
 * Purpose: Prints the day in
 *          month-day format
 */

#ifndef DAYOFYEAR_HPP
#define DAYOFYEAR_HPP

//Start class DayOfYear
class DayOfYear
{
    private:
        int dayYr; // Holds day of the year
    public:
        //Constructor
        DayOfYear(int day){dayYr = day; print();}

        void print();  // Prints in month-day format
};

#endif //DAYOFYEAR_HPP
