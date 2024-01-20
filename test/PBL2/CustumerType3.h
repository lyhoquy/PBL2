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
    friend std::istream& operator >> (std::istream&, CustumerType3&);
    CustumerType3& operator=(const CustumerType2& custumer2);

    void Upgrade(CustumerType2&);
    void ReadFile(std::ifstream&);
    void WriteFile(const std::string&);
    int TotalPrice(){
        return this->p3.PriceVIP * this->p3.GetNumberOfMonth();
    }
};

