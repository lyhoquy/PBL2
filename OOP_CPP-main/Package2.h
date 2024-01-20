#ifndef PACKAGE2_H
#define PACKAGE2_H

#include "Package1.h"
// #include <iostream>

class Package2 : public Package1
{
protected:
    int NumberOfMonth;
public:
    static int PriceEachMonth;

    virtual int GetNumberOfMonth(){
        return this->NumberOfMonth;
    }

    virtual void SetNumberOfMonth(int& numberofmonth){
        this->NumberOfMonth = numberofmonth;
    }

    int GetPrice(){
        return this->PriceEachMonth;
    }
    
    void ChangePrice();
};

#endif

