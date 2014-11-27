/*
 * File:    TimeClock.hpp
 * Author:  Enrique Najera
 * Purpose: Sends hours to
 *          TimeClock()
 * 02 December 2014
 */

#ifndef TIMECLOCK_HPP
#define TIMECLOCK_HPP

//Published Libraries
#include "Time5.hpp"
#include "MilTime5.hpp"

class TimeClock : public MilTime5, public Time5
{
    public:
        //Constructors
        TimeClock(int, int);
};

#endif // TIMECLOCK_HPP
