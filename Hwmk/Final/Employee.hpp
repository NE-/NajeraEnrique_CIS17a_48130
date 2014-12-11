/*
 * File:    Employee.hpp
 * Author:  Najera Enrique
 * Purpose: Manage employee info
 * 12 December 2014
 */

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

class Employee
{
    private:
		double Tax(float);      //Utility Procedure
		char   MyName[20];      //Property
		char   JobTitle[20];    //Property
		float  HourlyRate;      //Property
		int    HoursWorked;     //Property
		float  GrossPay;        //Property
		float  NetPay;          //Property
    public:
		Employee(char[],char[],float);  //Constructor
		float  CalculatePay(float,int); //Procedure
		float  getGrossPay(float,int);  //Procedure
		float  getNetPay(float);        //Procedure
		void   toString();              //Procedure
		int    setHoursWorked(int);     //Procedure
		float  setHourlyRate(float);    //Procedure
};

#endif // EMPLOYEE_HPP
