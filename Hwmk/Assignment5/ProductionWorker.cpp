/*
 * File:    ProductionWorker.cpp
 * Author:  Enrique Najera
 * Purpose: Sets the production
 *          worker's shift
 * 02 December 2014
 */

//Published Libraries
#include "ProductionWorker.hpp"

//Start method setShift
void ProductionWorker::setShift(int s)
{
    //If shift is over 2 or 0, INIT shift
    if(s > 2 || s == 0)shift = 0;
    //If shift is 1 or 2, set shift
    else if(s == 1 || s == 2)shift = s;
}//End setShift
