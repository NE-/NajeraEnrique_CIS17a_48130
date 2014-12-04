/*
 * File:    Map.hpp
 * Author:  Najera Enrique
 * Purpose: Contains map properties
 *
 * 08 December 2014
 */

#ifndef MAP_HPP
#define MAP_HPP

//System Libraries
#include <iostream>

//Namespaces
using namespace std;

class Map
{
    protected:
        int mapX;       // Dimension of map X-axis
        int mapY;       // Dimension of map Y-axis
        char tile;      // Tiles for the map
    public:
        //Exception classes
        class NegativeW
            { /*If width x negative, throw*/ };
        class NegativeH
            { /*If height y negative, throw*/ };

        //Constructors
        //Default
        Map()
            { mapX = 11; mapY = 11; tile = '.'; }

        //Mutators
        void setMapX(int x);
        void setMapY(int y);
        void setTile(char t)
            { tile = t; }

        //Accessors
        int getMapX() const
            { return mapX; }
        int getMapY() const
            { return mapY; }
        char getTile() const
            { return tile; }

        //Overloaded operator >>
        friend istream &operator >> (istream &, Map &);

        //Functions
        void createMap();  // Allocates memory
        void destroyMap(); // Frees memory
};

#endif // MAP_HPP
