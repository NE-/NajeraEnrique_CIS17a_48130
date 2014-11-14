/*
 * File:    NumDays.cpp
 * Author:  Enrique Najera
 * Purpose: Convert work hours to days
 */

//System Libraries
#include <iostream>

//Published Libraries
#include "NumDays.hpp"

//Namespaces
using namespace std; //iostream

//Overlaod + Operator
NumDays NumDays::operator + (const NumDays &right)
{
    float temp = 0;
    temp = right.wHrs + right.getWhrs();

    return NumDays(temp);
}//End overload

//Overload - Operator
NumDays NumDays::operator - (const NumDays &right)
{
    float temp = 0;
    temp = right.wHrs - right.getWhrs();

    return NumDays(temp);
}//End overload

//Overload prefix ++ operator
NumDays NumDays::operator ++ ()
{
    float temp = wHrs;
    --wHrs;
    wHrs = temp;
    wDays = wHrs/8.0;
    cout<<wHrs<<endl;

    return *this;
}//End overload

//Overload postfix ++ operator
NumDays NumDays::operator ++ (int)
{
    float temp = wHrs;
    ++temp;
    NumDays nD = NumDays(wHrs);
    wHrs = temp;
    wDays = temp/8.0;

    return *this;
}//End overload

//Overload prefix -- operator
NumDays NumDays::operator -- ()
{
    float temp = wHrs;
    --wHrs;
    wHrs = temp;
    wDays = wHrs/8.0;
    cout<<wHrs<<endl;

    return *this;
}//End overload

//Overload postfix -- operator
NumDays NumDays::operator -- (int)
{
    float temp = wHrs;
    --temp;
    NumDays nD = NumDays(wHrs);
    wHrs = temp;
    wDays = temp/8.0;

    return nD;
}//End overload
