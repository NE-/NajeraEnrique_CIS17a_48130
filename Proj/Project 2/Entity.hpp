/*
 * File:    Entity.hpp
 * Author:  Najera Enrique
 * Purpose: Holds properties of entities
 *
 * 08 December 2014
 */

#ifndef ENTITY_HPP
#define ENTITY_HPP

//Start class Entity
class Entity
{
    protected:
        int locX;       // Holds entity location X
        int locY;       // Holds entity location Y
        int health;     // Holds entity health
        int points;     // Points entity worth
        float strength; // Holds entity strength
    public:
        //Constructor
        //Default
        Entity()
            { locX = 0; locY = 0;
              health = 5; strength = 1;
              points = 1; }
        //To build entity properties
        Entity(int x, int y, int h, float s)
            { locX = x; locY = y;
              health = h; strength = s; }

        //Accessor Functions
        int getLocX() const
            { return locX; }
        int getLocY() const
            { return locY; }
        int getHealth() const
            { return health; }
        float getStrength() const
            { return strength; }
};//End class Entity

//Start class Alien
class Alien : public Entity
{
    protected:
        char avatar; // Holds Alien's avatar
    public:
        //Constructors
        //Acts as a mutator
        Alien(int x, int y, int h, int s) : Entity(x, y, h, s)
        { avatar = '§'; locX = x; locY = y;
          health = h; strength = s; points = 1; }

        //Mutator Functions
        void setLocX_Alien(int x)
            { locX = x; }
        void setLocY_Alien(int y)
            { locY = y; }
        void setHealth_Alien(int h)
            { health += h; }

        //Accessor Functions
        char getAvatar_Alien() const
            { return avatar; }
        int getLocX_Alien() const
            { return locX; }
        int getLocY_Alien() const
            { return locY; }
        int getHealth_Alien() const
            { return health; }
        int getPoints_Alien() const
            { return points; }
        float getStrength_Alien() const
            { return strength; }
};//End class Alien

//Start class Virus
class Virus : public Entity
{
    protected:
        char avatar; // Holds Virus' avatar
    public:
        //Constructors
        //Acts as a mutator
        Virus(int x, int y, int h, int s) : Entity(x, y, h, s)
        { avatar = 'í'; locX = x; locY = y;
          health = h; strength = s; points = 2;}

        //Mutator Functions
        void setLocX_Virus(int x)
            { locX = x; }
        void setLocY_Virus(int y)
            { locY = y; }
        void setHealth_Virus(int h)
            { health += h; }

        //Accessor Functions
        char getAvatar_Virus() const
            { return avatar; }
        int getLocX_Virus() const
            { return locX; }
        int getLocY_Virus() const
            { return locY; }
        int getHealth_Virus() const
            { return health; }
        int getPoints_Virus() const
            { return points; }
        float getStrength_Virus() const
            { return strength; }
};//End class Virus

//Start class Giant
class Giant : public Entity
{
    protected:
        char avatar; // Holds Giant's avatar
    public:
        //Constructors
        //Acts as a mutator
        Giant(int x, int y, int h, int s) : Entity(x, y, h, s)
        { avatar = 'è'; locX = x; locY = y;
          health = h; strength = s; points = 5; }

        //Mutator Functions
        void setLocX_Giant(int x)
            { locX = x; }
        void setLocY_Giant(int y)
            { locY = y; }
        void setHealth_Giant(int h)
            { health += h; }

        //Accessor Functions
        char getAvatar_Giant() const
            { return avatar; }
        int getLocX_Giant() const
            { return locX; }
        int getLocY_Giant() const
            { return locY; }
        int getHealth_Giant() const
            { return health; }
        int getPoints_Giant() const
            { return points; }
        float getStrength_Giant() const
            { return strength; }
};//End class Dragon

#endif // ENTITY_HPP
