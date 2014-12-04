/*
 * File:    Map.cpp
 * Author:  Najera Enrique
 * Purpose: Contains map properties
 *
 * 08 December 2014
 */

//System Libraries
#include <iostream>
#include <new>

//Published Libraries
#include "Map.hpp"

//Namespaces
using namespace std;

//Start setMapX
void Map::setMapX(int x)
{
    //Set X to odd number for nicer map
    if(x % 2 == 0)x++;
    //Handle input error negative size
    if (x > 0)mapX = x;
    else throw NegativeW();
}//End setMapX

//Start setMapY
void Map::setMapY(int y)
{
    //Cannot be 1
    if(y == 1)throw NegativeH();
    //Set Y to odd number for nicer map
    if(y % 2 == 0)y++;
    //Handle input error negative size
    if (y > 0)mapY = y;
    else throw NegativeH();
}//End setMapX

//Start operator overload >>
istream &operator >> (istream &strm, Map &obj)
{
    //Prompt for map dimension X
    cout << "Enter the map dimension for X (Horizontal): ";
    strm >> obj.mapX;

    //Prompt for map dimension Y
    cout << "Enter the map dimension for Y (Vertical): ";
    strm >> obj.mapY;

    //Prompt for tile
    cout << "Enter the ASCII for the tiles: ";
    strm >> obj.tile;

    //Set the values
    try
    {
        obj.setMapX(obj.mapX);
        obj.setMapY(obj.mapY);
    }
    //Catch the errors
    catch (Map::NegativeW)
    {
        cout << "\nERROR: Width must be greater than 1!\n";
        exit(EXIT_FAILURE);
    }
    catch (Map::NegativeH)
    {
        cout << "\nERROR: Height must be greater than 1!\n";
        exit(EXIT_FAILURE);
    }
    //Set tile
    obj.setTile(obj.tile);

    return strm;
}//End operator overload >>
