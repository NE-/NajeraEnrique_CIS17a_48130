/*
 * File:    TestScores.hpp
 * Author:  Enrique Najera
 * Purpose: Calculate average of 3 test scores
 */

#ifndef TESTSCORES_HPP
#define TESTSCORES_HPP

//Start class TestScores
class TestScores
{
    private:
        float score; //Holds the score
    public:
        //Constructor
        TestScores(){score = 0;}

        //Mutator
        void setScore(float);

        //Accessor
        float getScrAvg() const;

};
//End TestScores

#endif //TESTSCORES_HPP
