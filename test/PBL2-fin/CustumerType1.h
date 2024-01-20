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
    static std::string NameCustumerType1; // ten goi cua Khach hang loai 1
    static int Count1;
    virtual void ReadFile(std::ifstream&);
    virtual void WriteFile(const std::string&);
    virtual void Show(); // Show ra thong tin cua khach hang
    virtual void Update(); // Cap nhat lai thong tin cua khach hang
    // friend std::istream& operator >> (std::istream&,CustumerType1&);

    int Input(const std::string&); // Nhap thong tin cua khach hang neu nhap toan bo tra ve 1 neu thoat tra ve 0
    std::string InputTrainDay(); // Nhap ngay tap moi 
    void AddTrainDay(); // Them ngay tap vao danh sach ngay tap
    
    // void Input(const std::string&);

    //gia cua loai khach hang theo ngay
    int TotalPrice() {
        return this->p1.PriceEachDay;
    }

    // Lay ra danh sach nhung ngay da tap
    const std::vector<std::string>& GetHistory() const {
        return History;
    }

    // Chuyen thang dang o dang string -> int
    int GetMonth(){
        int temp1 = static_cast<int>((this->History.back()[3])-'0');
        int temp2 = static_cast<int>((this->History.back()[4])-'0');
        return temp1*10 + temp2;
    }

};

#endif