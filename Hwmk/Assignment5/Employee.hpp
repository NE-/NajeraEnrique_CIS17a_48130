/*
 * File:    Employee.hpp
 * Author:  Enrique Najera
 * Purpose: Stores information
 *          about an employee
 * 02 December 2014
 */

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

//System Libraries
#include <string>

//Namespaces
using namespace std;

class Employee
{
    private:
        string empName; // Holds employee's name
        int empNum;     // Holds employee's number
        int hireDate;   // Holds employee's hire date
    public:
        //Default constructor
        Employee()
            {empName = " ";
             empNum = 0;
             hireDate = 0;}

        //Takes name, number and hire date
        //then calls mutators
        Employee(string na, int num, int hiDa)
            {setEmpName(na);
             setEmpNum(num);
             setHireDate(hiDa);}

        //Mutator Functions
        void setEmpName(string eNa)
            {empName = eNa;}
        void setEmpNum(int eNu)
            {empNum = eNu;}
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

#endif // EMPLOYEE_HPP
