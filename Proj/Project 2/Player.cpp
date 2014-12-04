/*
 * File:    Player.cpp
 * Author:  Najera Enrique
 * Purpose: Stores info and
 *          properties of player
 *
 * 08 December 2014
 */

//System Libraries
#include <iostream>

//Published Libraries
#include "Player.hpp"

//Namespaces
using namespace std;

//Start setAvatar
void Player::setAvatar(char c)
{
    //If player avatar is the same as bullet, change bullet
    if(avatar == bullet)
    {
        bullet = 1 + avatar;

        //If bullet same as tile change bullet
        if(bullet == this->getTile())
            bullet = 1 - this->getTile();
    }
}//End setAvatar

//Start setAmmo
void Player::setAmmo(int a)
{
    //Can't have negative ammo so keep at 0
    if(ammo < 0)ammo = 0;
    else ammo += a;
}//End setAmmo

//Start operator overload >>
istream &operator >> (istream &strm, Player &obj)
{
    //Prompt for user's name
    cout << "Enter your username: ";
    strm >> obj.pName;

    //Prompt for ASCII character
    cout << "Enter your ASCII avatar: ";
    strm >> obj.avatar;

    //Set Inputs
    obj.setPName(obj.pName);
    obj.setAvatar(obj.avatar);

    return strm;
}//End operator overload >>

//Start operator overload <<
ostream &operator << (ostream &strm, const Player &obj)
{
    strm << endl
         << "User: "     << obj.getPName()
         << "\nHealth: " << obj.getHealth()
         << "\nAmmo: "   << obj.getAmmo()
         << "\nPoints: " << obj.getPts();
    return strm;
}
