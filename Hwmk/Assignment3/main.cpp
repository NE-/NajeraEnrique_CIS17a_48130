/* 
 * File: main.cpp
 * Author: Enrique Najera
 * Purpose: Assignment 3 menu
 *          Gaddis 8th ed. ch 11
 * 19 October 2014
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>

//Namespaces
using namespace std; //iostream

//Structures
//Problem 1
//Holds values for the movie
struct MovieData
{
    string title;
    string dirtr;
    int yrRelsd;
    int runTime;
};

//Problem 2
//Holds values for the movie
struct MovieData2
{
    string title;  // Holds movie title
    string dirtr;  // Holds movie director
    int yrRelsd;   // Holds year released 
    int runTime;   // Holds holds run time
    float prodCst; // Holds
    float yrRevnu; // Holds first-year revenue
};

//Problem 3
//Holds values of company data
struct CoData
{
    string divName;     // Holds Division Name (N,E,S,W)
    float fstQtrSales;  // Holds First-Quarter sales
    float scndQtrSales; // Holds Second-Quarter sales
    float thrQtrSales;  // Holds Third-Quarter sales
    float fthQtrSales;  // Holds Fourth-Quarter sales
    float ttlAnulSales; // Holds Total Annual sales
    float avgQrtSales;  // Holds Average Quarterly sales
};

//Problem 4
//Holds data of the customer
struct Customer
{
    string name;      // Name
    string adrss;     // Address
    string city;      // City
    string state;     // State
    string zip;       // Zone improvement plan number
    string telNum;    // Telephone number
    string accBlnc;   // Account balance
    string dtLstPaym; // Date of last payment
};

//Problem 5
//Hold values for the speaker
struct Speaker
{
    string name;
    string telNum; // Holds speaker's telephone number
    string topic;  // Holds speaker's topic
    float fee;     // Holds speaker's fee
};

//Problem 6
//Holds monthly budget of student
struct MonBudget
{
    float hous;     // Holds housing budget
    float util;     // Holds utilities budget
    float hsHldExp; // Holds household expenses budget
    float transp;   // Holds transportation budget
    float food;     // Holds food budget
    float med;      // Holds medical budget
    float insur;    // Holds insurance budget
    float entrt;    // Holds entertainment budget
    float cloth;    // Holds clothing budget
    float misc;     // Holds miscellaneous budget
};

//Holds how much actually spent
struct MonSpent
{
    float hous;     // Holds housing spent
    float util;     // Holds utilities spent
    float hsHldExp; // Holds household expenses spent
    float transp;   // Holds transportation spent
    float food;     // Holds food spent
    float med;      // Holds medical spent
    float insur;    // Holds insurance spent
    float entrt;    // Holds entertainment spent
    float cloth;    // Holds clothing spent
    float misc;     // Holds miscellaneous spent
};

//Problem 7
//Values for the drink machine
struct DrinkMach
{
    string dName;  // Holds drink name
    float dCost;   // Holds drink cost
    short nDrinks; // Holds number of drinks
};

//Function Prototypes
void Menu();     // Display main menu
int getN();      // Get user's choice
void def(int);   // Exit the program

void problem1(); // Gaddis ch11 prob  1
void problem2(); // Gaddis ch11 prob  2
void problem3(); // Gaddis ch11 prob  3
void problem4(); // Gaddis ch11 prob  7
void problem5(); // Gaddis ch11 prob  9
void problem6(); // Gaddis ch11 prob 11
void problem7(); // Gaddis ch11 prob 13

//Problem functions
//Problem 1
void dispMovData(MovieData, MovieData); // Displays the movie data

//Problem 2
void dispMovData2(MovieData2, MovieData2, bool, bool);
bool isProfit(MovieData2); // Calculates if profit or loss

//Problem 6
void getSpent(MonSpent &);
void dispRslt(MonBudget, MonSpent);

//No Global Variables

//Start method main
int main(int argv,char *argc[])
{
    //Declare variables
    int inN = 0; //Get input for the main menu
    
    do{
        Menu();
        inN=getN();
        
        switch(inN){
            case 1: problem1();break; // Gaddis ch11 prob  1
            case 2: problem2();break; // Gaddis ch11 prob  2
            case 3: problem3();break; // Gaddis ch11 prob  3
            case 4: problem4();break; // Gaddis ch11 prob  7
            case 5: problem5();break; // Gaddis ch11 prob  9
            case 6: problem6();break; // Gaddis ch11 prob 11
            case 7: problem7();break; // Gaddis ch11 prob 13
            default: def(inN);}
    }while(inN<8);
    
    system("Pause");
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
   cout<<"Type 8 to exit \n"<<endl;
}

int getN()
{
   int inN;
   cin>>inN;
   return inN;
}

//Start problems
// Gaddis ch11 prob 1
void problem1()
{
    MovieData movD1;
    MovieData movD2;
    
    //INIT variables
    movD1.yrRelsd = 0;
    movD1.runTime = 0;
    movD2.yrRelsd = 0;
    movD2.runTime = 0;
    
    cin.ignore();
    
    //Prompt for input
    //First movie title
    cout<<"Movie 1"<<endl;
    cout<<"Enter the movie title: ";
    getline(cin, movD1.title);
    
    //First movie director
    cout<<"Enter the movie's director: ";
    getline(cin, movD1.dirtr);
    cin.ignore();
    
    //First movie year released
    cout<<"Enter the movie's release year: ";
    
    cin>>movD1.yrRelsd;
    
    //First movie director
    cout<<"Enter the movie's runtime in minutes: ";
    cin>>movD1.runTime;
    
    //Second movie title
    cin.ignore();
    cout<<"Movie 2"<<endl;
    cout<<"Enter the movie title: ";
    getline(cin, movD2.title);
    
    //Second movie director
    cout<<"Enter the movie's director: ";
    getline(cin, movD2.dirtr);
    
    //Second movie year released
    cout<<"Enter the movie's release year: ";
    cin>>movD2.yrRelsd;
    
    //Second movie director
    cout<<"Enter the movie's runtime in minutes: ";
    cin>>movD2.runTime;
    cout<<endl;
    
    //Pass results to function
    dispMovData(movD1,movD2); // Movie 1
}// Gaddis ch11 prob 1

// Gaddis ch11 prob 2
void problem2()
{
    //Declare Variables
    bool pOl1, pOl2; // Check if profit or loss
    
    MovieData2 movD1;
    MovieData2 movD2;
    //INIT variables
    movD1.yrRelsd = 0;
    movD1.runTime = 0;
    movD1.prodCst = 0;
    movD1.yrRevnu = 0;
    movD2.yrRelsd = 0;
    movD2.runTime = 0;
    movD2.prodCst = 0;
    movD2.yrRevnu = 0;
    
    cin.ignore();
    
    //Prompt for input
    //First movie title
    cout<<"Movie 1"<<endl;
    cout<<"Enter the movie title: ";
    getline(cin, movD1.title);
    
    //First movie director
    cout<<"Enter the movie's director: ";
    getline(cin, movD1.dirtr);
    
    //First movie year released
    cout<<"Enter the movie's release year: ";
    cin>>movD1.yrRelsd;
    
    //First movie director
    cout<<"Enter the movie's runtime in minutes: ";
    cin>>movD1.runTime;
    
    //First movie production cost
    cout<<"Enter the movie's production cost: ";
    cin>>movD1.prodCst;
    
    //First movie revenues
    cout<<"Enter the movie's first-year revenues: ";
    cin>>movD1.yrRevnu;
    
    //Second movie title
    cin.ignore();
    cout<<"Movie 2"<<endl;
    cout<<"Enter the movie title: ";
    getline(cin, movD2.title);
    
    //Second movie director
    cout<<"Enter the movie's director: ";
    getline(cin, movD2.dirtr);
    
    //Second movie year released
    cout<<"Enter the movie's release year: ";
    cin>>movD2.yrRelsd;
    
    //Second movie director
    cout<<"Enter the movie's runtime in minutes: ";
    cin>>movD2.runTime;
    
    //First movie production cost
    cout<<"Enter the movie's production cost: ";
    cin>>movD2.prodCst;
    
    //First movie revenues
    cout<<"Enter the movie's first-year revenues: ";
    cin>>movD2.yrRevnu;
    
    cout<<endl;
    
    //Check if movie gained or lost money
    pOl1 = isProfit(movD1);
    pOl2 = isProfit(movD2);
    
    //Pass movie info to function
    dispMovData2(movD1, movD2, pOl1, pOl2);
}// Gaddis ch11 prob 2

// Gaddis ch11 prob 3
void problem3()
{
    //Make array for 4 divisions
    //INIT data
    CoData cD[4] = {
        {"East",  0, 0, 0, 0, 0, 0},
        {"West",  0, 0, 0, 0, 0, 0},
        {"North", 0, 0, 0, 0, 0, 0},
        {"South", 0, 0, 0, 0, 0, 0}
    };
    
    //East division input
    cout<<"Enter "<<cD[0].divName<<" Division's First-Quarter sales: ";
    cin>>cD[0].fstQtrSales;
    
    //Input validation
    //If negative number
    if(cD[0].fstQtrSales < 0)
    {
        cout<<"Insert only values above 0"<<endl;
    }
    //Else allow a move on
    else
    {
        cout<<"Enter "<<cD[0].divName<<" Division's Second-Quarter sales: ";
        cin>>cD[0].scndQtrSales;
        
        //Input validation
        //If negative number
        if(cD[0].scndQtrSales < 0)
        {
            cout<<"Insert only values above 0"<<endl;
        }
        //Else allow a move on
        else
        {
            cout<<"Enter "<<cD[0].divName<<" Division's Third-Quarter sales: ";
            cin>>cD[0].thrQtrSales;
            
            //Input validation
            //If negative number
            if(cD[0].thrQtrSales < 0)
            {
                cout<<"Insert only values above 0"<<endl;
            }
            //Else allow a move on
            else
            {
                cout<<"Enter "<<cD[0].divName<<" Division's Fourth-Quarter sales: ";
                cin>>cD[0].fthQtrSales;
            }
        }
    }
    
    //West division input
    cout<<"Enter "<<cD[1].divName<<" Division's First-Quarter sales: ";
    cin>>cD[1].fstQtrSales;
    
    //Input validation
    //If negative number
    if(cD[1].fstQtrSales < 0)
    {
        cout<<"Insert only values above 0"<<endl;
    }
    //Else allow a move on
    else
    {
        cout<<"Enter "<<cD[1].divName<<" Division's Second-Quarter sales: ";
        cin>>cD[1].scndQtrSales;
        
        //Input validation
        //If negative number
        if(cD[1].scndQtrSales < 0)
        {
            cout<<"Insert only values above 0"<<endl;
        }
        //Else allow a move on
        else
        {
            cout<<"Enter "<<cD[1].divName<<" Division's Third-Quarter sales: ";
            cin>>cD[1].thrQtrSales;
            
            //Input validation
            //If negative number
            if(cD[1].thrQtrSales < 0)
            {
                cout<<"Insert only values above 0"<<endl;
            }
            //Else allow a move on
            else
            {
                cout<<"Enter "<<cD[1].divName<<" Division's Fourth-Quarter sales: ";
                cin>>cD[1].fthQtrSales;
            }
        }
    }
    
    //North division input
    cout<<"Enter "<<cD[2].divName<<" Division's First-Quarter sales: ";
    cin>>cD[2].fstQtrSales;
    
    //Input validation
    //If negative number
    if(cD[2].fstQtrSales < 0)
    {
        cout<<"Insert only values above 0"<<endl;
    }
    //Else allow a move on
    else
    {
        cout<<"Enter "<<cD[2].divName<<" Division's Second-Quarter sales: ";
        cin>>cD[2].scndQtrSales;
        
        //Input validation
        //If negative number
        if(cD[2].scndQtrSales < 0)
        {
            cout<<"Insert only values above 0"<<endl;
        }
        //Else allow a move on
        else
        {
            cout<<"Enter "<<cD[2].divName<<" Division's Third-Quarter sales: ";
            cin>>cD[2].thrQtrSales;
            
            //Input validation
            //If negative number
            if(cD[2].thrQtrSales < 0)
            {
                cout<<"Insert only values above 0"<<endl;
            }
            //Else allow a move on
            else
            {
                cout<<"Enter "<<cD[2].divName<<" Division's Fourth-Quarter sales: ";
                cin>>cD[2].fthQtrSales;
            }
        }
    }
    
    //South division input
    cout<<"Enter "<<cD[3].divName<<" Division's First-Quarter sales: ";
    cin>>cD[3].fstQtrSales;
    
    //Input validation
    //If negative number
    if(cD[3].fstQtrSales < 0)
    {
        cout<<"Insert only values above 0"<<endl;
    }
    //Else allow a move on
    else
    {
        cout<<"Enter "<<cD[3].divName<<" Division's Second-Quarter sales: ";
        cin>>cD[3].scndQtrSales;
        
        //Input validation
        //If negative number
        if(cD[3].scndQtrSales < 0)
        {
            cout<<"Insert only values above 0"<<endl;
        }
        //Else allow a move on
        else
        {
            cout<<"Enter "<<cD[3].divName<<" Division's Third-Quarter sales: ";
            cin>>cD[3].thrQtrSales;
            
            //Input validation
            //If negative number
            if(cD[3].thrQtrSales < 0)
            {
                cout<<"Insert only values above 0"<<endl;
            }
            //Else allow a move on
            else
            {
                cout<<"Enter "<<cD[3].divName<<" Division's Fourth-Quarter sales: ";
                cin>>cD[3].fthQtrSales;
                
                cout<<endl;
            }
        }
    }
    
    //Calculate total annual sales for all divisions
    for(int i = 0; i < 4; i++)
    {
        cD[i].ttlAnulSales = (cD[i].fstQtrSales + cD[i].scndQtrSales + cD[i].thrQtrSales + cD[i].fthQtrSales);
    }
    
    //Calculate average annual sales for all divisions
    for(int j = 0; j < 4; j++)
    {
        cD[j].avgQrtSales = cD[j].ttlAnulSales / 4;
    }
    
    //Display total and average annual sales for all divisions
    for(int k = 0; k < 4; k++)
    {
        cout<<cD[k].divName<<" Division's total annual sales: "<<cD[k].ttlAnulSales<<endl;
        cout<<cD[k].divName<<" Division's average annual sales: "<<cD[k].avgQrtSales<<endl;
        cout<<endl;
    }

}// Gaddis ch11 prob 3

// Gaddis ch11 prob 7
void problem4()
{
    Customer cst[10] = {
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""},
        {"","","","","","","",""}
    };
    
    short getIn  = 0; // Get input for menu
    short numCst = 0; // Get number of customers for data input
    string cstName;   // Get customer name for data change 
    
    while(true)
    {
        cout<<"Enter 1 to enter customer data\n2 change customer data\n"
            <<"3 display all data entered\n4 Exit"<<endl;
        cin>>getIn;
        
        //Enter customer data
        if(getIn == 1)
        {
            cout<<"How many customers do you wish to enter data for? (1-10) ";
            cin>>numCst;
            
            for(int i = 0; i < numCst; i++)
            {
                cin.ignore();
                cout<<"Enter customer "<<i+1<<"'s name: ";
                getline(cin, cst[i].name);
                cout<<"Enter customer "<<i+1<<"'s address: ";
                getline(cin, cst[i].adrss);
                cout<<"Enter customer "<<i+1<<"'s city: ";
                getline(cin, cst[i].city);
                cout<<"Enter customer "<<i+1<<"'s state: ";
                getline(cin, cst[i].state);
                cout<<"Enter customer "<<i+1<<"'s ZIP: ";
                getline(cin, cst[i].zip);
                cout<<"Enter customer "<<i+1<<"'s telephone number: ";
                getline(cin, cst[i].telNum);
                cout<<"Enter customer "<<i+1<<"'s account balance: ";
                getline(cin, cst[i].accBlnc);
                cout<<"Enter customer "<<i+1<<"'s date of last payment: ";
                getline(cin, cst[i].dtLstPaym);
                cout<<"\nThank you, press the enter key\n";
            }
            
        }
        //Change customer data
        else if(getIn == 2)
        {
            cout<<"Which customer do you wish to change data for?"<<endl;
            cout<<"Enter their name: ";
            cin>>cstName;
            
            //Find that customer
            for(int i = 0; i < 10; i++)
            {
                //If customer found, enter new data
                if(cst[i].name == cstName)
                {
                    cin.ignore();
                    cout<<"Enter "<<cst[i].name<<"'s new address: ";
                    getline(cin, cst[i].adrss);
                    cout<<"Enter "<<cst[i].name<<"'s new city: ";
                    getline(cin, cst[i].city);
                    cout<<"Enter "<<cst[i].name<<"'s new state: ";
                    getline(cin, cst[i].state);
                    cout<<"Enter "<<cst[i].name<<"'s new ZIP: ";
                    getline(cin, cst[i].zip);
                    cout<<"Enter "<<cst[i].name<<"'s new telephone number: ";
                    getline(cin, cst[i].telNum);
                    cout<<"Enter "<<cst[i].name<<"'s new account balance: ";
                    getline(cin, cst[i].accBlnc);
                    cout<<"Enter "<<cst[i].name<<"'s new date of last payment: ";
                    getline(cin, cst[i].dtLstPaym);
                    
                    //Exit for loop and elif
                    break;
                }
                //Else display warning
                else
                {
                    cout<<"Customer not found!"<<endl;
                }
            }
        }
            
        //Display all data
        else if(getIn == 3)
        {
            cout<<"Displaying data for all customers"<<endl;
            for(int i = 0; i < 10; i++)
            {
                cout<<"Name: "<<cst[i].name<<endl;;
                cout<<"Address: "<<cst[i].adrss<<endl;;
                cout<<"City:"<<cst[i].city<<endl;;
                cout<<"State: "<<cst[i].state<<endl;
                cout<<"ZIP: "<<cst[i].zip<<endl;
                cout<<"Telephone Number: "<<cst[i].telNum<<endl;
                cout<<"Account Balance: "<<cst[i].accBlnc<<endl;
                cout<<"Date of Last Payment: "<<cst[i].dtLstPaym<<endl;
                cout<<endl;
            }
        }
        //Exit
        else if(getIn == 4)
        {
            cout<<"Exiting..."<<endl;
            break;
        }
        //Error
        else
        {
            cout<<"Invalid data detected!"<<endl;
        }
    }
}// Gaddis ch11 prob 7

// Gaddis ch11 prob 9
void problem5()
{
short getIn = 0; // Get input for menu
    string getName;  // Compare strings to find name 
    
    Speaker s[10] = {
        {"","","",0},
        {"","","",0},
        {"","","",0},
        {"","","",0},
        {"","","",0},
        {"","","",0},
        {"","","",0},
        {"","","",0},
        {"","","",0},
        {"","","",0}
    }; 

    while(true)
    {
        cout<<"Enter 1 to enter speaker data\n2 Change speaker data\n"
            <<"3 Display all data\n4 Exit\n";
        cin>>getIn;
        
        //Enter speaker data
        if(getIn == 1)
        {
            cin.ignore();
            cout<<"How many speakers do you wish to enter data for? (1-10)"<<endl;
            cin>>getIn;
            
            for(int i = 0; i < getIn; i++)
            {
                cin.ignore();
                cout<<"Enter speaker "<<i+1<<"'s name: ";
                getline(cin, s[i].name);
                cout<<"Enter speaker "<<i+1<<"'s telephone number: ";
                getline(cin, s[i].telNum);
                cout<<"Enter speaker "<<i+1<<"'s speaking topic: ";
                getline(cin, s[i].topic);
                cout<<"Enter speaker "<<i+1<<"'s fee required: ";
                cin>>s[i].fee;
                
                if(s[i].fee < 0)
                {
                    cout<<"Fee can't be less than 0!\n"<<endl;
                }
            }
        }
        //Change speaker data
        else if(getIn == 2)
        {
            cin.ignore();
            cout<<"For which speaker do you wish to change the data?"<<endl;
            getline(cin, getName);
            
            //Find that customer
            for(int i = 0; i < 10; i++)
            {
                //If customer found, enter new data
                if(s[i].name == getName)
                {
                    cout<<"Enter "<<s[i].name<<"'s new telephone number: ";
                    getline(cin, s[i].telNum);
                    cout<<"Enter "<<s[i].name<<"'s new speaking topic: ";
                    getline(cin, s[i].topic);
                    cin.ignore();
                    cout<<"Enter "<<s[i].name<<"'s new fee required: ";
                    cin>>s[i].fee;
                    
                    //Exit for loop and elif
                    break;
                }
                
                //Else display warning
                else
                {
                    cout<<"Speaker not found!"<<endl;
                }
            }
        }
        //Display all speaker's data
        else if(getIn == 3)
        {
            cout<<"Displaying all speaker's data..."<<endl;
            for(int i = 0; i < 10; i++)
            {
                cout<<"Name: "<<s[i].name<<endl;;
                cout<<"Telephone Number: "<<s[i].telNum<<endl;
                cout<<"Speaking Topic: "<<s[i].topic<<endl;
                cout<<"Fee Required: "<<s[i].fee<<endl;
                cout<<endl;
            }
        }
        //Exit
        else if(getIn == 4)
        {
            cout<<"Exiting..."<<endl;
            break;
        }
        //Error detected
        else
        {
            cout<<"Invalid data detected!"<<endl;
        }
        
    }
}// Gaddis ch11 prob 9

// Gaddis ch11 prob 11
void problem6()
{
    MonBudget mB;
    
    //Set budget amounts
    mB.hous     = 500.00f;
    mB.util     = 150.00f;
    mB.hsHldExp =  65.00f;
    mB.transp   =  50.00f;
    mB.food     = 250.00f;
    mB.med      =  30.00f;
    mB.insur    = 100.00f;
    mB.entrt    = 150.00f;
    mB.cloth    =  75.00f;
    mB.misc     =  50.00f;
    
    MonSpent mS;
    
    //INIT monthly spent
    mS.hous     = 0.00f;
    mS.util     = 0.00f;
    mS.hsHldExp = 0.00f;
    mS.transp   = 0.00f;
    mS.food     = 0.00f;
    mS.med      = 0.00f;
    mS.insur    = 0.00f;
    mS.entrt    = 0.00f;
    mS.cloth    = 0.00f;
    mS.misc     = 0.00f;

    getSpent(mS);     // Get user input
    dispRslt(mB, mS); // Display results
}// Gaddis ch11 prob 11

// Gaddis ch11 prob 13
void problem7()
{
//Declare Variables
    short choice = 0; // User's drink choice
    float insert = 0; // User's money inserted
    float change = 0; // User's change
    float earned = 0; // Machine money earned
    
    DrinkMach dM[5] = {
        {"Cola",       0.75f, 20},
        {"Root Beer",  0.75f, 20},
        {"Lemon-Lime", 0.75f, 20},
        {"Grape Soda", 0.80f, 20},
        {"Cream Soda", 0.80f, 20}
    };
    
    while(true)
    {
        //Display drink names
        for(int i = 0; i < 5; i++)
        {
            cout<<i+1<<") "<<dM[i].dName<<setw(8)<<dM[i].dCost;
            cout<<endl;
        }
        cout<<"Enter the drink number or press 6 to exit"<<endl;
        cin>>choice;
        
        cout<<showpoint<<setprecision(2);
        if(choice == 1)
        {
            insert = 0; // INIT insert
            cout<<"Enter the amount of money you will insert"<<endl;
            cin>>insert;
            
            if(dM[0].nDrinks <= 0)
            {
                cout<<dM[0].dName<<" has sold out!"<<endl;
            }
            
            if(insert < 0 || insert >= 1)
            {
                cout<<"Invalid amount!"<<endl;
            }  
            else
            {
                //Display change
                //Calculate change
                change = insert - dM[0].dCost;
                
                //If change > 0 give change
                if(change > 0)
                {
                    cout<<"Your change: "<<change<<endl;
                    //Take out a drink
                    dM[0].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[0].dCost;
                }
                //If change == 0 no change
                else if(change == 0)
                {
                    cout<<"No change"<<endl;
                    //Take out a drink
                    dM[0].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[0].dCost;
                }
                //If change < 0 not enough money
                else
                {
                    cout<<"Not enough money inserted!"<<endl;
                }
            }   
        }
        else if(choice == 2)
        {
            insert = 0; // INIT insert
            cout<<"Enter the amount of money you will insert"<<endl;
            cin>>insert;
            
            if(dM[1].nDrinks <= 0)
            {
                cout<<dM[1].dName<<" has sold out!"<<endl;
            }
            
            if(insert < 0 || insert >= 1)
            {
                cout<<"Invalid amount!"<<endl;
            }  
            else
            {
                //Display change
                change = insert - dM[1].dCost;
                if(change > 0)
                {
                    cout<<"Your change: "<<change<<endl;
                    //Take out a drink
                    dM[1].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[1].dCost;
                }
                else if(change == 0)
                {
                    cout<<"No change"<<endl;
                    //Take out a drink
                    dM[1].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[1].dCost;
                }
                else
                {
                    cout<<"Not enough money inserted!"<<endl;
                }
            }
        }
        else if(choice == 3)
        {
            insert = 0; // INIT insert
            cout<<"Enter the amount of money you will insert"<<endl;
            cin>>insert;
            
            if(dM[2].nDrinks <= 0)
            {
                cout<<dM[2].dName<<" has sold out!"<<endl;
            }
            
            if(insert < 0 || insert >= 1)
            {
                cout<<"Invalid amount!"<<endl;
            }  
            else
            {
                //Display change
                change = insert - dM[2].dCost;
                if(change > 0)
                {
                    cout<<"Your change: "<<change<<endl;
                    //Take out a drink
                    dM[2].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[2].dCost;
                }
                else if(change == 0)
                {
                    cout<<"No change"<<endl;
                    //Take out a drink
                    dM[2].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[2].dCost;
                }
                else
                {
                    cout<<"Not enough money inserted!"<<endl;
                }
            }
        
        }
        else if(choice == 4)
        {
            insert = 0; // INIT insert
            cout<<"Enter the amount of money you will insert"<<endl;
            cin>>insert;
            
            if(dM[3].nDrinks <= 0)
            {
                cout<<dM[3].dName<<" has sold out!"<<endl;
            }
            
            if(insert < 0 || insert >= 1)
            {
                cout<<"Invalid amount!"<<endl;
            }  
            else
            {
                //Display change
                change = insert - dM[3].dCost;
                if(change > 0)
                {
                    cout<<"Your change: "<<change<<endl;
                    //Take out a drink
                    dM[3].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[3].dCost;
                }
                else if(change == 0)
                {
                    cout<<"No change"<<endl;
                    //Take out a drink
                    dM[3].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[3].dCost;
                }
                else
                {
                    cout<<"Not enough money inserted!"<<endl;
                }
            }
        }
        else if(choice == 5)
        {
        
            insert = 0; // INIT insert
            cout<<"Enter the amount of money you will insert"<<endl;
            cin>>insert;
            
            if(dM[4].nDrinks <= 0)
            {
                cout<<dM[4].dName<<" has sold out!"<<endl;
            }
            
            if(insert < 0 || insert >= 1)
            {
                cout<<"Invalid amount!"<<endl;
            }  
            else
            {
                //Display change
                change = insert - dM[4].dCost;
                if(change > 0)
                {
                    cout<<"Your change: "<<change<<endl;
                    //Take out a drink
                    dM[4].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[4].dCost;
                }
                else if(change == 0)
                {
                    cout<<"No change"<<endl;
                    //Take out a drink
                    dM[4].nDrinks -= 1;
                    //For mahcine earned
                    earned += dM[4].dCost;
                }
                else
                {
                    cout<<"Not enough money inserted!"<<endl;
                }
            }
        }
        
        else if(choice == 6)
        {
            cout<<showpoint<<setprecision(3);
            
            cout<<"The machine earned $"<<earned<<endl;
            cout<<"Exiting..."<<endl;
            break;
        }
    }
}// Gaddis ch11 prob 13

void def(int inN)
{
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Functions from problems
//Problem 1
//Start method dispMovData
void dispMovData(MovieData mD1, MovieData mD2)
{
    //Display movie data
    cout<<"Title:         "<<setw(1)<<mD1.title<<endl;
    cout<<"Director:      "<<setw(1)<<mD1.dirtr<<endl;
    cout<<"Year Released: "<<setw(1)<<mD1.yrRelsd<<endl;
    cout<<"Run Time:      "<<setw(1)<<mD1.runTime<<endl;
    cout<<endl;
    cout<<"Title:         "<<setw(1)<<mD2.title<<endl;
    cout<<"Director:      "<<setw(1)<<mD2.dirtr<<endl;
    cout<<"Year Released: "<<setw(1)<<mD2.yrRelsd<<endl;
    cout<<"Run Time:      "<<setw(1)<<mD2.runTime<<endl;
    cout<<endl;
}//End method dispMovData

//Problem 2
//Start method isProfit checks if movie made or lost money
bool isProfit(MovieData2 mD)
{
    //Declare function variables
    float temp = 0; //Temporary holder
    
    temp = mD.yrRevnu - mD.prodCst;
    
    //If negative value, no profit
    if(temp <= 0)
    {
        return false;
    }
    //If not negative, gained profit
    else if(temp > 0)
    {
        return true;
    }
    //If no profit and no gain, error
    else
    {
        cout<<"Error\n";
    }
}//End method isProfit

//Start method dispMovData displays movie data
void dispMovData2(MovieData2 mD1, MovieData2 mD2, bool profLoss1, bool profLoss2)
{
    //Declare function variables
    float temp1 = 0, // Holds profit or loss for first movie
          temp2 = 0; // Holds profit or loss for second movie
    
    //If 1st movie gained profit
    if(profLoss1 == true)
    {
        //Profit = revenue  - cost of production
        temp1 = mD1.yrRevnu - mD1.prodCst;
        
        cout<<"Title:             "<<setw(1)<<mD1.title<<endl;
        cout<<"Director:          "<<setw(1)<<mD1.dirtr<<endl;
        cout<<"Year Released:     "<<setw(1)<<mD1.yrRelsd<<endl;
        cout<<"Run Time:          "<<setw(1)<<mD1.runTime<<endl;
        cout<<"First-year profit: $"<<setw(1)<<temp1<<endl;
        cout<<endl;
    }
    //If 1st movie lost profit
    else if(profLoss1 == false)
    {
        //Loss = revenue - production cost     subtract double loss to get a positive number
        temp1 = ((mD1.yrRevnu - mD1.prodCst) - (2 *(mD1.yrRevnu - mD1.prodCst)));
        
        cout<<"Title:             "<<setw(1)<<mD1.title<<endl;
        cout<<"Director:          "<<setw(1)<<mD1.dirtr<<endl;
        cout<<"Year Released:     "<<setw(1)<<mD1.yrRelsd<<endl;
        cout<<"Run Time:          "<<setw(1)<<mD1.runTime<<endl;
        cout<<"First-year loss:  $"<<setw(1)<<temp1<<endl;
        cout<<endl;
    }
    //If 2nd movie gained profit
    if(profLoss2 == true)
    {
        //Profit = revenue  - cost of production
        temp2 = mD2.yrRevnu - mD2.prodCst;
        
        cout<<"Title:             "<<setw(1)<<mD2.title<<endl;
        cout<<"Director:          "<<setw(1)<<mD2.dirtr<<endl;
        cout<<"Year Released:     "<<setw(1)<<mD2.yrRelsd<<endl;
        cout<<"Run Time:          "<<setw(1)<<mD2.runTime<<endl;
        cout<<"First-year profit: $"<<setw(1)<<temp2<<endl;
        cout<<endl;
    }
    //If 2nd movie lost profit
    else if(profLoss2 == false)
    {
        //Loss = revenue - production cost     subtract double loss to get a positive number
        temp2 = ((mD2.yrRevnu - mD2.prodCst) - (2 *(mD2.yrRevnu - mD2.prodCst)));
        
        cout<<"Title:             "<<setw(1)<<mD2.title<<endl;
        cout<<"Director:          "<<setw(1)<<mD2.dirtr<<endl;
        cout<<"Year Released:     "<<setw(1)<<mD2.yrRelsd<<endl;
        cout<<"Run Time:          "<<setw(1)<<mD2.runTime<<endl;
        cout<<"First-year loss:  $"<<setw(1)<<temp2<<endl;
        cout<<endl;
    }
}//End method dispMovData

//Problem 6
//Start method getSpent get user's spending
void getSpent(MonSpent &monS)
{
    cout<<"Enter amount spent for housing: $";
    cin>>monS.hous;
    cout<<"Enter amount spent for utilities: $";
    cin>>monS.util;
    cout<<"Enter amount spent for household expenses: $";
    cin>>monS.hsHldExp;
    cout<<"Enter amount spent for transportation: $";
    cin>>monS.transp;
    cout<<"Enter amount spent for food: $";
    cin>>monS.food;
    cout<<"Enter amount spent for medical: $";
    cin>>monS.med;
    cout<<"Enter amount spent for insurance: $";
    cin>>monS.insur;
    cout<<"Enter amount spent for entertainment: $";
    cin>>monS.entrt;
    cout<<"Enter amount spent for clothing: $";
    cin>>monS.cloth;
    cout<<"Enter amount spent for miscellaneous: $";
    cin>>monS.misc;
}//End method getSpent

//Start method dispRslt display budget results
void dispRslt(MonBudget monB, MonSpent monS)
{
    float temp = 0; // Holds calculation 

    
    cout<<fixed<<showpoint<<setprecision(2);
    //Calculate housing
    temp = monB.hous - monS.hous;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.hous<<")"<<endl;
    }
    
    //If budget > temp, under
    else if(monB.hous > temp && temp > 0)
    {
        cout<<"Your housing expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.hous > temp && temp < 0)
    {
        cout<<"Your housing expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate utilities
    temp = monB.util - monS.util;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.util<<")"<<endl;
    }
    //If budget > temp, under
    else if(monB.util > temp && temp > 0)
    {
        cout<<"Your utility expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.util > temp && temp < 0)
    {
        cout<<"Your utility expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate household expenses
    temp = monB.hsHldExp - monS.hsHldExp;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.hsHldExp<<")"<<endl;
    }
    //If budget > temp, under
    else if(monB.hsHldExp > temp && temp > 0)
    {
        cout<<"Your household expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.hsHldExp > temp && temp < 0)
    {
        cout<<"Your household expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate transportation 
    temp = monB.transp - monS.transp;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.transp<<")"<<endl;
    }
    //If budget > temp, under
    else if(monB.transp > temp && temp > 0)
    {
        cout<<"Your transportation expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.transp > temp && temp < 0)
    {
        cout<<"Your transportation expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate food
    temp = monB.food - monS.food;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.food<<")"<<endl;
    }
    //If budget > temp, under
    else if(monB.food > temp && temp > 0)
    {
        cout<<"Your food expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.food > temp && temp < 0)
    {
        cout<<"Your food expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate medical
    temp = monB.med - monS.med;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.med<<")"<<endl;
    }
    //If budget > temp, under
    else if(monB.med > temp && temp > 0)
    {
        cout<<"Your medical expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.med > temp && temp < 0)
    {
        cout<<"Your medical expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate insurance
    temp = monB.insur - monS.insur;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.insur<<")"<<endl;
    }
    //If budget > temp, under
    else if(monB.insur > temp && temp > 0)
    {
        cout<<"Your insurance expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.insur > temp && temp < 0)
    {
        cout<<"Your insurance expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate entertainment
    temp = monB.entrt - monS.entrt;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.entrt<<")"<<endl;
    }
    //If budget > temp, under
    else if(monB.entrt > temp && temp > 0)
    {
        cout<<"Your entertainment expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.entrt > temp && temp < 0)
    {
        cout<<"Your entertainment expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate clothing
    temp = monB.cloth - monS.cloth;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.cloth<<")"<<endl;
    }
    //If budget > temp, under
    else if(monB.cloth > temp && temp > 0)
    {
        cout<<"Your clothing expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.cloth > temp && temp < 0)
    {
        cout<<"Your clothing expenses are over $"<<temp - (temp*2)<<endl;
    }
    
    
    temp=0; //Reset temp
    
    //Calculate miscellaneous 
    temp = monB.misc - monS.misc;
    
    //If temp = budget, perfect
    if(temp == 0)
    {
        cout<<"You spent exactly what is on your budget ($"<<monB.misc<<")"<<endl;
    } 
    //If budget > temp, under
    else if(monB.misc > temp && temp > 0)
    {
        cout<<"Your miscellaneous expenses are under $"<<temp<<endl;
    }
    //If budget < temp, over
    else if(monB.misc > temp && temp < 0)
    {
        cout<<"Your miscellaneous expenses are over $"<<temp - (temp*2)<<endl;
    }
    
}//End method dispRslt
