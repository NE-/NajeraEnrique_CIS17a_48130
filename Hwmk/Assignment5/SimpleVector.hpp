/*
 * File:    SimpleVector.hpp
 * Author:  Enrique Najera
 * Purpose: Makes a vector array
 * 02 December 2014
 */

#ifndef SIMPLEVECTOR_HPP
#define SIMPLEVECTOR_HPP

//System Libraries
#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

template <class T>
class SimpleVector
{
    private:
        T *aptr;         // To point to the allocated array
        int arraySize;   // Number of elements in the array
        void memError(); // Handles memory allocation errors
        void subError(); // Handles subscripts out of range

    public:
        //Default Constructor
        SimpleVector()
            { aptr = 0; arraySize = 0; }

        //Constructor Declaration
        SimpleVector(int);

        //Copy constructor declaration
        SimpleVector(const SimpleVector &);

        //Destructor declaration
        ~SimpleVector();

        //Accessor to return the array size
        int size() const
            { return arraySize; }

        //Accessor to return a specific element
        T getElementAt(int position);

        //Overloaded [] operator declaration
        T &operator[](const int &);
};

//Constructor
template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    //Allocate memory for the array
    try
    {
        aptr = new T [s];
    }
    catch (bad_alloc)
    {
        memError();
    }

    //Initialize the array
    for (int count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//Copy constructor
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    //Copy the array size
    arraySize = obj.arraySize;

    //Allocate memory for the array
    aptr = new T [arraySize];
    if (aptr == 0)
        memError();

    //Copy the elements of obj's array
    for(int count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//Destructor
template <class T>
SimpleVector<T>::~SimpleVector()
{
    if (arraySize > 0)
        delete [] aptr;
}

//memError function
template <class T>
void SimpleVector<T>::memError()
{
    cout << "ERROR: Cannot allcate memory.\n";
    exit(EXIT_FAILURE);
}

//SubError Function
template <class T>
void SimpleVector<T>::subError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
}

//getElementAt function
template <class T>
T SimpleVector<T>::getElementAt(int sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

//Overloaded [] operator
template <class T>
T &SimpleVector<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= arraySize)
        subError();
    return aptr[sub];
}

#endif // SIMPLEVECTOR_HPP
