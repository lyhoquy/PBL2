#ifndef PACKAGE1_H
#define PACKAGE1_H

#include <iostream>
#include <vector>
#include "Package.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"

class Package1 : public Package
{
protected:
    std::string Day;
    std::string Month;
    std::vector<std::string> History;
public:
    static std::string d[4][10];
    static std::string m[12];
    static std::string Year;
    static int PriceEachDay;

    std::string GetDay(){
        return this->Day;
    }

    void SetDay(const std::string& day){
        this->Day = day;
    }

    std::string GetMonth() const{
        return this->Month;
    }

    void SetMonth(const std::string& month){
        this->Month = month;
    }
    
    void ChangePrice();
    void OutputMonth(const int&);
    std::string ChooseMonth();
    void OutputDay(const int& ,const int&, const int&);
    std::string ChooseDay(const int&);

    int StringToInt(const std::string&) const;
};

#endif

