/*
 * File:    Prob2Sort.hpp
 * Author:  Najera Enrique
 * Purpose: Sort a single column array
 * 12 December 2014
 */

#ifndef PROB2SORT_HPP
#define PROB2SORT_HPP

//System Libraries
#include <iostream>

//Namespaces
using namespace std;

//Start template class Prob2Sort
template<class T>
class Prob2Sort
{
	private:
		T *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index=0;};                      //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T*,int,bool);           //Sorts a single column array
		T * sortArray(const T*,int,int,int,bool);   //Sorts a 2 dimensional array represented as a 1 dim array
};//End Prob2Sort

#endif // PROB2SORT_HPP

//Start sortArray
template <class T>
T *Prob2Sort<T>::sortArray(const T *arrPtr,int size,bool ascending)
{
    //Allocate Memory
    index = new int[10*16];

    //Add contents to new array
    for(int i = 0; i < (10*16) - 1; i++)
        index[i] = arrPtr[i];
    //Declare Variables
    int temp; //Temporarily holds a value

    //Start sorting
    do
    {
        ascending = false;
        for(int count = 0; count < (size - 1); count++)
        {
            if(index[count] > index[count + 1])
            {
                temp = index[count];
                index[count] = index[count + 1];
                index[count + 1] = temp;
                ascending = true;
            }
        }
    }while (ascending);
}//End sortArray

//Start sortArray
template <class T>
T *Prob2Sort<T>::sortArray(const T *arrPtr,int y,int x,int col,bool ascending)
{
    //Allocate Memory
    index = new T[y*x];
    //Set new array equal to array pointer
    for(int i = 0; i < (y*x); i++)
        index[i] = arrPtr[i];

    int temp;
    //int temp2 = col + 3;
    //int area = y*x;

    if(col > 0 && col < 16)
    {
        cout << "Sorting on column " << col << endl;

        do
        {
            ascending = false;
            for(int count = 0; count < col; count++)
            {
                if(index[count] > index[count+1])
                {
                    temp = index[count];
                    index[count] = index[count+1];
                    index[count+1] = temp;
                    ascending = true;
                }
            }
        }while (ascending);
       // temp = col;
      //  area = y*x;
      /* while(temp-->0)
        {
            if(index[area-(col+3)] > index[(area-=x) - (col+3)])
               {
                   temp2 = index[(area)-(col+3)];
                   index[(area)-(col+3)] = index[(area-=x) - (col+3)];
                   index[(area-=x) - (col+3)] = temp2;
               }
        }*/

        return index;
    }
    else cout << "\nColumn ranges from 1 - 15\n";
}//End sortArray


