/*
 * File:    Speechbox.hpp
 * Author:  Najera Enrique
 * Purpose: Outputs speech events
 *
 * 08 December 2014
 */
#ifndef SPEECHBOX_HPP
#define SPEECHBOX_HPP

//System Libraries
#include <iostream>

//Published Libraries
#include "Entity.hpp"

//Namespaces
using namespace std;

//Start class Speechbox
class Speechbox
{
    public:
        //Functions
        //Start attacks entity attacks
        virtual void attacks(int entity) const
        {
            //If entity is, output entity attacks
            if(entity == 0)cout << "\nAlien Attacks!\n";      // Alien
            else if(entity == 1)cout << "\nVirus Attacks!\n"; // Virus
            else if(entity == 2)cout << "\nGiant Attacks!\n"; // Giant
            else ;                                            // Nothing so ignore
        }//End attacks
};//End class Speechbox

//Start class Playerbox
class Playerbox : public Speechbox , public Entity
{
    public:
        //Start attacks player attacks
        virtual void attacks(char entity)
        {
            //If entity is, output player attacks
            if(entity == '§')cout << "\nAttacking Alien\n";      // Alien
            else if(entity == 'í')cout << "\nAttacking Virus\n"; // Virus
            else if(entity == 'è')cout << "\nAttacking Giant\n"; // Giant
            else ;                                               // Nothing so ignore
        }//End attacks
};//End class Playerbox

//Start class Pickupbox
class Pickupbox : public Speechbox
{
    public:
        //Start picksup output picked up item
        void picksup(int pu)
        {
            if(pu == 0)cout << "\nBullet Retrieved!\n";          // Bullet picked up
            else if(pu == 1)cout << "\nHealth Box Retrieved!\n"; // Health picked up
            else ;                                               // Nothing so ignore
        }//End picksup
};//End class Pickupbox

#endif // SPEECHBOX_HPP

