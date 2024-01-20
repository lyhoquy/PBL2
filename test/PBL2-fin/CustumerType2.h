#ifndef CUSTUMERTYPE2_H
#define CUSTUMERTYPE2_H

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

    // Lay ra ma khach hang
    std::string GetCustumerNumer(){
        return this->CustumerNumber;
    }

    // Cap nhat ma khach hang
    void SetCustumerNumber(std::string& custumernumber){
        this->CustumerNumber = custumernumber;
    }

    // lay ra ten cua khach hang loai 2
    std::string GetName2(){
        return this->FullName;
        
    }

    void Show();
    // void Update();
    virtual void ReadFile(std::ifstream&);
    virtual void WriteFile(const std::string&);

    int Input(const std::string&);

    // Tra ve tong gia tri cua goi tap
    int TotalPrice() {
        return this->p2.PriceEachMonth*p2.GetNumberOfMonth();
    }

    // Tra ve gia goi tap moi thang
    int GetPrice(){
        return this->p2.PriceEachMonth;
    }

    int GetMonth(){
        std::string temp = this->p2.GetMonth();
        (temp.length() == 1) ? temp = "0"+temp : temp;
        return (static_cast<int>(temp[0])-'0')*10 + (static_cast<int>(temp[1])-'0');
    }
};

#endif