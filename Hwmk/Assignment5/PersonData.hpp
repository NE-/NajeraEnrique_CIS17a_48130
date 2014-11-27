/*
 * File:    PersonData.hpp
 * Author:  Enrique Najera
 * Purpose: Holds, sets and gets
 *          data for person
 * 02 December 2014
 */

#ifndef PERSONDATA_HPP
#define PERSONDATA_HPP

//System Libraries
#include <string>

using namespace std;

class PersonData
{
    private:
        string lastName;
        string firstName;
        string address;
        string city;
        string state;
        string phone;
        int zip;
    public:
        //Constructor
        //Default
        PersonData()
        { lastName  = " ";
          firstName = " ";
          address   = " ";
          city      = " ";
          state     = " ";
          phone     = " ";
          zip       = 0;   }

        //Set constructor
        PersonData(string, string, string,
                   string, string, string, int);

        //Mutator Functions
        void setLname(string lM)
            { lastName = lM; }
        void setFname(string fM)
            { firstName = fM; }
        void setAddress(string a)
            { address = a; }
        void setCity(string c)
            { city = c; }
        void setState(string s)
            { state = s; }
        void setPhone(string p)
            { phone = p; }
        void setZip(int z)
            { zip = z; }

        //Accessor Functions
        string getLName() const
            { return lastName; }
        string getFName() const
            { return firstName; }
        string getAddress() const
            { return address; }
        string getCity() const
            { return city; }
        string getState() const
            { return state; }
        string getPhone() const
            { return phone; }
        int getZip() const
            { return zip; }
};

#endif // PERSONDATA_HPP
