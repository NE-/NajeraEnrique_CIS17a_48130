/*
 * File:    GradedActivity.cpp
 * Author:  Enrique Najera
 * Purpose: Gets letter grade
 * 02 December 2014
 */

//Published Libraries
#include "GradedActivity.hpp"

char GradedActivity::getLetterGrade() const
{
    //Declare Variables
    char letterGrade;

    if(score > 89)
        letterGrade = 'A';
    else if(score > 79)
        letterGrade = 'B';
    else if(score > 69)
        letterGrade = 'C';
    else if(score > 59)
        letterGrade = 'D';
    else
        letterGrade = 'F';

    return letterGrade;
}
