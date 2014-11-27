/*
 * File:    Essay.hpp
 * Author:  Enrique Najera
 * Purpose: Holds essay points
 * 02 December 2014
 */

#ifndef ESSAY_HPP
#define ESSAY_HPP

//Published Libraries
#include "GradedActivity.hpp"

class Essay : public GradedActivity
{
    private:
        int grmr,      // Holds grammar pts
            spl,       // Holds spelling pts
            corLength, // Holds correct length pts
            cont;      // Holds content pts
    public:
        //Constructors
        //Default
        Essay()
            {grmr = 0; spl = 0;
             corLength = 0; cont = 0;}

        //Sets score
        Essay(int g, int s, int cL, int c)
            { set(g, s, cL, c); }

        //Mutator Function
        void set(int, int, int, int);
};

#endif // ESSAY_HPP
