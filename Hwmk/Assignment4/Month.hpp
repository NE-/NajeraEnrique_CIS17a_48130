/*
 * File:    Month.hpp
 * Author:  Enrique Najera
 * Purpose: Prints the month
 *          and day number
 */

#ifndef MONTH_HPP
#define MONTH_HPP

//System Libraries
#include <iostream>
#include <string>

//Namespaces
using namespace std; //iostream, string

class Month
{
    private:
        string name;     // Holds month name
        int monthNumber; // Holds month number
    public:
        //Constructors
        //Default
        Month()
            {name = "January"; monthNumber = 1;}
        Month(string); // Takes month string convert to month int
        Month(int);    // Takes month int convert to month string

        //Mutators
        void setName(string moNa){name = moNa;}
        void setMonthNumber(int moNu){monthNumber = moNu;}

        //Accessors
        string getName() const{return name;}
        int getMonthNumber() const{return monthNumber;}

        //Overloaded Operator Functions
        Month &operator ++ ();    // Prefix  ++
        Month operator ++ (int);  // Postfix ++
        Month &operator -- ();    // Prefix  --
        Month operator -- (int);  // Postfix --

        //Overloaded stream functions
        friend ostream &operator << (ostream &, Month &);
        friend istream &operator >> (istream &, Month &);
};

#endif // MONTH_HPP
