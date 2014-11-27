/*
 * File:    Time5.hpp
 * Author:  Enrique Najera
 * Purpose: Holds properties
 *          of time
 * 02 December 2014
 */

#ifndef TIME5_HPP
#define TIME5_HPP

class Time5
{
    protected:
        int hour; // Holds the hour
        int min;  // Holds the minute(s)
        int sec;  // Holds the seconds
    public:
        //Default Constructor
        Time5()
            { hour = 0; min = 0; sec = 0; }

        //Constructor
        Time5(int h, int m, int s)
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
