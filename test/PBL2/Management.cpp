#include "Management.h"

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
    // std::cout << "Danh sach khach hang " << CustumerType1::NameCustumerType1 <<  std::endl << std::endl;
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
    std::cout << "Ghi du lieu thanh cong " << std::endl;
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
T Management<T>::GetCustumer(const std::string& phonenumber){
    int index = Check(phonenumber);
    if (index != -1)
    {
        return customers[index];
        DeleteCustomer(index);
    }
    std::cout << "Khach hang voi so dien thoai: " << phonenumber << " khong tim thay" << std::endl;
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


// template<typename T>
// void Management<T>::ShowPay(){
//     for(int i=0; i<12; ++i){
//         std::cout << "Thang " << i+1 << ": " << pay[i] << std::endl;
//     }
// }

template<>
void Management<CustumerType1>::LastHope(const int& index){
    customers[index].AddTrainDay();
}

template<typename T>
void Management<T>::Revenue() {
    for (size_t i = 0; i < customers.size(); ++i)
    {
        revenue[customers[i].GetMonth()-1] += customers[i].TotalPrice();

    }
       
}


template<>
void Management<CustumerType1>::Revenue1() {

    int month;
    int temp1, temp2;
    for (size_t i = 0; i < customers.size(); ++i)
    {
        // CustumerType1& ct1 = customers[i];
        std::vector<std::string> history = customers[i].GetHistory();
        for (size_t j = 0; j<history.size(); ++j)
        {
            temp1 = static_cast<int>(history[j][3]) - '0';
            temp2 = static_cast<int>(history[j][4]) - '0';
            month = temp1*10 + temp2;
            revenue[month-1] += customers[i].TotalPrice();    
        }
    }  
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
        std::cout << "Du lieu da duoc doc tu file thanh cong." << std::endl;
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
        std::cout << "Du lieu da duoc ghi vao file thanh cong." << std::endl;
    }
    else {
        std::cout << "Khong the mo file de ghi du lieu." << std::endl;
    }
}