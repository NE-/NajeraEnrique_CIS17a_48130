/*
 * File:    ProductionWorker.hpp
 * Author:  Enrique Najera
 * Purpose: Stores information about
 *          a production worker
 *          with exceptions
 * 02 December 2014
 */

#ifndef PRODUCTIONWORKER16_HPP
#define PRODUCTIONWORKER16_HPP

//Published Libraries
#include "Employee16.hpp"

class ProductionWorker16 : public Employee16
{
    private:
        int shift;     // Holds shift time
        float hrPayRt; // Holds hourl pay rate
    public:
        //Exception Classes
        class InvalidShift
            {};
        class InvalidPayRate
            {};

        //Default Constructor
        ProductionWorker16()
            {shift = 0;
             hrPayRt = 0.0;}

        //Takes shift and hourly pay rate
        ProductionWorker16(int s, float hpr)
            {setShift(s);
             setHrPayRt(hpr);}

        //Mutators
        void setShift(int);
        void setHrPayRt(float);

        //Accessors
        int getShift()     const
            {return shift;}
        float getHrPayRt() const
            {return hrPayRt;}
};

#endif // PRODUCTIONWORKER16_HPP
