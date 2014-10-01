/*
 * File: main.cpp
 * Author: Enrique Najera
 * Purpose: Assignment 2 Gaddis
            Ch 10 8th Ed. problems
 * 30 September 2014
 */
 
//System Libraries
#include <iostream>
#include <fstream>
#include <string>

//Namespaces
using namespace std; // iostream

//No Globals

//Function Prototypes
void Menu();      // Main menu to choose probs
int getN();       // Get user's choice
void def(int);    // Exit the program

void problem1();  // Gaddis ch 10 prob  1
void problem2();  // Gaddis ch 10 prob  2
void problem3();  // Gaddis ch 10 prob  3
void problem4();  // Gaddis ch 10 prob  6
void problem5();  // Gaddis ch 10 prob 17

void problem6();  // Gaddis ch 12 prob  1
void problem7();  // Gaddis ch 12 prob  2
void problem8();  // Gaddis ch 12 prob  4
void problem9();  // Gaddis ch 12 prob  5
void problem10(); // Gaddis ch 12 prob 15

//Problem functions
//Problem 1
int cntChars(char *); //Counts and returns characters in a string

//Problem 2
int cntChars_2(char *);               // Counts characters in string
void showString(const char *, int);   // Show string after sort

//Problem 3
int cntWrds(char *); //Count words

//Problem 4
//Procedure functions
int cntVowel(char *); // Counts vowels in a string
int cntConso(char *); // Counts consonants in a string

//Menu functions
void menu();          // Displays the menu
char getIN();         // Get the user's input for the menu
void kill();          // Kills the program if e | E is entered

//Problem 5
void txtToMorse(char *); // String to Morse code conversion

//Start method main
int main(int argc, char *argv[])
{
	//Declare Variables
	int inN = 0; // For user's choice
	
	//While problems
	do{
		Menu();     // Call and display the main menu
		inN=getN(); // Get user's choice
		
		switch(inN)
		{
			case  1:   problem1(); break; // Gaddis ch 10 prob  1
			case  2:   problem2(); break; // Gaddis ch 10 prob  2
			case  3:   problem3(); break; // Gaddis ch 10 prob  3
			case  4:   problem4(); break; // Gaddis ch 10 prob  6
			case  5:   problem5(); break; // Gaddis ch 10 prob 17
			
			case  6:   problem6(); break; // Gaddis ch 12 prob  1
			case  7:   problem7(); break; // Gaddis ch 12 prob  2
			case  8:   problem8(); break; // Gaddis ch 12 prob  4
			case  9:   problem9(); break; // Gaddis ch 12 prob  5
			case 10:   problem10();break; // Gaddis ch 12 prob 15
			default: def(inN);
		}
	}while(inN<11); //'11' to end switch inN

	//Exit the program
	system("PAUSE");
	return 0;
}//End method main

//Start Menu
void Menu()
{
	//Output user options
	cout<<"-Chapter 10 Problems--"<<endl;
	cout<<"Type  1 for problem  1"<<endl; // Gaddis ch 10 prob  1
	cout<<"Type  2 for problem  2"<<endl; // Gaddis ch 10 prob  2
	cout<<"Type  3 for problem  3"<<endl; // Gaddis ch 10 prob  3
	cout<<"Type  4 for problem  4"<<endl; // Gaddis ch 10 prob  6
	cout<<"Type  5 for problem  5"<<endl; // Gaddis ch 10 prob 17
	cout<<endl;
	cout<<"-Chapter 12 Problems--"<<endl;
	cout<<"Type  6 for problem  6"<<endl; // Gaddis ch 12 prob  1
	cout<<"Type  7 for problem  7"<<endl; // Gaddis ch 12 prob  2
	cout<<"Type  8 for problem  8"<<endl; // Gaddis ch 12 prob  4
	cout<<"Type  9 for problem  9"<<endl; // Gaddis ch 12 prob  5
	cout<<"Type 10 for problem 10"<<endl; // Gaddis ch 12 prob 15
	cout<<"Type 11 to exit \n"<<endl;
}//End Procedure Menu

//Start getN user input
int getN()
{
	//Declare Function Variables
	int inN = 0;
	
	//Prompt for user input 
	cin>>inN;
	//For console readability
	cout<<endl;
	
	return inN;
}//End procedure getN

