/*
 * File:    main.cpp
 * Author:  Najera Enrique
 * Purpose: CSC 17 A Final
 * 12 December 2014
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <stdlib.h>

//Published Libraries
//*Problem 1
#include "Prob1Random.hpp"
//*Problem 2
#include "Prob2Sort.hpp"
//*Problem 3
#include "Prob3TableInherited.hpp"
//*Problem 4
#include "SavingsAccount.hpp"
//*Problem 5
#include "Employee.hpp"

//Namespaces
using namespace std;

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1(); // Final problem 1
void problem2(); // Final problem 2
void problem3(); // Final problem 3
void problem4(); // Final problem 4
void problem5(); // Final problem 5
void problem6(); // Final problem 6

//Start method main
int main(int argv,char *argc[])
{
    int inN;

    //Prompt for problem number
    do
    {
        Menu();
        inN = getN();

        switch(inN)
        {
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            default:   def(inN);
        }
    }while(inN<7);

    system("PAUSE");
    return 0;
}//End method main

//Start Menu
void Menu()
{
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type 7 to exit \n"<<endl;
}//End Menu

//Start getN
int getN()
{
    int inN;
    cin >> inN;
    return inN;
}//End getN

//Start final problem 1
void problem1()
{
    char n        = 5;
	char rndseq[] = {16,34,57,79,144};
	int  ntimes   = 100000;

	Prob1Random a(n,rndseq);

    srand(time(0));

	for(int i=1;i<=ntimes;i++)
	{
		a.randFromSet();
	}

	int *x=a.getFreq();
	char *y=a.getSet();

	for(int i=0;i<n;i++)
	{
		cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
	}

	//cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}//End final problem 1

//Start final problem 2
void problem2()
{
    cout<<"The start of Problem 2, the sorting problem"<<endl;

	Prob2Sort<char> rc;

	bool ascending=true;

	ifstream infile;
	infile.open("Problem2.txt",ios::in);

	char *ch2=new char[10*16];
	char *ch2p=ch2;

	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	infile.close();

	cout<<endl;

	cout<<"Sorting on which column"<<endl;

	int column;
	cin>>column;

	char *zc=rc.sortArray(ch2p,10,16,column,ascending);

	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<zc[i*16+j];
		}
	}

	delete []zc;
	cout<<endl<<endl;
}//End final problem 2

//Start final problem 3
void problem3()
{
    cout<<"Entering problem number 3"<<endl;

	int rows=5;
	int cols=6;

	Prob3TableInherited<int> tab("Problem3.txt",rows,cols);

	const int *naugT=tab.getTable();

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<naugT[i*cols+j]<<" ";

		}
		cout<<endl;
	}

	cout<<endl;

	const int *augT=tab.getAugTable();

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cout<<augT[i*cols+j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}//End final problem 3

//Start final problem 4
void problem4()
{
    srand(time(0));
    SavingsAccount mine(-300);

	for(int i=1;i<=10;i++)
	{
		mine.Transaction((float)(rand()%500)*(rand()%3-1));
	}

	mine.toString();

	cout<<"Balance after 7 years given 10% interest = "
		<<mine.Total((float)(0.10),7)<<endl;
	cout<<"Balance after 7 years given 10% interest = "
		<<mine.TotalRecursive((float)(0.10),7)
		<<" Recursive Calculation "<<endl;
    cout<<endl;
}//End final problem 4

//Start final problem 5
void problem5()
{
    Employee Mark("Mark","Boss",215.50);
	Mark.setHoursWorked(-3);
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(20.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(40.0),
		Mark.setHoursWorked(25));
	Mark.toString();
	Mark.CalculatePay(Mark.setHourlyRate(60.0),
		Mark.setHoursWorked(25));
	Mark.toString();

	Employee Mary("Mary","VP",50.0);
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(40));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(50));
	Mary.toString();
	Mary.CalculatePay(Mary.setHourlyRate(50.0),
		Mary.setHoursWorked(60));
	Mary.toString();
	cout << endl;
}//End final problem 5

//Start final problem 6
void problem6()
{
    cout <<"\nIn problem 6\n";

    cout << "\nA) 420799a is 33.90000152587890625 in decimal\n"
         << "\nB) 44861333 is 1072.5999755859375 in decimal\n"
         << "\nC) 3d8f5c29 is 0.2800000011920928955078125 in decimal\n"
         << endl;
}//End final problem 6

//Start def
void def(int inN)
{
    cout << "You typed " << inN << " to exit the program" << endl;
}
