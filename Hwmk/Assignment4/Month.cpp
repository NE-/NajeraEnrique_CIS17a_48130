/*
 * File:    Month.cpp
 * Author:  Enrique Najera
 * Purpose: Prints the month
 *          and day number
 */

//System Libraries
#include <iostream>

//Published Libraries
#include "Month.hpp"

//Constructor ->month name <-month number
Month::Month(string mNa)
{
    name = mNa;

    if(name == "January" || name == "january")         monthNumber =  1;
    else if(name == "February" || name == "february")  monthNumber =  2;
    else if(name == "March" || name == "march")        monthNumber =  3;
    else if(name == "April" || name == "april")        monthNumber =  4;
    else if(name == "May" || name == "may")            monthNumber =  5;
    else if(name == "June" || name == "june")          monthNumber =  6;
    else if(name == "July" || name == "july")          monthNumber =  7;
    else if(name == "August" || name == "august")      monthNumber =  8;
    else if(name == "September" || name == "september")monthNumber =  9;
    else if(name == "October" || name == "october")    monthNumber = 10;
    else if(name == "November" || name == "november")  monthNumber = 11;
    else if(name == "December" || name == "december")  monthNumber = 12;
    //If ! month name, output error & INIT var monthNumber
    else {cout<<"\nINVALID INPUT!\n";monthNumber = 0;}
}

//Constructor ->month number <-month name
Month::Month(int mNu)
{
    monthNumber = mNu;

    if(monthNumber == 1)name = "January";
    else if(monthNumber == 2)name = "February";
    else if(monthNumber == 3)name = "March";
    else if(monthNumber == 4)name = "April";
    else if(monthNumber == 5)name = "May";
    else if(monthNumber == 6)name = "June";
    else if(monthNumber == 7)name = "July";
    else if(monthNumber == 8)name = "August";
    else if(monthNumber == 9)name = "September";
    else if(monthNumber == 10)name = "October";
    else if(monthNumber == 11)name = "Novemeber";
    else if(monthNumber == 12)name = "December";
}

//Overloaded Operator Functions
//Prefix ++
Month &Month::operator++()
{
    monthNumber++;
    if(monthNumber == 2)name = "February";
    else if(monthNumber == 3)name = "March";
    else if(monthNumber == 4)name = "April";
    else if(monthNumber == 5)name = "May";
    else if(monthNumber == 6)name = "June";
    else if(monthNumber == 7)name = "July";
    else if(monthNumber == 8)name = "August";
    else if(monthNumber == 9)name = "September";
    else if(monthNumber == 10)name = "October";
    else if(monthNumber == 11)name = "November";
    else if(monthNumber == 12)name = "December";
    else if(monthNumber == 13){name = "January"; monthNumber = 1;}
    else{name = " "; monthNumber = 0;}

    return *this;
}

//Postfix ++
Month Month::operator++(int)
{
    ++monthNumber;
    if(monthNumber == 2)name = "February";
    else if(monthNumber == 3)name = "March";
    else if(monthNumber == 4)name = "April";
    else if(monthNumber == 5)name = "May";
    else if(monthNumber == 6)name = "June";
    else if(monthNumber == 7)name = "July";
    else if(monthNumber == 8)name = "August";
    else if(monthNumber == 9)name = "September";
    else if(monthNumber == 10)name = "October";
    else if(monthNumber == 11)name = "November";
    else if(monthNumber == 12)name = "December";
    else if(monthNumber == 13){name = "January"; monthNumber = 1;}
    else{name = " "; monthNumber = 0;}

    return *this;
}

//Prefix --
Month &Month::operator--()
{
    monthNumber--;
    if(monthNumber == 2)name = "February";
    else if(monthNumber == 3)name = "March";
    else if(monthNumber == 4)name = "April";
    else if(monthNumber == 5)name = "May";
    else if(monthNumber == 6)name = "June";
    else if(monthNumber == 7)name = "July";
    else if(monthNumber == 8)name = "August";
    else if(monthNumber == 9)name = "September";
    else if(monthNumber == 10)name = "October";
    else if(monthNumber == 11)name = "November";
    else if(monthNumber == 12)name = "December";
    else if(monthNumber == 13){name = "January"; monthNumber = 1;}
    else{name = " "; monthNumber = 0;}

    return *this;
}

//Postfix --
Month Month::operator--(int)
{
    --monthNumber;
    if(monthNumber == 2)name = "February";
    else if(monthNumber == 3)name = "March";
    else if(monthNumber == 4)name = "April";
    else if(monthNumber == 5)name = "May";
    else if(monthNumber == 6)name = "June";
    else if(monthNumber == 7)name = "July";
    else if(monthNumber == 8)name = "August";
    else if(monthNumber == 9)name = "September";
    else if(monthNumber == 10)name = "October";
    else if(monthNumber == 11)name = "November";
    else if(monthNumber == 12)name = "December";
    else if(monthNumber == 13){name = "January"; monthNumber = 1;}
    else{name = " "; monthNumber = 0;}

    return *this;
}

ostream &operator << (ostream &strm, Month &obj)
{
    strm << obj.monthNumber << " " << obj.name << endl
         << "Prefix ++: " << obj.monthNumber++ << endl
         << "Postfix ++: " << ++obj.monthNumber << endl
         << "Prefix --: " << obj.monthNumber-- << endl
         << "Postfix --: " << --obj.monthNumber << endl;

    return strm;
}

istream &operator >> (istream &strm, Month &obj)
{
    cout<<"Enter the month name or number: ";
    strm >> obj.name;

    //Convert string to int
    if(obj.name == "1")
    {
        obj.monthNumber = 1;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "2")
    {
        obj.monthNumber = 2;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "3")
    {
        obj.monthNumber = 3;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "4")
    {
        obj.monthNumber = 4;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "5")
    {
        obj.monthNumber = 5;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "6")
    {
        obj.monthNumber = 6;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "7")
    {
        obj.monthNumber = 7;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "8")
    {
        obj.monthNumber = 8;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "9")
    {
        obj.monthNumber = 9;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "10")
    {
        obj.monthNumber = 10;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "11")
    {
        obj.monthNumber = 11;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    else if(obj.name == "12")
    {
        obj.monthNumber = 12;
        //Send to int constructor
        Month(obj.monthNumber);
    }
    //If not an int, send to string constructor
    else Month(obj.name);
}
