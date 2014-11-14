/*
 * File: main.cpp
 * Author: Enrique Najera
 * Purpose: Assignment 4 Menu
 *          Gaddis 8th ed. ch 13-14
 * 18 November 2014
 */

//System Libraries
#include <iostream>
#include <string>

//Published Libraries
//-Chapter 13
#include "Date.hpp"
#include "PrsnlDat.hpp"
#include "TestScores.hpp"
#include "Population.hpp"
#include "Temperature.hpp"
//-Chapter 14
#include "Numbers.hpp"
#include "DayOfYear.hpp"
#include "NumDays.hpp"
#include "Month.hpp"

//Namespaces
using namespace std; //iostream, string

//Function Prototypes
void Menu();     // Display main menu
int getN();      // Get user's choice
void def(int);   // Exit the program

void problem1(); // Gaddis ch13 prob  1
void problem2(); // Gaddis ch13 prob  4
void problem3(); // Gaddis ch13 prob  7
void problem4(); // Gaddis ch13 prob  9
void problem5(); // Gaddis ch13 prob 16
void problem6(); // Gaddis ch14 prob  1
void problem7(); // Gaddis ch14 prob  2
void problem8(); // Gaddis ch14 prob  4
void problem9(); // Gaddis ch14 prob  7

//No Global Variables

//Start Method Main
int main(int argv, char *argc[])
{
    //Declare Variables
    int inN = 0; //Get input for the main menu

    do{
        Menu();
        inN=getN();

        switch(inN){
            case 1: problem1();break; // Gaddis ch13 prob  1
            case 2: problem2();break; // Gaddis ch13 prob  4
            case 3: problem3();break; // Gaddis ch13 prob  7
            case 4: problem4();break; // Gaddis ch13 prob  9
            case 5: problem5();break; // Gaddis ch13 prob 16
            case 6: problem6();break; // Gaddis ch14 prob  1
            case 7: problem7();break; // Gaddis ch14 prob  2
            case 8: problem8();break; // Gaddis ch14 prob  4
            case 9: problem9();break; // Gaddis ch14 prob  7
            default: def(inN);}
    }while(inN<10);

    system("PAUSE");
    return 0;
}

void Menu()
{
   cout<<"Type 1 for problem 1"<<endl;
   cout<<"Type 2 for problem 2"<<endl;
   cout<<"Type 3 for problem 3"<<endl;
   cout<<"Type 4 for problem 4"<<endl;
   cout<<"Type 5 for problem 5"<<endl;
   cout<<"Type 6 for problem 6"<<endl;
   cout<<"Type 7 for problem 7"<<endl;
   cout<<"Type 8 for problem 8"<<endl;
   cout<<"Type 9 for problem 9"<<endl;
   cout<<"Type 10 to exit \n"<<endl;
}

int getN()
{
   int inN;
   cin>>inN;
   return inN;
}

//Start Problems
// Gaddis ch13 prob  1
void problem1()
{
    //Define instance
    Date d;

    d.getVals(); //Get Month, Day, Year values
    cout<<endl;
}// Gaddis ch13 prob  1

