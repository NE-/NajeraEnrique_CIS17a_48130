/*
 * File:    main.cpp
 * Author:  Najera Enrique
 * Purpose: CSC-17-A Project 2
 *          Some random RPG
 *
 * 08 December 2014
 */

//System Libraries
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime>   // time
#include <conio.h> // _getch()
#include <new>     // Catch memory errors

//Published Libraries
#include "Map.hpp"
#include "Player.hpp"
#include "Entity.hpp"
#include "MainMenu.hpp"
#include "Speechbox.hpp"

//Function Prototypes
int randnumX(int *, int *);
int randnumY(int *, int *);

//Namespaces
using namespace std;

int main()
{
    //Declare Variables
    char wasd  = ' ';          // Holds player's movement
    char *loc  = 0;            // Holds player location
    char **arrMap1;            // For allocating memory
    int locX   = 0;            // Holds X location
    int locY   = 0;            // Holds Y location
    int turn   = 0;            // Holds turns taken
    int menuIn = 0;            // Holds menu input
    int debug[0];              // Converts char to int for debug file
    bool isGameRunning = true; // Checks if game is still running
    bool action = false;       // Checks if player is fighting

    //Define objects
    Player p;
    Map map1;
    MainMenu menu;

    //Allocate instances
    Speechbox *sB = new Playerbox();
    Playerbox *pB = new Playerbox();
    Pickupbox *pU = new Pickupbox();

    //Build FileStream object
    FileStream f;
    //Display menu and prompt for choice
    f.readFile("Main.mnu", 0, 0);

    cin >> menuIn;

    //If 3, display help screen
    if(menuIn == 3)
    {
        system("cls");
        f.readFile("help.mnu", 0, 0);
        cout << "\nPress Enter to start game\n";
        _getch();
        system("cls");
    }
    //If 4, exit and don,t bother set or output
    else if(menuIn == 4){ cout << "\nGoodbye!\n"; exit(EXIT_SUCCESS); }

    //If not 3, set and output menu
    menu.setInN(menuIn);
    menu.outMenu(menuIn);

    //If load game fail, prompt
    if(menu.getIsCodeGood() == false)
    {
        //Prompt for user info
        cin >> p;

        //Prompt for map properties
        cin >> map1;
    }

    //Allocate memory for map
    try
    {
        arrMap1 = new char*[map1.getMapY()];
        for (int i = 0; i < map1.getMapY(); ++i)
            arrMap1[i] = new char[map1.getMapX()];
    }
    //Catch error
    catch (bad_alloc)
    {
        cout << "Insufficient memory!\n";
    }

    //Fill the map with tiles
    for(int y = 0; y < map1.getMapY(); y++)
    {
        for(int x = 0; x < map1.getMapX(); x++)
            arrMap1[y][x] = map1.getTile();
    }

    //Place player in center of map
    arrMap1[map1.getMapY() / 2][map1.getMapX() / 2] = p.getAvatar();

    //Get player's location for logging
    p.setLocX(map1.getMapX());
    p.setLocY(map1.getMapY());

    //Get player's location for movement
    locX = p.getLocX() / 2;
    locY = p.getLocY() / 2;

    //Build entities
    //location x, location y, health, strength
    Alien alien(0, 0, 1, -0.2f);
    Virus virus(0, 0, 3, -0.5f);
    Giant giant(0, 0, 5, -1.0f);

    //Output map
    for (int y = 0; y < map1.getMapY(); y++)
    {
        for (int x = 0; x < map1.getMapX(); x++)cout << arrMap1[y][x]<<" ";
        cout<<endl;
    }

    //Display user info
    cout << p;

    //Game loop starts here
    do{
        //Update locations
        //Player
        p.setLocX(locX);
        p.setLocY(locY);
        //Alien
        alien.setLocY_Alien(randnumY(&locY, &locX));
        alien.setLocX_Alien(randnumX(&locY, &locX));
        //Virus
        virus.setLocY_Virus(randnumY(&locY, &locX));
        virus.setLocX_Virus(randnumY(&locY, &locX));
        //Giant
        giant.setLocY_Giant(randnumY(&locY, &locX));
        giant.setLocX_Giant(randnumY(&locY, &locX));

        //Place objects on map if not action
        if(action == false)
        {
            //Entities
            arrMap1[randnumY(&locY, &locX)][randnumX(&locY, &locX)] = alien.getAvatar_Alien();
            //Every 2 turns add a virus
            if(turn % 2 == 0)arrMap1[randnumY(&locY, &locX)][randnumX(&locY, &locX)] = virus.getAvatar_Virus();
            //Every 4 turns add a giant
            if(turn % 4 == 0)arrMap1[randnumY(&locY, &locX)][randnumX(&locY, &locX)] = giant.getAvatar_Giant();
            //Pickups
            //Every 5 turns add a bullet
            if(turn % 5 == 0)arrMap1[randnumY(&locY, &locX)][randnumX(&locY, &locX)] = p.getBullet();
            //every 10 turns add health
            if(turn % 10 == 0)arrMap1[randnumY(&locY, &locX)][randnumX(&locY, &locX)] = '+';
        }//End placing objects

        //Get player movement
        wasd = _getch();

        //Increment turn
        turn++;

        //For keylogging
        p.setMovement(wasd);

        //Keep track of player location
        loc = &arrMap1[locY][locX];

        //If player quits, break from game loop
        if (wasd == 'p')
        {
            action = false;        // No action raking place
            isGameRunning = false; // Game will close
            debug[0] = 112;           // Debug value is quit
            cout << "\n\nGoodbye!\n" << endl;
            //Write to file for debugging purposes
            f.writeFile("debug.info", debug, 0);
            break;
        }//End player quits

        //Pause game
        else if(wasd == 'b')
        {
            //INTIT var menuIn
            menuIn = 0;
            system("cls");
            //Read pause menu file
            f.readFile("Pause.mnu", 0, 0);
            //Prompt for decision
            cin >> menuIn;
            //If 3, exit and clean
            if(menuIn == 3)break;

            //If not 3, set and output menu
            menu.setInN(menuIn);
            menu.outPMenu(menuIn);
            //If game saved, output load game code
            if(menuIn == 2)cout << "Your code is " << menu.getPassword() << endl;
            _getch();
        }//End pause game

        /* PLAYER MOVEMENT */

        //Move up
        else if (wasd == 'w')
        {
            //If inside boundary
            if(locY > 0)
            {
                action = false;
                //Detect if player touched something
                if(arrMap1[locY][locX] == p.getBullet())                // Bullet     add  bullet
                { p.setAmmo(1); pU->picksup(0); _getch(); }
                else if(arrMap1[locY][locX] == '+')                     // Health Box add  health
                { p.setHealth(1); pU->picksup(1); _getch(); }
                else if(arrMap1[locY][locX] == alien.getAvatar_Alien()) // Alien      take health
                {
                    p.setHealth(alien.getStrength_Alien());
                    //Output entity attacks
                    sB->attacks(0);
                    _getch();
                }
                else if(arrMap1[locY][locX] == virus.getAvatar_Virus()) // Virus      take health
                {
                    p.setHealth(virus.getStrength_Virus());
                    //Output entity attacks
                    sB->attacks(1);
                    _getch();
                }
                else if(arrMap1[locY][locX] == giant.getAvatar_Giant()) // Giant      take health
                {
                    p.setHealth(giant.getStrength_Giant());
                    //Output entity attacks
                    sB->attacks(2);
                    _getch();
                }

                arrMap1[locY][locX] = map1.getTile(); // Redraw tile for player
                loc = &arrMap1[locY--][locX];         // Get new location

                arrMap1[locY][locX] = p.getAvatar();  // Draw avatar on new location
                system("cls");                        // Clear the screen
            }
            else system("cls");
        }//End move up

        //Move down
        else if (wasd == 's')
        {
            //If inside boundary
            if(locY < ((map1.getMapY()) - 1))
            {
                action = false;
                //Detect if player touched something
                if(arrMap1[locY][locX] == p.getBullet())                // Bullet     add bullet
                { p.setAmmo(1); pU->picksup(0); _getch(); }
                else if(arrMap1[locY][locX] == '+')                     // Health Box add health
                { p.setHealth(1); pU->picksup(1); _getch(); }
                else if(arrMap1[locY][locX] == alien.getAvatar_Alien()) // Alien      take health
                {
                    p.setHealth(alien.getStrength_Alien());
                    //Output entity attacks
                    sB->attacks(0);
                    _getch();
                }
                else if(arrMap1[locY][locX] == virus.getAvatar_Virus()) // Virus      take health
                {
                    p.setHealth(virus.getStrength_Virus());
                    //Output entity attacks
                    sB->attacks(1);
                    _getch();
                }
                else if(arrMap1[locY][locX] == giant.getAvatar_Giant()) // Giant      take health
                {
                    p.setHealth(giant.getStrength_Giant());
                    //Output entity attacks
                    sB->attacks(2);
                    _getch();
                }

                arrMap1[locY][locX] = map1.getTile(); // Redraw tile
                loc = &arrMap1[locY++][locX];         // Get new location

                arrMap1[locY][locX] = p.getAvatar();  // Draw avatar on new location
                system("cls");                        // Clear the screen
            }
            else system("cls");
        }//End move down

        //Move left
        else if (wasd == 'a')
        {
            //If inside boundary
            if(locX > 0)
            {
                action = false;
                //Detect if player touched something
                if(arrMap1[locY][locX] == p.getBullet())                // Bullet     add bullet
                { p.setAmmo(1); pU->picksup(0); _getch(); }
                else if(arrMap1[locY][locX] == '+')                     // Health Box add health
                { p.setHealth(1); pU->picksup(1); _getch(); }
                else if(arrMap1[locY][locX] == alien.getAvatar_Alien()) // Alien      take health
                {
                    p.setHealth(alien.getStrength_Alien());
                    //Output entity attacks
                    sB->attacks(0);
                    _getch();
                }
                else if(arrMap1[locY][locX] == virus.getAvatar_Virus()) // Virus      take health
                {
                    p.setHealth(virus.getStrength_Virus());
                    //Output entity attacks
                    sB->attacks(1);
                    _getch();
                }
                else if(arrMap1[locY][locX] == giant.getAvatar_Giant()) // Giant      take health
                {
                    p.setHealth(giant.getStrength_Giant());
                    //Output entity attacks
                    sB->attacks(2);
                    _getch();
                }

                arrMap1[locY][locX] = map1.getTile(); // Redraw tile
                loc = &arrMap1[locY][locX--];         // Get new location

                arrMap1[locY][locX] = p.getAvatar();  // Draw avatar on new location
                system("cls");                        // Clear the screen
            }
            else system("cls");
        }//End move left

        //Move right
        else if (wasd == 'd')
        {
            //If inside boundary
            if(locX < (map1.getMapX() - 1))
            {
                action = false;
                //Detect if player touched something
                if(arrMap1[locY][locX] == p.getBullet())                // Bullet     add bullet
                { p.setAmmo(1); pU->picksup(0); _getch(); }
                else if(arrMap1[locY][locX] == '+')                     // Health Box add health
                { p.setHealth(1); pU->picksup(1); _getch(); }
                else if(arrMap1[locY][locX] == alien.getAvatar_Alien()) // Alien      take health
                {
                    p.setHealth(alien.getStrength_Alien());
                    //Output entity attacks
                    sB->attacks(0);
                    _getch();
                }
                else if(arrMap1[locY][locX] == virus.getAvatar_Virus()) // Virus      take health
                {
                    p.setHealth(virus.getStrength_Virus());
                    //Output entity attacks
                    sB->attacks(1);
                    _getch();
                }
                else if(arrMap1[locY][locX] == giant.getAvatar_Giant()) // Giant      take health
                {
                    p.setHealth(giant.getStrength_Giant());
                    //Output entity attacks
                    sB->attacks(2);
                    _getch();
                }

                arrMap1[locY][locX] = map1.getTile(); // Redraw tile
                loc = &arrMap1[locY][locX++];         // Get new location

                arrMap1[locY][locX] = p.getAvatar();  // Draw avatar on new location
                system("cls");                        // Clear the screen
            }
            else system("cls");
        }//End move right

        /* PLAYER ACTIONS */

        //Shooting
        //shoot up
        if(wasd == 'i')
        {
            action = true;

            //Check if still has ammo
            if(p.getAmmo() <= 0)
                cout << "\nNo more ammo!\n";
            else if(p.getAmmo() > 0)
            {
                //Remove bullet
                p.setAmmo(-1);

                //Shoot entity if present
                //Alien
                if(arrMap1[locY - 1][locX] == alien.getAvatar_Alien())
                {
                    //Tell player attacking alien
                    pB->attacks(alien.getAvatar_Alien());
                    //Take away 1 health point from alien
                    alien.setHealth_Alien(-1);
                    cout << "\nAlien killed!\n\n";

                    //Give points
                    p.setPts(alien.getPoints_Alien());

                    //Remove alien from map
                    arrMap1[locY - 1][locX] == map1.getTile();

                    //Reset alien health for other aliens
                    alien.setHealth_Alien(1);
                }//End murdering Alien
                //Virus
                else if(arrMap1[locY - 1][locX] == virus.getAvatar_Virus())
                {
                    //Tell player attacking virus
                    pB->attacks(virus.getAvatar_Virus());
                    //Show and remove virus health
                    cout << "\nVirus Health: " << virus.getHealth_Virus()
                         << endl << endl;
                    virus.setHealth_Virus(-1);

                    //If virus killed
                    if(virus.getHealth_Virus() == 0)
                    {
                        cout << "\nVirus Killed!\n\n";

                        //Give points
                        p.setPts(virus.getPoints_Virus());

                        //Remove virus from map
                        arrMap1[locY - 1][locX] == map1.getTile();

                        //Reset virus health for other viruses
                        virus.setHealth_Virus(3);
                    }
                }//End murdering Virus
                //Giant
                else if(arrMap1[locY - 1][locX] == giant.getAvatar_Giant())
                {
                    //Tell player attacking giant
                    pB->attacks(giant.getAvatar_Giant());
                    //Show and remove giant health
                    cout << "\nGiant Health: " << giant.getHealth_Giant()
                         << endl << endl;
                    giant.setHealth_Giant(-1);

                    //If giant killed
                    if(giant.getHealth_Giant() == 0)
                    {
                        cout << "\nGiant Killed!\n\n";

                        //Give points
                        p.setPts(giant.getPoints_Giant());

                        //Remove Giant from map
                        arrMap1[locY - 1][locX] == map1.getTile();

                        //Reset Giant health for other giants
                        giant.setHealth_Giant(5);
                    }
                }//End murdering Giant
                else cout << endl;
            }//End if p.getAmmo() > 0
        }//End shoot up

        //shoot down
        else if(wasd == 'k')
        {
            action = true;

            //Check if still has ammo
            if(p.getAmmo() <= 0)
                cout << "\nNo more ammo!\n";
            else if(p.getAmmo() > 0)
            {
                //Remove bullet
                p.setAmmo(-1);

                //Shoot entity if present
                //Alien
                if(arrMap1[locY + 1][locX] == alien.getAvatar_Alien())
                {
                    //Tell player attacking alien
                    pB->attacks(alien.getAvatar_Alien());
                    //Take away 1 health point from alien
                    alien.setHealth_Alien(-1);
                    cout << "\nAlien killed!\n\n";

                    //Give points
                    p.setPts(alien.getPoints_Alien());

                    //Remove alien from map
                    arrMap1[locY + 1][locX] == map1.getTile();

                    //Reset alien health for other aliens
                    alien.setHealth_Alien(1);
                }//End murdering Alien
                //Virus
                else if(arrMap1[locY + 1][locX] == virus.getAvatar_Virus())
                {
                    //Tell player attacking virus
                    pB->attacks(virus.getAvatar_Virus());
                    //Show and remove virus health
                    cout << "\nVirus Health: " << virus.getHealth_Virus()
                         << endl << endl;
                    virus.setHealth_Virus(-1);

                    //If virus killed
                    if(virus.getHealth_Virus() == 0)
                    {
                        cout << "\nVirus Killed!\n\n";

                        //Give points
                        p.setPts(virus.getPoints_Virus());

                        //Remove virus from map
                        arrMap1[locY + 1][locX] == map1.getTile();

                        //Reset virus health for other viruses
                        virus.setHealth_Virus(3);
                    }
                }//End murdering Virus
                //Giant
                else if(arrMap1[locY + 1][locX] == giant.getAvatar_Giant())
                {
                    //Tell player attacking giant
                    pB->attacks(giant.getAvatar_Giant());
                    //Show and remove giant health
                    cout << "\nGiant Health: " << giant.getHealth_Giant()
                         << endl << endl;
                    giant.setHealth_Giant(-1);

                    //If giant killed
                    if(giant.getHealth_Giant() == 0)
                    {
                        cout << "\nGiant Killed!\n\n";

                        //Give points
                        p.setPts(giant.getPoints_Giant());

                        //Remove Giant from map
                        arrMap1[locY + 1][locX] == map1.getTile();

                        //Reset Giant health for other giants
                        giant.setHealth_Giant(5);
                    }
                }//End murdering Giant
                else cout << endl;
            }//End if p.getAmmo() > 0
        }//End shoot down

        //shoot left
        else if(wasd == 'j')
        {
            action = true;

            //Check if still has ammo
            if(p.getAmmo() <= 0)
                cout << "\nNo more ammo!\n";
            else if(p.getAmmo() > 0)
            {
                //Remove bullet
                p.setAmmo(-1);

                //Shoot entity if present
                //Alien
                if(arrMap1[locY][locX - 1] == alien.getAvatar_Alien())
                {
                    //Tell player attacking alien
                    pB->attacks(alien.getAvatar_Alien());
                    //Take away 1 health point from alien
                    alien.setHealth_Alien(-1);
                    cout << "\nAlien killed!\n\n";

                    //Give points
                    p.setPts(alien.getPoints_Alien());

                    //Remove alien from map
                    arrMap1[locY][locX] == map1.getTile();

                    //Reset alien health for other aliens
                    alien.setHealth_Alien(1);
                }//End murdering Alien
                //Virus
                else if(arrMap1[locY][locX - 1] == virus.getAvatar_Virus())
                {
                    //Tell player attacking virus
                    pB->attacks(virus.getAvatar_Virus());
                    //Show and remove virus health
                    cout << "\nVirus Health: " << virus.getHealth_Virus()
                         << endl << endl;
                    virus.setHealth_Virus(-1);

                    //If virus killed
                    if(virus.getHealth_Virus() == 0)
                    {
                        cout << "\nVirus Killed!\n\n";

                        //Give points
                        p.setPts(virus.getPoints_Virus());

                        //Remove virus from map
                        arrMap1[locY][locX - 1] == map1.getTile();

                        //Reset virus health for other viruses
                        virus.setHealth_Virus(3);
                    }
                }//End murdering Virus
                //Giant
                else if(arrMap1[locY][locX - 1] == giant.getAvatar_Giant())
                {
                    //Tell player attacking giant
                    pB->attacks(giant.getAvatar_Giant());
                    //Show and remove giant health
                    cout << "\nGiant Health: " << giant.getHealth_Giant()
                         << endl << endl;
                    giant.setHealth_Giant(-1);

                    //If giant killed
                    if(giant.getHealth_Giant() == 0)
                    {
                        cout << "\nGiant Killed!\n\n";

                        //Give points
                        p.setPts(giant.getPoints_Giant());

                        //Remove Giant from map
                        arrMap1[locY][locX - 1] == map1.getTile();

                        //Reset Giant health for other giants
                        giant.setHealth_Giant(5);
                    }
                }//End murdering Giant
                else cout << endl;
            }//End if p.getAmmo() > 0
        }//End shoot left

        //shoot right
        else if(wasd == 'l')
        {
            action = true;

            //Check if still has ammo
            if(p.getAmmo() <= 0)
                cout << "\nNo more ammo!\n";
            else if(p.getAmmo() > 0)
            {
                //Remove bullet
                p.setAmmo(-1);

                //Shoot entity if present
                //Alien
                if(arrMap1[locY][locX + 1] == alien.getAvatar_Alien())
                {
                    //Tell player attacking alien
                    pB->attacks(alien.getAvatar_Alien());
                    //Take away 1 health point from alien
                    alien.setHealth_Alien(-1);
                    cout << "\nAlien killed!\n\n";

                    //Give points
                    p.setPts(alien.getPoints_Alien());

                    //Remove alien from map
                    arrMap1[locY][locX + 1] == map1.getTile();

                    //Reset alien health for other aliens
                    alien.setHealth_Alien(1);
                }//End murdering Alien
                //Virus
                else if(arrMap1[locY][locX + 1] == virus.getAvatar_Virus())
                {
                    //Tell player attacking virus
                    pB->attacks(virus.getAvatar_Virus());
                    //Show and remove virus health
                    cout << "\nVirus Health: " << virus.getHealth_Virus()
                         << endl << endl;
                    virus.setHealth_Virus(-1);

                    //If virus killed
                    if(virus.getHealth_Virus() == 0)
                    {
                        cout << "\nVirus Killed!\n\n";

                        //Give points
                        p.setPts(virus.getPoints_Virus());

                        //Remove virus from map
                        arrMap1[locY][locX + 1] == map1.getTile();

                        //Reset virus health for other viruses
                        virus.setHealth_Virus(3);
                    }
                }//End murdering Virus
                //Giant
                else if(arrMap1[locY][locX + 1] == giant.getAvatar_Giant())
                {
                    //Tell player attacking giant
                    pB->attacks(giant.getAvatar_Giant());
                    //Show and remove giant health
                    cout << "\nGiant Health: " << giant.getHealth_Giant()
                         << endl << endl;
                    giant.setHealth_Giant(-1);

                    //If giant killed
                    if(giant.getHealth_Giant() == 0)
                    {
                        cout << "\nGiant Killed!\n\n";

                        //Give points
                        p.setPts(giant.getPoints_Giant());

                        //Remove Giant from map
                        arrMap1[locY][locX + 1] == map1.getTile();

                        //Reset Giant health for other giants
                        giant.setHealth_Giant(5);
                    }
                }//End murdering Giant
                else cout << endl;
            }//End if p.getAmmo() > 0
        }//End shoot right

        //If player us dead
        else if(p.getHealth() == 0)
        {
            cout << "\nYou Have Died!!\n\n"
                 << "Final Score: " << p.getPts() << endl;
            break;
        }

        //If wrong character, cls to avoid duplicating screen
        else system("cls");

        //Display map
        for (int y = 0; y < map1.getMapY(); y++)
        {
            for (int x = 0; x < map1.getMapX(); x++)cout << arrMap1[y][x]<<" ";
            cout<<endl;
        }

        //Clear some entities off the map
        arrMap1[randnumY(&locY, &locX)][randnumX(&locY, &locX)] = map1.getTile();

        //Display player info
        cout << p;

    }while(isGameRunning); //End game loop

    //Free allocated memory
    cout << "Exiting";
    for(int i = 0; i < map1.getMapY(); ++i)
    {
        cout << ".";
        delete [] arrMap1;
    }
    delete [] arrMap1;
    delete sB;
    delete pB;
    delete pU;

    //Exit program
    system("PAUSE");
    return 0;
}//End method main

//Function Prototypes
//Start method randnumX
int randnumX(int *y, int *x)
{
    //Declare function variables
    int randN; // Holds random number
    //Set random number seed
    srand(time(0));

    //If denominator will be 0, return var y
    if(((*x + 1) - *y) <= 0)return *y;
    else
        //Keeps number between locX and locY
	    randN = *y + rand() % ((*x + 1) - *y);

    //Return the random number
	return randN;
}//End method randnumX

//Start method randnumY
int randnumY(int *y, int *x)
{
    //Declare function variables
    int randN; // Holds random number

    //If denominator will be 0, return var y
    if(((*x + 1) - *y) <= 0)return *y;
    else
        //Keeps number between locX and locY
	    randN = *y + rand() % ((*x + 1) - *y);

    //Return the random number
	return randN;
}//End method randnumY