//Gaddis ch 10 prob 1
void problem1()
{
	//Declare Function Variables
	const int LENGTH = 50; // Max length of string 
	char inString[LENGTH]; // Input string
	
	//Prompt for string
	cout<<"Input a string\n";
	cin.ignore();
	cin.getline(inString, LENGTH);
	
	//Send var inString to method cntChars
	cout<<"The string has "<<cntChars(inString)<<" characters.\n";
	
	cout<<endl;
}//End ch 10 prob 1

//Gaddis ch 10 prob 2
void problem2()
{
	//Declare Function Variables
	const int LENGTH = 100; // total length of string
	int ttlChar=0;          // total number of chars in string
	char inString[LENGTH];  // carries input string
	
	//Prompt for word to be reversed
	cout<<"Input a string to be reversed\n";
	cin.ignore();
	cin.getline(inString, LENGTH);
	
	ttlChar = cntChars_2(inString); // Count characters in the string for display purposes
	showString(inString,ttlChar);   // Show reversed string
	
	cout<<endl;
}//End ch 10 prob 2

//Gaddis ch 10 prob 3
void problem3()
{
	//Declare Function Variables
	const int SIZE = 100; // Array size
	char usrWrds[SIZE];   // User words
	int ttlWrds = 0;      // Total words (for grammar sake)
	
	//Prompt user for words
	cout<<"Enter some words"<<endl;
	cin.ignore();
	cin.getline(usrWrds, SIZE);
	
	ttlWrds = cntWrds(usrWrds)+1; //Count total words
	
	//Output result
	//If entered 1 word, make 'word' singular
    if(ttlWrds == 1)
	{
		cout<<"You entered "<<ttlWrds<<" word\n";
	}
	//If words > 1, 'word' is plural
	else{
		cout<<"You entered "<<ttlWrds<<" words\n";
	}
	
	cout<<endl;
}//End ch 10 prob 3

//Gaddis ch 10 prob 6
void problem4()
{
	//Declare Function Variables
	const int SIZE = 100; // Total array size
	char inString[SIZE];  // User input string
	char inMenu;          // For user menu input
	bool loop = true;     // Loop the menu

	//Prompt for user's string
	cout<<"Enter a string\n";
	cin.ignore();
	cin.getline(inString, SIZE);
	
	// While inN != 'E'
	do{
		menu();           // Call and display the menu
		inMenu = getIN(); // Get user's choice
		
		switch(inMenu)
		{
			case 'a':
			case 'A': cout<<cntVowel(inString)<<" vowel(s)"<<endl;break;     // Call count vowels method
			case 'b':
			case 'B': cout<<cntConso(inString)<<" consonant(s)"<<endl;break; // Call count consonants method
			case 'c':
			case 'C': cout<<cntVowel(inString)<<" vowel(s)";                 // Count vowels
					  cout<<" and ";                                         // and
			          cout<<cntConso(inString)<<" consonant(s)"<<endl;       // Count consonants
					  break;
			case 'd':
			case 'D': cout<<"Enter a new string \n";                         // Replace string
			          cin.ignore();
					  cin.getline(inString, SIZE);
					  break;
			case 'e':
			case 'E': kill();loop = false;break;                             // End program
			default: cout<<"Wrong input detected!"<<endl;
		}
	}while(loop == true);
}//End ch 10 prob 6

//Gaddis ch 10 prob 17
void problem5()
{
	//Declare Function Variables
	const int LENGTH = 100; // Length of string
	char inString[LENGTH];  // Input string
	
	//Prompt for user's string
	cout<<"Enter a string to be converted to Morse code \n";
	cin.ignore();
	cin.getline(inString, LENGTH);
	
	//Convert inString value to Morse code
	txtToMorse(inString);
	
	cout<<"\n"<<endl;
}//End ch 10 prob 17