// Gaddis ch13 prob  4
void problem2()
{
    //Declare Variables
	string name;    // Holds the name of user
	string address; // Holds the address of user
	short age = 0;  // Holds the age of user
	int pNum  = 0;  // Holds the phone number of user

	//Define Instances
	PrsnlDat pD1;
	PrsnlDat pD2;
	PrsnlDat pD3;

	cin.ignore();

	//Prompt for user's info
	cout<<"1) Enter your name: ";
	getline(cin, name);
	pD1.setName(name);

	cout<<"1) Enter your address: ";
	getline(cin, address);
	pD1.setAddress(address);

	cout<<"1) Enter your age: ";
	cin>>age;
	pD1.setAge(age);

	cout<<"1) Enter your phone number: ";
	cin>>pNum;
	pD1.setPhNum(pNum);

	cin.ignore();

	//Prompt for family/friend info
	cout<<"\n2) Enter your family member's or friend's name: ";
	getline(cin, name);
	pD2.setName(name);

	cout<<"2) Enter your family member's or friend's address: ";
	getline(cin, address);
	pD2.setAddress(address);

	cout<<"2) Enter your family member's or friend's age: ";
	cin>>age;
	pD2.setAge(age);

	cout<<"2) Enter your family member's or friend's phone number: ";
	cin>>pNum;
	pD2.setPhNum(pNum);

	cin.ignore();

	//Prompt for family/friend info
	cout<<"\n3) Enter your family member's or friend's name: ";
	getline(cin, name);
	pD3.setName(name);

	cout<<"3) Enter your family member's or friend's address: ";
	getline(cin, address);
	pD3.setAddress(address);

	cout<<"3) Enter your family member's or friend's age: ";
	cin>>age;
	pD3.setAge(age);

	cout<<"3) Enter your family member's or friend's phone number: ";
	cin>>pNum;
	pD3.setPhNum(pNum);

	//Display data
	cout<<"\n"<<pD1.getName()<<"'s data\n";
	cout<<pD1.getName()<<"'s address: "     <<pD1.getAddress()<<endl;
	cout<<pD1.getName()<<"'s age: "         <<pD1.getAge()<<endl;
	cout<<pD1.getName()<<"'s phone number: "<<pD1.getPhNum()<<endl;

	cout<<"\n"<<pD2.getName()<<"'s data\n";
	cout<<pD2.getName()<<"'s address: "     <<pD2.getAddress()<<endl;
	cout<<pD2.getName()<<"'s age: "         <<pD2.getAge()<<endl;
	cout<<pD2.getName()<<"'s phone number: "<<pD2.getPhNum()<<endl;

	cout<<"\n"<<pD3.getName()<<"'s data\n";
	cout<<pD3.getName()<<"'s address: "     <<pD3.getAddress()<<endl;
	cout<<pD3.getName()<<"'s age: "         <<pD3.getAge()<<endl;
	cout<<pD3.getName()<<"'s phone number: "<<pD3.getPhNum()<<endl;

	cout<<endl;
}// Gaddis ch13 prob  4

// Gaddis ch13 prob  7
void problem3()
{
    //Declare variables
    float scr = 0; //Holds scores

    //Define Instance
    TestScores t1; // Holds first score
    TestScores t2; // Holds second score
    TestScores t3; // Holds third score

    //Prompt for scores
    cout<<"Enter first score: ";
    cin>>scr;
    t1.setScore(scr);

    cout<<"Enter second score: ";
    cin>>scr;
    t2.setScore(scr);

    cout<<"Enter third score: ";
    cin>>scr;
    t3.setScore(scr);

    //Output average
    scr = (t1.getScrAvg() + t2.getScrAvg() + t3.getScrAvg());

    //Output results
    cout<<"The test score average is: "<<scr<<endl;

    cout<<endl;
}// Gaddis ch13 prob  7

// Gaddis ch13 prob  9
void problem4()
{
    //Declare Variables
    float pop   = 0, // Holds total population
          brths = 0, // Holds total births
          dths  = 0; // Holds total deaths
    float dtRt  = 0, // Holds death rate
          btRt  = 0; // Holds birth rate

    //Define Instances
    Population p;

    //Prompt for input
    while(true)
    {
        cout<<"Enter the total population: ";
        cin>>pop;

        //Input validation pop must be > 1
        if(pop < 1)cout<<"Please enter a number greater than 1!\n";
        else {p.setPopu(pop);break;}
    }

    while(true)
    {
        cout<<"Enter the total births per year: ";
        cin>>brths;

        //Input validation brths must be > 0
        if(brths < 0)cout<<"Please enter a number greater than 0!\n";
        else{p.setNBrth(brths);break;}
    }

    while(true)
    {
        cout<<"Enter the total deaths per year: ";
        cin>>dths;

        //Input validation brths must be > 0
        if(dths < 0)cout<<"Please enter a number greater than 0!\n";
        else{p.setNumDth(dths);break;}
    }

    //Get birth and death rates
    btRt = p.getBrthRt();
    dtRt = p.getDthRt();

    //Output results
    cout<<"In a population of "<<pop<<",\n"
        <<"The birth rate is: "<<btRt<<",\n"
        <<"The death rate is: "<<dtRt<<endl;

    cout<<endl;
}// Gaddis ch13 prob  9

