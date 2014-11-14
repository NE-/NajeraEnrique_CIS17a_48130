/*
 * File:    Numbers.cpp
 * Author:  Enrique Najera
 * Purpose: Convert whole numbers
 *          to english description
 */

//System Libraries
#include <iostream>

//Published Libraries
#include "Numbers.hpp"

//Namespaces
using namespace std; //iostream

//Start constructor
Numbers::Numbers(int n)
{
    //Initialize variable
    number = n;

    print(number);
}

//Print english number name
void Numbers::print(int n)
{
    //Declare function variables
    string lessThan20[20] = {"zero","one","two","three","four",
                             "five","six","seven","eight","nine",
                             "ten","eleven","twelve","thirteen","fourteen",
                             "fifteen","sixteen","seventeen","eighteen","ninteen"};
    string tens[8] = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
    string hundred = "hundred";
    string thousand = "thousand";

    //Check for out of range
    if(n > 9999)cout<<"INVALID INPUT!\nRANGE(0 - 9999)\n";

    //If in the thousands
    else if(n <= 9999 && n >= 1000)
    {
        //Check the thousands place
        if(((n%10000)/1000) < 10 && ((n%10000)/1000) != 0)
        {
            cout<<lessThan20[(n%10000)/1000]<<" "<<thousand;

            //Check the hundreds
            if(((n%1000)/100) < 10 && ((n%1000)/1000) != 0)
            {
                cout<<" "<<lessThan20[(n%1000)/100]<<" "<<hundred;

                //Check the tens
                if(n%100 >= 20 && n%100 != 0)
                {
                    cout<<" "<<tens[((n%100)/10)-2];

                    //Check the ones place
                    if(n%10 < 10 && n%10 != 0)
                    {
                        cout<<" "<<lessThan20[n%10];
                    }
                }
                //Check the ones place
                else if(n%100 < 20 && n%100 != 0)
                {
                    cout<<" "<<lessThan20[n%100];
                }
            }
        }
    }
    //If in the hundreds place
    if(n >= 100 && n <= 999)
    {
        cout<<lessThan20[n/100]<<" "<<hundred;
        //Check the tens place
        if(n%100 >= 20)
        {
            cout<<" "<<tens[((n%100)/10)-2]<<" ";

            //Check the ones place
            if(n%10 < 10 && n%10 != 0)
            {
                cout<<lessThan20[n%10];
            }
        }
        //Check the ones place
        else if(n%100 < 20 && n%100 != 0)
        {
            cout<<" "<<lessThan20[n%100];
        }
    }
    //If in the tens place
    else if(((n%100)/10) == 2)
    {
        cout<<" "<<tens[0]<<" ";

        //Check the ones place
        if(n%10 < 10 && n%10 != 0)
        {
            cout<<lessThan20[n%10];
        }
    }
    else if(((n%100)/10) == 3)
    {
        cout<<" "<<tens[1]<<" ";

        //Check the ones place
        if(n%10 < 10 && n%10 != 0)
        {
            cout<<lessThan20[n%10];
        }
    }
    else if(((n%100)/10) == 4)
    {
        cout<<" "<<tens[2]<<" ";

        //Check the ones place
        if(n%10 < 10 && n%10 != 0)
        {
            cout<<lessThan20[n%10];
        }
    }
    else if(((n%100)/10) == 5)
    {
        cout<<" "<<tens[3]<<" ";

        //Check the ones place
        if(n%10 < 10 && n%10 != 0)
        {
            cout<<lessThan20[n%10];
        }
    }
    else if(((n%100)/10) == 6)
    {
        cout<<" "<<tens[4]<<" ";

        //Check the ones place
        if(n%10 < 10 && n%10 != 0)
        {
            cout<<lessThan20[n%10];
        }
    }
    else if(((n%100)/10) == 7)
    {
        cout<<" "<<tens[5]<<" ";

        //Check the ones place
        if(n%10 < 10 && n%10 != 0)
        {
            cout<<lessThan20[n%10];
        }
    }
    else if(((n%100)/10) == 8)
    {
        cout<<" "<<tens[6]<<" ";

        //Check the ones place
        if(n%10 < 10 && n%10 != 0)
        {
            cout<<lessThan20[n%10];
        }
    }
    else if(((n%100)/10) == 9)
    {
        cout<<" "<<tens[7]<<" ";

        //Check the ones place
        if(n%10 < 10 && n%10 != 0)
        {
            cout<<lessThan20[n%10];
        }
    }
    //Check the ones place
    else if(n%100 < 20 && n%100 != 0)
    {
        cout<<" "<<lessThan20[n%100];
    }
    //If zero
    else if(n == 0)cout<<lessThan20[0];
    //If other
    else cout<<"INVALID INPUT OR SYSTEM ERROR!\n";

    cout<<endl;
}
