/*
 * File:    CustomerData.hpp
 * Author:  Enrique Najera
 * Purpose: Holds, sets, and gets
 *          customer's data
 * 02 December 2014
 */

#ifndef CUSTOMERDATA_HPP
#define CUSTOMERDATA_HPP

//Published Libraries
#include "PersonData.hpp"

class CustomerData : public PersonData
{
    private:
        int customerNumber; // Holds customer's number
        bool mailingList;   // Holds if mailing list
    public:
        //Constructor
        //Default
        CustomerData()
            { customerNumber = 0;
              mailingList = true; }

        //Mutator Functions
        void setCNum(int cN)
            { customerNumber = cN; }
        void isMailList(bool mL)
            { mailingList = mL; }

        //Accessor Function
        int getCNum() const
            { return customerNumber; }
        bool getIsMailingList() const
            { return mailingList; }
};

#endif // CUSTOMERDATA_HPP
