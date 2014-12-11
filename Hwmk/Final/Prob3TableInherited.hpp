/*
 * File:    Prob3TableInherited.hpp
 * Author:  Najera Enrique
 * Purpose: Add columns and rows
 *          of a spreadsheet
 * 12 December 2014
 */

#ifndef PROB3TABLEINHERITED_HPP
#define PROB3TABLEINHERITED_HPP

//Published Libraries
#include "Prob3Table.hpp"

//Start template class Prob3TableInherited
template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;};
};//End Prob3TableInherited

//Start Prob3TableInherited
template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char *file, int row, int col) :
                        Prob3Table<T>(file, row, col)
{
    fstream infile(file, ios_base::in);

    augTable = new T[row*col];
    int count = 0;

    T a;
    while (infile >> a)
    {
        augTable[count] = a;
        count++;
    }
}//End Prob3TableInherited

#endif // PROB3TABLEINHERITED
