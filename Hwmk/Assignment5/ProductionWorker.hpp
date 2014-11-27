/*
 * File:    ProductionWorker.hpp
 * Author:  Enrique Najera
 * Purpose: Stores information about
 *          a production worker
 * 02 December 2014
 */

#ifndef PRODUCTIONWORKER_HPP
#define PRODUCTIONWORKER_HPP

//Published Libraries
#include "Employee.hpp"

class ProductionWorker : public Employee
{
    private:
        int shift;     // Holds shift time
        float hrPayRt; // Holds hourl pay rate
    public:
        //Default Constructor
        ProductionWorker()
            {shift = 0;
             hrPayRt = 0.0;}

        //Takes shift and hourly pay rate
        //Calls mutators
        ProductionWorker(int s, float hpr)
            {setShift(s);
             setHrPayRt(hpr);}

        //Mutators
        void setShift(int);
        void setHrPayRt(float h)
            {hrPayRt = h;}

        //Accessors
        int getShift()     const
            {return shift;}
        float getHrPayRt() const
            {return hrPayRt;}
};

#endif // PRODUCTIONWORKER_HPP
