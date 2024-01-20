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
    friend std::istream& operator >> (std::istream&,CustumerType1&);

    void InputTrainDay();
    void AddTrainDay();
    
    void Input(const std::string&);

    int TotalPrice() const{
        return this->p1.PriceEachDay;
    }

    const Package1& GetPackage() const{
        return this->p1;
    }

    std::vector<std::string> GetHistory() const {
        return History;
    }

    int GetMonth(){
        std::string temp = this->p1.GetMonth();
        (temp.length() == 1) ? temp = "0"+temp : temp;
        return (static_cast<int>(temp[0])-'0')*10 + (static_cast<int>(temp[1])-'0');
    }

};

#endif