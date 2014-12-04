/*
 * File:    Random.hpp
 * Author:  Najera Enrique
 * Purpose: Generates and returns
 *          working random number
 *
 * 08 December 2014
 */

#ifndef RANDOM_HPP
#define RANDOM_HPP

//System Libraries
#include <vector>

//Namespaces
using namespace std;

//Start template class Random
template <class T>
class Random
{
    private:
        vector<T> rndm; // Array of random numbers
    public:
        //Accessor Functions
        T top() const;

        //Functions
        void push(T const&); // Push numbers
        void pop();          // Pop numbers

};//End template class Rand

//Start push
template <class T>
void Random<T>::push (T const& num)
{
    //Push copy of number in vector
    rndm.push_back(num);
}//End push

//Start pop
template <class T>
void Random<T>::pop()
{
    //Pop back last number
    rndm.pop_back();
}//End pop

//Start top
template <class T>
T Random<T>::top() const
{
    //Return result
    return rndm.back();
}//End top

#endif // RANDOM_HPP