// Gaddis ch13 prob 16
void problem5()
{
    //Declare Variables
	bool c2h5F, c2h5B, // Ethyl  is freezing/boiling
	     o2F, o2B,     // Oxygen is freezing/boiling
		 h2oF, h2oB;   // Water  is freezing/boiling

	float tempt = 0.0f; // Holds temperature

	//Define Instance
	Temperature t;

	//Prompt for temperature
	cout<<"Enter the temperature: ";
	cin>>tempt;

	t.setTemp(tempt);

	//Get bool values
	c2h5F = t.isEthylFreezing();
	c2h5B = t.isEthylBoiling();
	o2F   = t.isOxygenFreezing();
	o2B   = t.isOxygenBoiling();
	h2oF  = t.isWaterFreezing();
	h2oB  = t.isWaterBoiling();

	//Output results
	if(c2h5F == 0){}
	else cout<<"Ethyl is freezing\n";
	if(c2h5B == 0){}
	else cout<<"Ethyl is boiling\n";

	if(o2F == 0){}
	else cout<<"Oxygen is freezing\n";
	if(o2B == 0){}
	else cout<<"Oxygen is boiling\n";

	if(h2oF == 0){}
	else cout<<"Water is freezing\n";
	if(h2oB == 0){}
	else cout<<"Water is boiling\n";

	cout<<endl;
}// Gaddis ch13 prob 16

// Gaddis ch14 prob  1
void problem6()
{
    int mNum = 0; // Holds whole dollar amount

    //Prompt for whole dollar amount
    cout<<"Enter the whole dollar amount (0 - 9999): ";
    cin>>mNum;

    Numbers n(mNum);

    cout<<endl;
}// Gaddis ch14 prob  1

// Gaddis ch14 prob  2
void problem7()
{
    //Declare Variables
    int day = 0; //Holds the day

    //Prompt for the day
    cout<<"Enter a day more than 0 and less than 365: ";
    cin>>day;

    DayOfYear dy(day);

    cout<<endl;
}// Gaddis ch14 prob  2

// Gaddis ch14 prob  4
void problem8()
{
    //Declare variables
    float hours = 0; //Holds hours

    //Prompt for work hours
    cout<<"Enter the first work hours: ";
    cin>>hours;

    NumDays nD1(hours);
    hours = 0; //reset hours

    cout<<"Enter the second work hours: ";
    cin>>hours;

    NumDays nD2(hours);

    //Addition operator
    NumDays nD3 = nD1 + nD2;
    cout<<"\nThe first work hours plus the second is: "<<nD3.getWdays();

    //Subtraction operator
    nD3 = nD1 - nD2;
    cout<<"\nThe first work hours minus the second is: "<<nD3.getWdays();

    //Prefix ++ operator
    ++nD3;
    cout<<"\nPrefix increment is: "<<nD3.getWdays();

    //Postfix ++ operator
    nD3++;
    cout<<"\nPostfix increment is: "<<nD3.getWdays();

    //Prefix -- operator
    --nD3;
    cout<<"\nPrefix decrement is: "<<nD3.getWdays();

    //Postfix -- operator
    nD3--;
    cout<<"\nPostfix decrement is: "<<nD3.getWdays()<<endl;

    cout<<endl;
}// Gaddis ch14 prob  4

// Gaddis ch14 prob  7
void problem9()
{
    //Declare Variables
    int moNa;

    //Define Instance
    Month a;

    //Prompt for input
    cin>>a;

   //Month m(moNa);

    cout<<a;

    cout<<endl;
}// Gaddis ch14 prob  7

void def(int inN)
{
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
