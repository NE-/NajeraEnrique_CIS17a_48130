/*
 * File:    SavingsAccount.cpp
 * Author:  Najera Enrique
 * Purpose: Manage savings account
 * 12 December 2014
 */

//System Libraries
#include <iostream>

//Published Libraries
#include "SavingsAccount.hpp"

//Namespaces
using namespace std;

//Start SavingsAccount
SavingsAccount::SavingsAccount(float b)
{
    //INIT vars
    if(b > 0)Balance = b;
    else Balance     = 0;
    FreqWithDraw     = 0;
    FreqDeposit      = 0;
}//End SavingsAccount

//Start Transaction
void SavingsAccount::Transaction(float tAction)
{
    if(tAction > 0)Deposit(tAction);
    else if(tAction < 0)Withdraw(tAction);
}//End Transaction

//Start Deposit
float SavingsAccount::Deposit(float d)
{
    Balance += d;
    ++FreqDeposit;
}//End Deposit

//Start Withdraw
float SavingsAccount::Withdraw(float w)
{
    if(Balance > w)
    {
        Balance -= w;
        ++FreqWithDraw;
    }
    else cout << "WithDraw not Allowed\n";
}//End Withdraw

//Start toString
void SavingsAccount::toString()
{
    cout << "Balance = "   << Balance      << endl;
    cout << "WithDraws = " << FreqWithDraw << endl;
    cout << "Deposits = "  << FreqDeposit  << endl;
}//End toString

//Start Total
float SavingsAccount::Total(float savint, int time)
{
    float ttl = 0;
    for(int i = 0; i < time; i++)
    {
        ttl = (Balance*(1+savint))*i;
    }

    return ttl;
}//End Total

//Start TotalRecursive
float SavingsAccount::TotalRecursive(float savint, int time)
{
    float rTtl = 0;

    for(int i = 0; i < time; i++)
    {
        rTtl = (Balance*TotalRecursive(i,savint));
    }

    return rTtl;
}//End TotalRecursive