//Gaddis ch 12 prob 1
void problem6()
{
	//Declare Function Variables
	string fileName;  // Holds the file name
	char ch;          // Holds file characters
	fstream file;     // Rename structure
	int cntLines = 0; // Count the lines in file
	
	//Prompt for filename
	cout<<"Enter the name of the file: ";
	cin>>fileName;
	
	//Open the promted file
	file.open(fileName.c_str(), ios::in );
	
	//If the file opened
	if(file)
	{
		//Get char from the file
		file.get(ch);
		
		//While can get char in file
		while(file)
		{
			//Display character read
			cout<<ch;
			
			//If end of line, count
			if(ch=='\n')cntLines++;
			
			//If 10 lines, stop
			if(cntLines == 10)
			{
				//Close file if lines > 10
				file.close();
			}
			//Progress to next char
			file.get(ch);
		}
		//Close the file if lines < 10
		file.close();
	}
	//If file could not be opened
	else
		cout<<"Error opening "<<fileName<<endl;
}//End ch 12 prob 1

//Gaddis ch 12 prob 2
void problem7()
{
	//Declare Function Variables
	string fileName;  // Holds the file name
	char ch;          // Holds file's characters
	fstream file;     // Rename structure
	int cntLines = 0; // Counts lines in file
	
	//Prompt for file
	cout<<"Enter the name of the file: ";
	cin>>fileName;
	
	file.open(fileName.c_str(), ios::in);
	
	//If file opened
	if(file)
	{
		//Get file's characters
		file.get(ch);
		
		//While can get char from file
		while(file)
		{
			//Output character
			cout<<ch;
			
			//If end of line, count
			if(ch == '\n')
			{
				cntLines++;
			}
			//If lines = 24
			if(cntLines == 24)
			{
				cntLines = 0;    // Recount
				system("PAUSE"); // Pause
			}
			//Progress to next char
			file.get(ch);
		}
		//Close the file
		file.close();
	}
	else 
		cout<<"Error opening "<<fileName<<endl;
	
	cout<<endl;
}//End ch 12 prob 2

//Gaddis ch 12 prob 4
void problem8()
{
	//Declare Function Variables
	string fileName; // Hold filename
	char ch;         // Get file's chars
	fstream file;    // Rename structure
	int cntr = 0;    // Counter for lines
	
	//Prompt for file
	cout<<"Enter the name of the file: ";
	cin>>fileName;
	
	file.open(fileName.c_str(), ios::in);
	
	//If the file opened
	if(file)
	{
		//Get char from the file
		file.get(ch);
		
		//While can get char in file
		while(file)
		{
			if(ch == '\n')cntr++; //If end of line, count
			
			//If 9 or more lines, start output
			if(cntr>=9)
			{
				cout<<ch;
				if(cntr == 20)file.close(); //If 20 lines, stop output and close
			}
			//Progress to next char
			file.get(ch);
		}
		//Close the file if lines < 10
		file.close();
	}
	//If file could not be opened
	else
		cout<<"Error opening "<<fileName<<endl;
	cout<<endl;
}//End ch 12 prob 4

//Gaddis ch 12 prob 5
void problem9()
{
	//Declare Function Variables
	string fileName; // Holds the file's name
	char ch;         // Holds file's chars
	fstream file;    // Rename structure
	int cntr = 1,    // Output line number
	    lines = 1;   // Counts which line
	
	//Prompt for file
	cout<<"Enter the name of the file: ";
	cin>>fileName;
	
	file.open(fileName.c_str(), ios::in);
	
	//If file opened
	if(file)
	{
		//Get the file's chars
		file.get(ch);
		
		//While can get char in file
		while(file)
		{
			//For line 1
			if (cntr == 1)
			{
				cout<<cntr<<":";
				cntr++;
			}
			
			//output char in file
			cout<<ch;
			
			//For all other lines
			//If at end of line
			if(ch == '\n')
			{	
				if (lines == 24)
				{
					lines = 0;       // Recount
					system("PAUSE"); // Pause
				}
				
				//Output line number and a colon
				cout<<cntr<<":";
				cntr++; //go to next line
				lines++; //Count current line
			}
			//Advance to next char
			file.get(ch);
		}
		file.close();
	}
	else 
		cout<<"Error opening "<<fileName<<endl;
	
	cout<<endl;
}//End ch 12 prob 5

