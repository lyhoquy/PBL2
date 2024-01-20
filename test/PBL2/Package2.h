#ifndef PACKAGE2_H
#define PACKAGE2_H

#include "Package1.h"
// #include <iostream>

class Package2 : public Package1
{
private:
    int NumberOfMonth;
public:
    static int PriceEachMonth;

    int GetNumberOfMonth(){
        return this->NumberOfMonth;
    }

    void SetNumberOfMonth(int& numberofmonth){
        this->NumberOfMonth = numberofmonth;
    }
    
    void ChangePrice();
};

#endif

