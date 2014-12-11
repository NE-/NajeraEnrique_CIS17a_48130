/*
 * File:    Employee.cpp
 * Author:  Najera Enrique
 * Purpose: Manage employee info
 * 12 December 2014
 */

//System Libraries
#include <iostream>

//Published Libraries
#include "Employee.hpp"

//Namespaces
using namespace std;

//Start Employee
Employee::Employee(char *name, char *title, float hrRt)
{
    //INIT vars
    MyName[20]   = *name;
    JobTitle[20] = *title;
    HourlyRate   = hrRt;
    HoursWorked  = 0;
    GrossPay     = 0;
    NetPay       = 0;
}//End Employee

//Start Tax
double Employee::Tax(float gPay)
{
    if(gPay < 500)
        NetPay *= 0.1;
    else if(gPay > 500 && gPay < 1000)
        NetPay *= 0.2;
    else
        NetPay *= 0.3;
}//End Tax

//Start setHoursWorked
int Employee::setHoursWorked(int hrWrk)
{
    if(hrWrk > 0 && hrWrk < 84)HoursWorked = hrWrk;
    else cout << "Hours worked must be above 0\n";
    return HoursWorked;
}//End setHoursWorked

//Start setHourlyRate
float Employee::setHourlyRate(float hrRt)
{
    if(hrRt > 0.0 && hrRt < 200)HourlyRate = hrRt;
    else cout << "Hourly rate must be above 0\n";
    return HourlyRate;
}//End setHourlyRate

//Start getNetPay
float Employee::getNetPay(float gP)
{
    return NetPay;
}//End getNetPay

//Start getGrossPay
float Employee::getGrossPay(float rate, int hours)
{
    if(hours < 40)GrossPay = rate * hours;
    else if(hours > 40 && hours <= 50)
        GrossPay = (rate * hours) + (((hours - 40) * rate)/2);
    else if(hours > 50)
        GrossPay = (rate * hours) + (((rate/2) + rate) * (hours - 50));

    return GrossPay;
}//End getGrossPay

//Start calculatePay
float Employee::CalculatePay(float x,int y)
{
    return getNetPay(getGrossPay(setHourlyRate(x)
		,setHoursWorked(y)));
}//Emd calculatePay

//Start toString
void Employee::toString()
{
    cout << "Name: "         << MyName      << endl;
    cout << "Job Title: "    << JobTitle    << endl;
    cout << "Hourly Rate: "  << HourlyRate  << endl;
    cout << "Hours Worked: " << HoursWorked << endl;
    cout << "Gross Pay: "    << GrossPay    << endl;
    cout << "Net Pay: "      << NetPay      << endl;
}//End toString
