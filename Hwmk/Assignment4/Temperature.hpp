/*
 * File:    Temperature.hpp
 * Author:  Enrique Najera
 * Purpose: Reports if O2,C2H5,H2O are
 *          freezing or boiling
 */

#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

class Temperature
{
	private:
		float temptr;
	public:
		//Mutator
		void setTemp(float); //Sets temperature
		
		//Check freezing or boiling
		bool isEthylFreezing();
		bool isEthylBoiling();
		
		bool isOxygenFreezing();
		bool isOxygenBoiling();
		
		bool isWaterFreezing();
		bool isWaterBoiling();		
};

#endif //TEMPERATURE_HPP
