/*
 * File:    Population.hpp
 * Author:  Enrique Najera
 * Purpose: Calculate birth and death rate
 */

//Published Libraries
#include "Population.hpp"

//Start mutator setPopu
void Population::setPopu(float p)
{
    popu = p;
}//End setPopu

//Start mutator setNBrth
void Population::setNBrth(float b)
{
    numBrth = b;
}//End setNBrth

//Start mutator setNumDth
void Population::setNumDth(float d)
{
    numDth = d;
}//End setNumDth

//Start accessor getBrthRt
float Population::getBrthRt() const
{
    return numBrth / popu;
}//End getBrthRt

//Start accessor getDthRT
float Population::getDthRt() const
{
    return numDth / popu;
}//End getDthRt
