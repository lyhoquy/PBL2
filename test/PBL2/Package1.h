#ifndef PACKAGE1_H
#define PACKAGE1_H


#include "Package.h"
#include <iostream>
class Package1 : public Package
{
private:
    std::string Day;
    std::string Month;

public:
    static std::string Year;

    static int PriceEachDay;

    std::string GetDay(){
        return this->Day;
    }

    void SetDay(const std::string& day){
        this->Day = day;
    }

    std::string GetMonth(){
        return this->Month;
    }

    void SetMonth(const std::string& month){
        this->Month = month;
    }
    
    void ChangePrice();
    // int TotalPrice();
};

#endif

