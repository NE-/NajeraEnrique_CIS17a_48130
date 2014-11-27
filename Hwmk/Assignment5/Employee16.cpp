#include "Employee16.hpp"

void Employee16::setEmpNum(int eNu)
{
    if (eNu > 0 && eNu <= 9999)
        empNum = eNu;
    else
        throw InvalidEmployeeNumber();
}
