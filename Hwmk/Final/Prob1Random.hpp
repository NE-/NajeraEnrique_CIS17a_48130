/*
 * File:    Prob1Random.hpp
 * Author:  Najera Enrique
 * Purpose: Return random number from set
 * 12 December 2014
 */

#ifndef PROB1RANDOM_HPP
#define PROB1RANDOM_HPP

class Prob1Random
{
    private:
		char *set;      //The set of numbers to draw random numbers from
		char  nset;     //The number of variables in the sequence
		int  *freq;     //Frequency of all the random numbers returned
		int   numRand;  //The total number of times the random number function is called
	public:
		Prob1Random(const char,const char *);     //Constructor
		~Prob1Random(void);                       //Destructor
		char randFromSet(void);                   //Returns a random number from the set
		int *getFreq(void) const;                 //Returns the frequency histogram
		char *getSet(void) const;                 //Returns the set used
		int getNumRand(void) const;
};

#endif // PROB1RANDOM_HPP
