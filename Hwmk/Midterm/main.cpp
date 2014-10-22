/*
 * Author: Enrique Najera
 * File: main.cpp
 * Date: 24 October 2014
 * Purpose: CSC 17A Mideterm 
 */

//System Libraries
#include <iostream>
#include <iomanip>

//Namespaces
using namespace std; //iostream

//Structures
//Problem 1
struct AcctBlnc
{
    int acctNum;  // Customer account number
    int monBlnc;  // Balance at the beginning of the month
    int ttlChx;   // Total of all checks written this month
    int ttlDepos; // Total of all deposits of customer's account
};

//Problem 2
struct GrossPay
{
    string name; // Employee's name
    int hrsWrk;  // Hours worked
    int rOfPay;  // Rate of pay
    int grssPay; // Gross pay 
};

//Problem 3
struct StatsResult
{
    float avg;
    float median; // 
    int *mode;    // Array containing the modes
    int nModes;   // Number of modes in the array
    int maxFreq;  // Max frequency of modes
};

//Problem 4
struct Encrypt
{
    int numDat; // Data in integers
    int num1;   // First number
    int num2;   // Second number
    int num3;   // Third number
    int num4;   // Fourth number
};

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Problem Functions
//Problem 1
int cntAcctNum(int);        // Counts digits in account number
int total(int *, int, int); // Calculates totals

//Problem 3
StatsResult *avgMedMode(int *, int); // Calculate results
void sort(int *, int);               // Sort the array

//Start method main
int main(int argv,char *argc[]){

    //Declare Variables
    int inN = 0; //Get user menu choice
    
    do{
        Menu();     // Display menu
        inN=getN(); // Get user menu choice
        
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            default:   def(inN);
        }
    }while(inN>=1&&inN<=6);
    
    //Exit main program
    system("PAUSE");
    return 0;
}//End method main

//Start method Menu display menu
void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}//End method Menu

//Start method getN get user Menu choice
int getN(){
    int inN;
    cin>>inN;
    return inN;
}//End method getN

//Start method problem1
void problem1(){
    //Declare function Variables
    int *chx;        // Input checks written
    int *dep;        // Input deposits
    int tChecks = 0; // Total of all checks
    int tDepost = 0; // Total of all deposits
    int chxBal  = 0; // Holds beginning balance - checks  
    
    
    AcctBlnc *aNum, aB;
    //INIT vars
    aNum->acctNum  = 0; // Customer account number
    aB.monBlnc     = 0; // Balance at the beginning of the month
    aB.ttlChx      = 0; // Total of all checks written this month
    aB.ttlDepos    = 0; // Total of all deposits of customer's account
    

    //Prompt for customer's account number
    do{
        cout<<"Enter your 5-digit account number: ";
        cin>>aNum->acctNum;
        
        if(cntAcctNum(aNum->acctNum) == 5)
        {
            //Prompt for balance
            cout<<"Enter your balance at the begging of the month: ";
            cin>>aB.monBlnc;
            
            //Prompt for number of checks written
            cout<<"How many checks have you written this month? ";
            cin>>aB.ttlChx;
            
            //Dynamically allocate memory
            chx = new int[aB.ttlChx];
            
            //Get check amounts
            for(int i = 0; i < aB.ttlChx; i++)
            {
                cout<<"Amount of check "<<(i+1)<<": ";
                cin>>chx[i];
            }
            
            //Prompt for deposits
            cout<<"How many deposits have you made this month? ";
            cin>>aB.ttlDepos;
            
            //Dynamically allocate memory
            dep = new int[aB.ttlDepos];
            
            for(int i = 0; i < aB.ttlDepos; i++)
            {
                cout<<"Amount of deposit "<<(i+1)<<": ";
                cin>>dep[i];
            }
            
            //Calculate totals
            tChecks = total(chx, aB.ttlChx, aB.monBlnc);   // Checks
            tDepost = total(dep, aB.ttlDepos, aB.monBlnc); // Deposits
            
            //Calculate balance after checks
            chxBal = (aB.monBlnc - tChecks)+tDepost;
            
            //If account overdrawn
            if(chxBal < 0)
            {
                //Show new balance
                cout<<"Account Overdrawn\n$12 fee has been accessed\n";
                
                //Show balance after fee
                cout<<"New balance after fee: $"<<(chxBal)-12;
                //Free dynamic memory
                delete [] chx;
                delete [] dep;
            }
            //If account not overdrawn
            else
            {
                //Show new balance
                cout<<"New balance: $"<<chxBal<<endl;
                //Free dynamic memory
                delete [] chx;
                delete [] dep;
            }
        }
        else
        {
            cout<<"Account number must be 5-digits only!"<<endl;
        }
    }while(cntAcctNum(aNum->acctNum) != 5);  
}//End method problem1

