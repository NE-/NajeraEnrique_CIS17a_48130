/*
 * File:    PersonData.cpp
 * Author:  Enrique Najera
 * Purpose: Sends person's data
 *          to mutators
 * 02 December 2014
 */

//Published Libraries
#include "PersonData.hpp"

PersonData::PersonData(string lN, string fN, string a,
                       string c, string s, string p, int z)
{
    //Set values
    setLname(lN);
    setFname(fN);
    setAddress(a);
    setCity(c);
    setState(s);
    setPhone(p);
    setZip(z);
}
