#ifndef CUSTUMERTYPE1_H
#define CUSTUMERTYPE1_H

#include <iostream>
#include <fstream> // thu vien lam viec voi file

#include "Package1.h"
#include "Human.h"

class CustumerType1 : public Human
{
protected:
    Package1 p1;
private:
    std::vector<std::string> History;

public:
    static std::string NameCustumerType1;
    static int Count1;
    virtual void ReadFile(std::ifstream&);
    virtual void WriteFile(const std::string&);
    virtual void Show();
    virtual void Update();
    // friend std::istream& operator >> (std::istream&,CustumerType1&);

    void InputTrainDay();
    void AddTrainDay();
    
    void Input(const std::string&);

    int TotalPrice() {
        return this->p1.PriceEachDay;
    }

    int GetPrice(){
        return this->p1.PriceEachDay;
    }

    const std::vector<std::string>& GetHistory() const {
        return History;
    }

    int GetMonth(){
        int temp1 = static_cast<int>((this->History.back()[3])-'0');
        int temp2 = static_cast<int>((this->History.back()[4])-'0');
        return temp1*10 + temp2;
    }

    int thu(const std::string&);
};

#endif