//Start method problem2
void problem2(){
    int numEmp = 0;    // Number of employees for dynamic memory allocation
    bool show  = true; // To show data if data is good 
        
    GrossPay *gP = NULL; //Pointer for dynamic memory
    
    //Prompt for number of employees
    cout<<"How many employees?: ";
    cin>>numEmp;
    
    //Dynamically allocate memory
    gP = new GrossPay[numEmp];
    
    //Prompt for employee info
    for(int i = 0; i < numEmp; i++)
    {
        cin.ignore();
        cout<<"Enter employee "<<(i+1)<<"'s name: ";
        getline(cin, gP[i].name);
        
        cout<<"Enter the total hours worked: ";
        cin>>gP[i].hrsWrk;
        //Input validation
        if(gP[i].hrsWrk < 0)
        {
            cout<<"Hours must be greater than 0!\n";
            show = false;
            break;
        }
        
        cout<<"Enter the employee's rate of pay: ";
        cin>>gP[i].rOfPay;
        
        //Input validation
        if(gP[i].rOfPay < 0)
        {
            cout<<"Rate of pay must be greater than 0!\n";
            show = false;
            break;
        }
        
        cout<<endl;
    }
    
    //Calculate gross pay
    for(int i = 0; i < numEmp; i++)
    {
        //If worked under 20 Hrs, straight pay
        if(gP[i].hrsWrk <= 20)gP[i].grssPay = gP[i].hrsWrk * gP[i].rOfPay;
        //If worked over 20, under 40, double time pay
        else if(gP[i].hrsWrk > 20 && gP[i].hrsWrk < 40)gP[i].grssPay = (gP[i].hrsWrk * gP[i].rOfPay) * 2;
        //If worked over 40, triple time pay
        else if(gP[i].hrsWrk > 40)gP[i].grssPay = (gP[i].hrsWrk * gP[i].rOfPay) * 3;
        //If none, then error
        else cout<<"ERROR"<<endl;
    }
    
    //Output check
    if(show == true)
    {
        for(int i = 0; i < numEmp; i++)
        {
            cout<<"Employee: "<<gP[i].name<<endl
                <<"Hours worked: "<<gP[i].hrsWrk<<endl
                <<"Rate of pay: $"<<gP[i].rOfPay<<endl
                <<"Gross pay: $"<<gP[i].grssPay<<endl 
                <<endl;
        }
    }

    //Free dynamic memory
    delete [] gP;
    
}//End method problem2

//Start method problem3
void problem3(){
    int *arr   = 0; // Dynamically allocate array
    int numNum = 0; // Holds number of numbers
    int temp   = 0; // Holds number for sorting
    
    StatsResult s;
    
    s.avg     = 0;
    s.median  = 0;
    s.mode    = 0;
    s.nModes  = 0;
    s.maxFreq = 0;
    
    //Prompt for number of numbers
    cout<<"How many numbers do you wish to put in the array?\n";
    cin>>numNum;
    
    arr = new int[numNum];
    
    //Get the numbers
    for(int i = 0; i < numNum; i++)
    {
        cout<<(i+1)<<") Enter number: ";
        cin>>arr[i];
    }

    //Sort the array
    sort(arr, numNum);
   
   //Find and display average, median, and mode
    avgMedMode(arr, numNum);
    
    cout<<endl;
    
    //Free dynamic memory
    delete [] arr;
}//End method problem3

//Start method problem4
void problem4(){
    //Declare Variables
    int temp1  = 0, // Temp holder for swap
        temp2  = 0; // Temp holder for swap
        
    Encrypt e;
    
    e.numDat = 0; // Number data
    e.num1   = 0; // First number
    e.num2   = 0; // Second number
    e.num3   = 0; // Third number
    e.num4   = 0; // Fourth number
    
        
    cout<<"Enter the number to be encrypted: ";
    cin>>e.numDat;
    
    //Input validation
    //If number is 5+ digits or 3- digits 
    if(e.numDat >= 10000 || e.numDat <= 999)
    {
        cout<<"Integer must be 4-digit!"<<endl;
    }
    else
    {
        //Get indv. numbers from data
        e.num1 = e.numDat%10000/1000;
        e.num2 = e.numDat%1000/100;
        e.num3 = e.numDat%100/10;
        e.num4 = e.numDat%10; 
        
        //If 8 or 9 detected, output error
        if(e.num1 > 7 || e.num2 > 7 || e.num3 > 7 || e.num4 > 7)
        {
            cout<<"Invalid integer detected!\n";
        }
        //If no 8 or 9, start decryption
        else 
        {
            e.num1 = (e.num1 + 3) % 8;
            e.num2 = (e.num2 + 3) % 8;
            e.num3 = (e.num3 + 3) % 8;
            e.num4 = (e.num4 + 3) % 8;
            
            //Start swap
            temp1 = e.num1;
            e.num1 = e.num2;
            e.num2 = temp1;
            
            temp2 = e.num3;
            e.num3 = e.num4;
            e.num4 = temp2;
            
            cout<<"\nEncrypted number: ";
            cout<<e.num1<<e.num2<<e.num3<<e.num4<<endl;
            cout<<endl;
        }
    }
}//End method problem4

