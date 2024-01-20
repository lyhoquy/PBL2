#include <algorithm>
#include "Management.h"

template<typename T>
std::vector<int> Management<T>::revenue(12,0);

template<typename T>
void Management<T>::AddCustomer(const T& custumer){
    customers.push_back(custumer);
}

template<typename T>
void Management<T>::ShowAllCustomers(){
    if(customers.size() == 0){
        std::cout<<"Danh sach khach hang loai nay dang trong!"<<std::endl << std::endl;
        return;
    }

    for(int i=0; i<customers.size(); ++i){
        customers[i].Show();
        std::cout << std::endl;
    }  
}

template<typename T>
void Management<T>::WriteFile(const std::string& filename){

    std::ofstream ofs(filename, std::ios::trunc);
    if (!ofs) {
        std::cout << "Khong the mo file de xoa." << std::endl;
        return;
    }


    for(int i=0; i<customers.size(); ++i){
        customers[i].WriteFile(filename);
    }
    // std::cout << "Ghi du lieu thanh cong " << std::endl;
    ofs.close();
}

template <typename T>
void Management<T>::ReadFile(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs) {
        std::cerr << "Khong the mo file." << std::endl;
        return;
    }

    T customer;
    while (!ifs.eof())
    {      
    customer.ReadFile(ifs);
    customers.push_back(customer);
    }
    
    ifs.close();
}

template<typename T>
int Management<T>::Check(const std::string& s){
    for(int i=0; i<customers.size(); ++i){
        if(customers[i].GetPhoneNumber() == s){
            return i;
        }
    }
    return -1;
}

template <typename T>
void Management<T>::DeleteCustomer(const std::string& phoneNumber) {
    int index = Check(phoneNumber);
    if(index != -1){
        std::cout << "Da xoa khach hang voi so dien thoai: " << phoneNumber << std::endl;
        customers.erase(customers.begin()+index);
        return;
    }
    std::cout << "Khach hang voi so dien thoai: " << phoneNumber << " khong tim thay!" << std::endl;
}

template<typename T>
void Management<T>::DeleteCustomer(const int& index){
    customers.erase(customers.begin()+index);
}

template<typename T>
void Management<T>::Update(const std::string& phonenumber){
    int index = Check(phonenumber);
    if(index != -1){
        // std::cout << "Da xoa khach hang voi so dien thoai: " << phoneNumber << std::endl;
        customers[index].Update();
        return;
    }
    std::cout << "Khach hang voi so dien thoai: " << phonenumber << " khong tim thay!" << std::endl;
}

template<typename T>
void Management<T>::FindCustumer(const std::string& phonenumber){
    int index = Check(phonenumber);
    if(index != -1){
        customers[index].Show();
        return;
    }
    std::cout << "Khach hang voi so dien thoai: " << phonenumber << " khong tim thay" << std::endl;
    return;
}

template<typename T>
void Management<T>::Upgrade(CustumerType2 ct2){
    T ct3;
    ct3.Upgrade(ct2);
    AddCustomer(ct3);
}

template<typename T>
void Management<T>::ShowRevenue() {
    int maxRevenue = *std::max_element(revenue.begin(), revenue.end());

    for (size_t i = 0; i < 12; ++i) {
        std::cout << "Thang " << std::setw(2) << i + 1 << ": ";
        int barLength = (revenue[i] * 10) / maxRevenue; // Độ dài thanh đồ thị
        for (size_t j = 0; j < barLength; ++j) {
            std::cout << "[]";
        }
        std::cout << " (" << revenue[i] << ")" << std::endl;
    }
}

template<typename T>
void Management<T>::AddRevenue(const int& money, const int& index){
    revenue[index] += money;
}

template<typename T>
void Management<T>::ReadRevenueFromFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    int a;
    if (inputFile.is_open()) {
        for (size_t i = 0; i < 12; ++i) {
            inputFile >> a;
            revenue[i] = a;
            inputFile.ignore(1, ',');
        }

        inputFile.close();
    }
    else {
        std::cout << "Khong the mo file de doc du lieu." << std::endl;
    }
}



template<typename T>
void Management<T>::UpdateRevenueFile(const std::string& filename) {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (size_t i = 0; i < 11; ++i) {
            outputFile << revenue[i] << ",";
        }
        outputFile << revenue[11];

        outputFile.close();
    }
    else {
        std::cout << "Khong the mo file de ghi du lieu." << std::endl;
    }
}
