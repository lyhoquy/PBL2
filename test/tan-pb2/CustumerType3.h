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
    std::vector<int> upgrade;
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

    const Package3& GetPackage() const{
        return this->p3;
    }

    void Show();
    friend std::istream& operator >> (std::istream&, CustumerType3&);
    CustumerType3& operator=(const CustumerType2& custumer2);

    void Upgrade(CustumerType2&);
    // void Update();
    void ReadFile(std::ifstream&);
    void WriteFile(const std::string&);

    void Input(const std::string&);

    int TotalPrice() const{
        return this->p3.PriceVIP * this->p3.GetNumberOfMonth();
    }

    int GetMonth(){
        std::string temp = this->p3.GetMonth();
        (temp.length() == 1) ? temp = "0"+temp : temp;
        return (static_cast<int>(temp[0])-'0')*10 + (static_cast<int>(temp[1])-'0');
    }

    std::vector<int> GetUp() const {
        return upgrade;
    }
};

#endif