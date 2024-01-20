
// #include <windows.h>
#include "CustumerType3.h"

std::string CustumerType3::NameCustumerType3 = "Khach hang loai VIP";
int CustumerType3::Count3 = 0;

void CustumerType3::Show(){
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(17) << "Ma khach hang : " << this->CustumerNumber << std::setw(22) << "|" << std::endl;
    std::cout << "|" << std::setw(17) << "Xep loai : "<< this->NameCustumerType3 
                     << std::setw(28-this->NameCustumerType3.length()) << "|" << std::endl;
    Human::Show();
    std::cout << "|" << std::setw(17) << "Ngay bat dau : " << ((p3.GetDay().length()==1) ? ("0"+p3.GetDay()) : p3.GetDay())
              << "/" << ((p3.GetMonth().length()==1) ? ("0"+p3.GetMonth()) : p3.GetMonth()) << "/" << p3.Year
              << std::setw(18) << "|" << std::endl;

    int number = p3.GetNumberOfMonth();
    std::string s = std::to_string(number);

    std::cout << "|" << std::setw(17) << "Thoi han : " << ((s.length()==1) ? ("0"+s) : s) << " thang" 
              << std::setw(20) << "|" << std::endl;
    std::cout << "|" << std::setw(17) << "Uu dai di kem : " << this->Service << std::setw(28 - this->Service.length()) << "|" << std::endl; 
    std::cout << "----------------------------------------------" << std::endl;
}

void CustumerType3::Upgrade(CustumerType2& ct2){
    ++Count3;
    this->CustumerNumber = "VIP" + std::string(3-std::to_string(CustumerType3::Count3).length(),'0') + std::to_string(CustumerType3::Count3);
    this->FullName = ct2.GetName();
    this->BornYear = ct2.GetYear();
    this->Gender = ct2.GetGender();
    this->PhoneNumber = ct2.GetPhoneNumber();

    std::string day, month;
    int year = p1.StringToInt(p1.Year);
    std::cout << "Nhap thoi gian bat dau goi tap VIP " << std::endl;


    std::cout << "Nhap thang bat dau " << std::endl;
    month = p1.ChooseMonth();
    this->p3.SetMonth(month);

    int high;
    if(month == "2"){
        (year%4 == 0 && year%100 != 0) ? high = 29 : high = 28; 
    }
    else if (month == "4" || month == "6" || month == "9" || month == "11")
    {
        high = 30;
    }
    else{
        high = 31;
    }
    
    day = p3.ChooseDay(high);
    p3.SetDay(day);

    std::cout << "Nhap so thang tap " << std::endl;
    int n;
    std::cin >> n;
    this->p3.SetNumberOfMonth(n);
    // std::cout << "Nhap so thang con lai cua goi tap 2: " << std::endl;
    // int remainingMonths;
    // std::cin >> remainingMonths;

    // int remainingPrice = ct2.GetPackage().PriceEachMonth * remainingMonths;
    // int upgradePrice = this->p3.PriceEachMonth * n;
    // double totalPrice = remainingPrice - upgradePrice;
    // if (totalPrice < 0) {
    //     std::cout << "Khong du tien nang cap goi tap VIP!" << std::endl;
    //     std::cout << "Con thieu: " << abs(totalPrice) << " VND" << std::endl;
    //     // return;
    // }
    // else{
    //     std::cout << "So tien du la: " << totalPrice << " VND" << std::endl;
    // }
    // std::cout << "Nhan phim bat ky de tiep tuc chon dich vu chon khach" << std::endl;
    // system("pause");
    this->Service = this->p3.GetService();
}

void CustumerType3::ReadFile(std::ifstream& ifs){
    // // Kiểm tra xem file có trống hay không
    // if (ifs.peek() == std::ifstream::traits_type::eof()) {
    //     std::cout << "File đang trống." << std::endl;
    //     return; // Kết thúc hàm nếu file trống
    // }

    ++CustumerType3::Count3;
    getline(ifs,this->CustumerNumber,',');
    
    getline(ifs, this->FullName,',');

    getline(ifs,BornYear,',');
    ifs.ignore(1, ',');
    
    getline(ifs,this->Gender,',');
    ifs.ignore(1, ',');

    getline(ifs,this->PhoneNumber,',');
    ifs.ignore(1, ',');

    // CustumerType1::ReadFile(ifs);

    std::string day, month,year;
    int number;

    getline(ifs,day,',');    
    p3.SetDay(day);
    ifs.ignore(1, ',');

    getline(ifs,month,',');
    p3.SetMonth(month);
    ifs.ignore(1, ',');

    // getline(ifs,year,',');
    // p3.SetYear(year);
    // ifs.ignore(1, ',');

    ifs >> number;
    p3.SetNumberOfMonth(number);
    ifs.ignore(1,',');
    
    getline(ifs, this->Service,'\n');
}

void CustumerType3::WriteFile(const std::string& filename){
    std::ofstream ofs(filename,std::ios::app);
    if(!ofs) {
        std::cerr<<"Can't open output file.\n";
        return;
    }
    if(Count3 != 0){
        Count3 = 0;
    }
    else{
        ofs << std::endl;
    }
    ofs << this->GetCustumerNumer() << "," <<FullName << "," << BornYear << ", "  << Gender << ", " << PhoneNumber << ", "
        << p3.GetDay() << ", " << p3.GetMonth() << ", " << p3.GetNumberOfMonth() 
        << "," << this->ChooseService();

    ofs.close();
}

void CustumerType3::Input(const std::string& s){
    ++CustumerType3::Count3;
    this->CustumerNumber = "VIP" + std::string(3-std::to_string(CustumerType3::Count3).length(),'0') + std::to_string(CustumerType3::Count3);
    std::cin.ignore();
    Human::Input(s);

    int year = p1.StringToInt(p1.Year);
    std::string month;

    month = p1.ChooseMonth();
    p3.SetMonth(month);
    int high;
    if(month == "2"){
        (year%4 == 0 && year%100 != 0) ? high = 29 : high = 28; 
    }
    else if (month == "4" || month == "6" || month == "9" || month == "11")
    {
        high = 30;
    }
    else{
        high = 31;
    }

    std::string day;
    
    day = p1.ChooseDay(high);
    p3.SetDay(day);

    int n;
    std::cout << "\nNhap so thang tap: ";
    std::cin >> n;
    this->p3.SetNumberOfMonth(n); 

    this->Service = this->p3.GetService();
    
}