/*
 * File:    MilTime2.cpp
 * Author:  Enrique Najera
 * Purpose: Converts military hour
 *          to standard hour
 * 02 December 2014
 */

//Published Libraries
#include "MilTime2.hpp"

//Converts military hour to std hour
MilTime2::MilTime2(int hr, int sc)
{
    setTime(hr, sc);
    //Convert the hours and minutes
    if(hr >= 2300 && hr < 2360)
    {
        hour = 11;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 2200 && hr < 2260)
    {
        hour = 10;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 2100 && hr < 2160)
    {
        hour = 9;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 2000 && hr < 2060)
    {
        hour = 8;
        min = hr % 100;;
        aOp = "PM";
    }
    else if(hr >= 1900 && hr < 1960)
    {
        hour = 7;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 1800 && hr < 1860)
    {
        hour = 6;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 1700 && hr < 1760)
    {
        hour = 5;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 1600 && hr < 1660)
    {
        hour = 4;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 1500 && hr < 1560)
    {
        hour = 3;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 1400 && hr < 1460)
    {
        hour = 2;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 1300 && hr < 1360)
    {
        hour = 1;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 1200 && hr < 1260)
    {
        hour = 12;
        min = hr % 100;
        aOp = "PM";
    }
    else if(hr >= 1100 && hr < 1160)
    {
        hour = 11;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 1000 && hr < 1060)
    {
        hour = 10;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 900 && hr < 960)
    {
        hour = 9;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 800 && hr < 860)
    {
        hour = 8;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 700 && hr < 760)
    {
        hour = 7;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 600 && hr < 660)
    {
        hour = 6;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 500 && hr < 560)
    {
        hour = 5;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 400 && hr < 460)
    {
        hour = 4;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 300 && hr < 360)
    {
        hour = 3;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 200 && hr < 260)
    {
        hour = 2;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr >= 100 && hr < 160)
    {
        hour = 1;
        min = hr % 100;
        aOp = "AM";
    }
    else if(hr == 0 && hr < 60)
    {
        hour = 12;
        min = hr % 100;
        aOp = "AM";
    }
    else
        throw BadHour();

    //Convert the seconds
    if(sc >=0 && sc < 60)sec = sc;
    else throw BadSeconds();
}

//Sets military time to std time
void MilTime2::setTime(int hr, int sc)
{
    milHours = hr;
    milSeconds = sc;

    //Convert the hours and minutes
    if(milHours >= 2300 && milHours < 2360)
    {
        hour = 11;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 2200 && milHours < 2260)
    {
        hour = 10;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 2100 && milHours < 2160)
    {
        hour = 9;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 2000 && milHours < 2060)
    {
        hour = 8;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1900 && milHours < 1960)
    {
        hour = 7;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1800 && milHours < 1860)
    {
        hour = 6;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1700 && milHours < 1760)
    {
        hour = 5;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1600 && milHours < 1660)
    {
        hour = 4;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1500 && milHours < 1560)
    {
        hour = 3;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1400 && milHours < 1460)
    {
        hour = 2;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1300 && milHours < 1360)
    {
        hour = 1;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1200 && milHours < 1260)
    {
        hour = 12;
        min = hr % 100;
        aOp = "PM";
    }
    else if(milHours >= 1100 && milHours < 1160)
    {
        hour = 11;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 1000 && milHours < 1060)
    {
        hour = 10;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 900 && milHours < 960)
    {
        hour = 9;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 800 && milHours < 860)
    {
        hour = 8;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 700 && milHours < 760)
    {
        hour = 7;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 600 && milHours < 660)
    {
        hour = 6;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 500 && milHours < 560)
    {
        hour = 5;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 400 && milHours < 460)
    {
        hour = 4;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 300 && milHours < 360)
    {
        hour = 3;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 200 && milHours < 260)
    {
        hour = 2;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours >= 100 && milHours < 160)
    {
        hour = 1;
        min = hr % 100;
        aOp = "AM";
    }
    else if(milHours == 0 && milHours < 60)
    {
        hour = 12;
        min = hr % 100;
        aOp = "AM";
    }

    //Convert the seconds
    if(milSeconds >=0 && milSeconds < 60)sec = sc;
    else sec = 0;
}
