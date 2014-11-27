/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Sets Essay variables
 *          adds variables and sets final grade
 * 02 December 2014
 */

//Published Libraries
#include "Essay.hpp"

void Essay::set(int g, int s, int cL,int c)
{
    int temp = 0; // Holds numeric score

    // Set vars
    grmr      = g;
    spl       = s;
    corLength = cL;
    cont      = c;

    //Add up the score
    temp = grmr + spl + corLength + cont;

    //Call setScore to get final grade
    setScore(temp);
}
