/*
 * File:    SearchableVector.hpp
 * Author:  Enrique Najera
 * Purpose: Template to find value
 * 02 December 2014
 */

#ifndef SEARCHABLEVECTOR_HPP
#define SEARCHABLEVECTOR_HPP

//Published Libraries
#include "SimpleVector.hpp"

template <class T>
class SearchableVector : public SimpleVector<T>
{
    public:
        //Default Constructor
        SearchableVector() : SimpleVector<T>()
            {}

        //Constructor
        SearchableVector(int size) : SimpleVector<T>(size)
            {}

        //Copy constructor
        SearchableVector(const SearchableVector &);

        //Accessor to find item
        int findItem(const T);
};

//Copy constructor
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) :
                     SimpleVector<T>(obj.size())
{
    for(int count = 0; count < this->size(); count++)
        this->operator[](count) = obj[count];
}

//findItem Function
template <class T>
int SearchableVector<T>::findItem(const T item)
{
    for (int count = 0; count <= this->size(); count++)
    {
        if (this->getElementAt(count) == item)
            return count;
    }
    return -1;
}

#endif // SEARCHABLEVECTOR_HPP
