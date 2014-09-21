/*
 * File: main.cpp
 * Author: Enrique Najera
 * Purpose: Assignment 1 Gaddis
            8th Ed. problems
 * 17 September 2014
 */
 
//Libraries
#include <iostream>
#include <iomanip>

//Namespaces
using namespace std;//iostream

//No Globals

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1(); //Given assignment
void problem2(); //Gaddis ch 9 prob 1
void problem3(); //Gaddis ch 9 prob 2
void problem4(); //Gaddis ch 9 prob 5
void problem5(); //Gaddis ch 9 prob 6
void problem6(); //Gaddis ch 9 prob 7

//Problem Functions
//Problem 1 (given assignment) Functions
float mean(int [],int);   //Calculate mean
float median(int [],int); //Calculate median
int *mode(int [],int);    //Calculate mode

//Problem 2 (Gaddis ch 9 prob 1) Functions
int *inArr(int);

//Problem 3 (Gaddis ch 9 prob 2) Functions
void srtScore(float [], int); //Sort the scores
float avgScore(float, float);

//Problem 4 (Gaddis ch 9 prob 5) Functions
int doSomething(int *, int *);

//Problem 5 (Gaddis ch 9 prob 6) Functions
void arrSelectSort(int *[], int);
void showArray(const int [], int);
void showArrPtr(int *[], int);

//Problem 6 (Gaddis ch 9 prob 7) Functions
void arrSelectSort_6(int *[], int);
void showArray_6(const int [], int);
void showArrPtr_6(int *[], int);

//Start method main
int main(int argc, char *argv[])
{
	//Declare Variables
	int inN;
	
	//While problem != 5
	do{
		Menu();
		inN=getN();
		
		switch(inN)
		{
			case 1:   problem1();break; //Given Assignment
			case 2:   problem2();break; //Gaddis ch 9 prob 1
			case 3:   problem3();break; //Gaddis ch 9 prob 2
			case 4:   problem4();break; //Gaddis ch 9 prob 5
			case 5:   problem5();break; //Gaddis ch 9 prob 6
			case 6:   problem6();break; //Gaddis ch 9 prob 7
			default: def(inN);
		}
	}while(inN<7); //'7' to end switch inN
	
	//terminate program
	system("PAUSE");
	return 0;
}//End method main

//Start Menu
void Menu()
{
	//Output user options
	cout<<"Type 1 for problem 1"<<endl; //Given Assignment
	cout<<"Type 2 for problem 2"<<endl; //Gaddis ch 9 prob 1
	cout<<"Type 3 for problem 3"<<endl; //Gaddis ch 9 prob 2
	cout<<"Type 4 for problem 4"<<endl; //Gaddis ch 9 prob 5
	cout<<"Type 5 for problem 5"<<endl; //Gaddis ch 9 prob 6
	cout<<"Type 6 for problem 6"<<endl; //Gaddis ch 9 prob 7
	cout<<"Type 7 to exit \n"<<endl;
}//End Procedure Menu

//Start getN user input
int getN()
{
	//Declare Variables
	int inN;
	
	//Prompt for user input 
	cin>>inN;
	//For console readability
	cout<<endl;
	
	return inN;
}//End procedure getN

//Given Assignment
void problem1()
{
	//Declare Variables
	int rpAry[20]={0,14,23,36,43,59,68,73,84,96,
	               0,14,23,36,43,59,68,73,84,96}; //repeated array
	short nAry=20,//Number of elements in array
	      cL  =0;     //chosen length 
	
	//Prompt for user input
	cout<<"Enter a value from 1-20 to get the mean, "
	    <<"median and mode of a fixed array"<<endl;
	cin>>cL;
	
	//goto method mean
	mean(rpAry, cL);
}

//Gaddis ch 9 prob 1
void problem2()
{
	//Declare Variables
	int size=0; //Element size
	
	//Prompt for size of element
	cout<<"Enter the number of elements: ";
	cin>>size;
	
	//Dynamically allocate array
	int *array = inArr(size);
	
	//Free dynamic memory
	delete [] array;
	array = 0;
}

