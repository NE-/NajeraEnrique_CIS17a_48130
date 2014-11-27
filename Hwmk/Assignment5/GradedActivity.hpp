/*
 * File:    GradedActivity.hpp
 * Author:  Enrique Najera
 * Purpose: Sets and gets score
 *          and gets letter grade
 * 02 December 2014
 */

#ifndef GRADEDACTIVITY_HPP
#define GRADEDACTIVITY_HPP

class GradedActivity
{
    private:
        float score; // Holds numeric score
    public:
        // Default Constructor
        GradedActivity()
            { score = 0.0; }

        // Constructor
        GradedActivity(float s)
            { score = s; }

        // Mutator Function
        void setScore(float s)
            { score = s; }

        // Accessor Functions
        float getScore() const
            { return score; }

        char getLetterGrade() const;
};

#endif // GRADEDACTIVITY_HPP
