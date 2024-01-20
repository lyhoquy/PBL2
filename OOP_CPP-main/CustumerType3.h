#ifndef CUSTUMERTYPE3_H
#define CUSTUMERTYPE3_H

#include "CustumerType2.h"
#include "Package3.h"

class CustumerType3 : public CustumerType2
{
private:
    std::string Service;
    Package3 p3;
public:
    static std::string NameCustumerType3;
    static int Count3;

    std::string ChooseService(){
        return this->Service;
    }

    void Show();

    // Nang cap khach hang len goi VIP tu khach hang dinh ky
    void Upgrade(CustumerType2&);
    // void Update();
    void ReadFile(std::ifstream&);
    void WriteFile(const std::string&);

    int Input(const std::string&);

    int TotalPrice() {
        return this->p3.GetPrice()*this->p2.GetNumberOfMonth();
    }

};

#endif