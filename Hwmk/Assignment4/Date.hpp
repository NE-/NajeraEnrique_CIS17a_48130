/*
 * File:    Date.hpp
 * Author:  Enrique Najera
 * Purpose: Print month, day and year
 *          in multiple formats
 */

#ifndef DATE_HPP
#define DATE_HPP

//Start class Date
class Date
{
    private:
        int mnth; // Holds month 
        int day;  // Holds day
        int yr;   // Holds year
    public:
        void getVals();                 // Gets int m d y values
        void printNums(int, int, int) ; // Prints mm/dd/yyyy format
        void printMnth(int, int, int) ; // Prints month day, year format
        void printDay(int, int, int)  ; // Prints day month year format 
        
};
//End class Date

#endif //DATE_HPP
