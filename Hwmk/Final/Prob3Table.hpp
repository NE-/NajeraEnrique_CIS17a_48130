/*
 * File:    Prob3Table.hpp
 * Author:  Najera Enrique
 * Purpose: Add columns and rows
 *          of a spreadsheet
 * 12 December 2014
 */

#ifndef PROB3TABLE_HPP
#define PROB3TABLE_HPP

//System Libraries
#include <fstream>
#include <iostream>

//Namespaces
using namespace std;

//Start template class Prob3Table
template<class T>
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char *,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};//End Prob3Table

//Start Prob3Table
template <class T>
Prob3Table<T>::Prob3Table(char *file, int r, int c)
{
    //Declare Variables
    int colHold = c; // Column holder
    int rowHold = r; // Row holder
    int count   = 0; // Count for file streaming
    int counter = 0; // Counter for adding rows and cols
    grandTotal  = 0; // INIT grandTotal var

    //Allocate Memory
    table  = new T[r*c];
    rowSum = new T[c];
    colSum = new T[r];

    //Read from file to array
    fstream infile(file, ios_base::in);

    T a;
    while (infile >> a)
    {
        table[count] = a;
        count++;
    }

    //INIT rowSum
    for(int i = 0; i < colHold; i++)
        rowSum[i] = 0;
    //Calculate row sums
    for(int i=0; i < colHold;i++)
    {
		for(counter;counter<c;counter++)
		{
			rowSum[i] += table[counter];
		}
		c+=6;
    }

    //Output row sums
    cout << "Row Sums: ";
    for(int i = 0; i < 5; i++)
        cout<<rowSum[i]<<" ";

    counter = 0;
    int temp = 0; // Temporary holder

    //INIT colSum
    for(int i = 0; i < rowHold; i++)
        colSum[i] = 0;
    //Calculate column sums
    for(int i=0; i < rowHold+1;i++)
    {
        temp = 0;

		for(counter;counter<r;counter++)
		{
			colSum[i] += table[counter+temp];
			temp += 5;
		}
		//r+=5;
    }
    cout<<endl;

    //Output col sums
    cout << "Col Sums: ";
    for(int i = 0; i < 6; i++)
        cout << colSum[i] << " ";
    cout<<endl;

    //Calculate grandtotal
    for(int i = 0; i < 5; i++)
        grandTotal += rowSum[i];
    for(int i = 0; i < 6; i++)
        grandTotal += colSum[i];

    //Output Grand Total
    cout << "Grandtotal: " << grandTotal << endl;;
}//End Prob3Table

#endif // PROB3TABLE_HPP
