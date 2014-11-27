/*
 * File:    Time4.hpp
 * Author:  Enrique Najera
 * Purpose: Holds time objects
 * 02 December 2014
 */

#ifndef TIME4_HPP
#define TIME4_HPP

class Time4
{
    protected:
        int hour; // Holds the hour
        int min;  // Holds the minutes
        int sec;  // Holds the seconds
    public:
        //Default Constructor
        Time4()
            { hour = 0; min = 0; sec = 0; }

        //Constructor
        //Acts as a mutator
        Time4(int h, int m, int s)
            { hour = h; min = m, sec = s; }

        //Accessor Functions
        int getHour() const
            { return hour;}
        int getMin() const
            { return min; }
        int getSec() const
            { return sec; }
};

#endif // TIME_HPP