//Gaddis ch 12 prob 15
void problem10()
{
	//Declare Function Variables
	char ch;          // Holds the file's chars
	fstream file;     // Rename structure
	int cntSentn = 0, // Count number of sentences the file has
	    cntWords = 0; // Count number of words the file has
	
	//Open file
	file.open("text.txt", ios::in);
	
	//If file opened
	if(file)
	{
		//Get file's chars
		file.get(ch);
		
		//While can get chars
		while(file)
		{	
			// If there is a space, word found
			if(ch == ' ')
			{
				cntWords++; 
			}
			
			if(ch == '\n')
			{
				cntSentn++; // If \n found, end of sentence
				cntWords++; // Count end of sentence as a space for a word
			}
			//Advance to next char
			file.get(ch);
		}
		file.close();
	}
	else 
		cout<<"Error opening text.txt"<<endl;
	
	//Output result
	cout<<"The file \'text.txt\' has an average of "<<cntWords/cntSentn
	    <<" words per sentence.";
	cout<<"\n"<<endl;
}//End ch 12 prob 15

//Start def exit program
void def(int inN)
{
	cout<<"You typed "<<inN<<" to exit the program"<<endl;
}//End procedure def

//Start method cntChars
int cntChars(char *charPtr)
{
	//Declare function variables
	int count = 0; // Go through the string

	//While the string is not NULL
	while (*charPtr != '\0')
	{
		count++;   // Count the char
		charPtr++; // Advance to next char
		
		//If there is a space, don't count it
		if(*charPtr == ' ')charPtr++;
	}
	//Return number of chars in string
	return count;
}//End method cntChars

//Start method cntChars_2
int cntChars_2(char *charPtr)
{
	//Declare function variables
	int count = 0; // Go through the string

	//While the string is not NULL
	while (*charPtr != '\0')
	{
		count++;   // Count the char
		charPtr++; // Advance to next char
	}
	//Return number of chars in string
	return count;
}//End method cntChars_2

//Start method showString
void showString(const char *charPtr, int size)
{
	for(int i = size-1; i != -1 ; i-- )cout<<charPtr[i];
	cout<<endl;
}//End method showString

//Start method cntWords
int cntWrds(char *wrdPtr)
{
	int counter=0;//count words;
	
	//Count whitespaces
	while(*wrdPtr != '\0')
	{
		if(*wrdPtr == ' ' )counter++; //If whitespace, it's a word
		
		wrdPtr++;//goto next word
	}
	return counter;
}//End method cntWords

//Start method menu
void menu()
{
	cout<<"A) Count number of vowels in the string"<<endl;
	cout<<"B) Count number of consonants in the string"<<endl;
	cout<<"C) Count both vowels and consonants in the string"<<endl;
	cout<<"D) Enter another string"<<endl;
	cout<<"E) Exit the program\n"<<endl;
}//End method menu

//Start method getIN
char getIN()
{
	char choice; // User choice for the menu
	
	//Prompt for user input
	cin>>choice;
	//For console readability
	cout<<endl;
	
	return choice;
}//End method getIN

//Start method kill
void kill()
{
	cout<<"Goodbye!"<<endl;
}//End method kill

//Start method cntVowel
int cntVowel(char *strPtr)
{
	//Declare function variables
	int counter=0; // Count the vowels
	
	while(*strPtr != '\0')
	{
		// If a vowel was detected, count
		if(*strPtr == 'a')counter++;
		else if(*strPtr == 'A' )counter++;
		else if(*strPtr == 'I')counter++;
		else if(*strPtr == 'i')counter++;
		else if(*strPtr == 'U')counter++;
		else if(*strPtr == 'u')counter++;
		else if(*strPtr == 'E')counter++;
		else if(*strPtr == 'e')counter++;
		else if(*strPtr == 'O')counter++;
		else if(*strPtr == 'o')counter++;
		
		//Advance chars
		strPtr++;
	}
	return counter;
}//End method cntVowel

//Start method cntConso
int cntConso(char *strPtr)
{
	//Declare function variables
	int counter = 0; //Count the consonants
	
	//while not at the end of the string
	while(*strPtr != '\0')
	{
		//If there is a vowel, don't count
		if(*strPtr == 'a');
		else if(*strPtr == 'A' );
		else if(*strPtr == 'I');
		else if(*strPtr == 'i');
		else if(*strPtr == 'U');
		else if(*strPtr == 'u');
		else if(*strPtr == 'E');
		else if(*strPtr == 'e');
		else if(*strPtr == 'O');
		else if(*strPtr == 'o');
		//Exclude spaces
		else if(*strPtr == ' ');
		//If not a vowel, count
		else counter++;
		
		//Advance to next char
		strPtr++;
	}
	//Return the counter value
	return counter;
}//End method cntConso

