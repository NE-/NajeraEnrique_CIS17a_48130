/*
 * File:    MainMenu.hpp
 * Author:  Najera Enrique
 * Purpose: Build menus with
 *          help of Menu.hpp
 *
 * 08 December 2014
 */

#ifndef MAINMENU_HPP
#define MAINMENU_HPP

//System Libraries
#include <iostream>
#include <cstdlib>
#include <time.h>

//Published Libraries
#include "Menu.hpp"
#include "Random.hpp"

//Namespaces
using namespace std;

class MainMenu : public Menu
{
    private:
        int code;        // Holds code input
        char *cCode;     // Holds int to char conversion for passing
        int saveCode[0]; // Holds load game code for passing
        int pW;          // Holds password for load game
        bool isCodeGood; // True if load game code is good
                         // False if load game code is bad
    public:
        //Constructors
        //Default
        MainMenu() : Menu()
            { inN = 1; isCodeGood = false; }
        //Takes user input and sends to output menu
        MainMenu(int in)
            { inN = in;
              outMenu(inN); }

        //Accessor Functions
        bool getIsCodeGood() const
            { return isCodeGood; }
        int getPassword() const
            { return pW; }

        //Functions
        //Start outMenu displays main menu
        void outMenu(int in)
        {
            if(in == 1);              // Start Game
            else if(in == 2)inCode(); // Load Game
                                      // 3 is help menu
            //Other, just start new game
            else if (in > 4) cout << "Invalid choice! Starting game\n";
        }//End outMenu

        //Start outPMenu displays pause menu
        void outPMenu(int in)
        {
            if(in == 1);                // Resume Game
            else if(in == 2)saveGame(); // Save Game
                                        // 3 is help menu
            //Other, just resume game
            else if (in > 4) ;
        }//End outPMenu

        //Start inCode for loading saved game
        void inCode()
        {
            //Prompt for password/code
            cout << "Enter the code: ";
            cin >> code;
            //Decrypt code
            cCode = reinterpret_cast<char *>(code), sizeof(code);
            //Convert int to char *
            sprintf(fName, "%d", cCode);
            //Find that file
            readFile(fName, 0, 0);
            //Set isCodeGood to FileStreams isOpenSuccess
            isCodeGood = isOpenSuccess;
        }//End inCode

        //Start saveGame for saving game
        void saveGame()
        {
            //Set random number seed
            srand(time(0));

            //Generate objects
            Random<int> randNum;
            //Push in random number
            randNum.push(rand());
            //Pass number to array
            saveCode[0] = randNum.top();

            //Convert int to char *
            sprintf(fName, "%d", pW);
            cout << "Saving game..." << endl;
            //Write to save file
            writeFile(fName, saveCode, 1);
        }//End saveGame
};

#endif // MAINMENU_HPP
