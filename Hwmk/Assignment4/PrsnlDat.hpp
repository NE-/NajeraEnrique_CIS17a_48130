/*
 * File:    PrsnlDat.hpp
 * Author:  Enrique Najera
 * Purpose: Stores personal data
 *          of the user and 2 others 
 */

#ifndef PRSNLDAT_HPP
#define PRSNLDAT_HPP

//System Libraries
#include <string>

//Namespaces
using std::string; //iostream

//Start class PrsnlDat
class PrsnlDat
{
	private:
	    string name;    // User's name
	    string address; // User's address
	    short age;      // User's age
	    int phNum;  	// User's phone number	
	public:
		//Mutator Functions
		void setName(string);      // Set name
		void setAddress(string);   // Set address
		void setAge(short);        // Set age
		void setPhNum(int);        // Set phone number
		
		//Accessor Functions
		string getName() const;    // Get name
		string getAddress() const; // Get address
		short getAge() const;      // Get age
		int getPhNum() const;      // Get phone number
};
//End class PrsnlDat 

#endif //PRSNLDAT_HPP