//Gaddis ch 9 prob 2
void problem3()
{
	//Declare Variables
	float *scores,    // dynamically allocate array
	      ttl = 0.0f, // calculate total for the average
		  avg = 0.0f;
	int nScore = 0,   // Number of test scores
	    ctr    = 0;   // Counter
		
	//Prompt user for number of test scores
	cout<<"How many test scores?"<<endl;
	cin>>nScore;
	
	//Dynamically allocate array based on nScore
	scores = new float[nScore];
	
	//Prompt for test scores
	cout<<"\nEnter test scores"<<endl;
	for(ctr=0; ctr < nScore; ctr++)
	{
		do{
			cout<<"Test score "<<(ctr+1)<<endl;
			cin>>scores[ctr];
			
			//Input validation
			//No negative numbers
			if(scores[ctr]<0)
			{
				cout<<"Test scores must be a positive number!\n";
				cout<<endl;
			}
		}while(scores[ctr]<0);
	}
	
	//get total
	for(ctr = 0; ctr < nScore; ctr++)
	{
		ttl += scores[ctr];
	}
	
	//goto method srtScore
	srtScore(scores, nScore);
	for(ctr = 0; ctr < nScore; ctr++)
	{
		cout<<"score "<<(ctr+1)<<": "<<scores[ctr]<<endl;
	}
	
	//Set var avg to = avgScore value
	avg = avgScore(ttl, nScore);
	
	//Output average score
	cout<<fixed<<showpoint<<setprecision(2);
	cout<<"Average score is: "<<avg<<endl<<endl;
	
	//Free dynamic memory
	delete [] scores;
	scores = 0;
}

//Gaddis ch 9 prob 5
void problem4()
{
	//Declare Variables
	int x=0,      // User input 1
	    y=0,      // User input 2
		disp = 0; // Display total of method doSomething
		
	//Prompt for first number
	cout<<"Enter a number: ";
	cin>>x;
	
	//Prompt for second number
	cout<<"Enter another number: ";
	cin>>y;
	
	//Set var disp to = doSomething value
	disp = doSomething(&x, &y);
	
	//Output results
	cout<<disp<<endl<<endl;
}

//Gaddis ch 9 prob 6
void problem5()
{
	//Declare Variables
	int *donations;     // Dynamically allocate array
	int nDonations = 0; // Number of donations
	
	//Prompt for number of donations								
	cout<<"How many donations? ";
	cin>>nDonations;
	
	//Dynamically allocate array based on nDonations
	donations = new int[nDonations];
	
	//User input donations
	cout<<"\nEnter the donations"<<endl;
	for(int i = 0; i < nDonations; i++)
	{
		cout<<"Donation "<<(i+1)<<endl;
		cin>>donations[i];
	}
									
	//array of pointers to int
	int *arrPtr[nDonations];
	
	//Fill with NULL
	for(int i = 0; i < nDonations; i++)
	{
		arrPtr[i] = NULL; 
	}
								   
	//each element of arrPtr is a pointer to int. Make each
	//element point to an element in the donations array
	for (int count = 0; count < nDonations; count++)
		arrPtr[count] = &donations[count];
		
	//sort the elements of the array of pointers
	arrSelectSort(arrPtr, nDonations);
	
	//display the donations using the array of pointers. This
	//will display them in sorted order
	cout<<"The donations, sorted in ascending order are: \n";
	showArrPtr(arrPtr, nDonations);
	
	//Display the donations in their original order
	cout<<"The donations, in their original order are: \n";
	showArray(donations, nDonations);
	
	//For better readability
	cout<<endl;
	
	//Free dynamic memory
	delete [] donations;
	donations = 0;
}

//Gaddis ch 9 prob 7
void problem6()
{
	//constant number of donations
	const int NUM_DONATIONS = 15;
	
	//array contains donation amounts
	int donations[NUM_DONATIONS] = { 5, 100,  5, 25,  10,
	                                 5,  25,  5,  5, 100,
									10,  15, 10,  5,  10 };
									
	//array of pointers to int
	int *arrPtr[NUM_DONATIONS] = { NULL, NULL, NULL, NULL, NULL,
						           NULL, NULL, NULL, NULL, NULL,
								   NULL, NULL, NULL, NULL, NULL };
								   
	//each element of arrPtr is a pointer to int. Make each
	//element point to an element in the donations array
	for (int count = 0; count < NUM_DONATIONS; count++)
		arrPtr[count] = &donations[count];
		
	//sort the elements of the array of pointers
	arrSelectSort_6(arrPtr, NUM_DONATIONS);
	
	//display the donations using the array of pointers. This
	//will display them in descending order
	cout<<"The donations, sorted in descending order are: \n";
	showArrPtr_6(arrPtr, NUM_DONATIONS);
	
	//Show array in original order
	cout<<"The donations, in their original order are: \n";
	showArray_6(donations, NUM_DONATIONS);
	
	//For better readability
	cout<<endl;
}

//Start def exit program
void def(int inN)
{
	cout<<"You typed "<<inN<<" to exit the program"<<endl;
}//End procedure def

//Functions used by problems
//Problem 1

//Start method mean
float mean(int meanAry[], int size)
{
	//Declare Function Variables
	float ttl=0.0f;//Total of all added values at var size
	
	//Add values based on var size
	for(int i=0; i<size; i++)
	{
		ttl += meanAry[i]; 
	}
	
	//Output results
	cout<<"Mean:   "<<ttl/size<<endl;;//Added values / var size
	
	//goto method median
	median(meanAry, size);
}//End method mean