//Start method txtToMorse
void txtToMorse(char *strMorse)
{
	//While not at the end of the string
	while(*strMorse != '\0')
	{
		// Punctuation
		if(*strMorse == ' ')cout<<"   ";
		if(*strMorse == ',')cout<<"--..-- ";
		if(*strMorse == '.')cout<<".-.-.- ";
		if(*strMorse == '?')cout<<"..--.. ";
		
		//Numbers
		if(*strMorse == '0')cout<<"----- ";
		if(*strMorse == '1')cout<<".---- ";
		if(*strMorse == '2')cout<<"..--- ";
		if(*strMorse == '3')cout<<"...-- ";
		if(*strMorse == '4')cout<<"....- ";
		if(*strMorse == '5')cout<<"..... ";
		if(*strMorse == '6')cout<<"-.... ";
		if(*strMorse == '7')cout<<"--... ";
		if(*strMorse == '8')cout<<"---.. ";
		if(*strMorse == '9')cout<<"----. ";
		
		//Alphabet
		if(*strMorse == 'a')cout<<".- ";
		else if (*strMorse == 'A')cout<<".- ";
		if(*strMorse == 'B')cout<<"-... ";
		else if (*strMorse == 'b')cout<<"-... ";
		if(*strMorse == 'C')cout<<"-.-. ";
		else if (*strMorse == 'c')cout<<"-.-. ";
		if(*strMorse == 'D')cout<<"-.. ";
		else if (*strMorse == 'd')cout<<"-.. ";
		if(*strMorse == 'E')cout<<". ";
		else if (*strMorse == 'e')cout<<". ";
		if(*strMorse == 'F')cout<<"..-. ";
		else if (*strMorse == 'f')cout<<"..-. ";
		if(*strMorse == 'G')cout<<"--. ";
		else if (*strMorse == 'g')cout<<"--. ";
		if(*strMorse == 'H')cout<<".... ";
		else if (*strMorse == 'h')cout<<".... ";
		if(*strMorse == 'I')cout<<".. ";
		else if (*strMorse == 'i')cout<<".. ";
		if(*strMorse == 'J')cout<<".--- ";
		else if (*strMorse == 'j')cout<<".--- ";
		if(*strMorse == 'K')cout<<"-.- ";
		else if (*strMorse == 'k')cout<<"-.- ";
		if(*strMorse == 'L')cout<<".-.. ";
		else if (*strMorse == 'l')cout<<".-.. ";
		if(*strMorse == 'M')cout<<"-- ";
		else if (*strMorse == 'm')cout<<"-- ";
		if(*strMorse == 'N')cout<<"-. ";
		else if (*strMorse == 'n')cout<<"-. ";
		if(*strMorse == 'O')cout<<"--- ";
		else if (*strMorse == 'o')cout<<"--- ";
		if(*strMorse == 'P')cout<<".--. ";
		else if (*strMorse == 'p')cout<<".--. ";
		if(*strMorse == 'Q')cout<<"--.- ";
		else if (*strMorse == 'q')cout<<"--.- ";
		if(*strMorse == 'R')cout<<".-. ";
		else if (*strMorse == 'r')cout<<".-. ";
		if(*strMorse == 'S')cout<<"... ";
		else if (*strMorse == 's')cout<<"... ";
		if(*strMorse == 'T')cout<<"- ";
		else if (*strMorse == 't')cout<<"- ";
		if(*strMorse == 'U')cout<<"..- ";
		else if (*strMorse == 'u')cout<<"..- ";
		if(*strMorse == 'V')cout<<"...- ";
		else if (*strMorse == 'v')cout<<"...- ";
		if(*strMorse == 'W')cout<<".-- ";
		else if (*strMorse == 'w')cout<<".-- ";
		if(*strMorse == 'X')cout<<"-..- ";
		else if (*strMorse == 'x')cout<<"-..- ";
		if(*strMorse == 'Y')cout<<"-.-- ";
		else if (*strMorse == 'y')cout<<"-.-- ";
		if(*strMorse == 'Z')cout<<"--.. ";
		else if (*strMorse == 'z')cout<<"--.. ";
		
		//Advance to next letter
		strMorse++;
	}
}//End method txtToMorse