//Start method problem5
void problem5(){
    cout<<"The largest factorial using a short is 11\n";
    cout<<"The largest factorial using a signed short is 11\n";
    cout<<"The largest factorial using an unsigned short is 17\n";
    cout<<endl;
    cout<<"The largest factorial using an int is 31\n";
    cout<<"The largest factorial using a signed int is 31\n";
    cout<<"The largest factorial using an unsigned int is 34\n";
    cout<<endl;
    cout<<"The largest factorial using a long is 31\n";
    cout<<"The largest factorial using a signed long is 31\n";
    cout<<"The largest factorial using an unsigned long is 33\n";
    cout<<endl;
    cout<<"The largest factorial using a float is 34\n";
    cout<<"Signed and unsigned float is invalid\n";
    cout<<endl;
    cout<<"The largest factorial using a double is 170\n";
    cout<<"Signed and unsigned double is invalid\n";
    cout<<"The largest factorial using a long double is 170\n";
    cout<<endl;
}//End method problem5

//Start method problem6
void problem6(){
        cout<<"2.125 in binary is: 01000000000011011100001010001111"<<endl;
        cout<<"2.125 in octal is: 10003341217"<<endl;
        cout<<"2.125 in hex is: 400DC28F"<<endl;
        cout<<endl;
        cout<<"0.06640625 in binary is: 00111101100010000000000000000000"<<endl;
        cout<<"0.06640625 in octal is: 7542000000"<<endl;
        cout<<"0.06640625 in hex is: 3D880000"<<endl;
        cout<<endl;
        cout<<"46666601 in decimal is: Not sure"<<endl;
        cout<<"46666602 in decimal is: Not sure"<<endl;
        cout<<"B9999AFE in decimal is: Not sure"<<endl;
        cout<<endl;
}//End method problem6

//Start method def breaks switch
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}//End method def

//Problem 1 Functions
//Start method cntAcctnum count digits in acct. number
int cntAcctNum(int aNum)
{
    //Declare function variables
    int countNum = 0; //Number counter
    
    //While scanning digits
    while(aNum > 0)
    {
        aNum /= 10; // Divide by 10 to regress
        countNum++; // Count digit
    }
    
    return countNum;
}//End method cntAcctNum

//Start method total add up elements in array
int total(int *array, int ttl, int monB)
{
    //Declare function variables
    int temp = 0; // Temporarily holds total
    
    //Add up total of all elements in array
    for(int i = 0; i < ttl; i++)
    {
       temp += array[i];
    }
    
    return temp;
}//End method total

//Problem 3 Functions
//Start method sort sorts the array
void sort(int *array, int size)
{
    bool swap; // If swapping
    int temp;  // Holds value of array element
    
    do
    {
        swap = false;
        for(int i = 0; i < (size - 1); i++)
        {
            if(array[i] > array[i + 1])
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swap = true;
            }
        }
    }while(swap);
}

//Start method avgMedMode
StatsResult *avgMedMode(int *arrPtr, int size)
{
    float sum   = 0;      // Sum of all numbers in array
    float even  = 0;      // Check if var size is even or odd
    short count = 0;      // Counter
    int last = arrPtr[0]; // Assign to first number in modeAry
    int mode = last;      // To get the mode
    int temp = 0;
    
    //Find the average
    for(int i = 0; i < size; i++)
    {
        sum += arrPtr[i];
    }
    
    cout<<showpoint<<setprecision(3);
    cout<<"The average is: "<<sum/size<<endl;
    
    //Find the median
    //Check if number of elements is odd
	if(size % 2 != 0)
	{
		//If odd, only one value can be median
		int temp = ((size+1)/2)-1; //Go back one on array
		
		//Output results
		cout<<"The median is: "<<arrPtr[temp]<<endl;
	}
	
	//If num of elements is even
	else{
		even = (arrPtr[(size/2)-1]) + (arrPtr[size/2]); // Middle two values added
		even /= 2;                                      // Then divide by 2
		
		//Output results
		cout<<"The median is: "<<even<<endl;
	}
    
    temp = 0; // Reset temp just in case
    
    //Find the mode
    for(int i =0; i<size; i++)
	{
		//If first number = modeAry[i]
		if(last == arrPtr[i])
		{
			temp++;
		}
		//If first number != modeAry[i]
		else
		{
			if(count > temp)
			{
				temp = count;
				mode = last;
			}
			temp=0;//reset counter
		}
	}
    cout<<"The mode is: "<<mode<<endl;
}
