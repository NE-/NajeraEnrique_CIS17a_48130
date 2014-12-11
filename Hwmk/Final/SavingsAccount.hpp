/*
 * File:    SavingsAccount.hpp
 * Author:  Najera Enrique
 * Purpose: Manage savings account
 * 12 December 2014
 */

#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

class SavingsAccount
{
    private:
		float Withdraw(float);               //Utility Procedure
		float Deposit(float);                //Utility Procedure
		float Balance;                       //Property
		int   FreqWithDraw;                  //Property
		int   FreqDeposit;
    public:
		SavingsAccount(float);               //Constructor
		void  Transaction(float);            //Procedure
		float Total(float=0,int=0);	         //Savings Procedure
		float TotalRecursive(float=0,int=0);
		void  toString();
};

#endif // SAVINGSACCOUNT_HPP
