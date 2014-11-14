/*
 * File:    TestScores.cpp
 * Author:  Enrique Najera
 * Purpose: Calculate average of 3 test scores
 */

//Published Libraries
#include "TestScores.hpp"

//Start Mutator setScore
void TestScores::setScore(float s)
{
    score = s;
}//End setScore

//Start Accessor getScrAvg
float TestScores::getScrAvg() const
{
    return score / 3;
}//End getScrAvg
