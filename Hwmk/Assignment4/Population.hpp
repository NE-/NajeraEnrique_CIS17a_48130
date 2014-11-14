/*
 * File:    Population.hpp
 * Author:  Enrique Najera
 * Purpose: Calculate birth and death rate
 */

#ifndef POPULATION_HPP
#define POPULATION_HPP

//Start class Population
class Population
{
    private:
        float popu;    // Holds total population
        float numBrth; // Holds number of births
        float numDth;  // Holds the number of deaths
    public:
        //Mutators
        void setPopu(float);     // Set total population
        void setNBrth(float);    // Set number of births
        void setNumDth(float);   // Set number of deaths

        //Accessors
        float getBrthRt() const; // Get the birth rate
        float getDthRt() const;  // Get the death rate
};
//End Population

#endif //POPULATION_HPP
