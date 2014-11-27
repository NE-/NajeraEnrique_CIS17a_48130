/*
 * File:    ProductionWorker.cpp
 * Author:  Enrique Najera
 * Purpose: Sets the production
 *          worker's shift
 * 02 December 2014
 */

//Published Libraries
#include "ProductionWorker16.hpp"

//Start setShift
void ProductionWorker16::setShift(int s)
{
    if(s > 2 || s == 0)throw InvalidShift();
    else if(s == 1 || s == 2)shift = s;
}//end setShift

//Start setHrPayRt
void ProductionWorker16::setHrPayRt(float hP)
{
    if (hP > 0)hrPayRt = hP;
    else throw InvalidPayRate();
}//End setHrPayRt
