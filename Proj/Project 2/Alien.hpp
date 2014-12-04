#ifndef ALIEN_HPP
#define ALIEN_HPP

#include "Entity.hpp"

class Alien : public Entity
{
    protected:
        char avatar;
    public:
        //Constructors
        Alien() : Entity(int x, int y, int h, int s)
        {
            avatar = '§'; locX = x; locY = y;
            health = h; strength = s;
        }
};

#endif // ALIEN_HPP
