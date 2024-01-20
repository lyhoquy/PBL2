#include <iostream>
#include <vector>
#include "CustumerType2.h"

template <typename T>
class Management {
private:
    std::vector<T> customers;
    std::vector<int> pay{std::vector<int>(12, 0)};
public:

    void AddCustomer(const T& customer); // them mot khach hang vao danh sach
    void ShowAllCustomers(); // in ra toan bo khach hang
    void WriteFile(const std::string&); // ghi thong tin cua danh sach khach hang vao file
    void ReadFile(const std::string&); // doc thong tin cua khach hang tu file
    int Check(const std::string&); // kiem tra mot so dien thoai co nam trong danh sach khong
    void DeleteCustomer(const std::string&); // xoa khach hang theo
    void DeleteCustomer(const int&); // xoa khach hang theo
    void Update(const std::string&);
    T GetCustumer(const std::string&);
    void FindCustumer(const std::string&);
    void Upgrade(CustumerType2);
    void LastHope(const int&);
    
    void Revenue();
    void Revenue1();
    void ShowRevenue();
    void ReadRevenueFromFile(const std::string&);
    void UpdateRevenueFile(const std::string&);
};