//Start method median
float median(int medAry[],int size)
{
	//Declare Function Variables
	float even=0.0f; //Placeholder for if even
	
	//Check if number of elements is odd
	if(size % 2 != 0)
	{
		//If odd, only one value can be median
		int temp = ((size+1)/2)-1; //go back one on array
		
		//Output results
		cout<<"Median: "<<medAry[temp]<<endl;
	}
	
	//If num of elements is even
	else{
		even = (medAry[(size/2)-1]) + (medAry[size/2]);//Middle two values added
		even/=2;                                       //Then divide by 2
		
		//Output results
		cout<<"Median: "<<even<<endl;
	}
	
	//goto method mode
	mode(medAry, size);
}//End method median

//Start method mode
int *mode(int modeAry[], int size)
{
	//Declare Function Variables
	int temp=0,          // Temporary value
		last=modeAry[0], // Assign to first number in modeAry
	    mode=last,       // get the mode
		count=1;         // counter
	
	int nMode=0; //number of modes
	
	//Go through array & check if 2 values are equal
	for(int i =0; i<size; i++)
	{
		//If first number = modeAry[i]
		if(last == modeAry[i])
		{
			temp++;
			nMode++;
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
	
	//Output results
	cout<<"Mode:  "<<mode<<endl;
	cout<<"Number of modes: "<<nMode<<endl;
	cout<<"Max Frequency:   "<<nMode<<endl<<endl;
}//End method mode

//Problem 2

//Start method onArr
int *inArr(int size)
{
	//Dynamically allocate array based in user input
	int *arrPtr = new int[size];
	return arrPtr;
}//End method inArr

//Problem 3

//Start method srtScore
void srtScore(float array[], int num)
{
	//Declare Function Variables
	bool isSorting; //Is array still being sorted?
	
	do{
		isSorting = false;
		
		for(int i = 0; i < num-1; i++)
		{
			if(array[i] > array[i+1])
			{
				//Swap values
				float temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				isSorting = true;
			}
		}
	}while(isSorting);
}//End method srtScore

//Start method avgScore
float avgScore(float total, float nScores)
{
	//Declare Function Variables
	float avg = 0; //Average
	
	//Average = total of all values / number of scores
	avg = total/nScores;
	
	//Return average
	return avg;
}

//Problem 4

//Start method doSomething
int doSomething(int *x, int *y)
{
	//Declare Function Variables
	int temp = *x;
	
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}

//Problem 5

//Start method arrSelectSort
void arrSelectSort(int *arr[], int size)
{
	//Declare Function Variables
	int startScan, // Start the scan 
	    minIndex;  // Minimum index of array
	int *minElem;  // Smallest element of the array
	
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		//Go through the array based on startScan
		minIndex = startScan;
		minElem = arr[startScan];
		
		//Start sorting
		for(int index = startScan + 1; index < size; index ++)
		{
			if(*(arr[index]) < *minElem)
			{
				minElem = arr[index];
				minIndex = index;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minElem;
	}
}

//Start method showArray
void showArray(const int arr[], int size)
{
	//Display contents of the array
	for (int count = 0; count < size; count++)
		cout<<arr[count]<<" ";
	cout<<endl;
}//End method showArray

//Start method showArrPtr
void showArrPtr(int *arr[], int size)
{
	//Display contents of the sorted array in ascending order
	for(int count = 0; count < size; count++)
		cout<<*(arr[count])<<" ";
	cout<<endl;
}//End method showArrPtr

//Problem 6

//Start method arrSelectSort_6
void arrSelectSort_6(int *arr[], int size)
{
	int startScan, // Start the scan
	    minIndex;  // Minimum index of array
	int *minElem;  // Smallest element of the array
	
	//Start scanning through array 
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minElem = arr[startScan];
		
		//Start sorting array
		for(int index = startScan + 1; index < size; index ++)
		{
			if(*(arr[index]) < *minElem)
			{
				minElem = arr[index];
				minIndex = index;
			}
		}
		arr[minIndex] = arr[startScan];
		arr[startScan] = minElem;
	}
}

//Start method showArray_6
void showArray_6(const int arr[], int size)
{
	//Show contents of the array
	for (int count = 0; count < size; count++)
		cout<<arr[count]<<" ";
	cout<<endl;
}//End method showArray_6

//Start method showArrPtr_6
void showArrPtr_6(int *arr[], int size)
{
	//Show contents of the array in descending arder
	for(int count = 14; count >= 0; count --)
		cout<<*(arr[count])<<" ";
	cout<<endl;
}//End method showArrPtr_6
