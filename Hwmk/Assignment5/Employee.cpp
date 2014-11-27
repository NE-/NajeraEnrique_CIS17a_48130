#include "Employee.hpp"

void Employee::setEmpNum(int eNu)
{
    if (eNu > 0 && eNu <= 9999)
        empNum = eNu;
    else
        throw InvalidEmployeeNumber();
}
