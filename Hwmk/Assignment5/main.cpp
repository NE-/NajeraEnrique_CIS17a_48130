/*
 * File:    main.cpp
 * Author:  Enrique Najera
 * Purpose: Assignment 5 Menu
 *          Gaddis 8th ed. ch 15-16
 * 02 December 2014
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>

//Published Libraries
//Chapter 15
//-ch15 prob1
#include "ProductionWorker.hpp"
//-ch15 prob 4
#include "MilTime4.hpp"
//-ch15 prob 5
#include "TimeClock.hpp"
//-ch15 prob 6
#include "Essay.hpp"
//-ch15 prob 7
#include "CustomerData.hpp"

//Chapter 16
//-ch16 prob 1
#include "Date.hpp"
//-ch16 prob 2
#include "MilTime2.hpp"
//-ch16 prob 9
#include "SearchableVector.hpp"
//-ch16 prob 16
#include "ProductionWorker16.hpp"

//Namespaces
using namespace std;

//Function Prototypes
void Menu();     // Display main menu
int getN();      // Get user's choice
void def(int);   // Exit the program

void problem1(); // Gaddis ch15 prob  1
void problem2(); // Gaddis ch15 prob  4
void problem3(); // Gaddis ch15 prob  5
void problem4(); // Gaddis ch15 prob  6
void problem5(); // Gaddis ch15 prob  7
void problem6(); // Gaddis ch16 prob  1
void problem7(); // Gaddis ch16 prob  2
void problem8(); // Gaddis ch16 prob  9
void problem9(); // Gaddis ch16 prob 15
void problem10();// Gaddis ch16 prob 16

//Problem Functions
//Ch 15 Prob 7
string MList(int); // Checks and outputs if
                   // customer is on mailing list

//No Global Variables

//Start Method main
int main(int argv, char *argc[])
{
    //Declare Variables
    int inN = 0; //Get input for main menu

    do{
        Menu();
        inN=getN();

        switch(inN){
            case 1: problem1();break; // Gaddis ch15 prob  1
            case 2: problem2();break; // Gaddis ch15 prob  4
            case 3: problem3();break; // Gaddis ch15 prob  7
            case 4: problem4();break; // Gaddis ch15 prob  9
            case 5: problem5();break; // Gaddis ch15 prob 16
            case 6: problem6();break; // Gaddis ch16 prob  1
            case 7: problem7();break; // Gaddis ch16 prob  2
            case 8: problem8();break; // Gaddis ch16 prob  4
            case 9: problem9();break; // Gaddis ch16 prob  7
            case 10: problem10();break;// Gaddis ch16 prob  7
            default: def(inN);}
    }while(inN<11);

    system("PAUSE");
    return 0;
}

void Menu()
{
   cout<<"Type  1 for problem  1"<<endl;
   cout<<"Type  2 for problem  2"<<endl;
   cout<<"Type  3 for problem  3"<<endl;
   cout<<"Type  4 for problem  4"<<endl;
   cout<<"Type  5 for problem  5"<<endl;
   cout<<"Type  6 for problem  6"<<endl;
   cout<<"Type  7 for problem  7"<<endl;
   cout<<"Type  8 for problem  8"<<endl;
   cout<<"Type  9 for problem  9"<<endl;
   cout<<"Type 10 for problem 10"<<endl;
   cout<<"Type 11 to exit \n"<<endl;
}

int getN()
{
   int inN;
   cin>>inN;
   return inN;
}

//Start Problems
// Gaddis ch15 prob  1
void problem1()
{
    //Declare Variables
    char temp[50];  // Temporarily hold employee name
    string eName;   // Holds employee name
    int eNumbr = 0; // Holds employee number
    int hireDt = 0; // Holds hire date
    int shift  = 0; // Holds shift 1 = day, 2 = night
    float hPR  = 0; // Holds pay rate by hour

    //Prompt for Employee info
    cin.ignore();
    cout << "Enter the employee's name: " << endl;
    cin.getline(temp, 50);
    eName = temp;
    cout << "Enter the employee's number: " << endl;
    cin >> eNumbr;
    cout << "Enter the employee's hire date (mmddyy format): "
         << endl;
    cin >> hireDt;

    //Set inputs
    Employee e(eName, eNumbr, hireDt);

    //Prompt for ProductionWorker info
    cout << "Enter " << e.getEmpName() << "'s shift (1 = day, 2 = night): "
         << endl;
    cin >> shift;
    cout << "Enter " << e.getEmpName() << "'s hourly pay rate: "
         << endl;
    cin >> hPR;

    //Set inputs
    ProductionWorker pW(shift, hPR);

    //Output data
    cout << "Employee: "  << e.getEmpName()  << endl;
    cout << "Number : "   << e.getEmpNum()   << endl;
    cout << "Hire date: " << e.getHireDate() << endl;
    cout << "Hourly pay rate: " << pW.getHrPayRt() << endl;
    cout << "Shift: " << pW.getShift() << endl;
    cout << endl;

}// Gaddis ch15 prob 1

// Gaddis ch15 prob  4
void problem2()
{
    //Declare Variables
    int mHr;  // Holds military hour
    int mSec; // Holds seconds

    //Prompt for hour and seconds
    while(true)
    {
        cout << "Enter the military hour to be converted to standard time: " << endl;
        cin >> mHr;

        //Input Validation
        if(mHr > 2359 || mHr < 0)cout << "Hours must be from 0 - 2359\n";
        else
        {
            cout << "Enter the seconds: " << endl;
            cin >> mSec;

            //Input Validation
            if(mSec > 59 || mSec < 0)cout << "Seconds must be from 0 - 59\n";
            else
            {
                //Start Conversion
                MilTime4 mT(mHr, mSec);

                //Output results
                cout << "Military Time: " << mT.getHour() << endl;
                cout << "Standard Time: " << mT.getStandHr() <<":"
                     << setw(2) << setfill('0') << mT.getMin() << "."
                     << setw(2) << setfill('0') << mT.getSec() <<" "
                     << mT.getAoP() << endl;
                break;
            }//end if seconds
        }//end if hours
    }//end while

    cout << endl;

}// Gaddis ch15 prob 4

// Gaddis ch15 prob  5
void problem3()
{
    //Declare Variables
    int mHr1 = 0;  // Holds military hour 1
    int mHr2 = 0;  // Holds military hour 2

    while(true)
    {
        cout << "Enter the starting time in military time format: " << endl;
        cin>>mHr1;

        //Input Validation
        if(mHr1 < 0 || mHr1 > 2359)cout << "Range must be between 0 - 2359\n";
        else
        {
            cout << "Enter the ending time in military time format: " << endl;
            cin>>mHr2;

            //Input Validation
            if(mHr1 < 0 || mHr1 > 2359)cout << "Range must be between 0 - 2359\n";
            else
            {
                TimeClock tC(mHr1, mHr2);

                break;
            }//end if 2nd hour
        }//end if 1st hour
    }//end while

    cout << endl;

}// Gaddis ch15 prob 5

// Gaddis ch15 prob  6
void problem4()
{
    //Declare Variables
    int gr = 0, // Holds grammar pts
        sp = 0, // Holds spelling pts
        cL = 0, // Holds correct length pts
        co = 0; // Holds content pts

    //Prompt for essay data
    cout << "How many points for grammar (MAX: 30)" << endl;
    cin >> gr;

    // Input validation
    if (gr > 30 || gr < 0)
    {
        cout << "\nPoints must be from 0 to 30\nInitializing points to 0\n\n";
        gr = 0;
    }

    cout << "How many points for spelling (MAX: 20)" << endl;
    cin >> sp;

    // Input validation
    if (sp > 20 || sp < 0)
    {
        cout << "\nPoints must be from 0 to 20\nInitializing points to 0\n\n";
        sp = 0;
    }

    cout << "How many points for correct length (MAX: 20)" << endl;
    cin >> cL;

    // Input validation
    if (cL > 20 || cL < 0)
    {
        cout << "\nPoints must be from 0 to 20\nInitializing points to 0\n\n";
        cL = 0;
    }

    cout << "How many points for content (MAX: 30)" << endl;
    cin >> co;

    // Input validation
    if (co > 30 || co < 0)
    {
        cout << "\nPoints must be from 0 to 30\nInitializing points to 0\n\n";
        co = 0;
    }

    //Define Essay object
    Essay e(gr, sp, cL, co);

    //Display results
    cout << "Total score for essay: " << e.getScore() << "/100" << endl;
    cout << "Final letter grade: " << e.getLetterGrade() << endl;

    cout << endl;

}// Gaddis ch15 prob 6

// Gaddis ch15 prob  7
void problem5()
{
    //Declare Variables
    string lName = " "; // Holds Last Name
    string fName = " "; // Holds First Name
    string adrs  = " "; // Holds Address
    string city  = " "; // Holds City
    string state = " "; // Holds State
    string phone = " "; // Holds Phone Number
    int zip      = 0;   // Holds ZIP Code

    int cNum     = 0;   // Holds customer number
    char mList;         // Holds if wants to be on mailing list

    //Create objects
    CustomerData cD;

    //Prompt for person data
    cout << "Enter the customer's last name"    << endl;
    cin >> lName;
    cout << "Enter the customer's first name"   << endl;
    cin >> fName;
    cout << "Enter the customer's address"      << endl;
    cin >> adrs;
    cout << "Enter the customer's city"         << endl;
    cin >> city;
    cout << "Enter the customer's state"        << endl;
    cin >> state;
    cout << "Enter the customer's phone number" << endl;
    cin >> phone;
    cout << "Enter the customer's ZIP"          << endl;
    cin >> zip;

    //Send data to constructor
    PersonData pD(lName, fName, adrs, city, state, phone, zip);

    //Prompt for customer data
    cout << "Enter " << pD.getLName() << "'s customer number" << endl;
    cin >> cNum;
    cD.setCNum(cNum);

    cout << "Does the customer wish to be on the mailing list? (y/n)" << endl;
    cin >> mList;

    //Check if mailing list true or false
    if (mList == 'y' || mList == 'Y')
        cD.isMailList(true);
    else if (mList == 'n' || mList == 'N')
        cD.isMailList(false);
    else {;}

    //Output Results
    cout << "Last Name: "    << pD.getLName()   << endl;
    cout << "First Name: "   << pD.getFName()   << endl;
    cout << "Address: "      << pD.getAddress() << endl;
    cout << "City: "         << pD.getCity()    << endl;
    cout << "State: "        << pD.getState()   << endl;
    cout << "ZIP: "          << pD.getZip()     << endl;
    cout << "Phone Number: " << pD.getPhone()   << endl;
    cout << "Mailing list: " << MList(cD.getIsMailingList()) <<endl;

    cout << endl;

}// Gaddis ch15 prob 7

// Gaddis ch16 prob  1
void problem6()
{
    //Declare Variables
    int month; // Holds month (digits)
    int day;   // Holds day
    int year;  // Holds year

    //Create Date object
    Date dt;

    //Prompt for input
    cout << "Enter the digit of the month: ";
    cin >> month;
    cout << "Enter the day: ";
    cin >> day;
    cout << "Enter the year: ";
    cin >> year;

    //Store values in the Date object
    try
    {
        dt.setMnth(month);
        dt.setDay(day);
        dt.setYr(year);

        //If no error, print Results
        dt.printDay(month, day, year);
        dt.printMnth(month, day, year);
        dt.printNums(month, day, year);

    }
    catch(Date::InvalidDay)
    {
        cout << "\nERROR: DAY RANGES FROM 1 - 31!\n";
    }
    catch(Date::InvalidMonth)
    {
        cout << "\nERROR: MONTH RANGES FROM 1 - 12!\n";
    }

    cout << endl;

}// Gaddis ch16 prob 1

// Gaddis ch16 prob  2
void problem7()
{
    //Declare Variables
    int mHr;  // Holds military hour
    int mSec; // Holds seconds

    //Prompt for hour and seconds
    cout << "Enter the military hour to be converted to standard time: " << endl;
    cin >> mHr;

    cout << "Enter the seconds: " << endl;
    cin >> mSec;

    //Start Conversion
    try
    {
        MilTime2 mT(mHr, mSec);

        //If no error, output results
        cout << "Military Time: " << mT.getHour() << endl;
        cout << "Standard Time: " << mT.getStandHr() <<":"
            << setw(2) << setfill('0') << mT.getMin() << "."
            << setw(2) << setfill('0') << mT.getSec() <<" "
            << mT.getAoP() << endl;
    }
    catch(MilTime2::BadHour)
    {
        cout << "\nERROR: HOUR RANGES FROM 000 - 2359!\n";
    }
    catch(MilTime2::BadSeconds)
    {
        cout << "\nERROR: SECONDS RANGE FROM 0 - 59!\n";
    }

    cout << endl;

}// Gaddis ch16 prob 2

// Gaddis ch16 prob  9
void problem8()
{
    //Declare Variables
    const int SIZE = 10;
    int count;
    int result;

    //Define a vector element
    vector<int> vect;

    //Create two SearchableVector objects
    SearchableVector<int> intTable(SIZE);
    SearchableVector<float> floatTable(SIZE);

    //Store values in the objects
    for (count = 0; count < SIZE; count++)
    {
        intTable[count] = (count * 2);
        floatTable[count] = (count * 2.14);
    }

    //Display the values in the objects
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl << endl;
    cout << "These values are in floatTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << floatTable[count] << " ";
    cout << endl;

    //Search for the value 6 in intTable
    cout << "\nSearching for 6 in intTable.\n";
    result = intTable.findItem(6);
    if (result == -1)
        cout << "6 was not found in intTable.\n";
    else
        cout << "6 was found at subscript " << result << endl;

    //Search for the value 12.84 in floatTable
    cout << "\nSearching for 12.84 in floatTable.\n";
    result = floatTable.findItem(12.84);
    if (result == -1)
        cout << "12.84 was not found in floatTable.\n";
    else
        cout << "12.84 was found at subscript " << result << endl;

    cout << endl;

}// Gaddis ch16 prob 9

// Gaddis ch16 prob  15
void problem9()
{
    //Declare Variables
    int userNum; // Holds user's account number

    //Define Vector element
    vector<int> vect;

    //Add values to vector element
    vect.push_back(5658845);
    vect.push_back(4520125);
    vect.push_back(7895122);
    vect.push_back(8777541);
    vect.push_back(8451277);
    vect.push_back(1302850);
    vect.push_back(8080152);
    vect.push_back(4562555);
    vect.push_back(5552012);
    vect.push_back(5050552);
    vect.push_back(7825877);
    vect.push_back(1250255);
    vect.push_back(1005231);
    vect.push_back(6545231);
    vect.push_back(3852085);
    vect.push_back(7576651);
    vect.push_back(7881200);
    vect.push_back(4581002);

    //Prompt for user account number
    cout << "Enter your charge account number: ";
    cin >> userNum;

    //Sort contents of the vector
    sort(vect.begin(), vect.end());

    //Send to validation and output result
    if (binary_search(vect.begin(), vect.end(), userNum))cout << "The number is valid!\n";
    else cout << "The number is invalid!\n";

    cout << endl;

}// Gaddis ch16 prob 15

// Gaddis ch16 prob  16
void problem10()
{
    //Declare Variables
    char temp[50];  // Temporarily hold employee name
    string eName;   // Holds employee name
    int eNumbr = 0; // Holds employee number
    int hireDt = 0; // Holds hire date
    int shift  = 0; // Holds shift 1 = day, 2 = night
    float hPR  = 0; // Holds pay rate by hour

    //Prompt for Employee info
    cin.ignore();
    cout << "Enter the employee's name: " << endl;
    cin.getline(temp, 50);
    eName = temp;
    cout << "Enter the employee's number: " << endl;
    cin >> eNumbr;
    cout << "Enter the employee's hire date (mmddyy format): "
         << endl;
    cin >> hireDt;

    //Set inputs
    Employee16 e(eName, eNumbr, hireDt);

    //Check for errors
    try
    {
        Employee16 e(eName, eNumbr, hireDt);
    }
    catch(Employee16::InvalidEmployeeNumber)
    {
        cout << "\nERROR: Employee number must be between 0 - 9999!\n";
        exit(EXIT_FAILURE);
    }

    //Prompt for ProductionWorker info
    cout << "Enter " << e.getEmpName() << "'s shift (1 = day, 2 = night): "
         << endl;
    cin >> shift;
    cout << "Enter " << e.getEmpName() << "'s hourly pay rate: "
         << endl;
    cin >> hPR;

    //Set inputs
    ProductionWorker16 pW(shift, hPR);

    //Check for errors
    try
    {
        ProductionWorker16 pW(shift, hPR);
    }
    catch(ProductionWorker16::InvalidShift)
    {
        cout << "\nERROR: Shift must be either 1 or 2!\n";
        exit(EXIT_FAILURE);
    }
    catch(ProductionWorker16::InvalidPayRate)
    {
        cout << "\nERROR: Hourly Pay rate must be above 0!\n";
        exit(EXIT_FAILURE);
    }
    //Output data
    cout << "Employee: "  << e.getEmpName()  << endl;
    cout << "Number : "   << e.getEmpNum()   << endl;
    cout << "Hire date: " << e.getHireDate() << endl;
    cout << "Hourly pay rate: " << pW.getHrPayRt() << endl;
    cout << "Shift: " << pW.getShift() << endl;

    cout << endl;
}// Gaddis ch16 prob 16

//Problem Functions
//Start MList
string MList(int mL)
{
    if (mL == 1) return "Yes";
    else if (mL == 0) return "No";
    else return "ERROR";
}//End MList

void def(int inN)
{
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
