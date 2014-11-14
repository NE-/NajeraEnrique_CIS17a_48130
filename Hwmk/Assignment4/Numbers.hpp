/*
 * File:    Numbers.hpp
 * Author:  Enrique Najera
 * Purpose: Convert whole numbers
 *          to english description
 */

#ifndef NUMBERS_HPP
#define NUMBERS_HPP

//System Libraries
#include <string>

//Namespaces
using namespace std; //iostream

class Numbers
{
    private:
        int number; //Holds the dollar amount
    public:
        //Constructors
        //Default
        Numbers()
            {number = 0;}
        //Takes an int, INIT Numbers object
        Numbers(int);

        //Print function
        void print(int);
};

#endif // NUMBERS_HPP
