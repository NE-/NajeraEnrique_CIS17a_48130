/*
 * File:    Employee16.hpp
 * Author:  Enrique Najera
 * Purpose: Stores information
 *          about an employee
 *          with exceptions
 * 02 December 2014
 */

#ifndef EMPLOYEE16_HPP
#define EMPLOYEE16_HPP

//System Libraries
#include <string>

//Namespaces
using namespace std;

class Employee16
{
    private:
        string empName; // Holds employee's name
        int empNum;     // Holds employee's number
        int hireDate;   // Holds employee's hire date
    public:
        //Exception Classes
        class InvalidEmployeeNumber
            {};

        //Default constructor
        Employee16()
            {empName = " ";
             empNum = 0;
             hireDate = 0;}
        //Takes name, number and hire date
        Employee16(string na, int num, int hiDa)
            {setEmpName(na);
             setEmpNum(num);
             setHireDate(hiDa);}

        //Mutator Functions
        void setEmpName(string eNa)
            {empName = eNa;}
        void setEmpNum(int);
        void setHireDate(int eHD)
            {hireDate = eHD;}

        //Accessor Functions
        string getEmpName() const
            {return empName;}
        int getEmpNum()     const
            {return empNum;}
        int getHireDate()   const
            {return hireDate;}
};

#endif // EMPLOYEE16_HPP
