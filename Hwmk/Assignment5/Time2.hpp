/*
 * File:    Time2.hpp
 * Author:  Enrique Najera
 * Purpose: Hols, sets, gets time elements
 * 02 December 2014
 */

#ifndef TIME2_HPP
#define TIME2_HPP

class Time2
{
    protected:
        int hour;
        int min;
        int sec;
    public:
        //Default Constructor
        Time2()
            { hour = 0; min = 0; sec = 0; }

        //Constructor
        Time2(int h, int m, int s)
            { hour = h; min = m, sec = s; }

        //Accessor Functions
        int getHour() const
            { return hour;}
        int getMin() const
            { return min; }
        int getSec() const
            { return sec; }
};

#endif // TIME2_HPP
