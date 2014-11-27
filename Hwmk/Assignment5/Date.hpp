/*
 * File:    Date.hpp
 * Author:  Enrique Najera
 * Purpose: Print month, day and year
 *          in multiple formats
 *          Throw exceptions
 * 02 December 2014
 */

#ifndef DATE_HPP
#define DATE_HPP

class Date
{
    private:
        int mnth; // Holds month
        int day;  // Holds day
        int yr;   // Holds year
    public:
        //Exception Classes
        class InvalidDay
            {};
        class InvalidMonth
            {};

        //Mutators
        void setMnth(int);
        void setDay(int);
        void setYr(int y)
            { yr = y; }

        //Print Functions
        void printNums(int, int, int); // Prints mm/dd/yyyy format
        void printMnth(int, int, int); // Prints month day, year format
        void printDay(int, int, int) ; // Prints day month year format
};

#endif //DATE_HPP
