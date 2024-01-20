#ifndef CUSTUMERTYPE3_H
#define CUSTUMERTYPE3_H

#include "CustumerType2.h"
#include "Package3.h"

class CustumerType3 : public CustumerType2
{
private:
    std::string CustumerNumber;
    std::string Service;
    Package3 p3;
public:
    static std::string NameCustumerType3;
    static int Count3;

    std::string GetCustumerNumer(){
        return this->CustumerNumber;
    }

    void SetCustumerNumber(std::string& custumernumber){
        this->CustumerNumber = custumernumber;
    }

    std::string GetDay(){
        return this->p3.GetDay();
    }

    void SetDay(const std::string& day){
        this->p3.SetDay(day);
    }

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
        return this->p3.PriceVIP*this->p3.GetNumberOfMonth();
    }

    int GetPrice(){
        return this->p3.PriceVIP;
    }

    int GetMonth(){
        std::string temp = this->p3.GetMonth();
        (temp.length() == 1) ? temp = "0"+temp : temp;
        return (static_cast<int>(temp[0])-'0')*10 + (static_cast<int>(temp[1])-'0');
    }
};

#endif