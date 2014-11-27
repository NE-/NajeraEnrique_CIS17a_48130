#include "TimeClock.hpp"

TimeClock::TimeClock(int h1, int h2)
{
    int temp = 0;   // Temporarily holds h2 - h1
    int m1 = 0,     // Holds minute of 1st time
        m2 = 0;     // Holds minute of 2nd time
    int ttlMin = 0; // Holds total minutes

    temp = (h2 - h1); //Subtract hours

    //Get minutes
    m1 = h1 % 100;
    m2 = h2 % 100;

    //Validate minutes; if error then init
    if(m1 < 0 || m1  >= 60)m1 = 0;
    if(m2 < 0 || m2  >= 60)m2 = 0;

    //Subtract minutes
    //Avoid negative validation
    if(m1 > m2)ttlMin = m1 - m2;
    else if(m1 < m2)ttlMin = m2 - m1;
    else{m1 = 0;m2 = 0;}

    //If negative, convert to positive
    if(temp < 0)
    {
        temp -= (2*temp);
    }

    //If hour < 12
    if(temp < 1200 && temp > 0)
    {
        temp /= 100;
        cout << "The elapsed time is " << temp
             << " hours and " << ttlMin << " minutes\n";
    }
    //If hour > 12
    else if(temp > 1200 && temp < 2400)
    {
        temp /= 100;
        cout << "The elapsed time is " << temp
             << " hours and " << ttlMin << " minutes\n";
    }
    else cout << "\nERROR OR 0 MINUTES ELAPSED\n";
}
