/*
 * File:    Temperature.cpp
 * Author:  Enrique Najera
 * Purpose: Reports if O2,C2H5,H2O are
 *          freezing or boiling
 */

//Published Libraries
#include "Temperature.hpp"

//Start mutator setTemp
void Temperature::setTemp(float t)
{
	temptr = t;
}//End setTemp

//Start isEthylFreezing
bool Temperature::isEthylFreezing()
{
	if(temptr <= -173)return true;
	else return false;
}//EndisEthylFreezing

//Start isEthylBoiling
bool Temperature::isEthylBoiling()
{
	if(temptr >= 172)return true;
	else return false;
}//End isEthylBoiling

//Start isOxygenFreezing
bool Temperature::isOxygenFreezing()
{
	if(temptr <= -362)return true;
	else return false;
}//End isOxygenFreezing

//Start isOxygenBoiling
bool Temperature::isOxygenBoiling()
{
	if(temptr >= -306)return true;
	else return false;
}//End isOxygenBoiling

//Start isWaterFreezing
bool Temperature::isWaterFreezing()
{
	if(temptr <= 32)return true;
	else return false;
}//End isWaterFreezing

//Start isWaterBoiling
bool Temperature::isWaterBoiling()
{
	if(temptr >= 212)return true;
	else return false;
}//End isWaterBoiling
