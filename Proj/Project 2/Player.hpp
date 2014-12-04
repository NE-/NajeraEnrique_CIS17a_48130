/*
 * File:    Player.hpp
 * Author:  Najera Enrique
 * Purpose: Stores info and
 *          properties of player
 *
 * 08 December 2014
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

//System Libraries
#include <string>

//Published Libraries
#include "Map.hpp"

class Player : public Map
{
    private:
        int locX;      // Holds user's X location
        int locY;      // Holds user's Y location
        int ammo;      // Stores user's ammo
        int pts;       // Stores user's points
        float health;  // Stores user's health
        char avatar;   // User's avatar
        char movement; // Stores key input
        char bullet;   // Holds bullet character
        string pName;  // Holds user's name
    public:
        //Constructors
        //Default
        Player()
            { avatar = '9'; health = 5;
              pName = "9"; ammo = 8;
              bullet = '*'; pts = 0; }

        //Mutators
        void setAvatar(char);
        void setLocX(int x)
            { locX = x; }
        void setLocY(int y)
            { locY = y; }
        void setMovement(char m)
            { movement = m; }
        void setPName(string n)
            { pName = n; }
        void setHealth(float h)
            { health += h; }
        void setAmmo(int);
        void setPts(int p)
            { pts += p; }

        //Accessors
        int getLocX() const
            { return locX;}
        int getLocY() const
            { return locY;}
        int getAmmo() const
            { return ammo; }
        int getPts() const
            { return pts; }
        float getHealth() const
            { return health; }
        char getMovement() const
            { return movement; }
        char getAvatar() const
            { return avatar; }
        char getBullet () const
            { return bullet; }
        string getPName() const
            { return pName; }

        //Overloaded operator functions
        friend istream &operator >> (istream &, Player &);       // Overload >>
        friend ostream &operator << (ostream &, const Player &); // Overload <<
};

#endif // PLAYER_HPP
