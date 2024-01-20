#include "CustumerType1.h"
#include "Package2.h"

class CustumerType2 : public CustumerType1
{
protected:
    std::string CustumerNumber;
    Package2 p2;
public:
    static std::string NameCustumerType2;
    static int Count2; // dem so luong khach loai 2 dung so luong ni de lam ma kh vd count2 = 1 -> ma la N001

    std::string GetCustumerNumer(){
        return this->CustumerNumber;
    }

    void SetCustumerNumber(std::string& custumernumber){
        this->CustumerNumber = custumernumber;
    }

    std::string GetName2(){
        return this->FullName;
    }

    std::string GetDay(){
        return this->p2.GetDay();
    }

    void SetDay(const std::string& day){
        this->p2.SetDay(day);
    }

    friend std::istream& operator >> (std::istream&, CustumerType2&);
    void Show();
    virtual void ReadFile(std::ifstream&);
    virtual void WriteFile(const std::string&);
    int TotalPrice(){
        return this->p2.PriceEachMonth * this->p2.GetNumberOfMonth();
    }
    Package2& CustumerType2::GetPackage(){
        return this->p2;
    }
};

