#include <iostream>
#include <fstream> // thu vien lam viec voi file
#include <vector>
#include "Package1.h"
#include "Human.h"


class CustumerType1 : public Human
{
protected:
    Package1 p1;
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

    int TotalPrice(){
        return this->p1.PriceEachDay;
    }
    // friend class Exp;
};

