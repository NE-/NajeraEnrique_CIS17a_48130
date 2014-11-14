/*
 * File:    PrsnlDat.cpp
 * Author:  Enrique Najera
 * Purpose: Stores personal data
 *          of the user and 2 others
 */

//System Libraries
#include <iostream>

//Published Libraries
#include "PrsnlDat.hpp"

//Start mutator setName
void PrsnlDat::setName(string n)
{
	name = n;
}//End setName

//Start mutator setAddress
void PrsnlDat::setAddress(string addr)
{
	address = addr;
}//End setAddress

//Start mutator setAge
void PrsnlDat::setAge(short a)
{
	age = a;
}//End setAge

//Start mutator setPhNum
void PrsnlDat::setPhNum(int pN)
{
	phNum = pN;
}//End setPhNum

//Start accessor getName
string PrsnlDat::getName() const
{
	return name;
}//End getName

//Start accessor getAddress
string PrsnlDat::getAddress() const
{
	return address;
}//End getAddress

//Start accessor getAge
short PrsnlDat::getAge() const
{
	return age;
}//End getAge

//Start accessor getPhNum
int PrsnlDat::getPhNum() const
{
	return phNum;
}//End getPhNum
