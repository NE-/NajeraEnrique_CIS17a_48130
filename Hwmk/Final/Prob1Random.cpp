/*
 * File:    Prob1Random.cpp
 * Author:  Najera Enrique
 * Purpose: Return random number from set
 * 12 December 2014
 */

//System Libraries
#include <iostream>
#include <cstdlib>

//Namespaces
using namespace std;

//Published Libraries
#include "Prob1Random.hpp"

//Start Prob1Random
Prob1Random::Prob1Random(const char n,const char *rndseq)
{
     nset    = n;
     numRand = 0;

     for(int i = 0; i <= int(n)-1; i++)
     {
         set[i] = int(rndseq[i]);
         freq[i] = 0;
     }
}//End Prob1Random

//Start ~Prob1Random
Prob1Random::~Prob1Random(void)
{
    delete [] set;
    delete [] freq;
}//End ~Prob1Random

//Start randFromSet
char Prob1Random::randFromSet(void)
{
    int randNum = 0;
    randNum = rand()%5;
    numRand++;
    set[randNum];
    freq[randNum]+=1;
}//End randFromSet

//Start getFreq
int *Prob1Random::getFreq(void) const
{
    return freq;
}//End getFreq

//Start getSet
char *Prob1Random::getSet(void) const
{
    return set;
}//End getSet

//Start getNumRand
int Prob1Random::getNumRand(void) const
{
    return numRand;
}//End getNumRand
