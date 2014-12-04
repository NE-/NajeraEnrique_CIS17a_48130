/*
 * File:    FileStream.cpp
 * Author:  Najera Enrique
 * Purpose: Reads and writes
 *          encrypted and readable
 *          files
 *
 * 08 December 2014
 */

//System Libraries
#include <fstream>
#include <iostream>

//Published Libraries
#include "FileStream.hpp"

//Namespaces
using namespace std;

//Read from file          read handle, content in file, should it be encrypted
void FileStream::readFile(char *rHnd, int content, bool isSecret)
{
    //Declare Variables
    char ch; //Get file characters

    //If file is not encrypted
    if(isSecret == 0)
    {
        //Create file stream object
        fstream rPublic;

        //Open file read handle
        rPublic.open(rHnd, ios::in);

        //If file open success
        if(rPublic)
        {
            rPublic.get(ch);     // Get char

            while(rPublic)
            {
                cout << ch;      // Display char
                rPublic.get(ch); // Get next char
            }
            rPublic.close();     // Close file
            setFileOpened(true); // File open success
        }
        //If file open fail, output error
        else
        {
            cout << "Error opening " << rHnd;
            setFileOpened(false); // File open fail
        }

        cout << endl;
    }//End if file not secret

    //If file is encrypted, decrypt
    if(isSecret == 1)
    {
        //Create file stream object
        fstream rPrivate;

       //Open and decrypt file content
       rPrivate.open(rHnd);
           rPrivate.read(reinterpret_cast<char *>(content), sizeof(content)) >> ch;
           rPrivate >> ch;
       rPrivate.close();
    }//End encrypted reading
}//End read file

//Write to file            write handle, content in file, should it be encrypted
void FileStream::writeFile(char *wHnd, int content[], bool isSecret)
{
    //Declare Function Variables
    char *newName; // Rewrites wHnd if bugged

    //If file can be read by user no problem
    if (isSecret == 0)
    {
        //Create file stream object
        fstream wPublic;

        //Start writing to file
        wPublic.open(wHnd, ios::out | ios::app);
            wPublic << content
                    << "\n";
        wPublic.close();
        //End writing to file
    }
    //If file would contain sensitive info, encrypt
    else if (isSecret == 1)
    {
        //Create file stream object
        fstream wPrivate;

        //Rewrite 2686656 bug
        if(*wHnd == 2686656)
        {
            //newName = some random number
            *wHnd = (rand() / 2) + 67; newName = wHnd;

            //Start writing to file
            wPrivate.open(newName, ios::out | ios::binary);
                wPrivate.write(reinterpret_cast<char *>(content), sizeof(content));
            wPrivate.close();
            //End writing to file
        }
        //If write handle has no bug
        else
        {
            //Start writing to file
            wPrivate.open(newName, ios::out | ios::binary);
                wPrivate.write(reinterpret_cast<char *>(content), sizeof(content));
            wPrivate.close();
            //End writing to file
        }
    }//End encryption
}//End write to file
