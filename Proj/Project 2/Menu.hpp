/*
 * File:    Menu.hpp
 * Author:  Najera Enrique
 * Purpose: Takes in menu inputs
 *
 * 08 December 2014
 */

#ifndef MENU_HPP
#define MENU_HPP

//System Libraries
#include <string>

//Published Libraries
#include "FileStream.hpp"

//Namespaces
using namespace std;

class Menu : public FileStream
{
    protected:
        int inN;        // Get user choice
        char fName[20]; // Holds file name for reading menu
    public:
        // Default constructor
        Menu()
            { inN = 0; }

        //Mutator Functions
        void setInN(int in)
            { inN = in; }

        //Accessor Functions
        int getIntN() const
            { return inN; }
};

#endif // MENU_HPP
