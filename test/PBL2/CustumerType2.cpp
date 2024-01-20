#include "CustumerType2.h"
#include <string>
#include <cstdlib>

int CustumerType2::Count2 = 0;
std::string CustumerType2::NameCustumerType2 = "Khach hang tap hang thang";

std::istream& operator >> (std::istream& in, CustumerType2& ct2){
    CustumerType2::Count2++;
    ct2.CustumerNumber = "N" + std::string(3-std::to_string(CustumerType2::Count2).length(),'0') + std::to_string(CustumerType2::Count2);

    std::cout << "Nhap ten khach hang: ";
    getline(in, ct2.FullName);

    std::cout << "Nhap nam sinh: ";
    in >> ct2.BornYear;

    ct2.Gender = ct2.ChooseGender();
    
    std::cout << "Nhap so dien thoai: ";
    in >> ct2.PhoneNumber;
    std::cout << "Nam bay gio la 2023" << std::endl;
    
    std::string day;
    std::cout << "Nhap ngay tap: ";
    in >> day;
    ct2.p2.SetDay(day) ;
    std::string month;
    std::cout << "Nhap thang bat dau tap: ";
    in >> month;
    ct2.p2.SetMonth(month);
    // operator>>(in, static_cast<CustumerType1&>(ct2));
    std::cout << "Nhap so thang tap: ";
    int n; in >> n;
    ct2.p2.SetNumberOfMonth(n);
    return in;
}

void CustumerType2::Show(){
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(17) << "Ma khach hang : " << this->CustumerNumber << std::setw(24) << "|" << std::endl;
    Human::Show();
    std::cout << "|" << std::setw(17) << "Ngay bat dau : " << ((p2.GetDay().length()==1) ? ("0"+p2.GetDay()) : p2.GetDay())
              << "/" << ((p2.GetMonth().length()==1) ? ("0"+p2.GetMonth()) : p2.GetMonth()) << "/" << p2.Year
              << std::setw(18) << "|" << std::endl;

    int number = p2.GetNumberOfMonth();
    std::string s = std::to_string(number);

    std::cout << "|" << std::setw(17) << "Thoi han : " << ((s.length()==1) ? ("0"+s) : s) << " thang" 
              << std::setw(20) << "|" << std::endl;

    // int temp =  (p2.GetNumberOfMonth())*std::stoi(p2.PriceEachMonth);
    // std::cout << "|" << std::setw(17) << "Don gia : " << temp << " 000VND"
    //           << std::setw(21 - std::to_string(temp).length()) << "|" << std::endl;

    std::cout << "----------------------------------------------" << std::endl;
}

void CustumerType2::ReadFile(std::ifstream& ifs){
    // // Kiểm tra xem file có trống hay không
    // if (ifs.peek() == std::ifstream::traits_type::eof()) {
    //     std::cout << "File đang trống." << std::endl;
    //     return; // Kết thúc hàm nếu file trống
    // }
    ++CustumerType2::Count2;
    getline(ifs,this->CustumerNumber,',');

    getline(ifs, this->FullName,',');

    ifs >> this->BornYear;
    ifs.ignore(1, ',');
    
    getline(ifs,this->Gender,',');
    ifs.ignore(1, ',');

    getline(ifs,this->PhoneNumber,',');
    ifs.ignore(1, ',');

    std::string day, month;
    int number;

    getline(ifs,day,',');    
    p2.SetDay(day);
    ifs.ignore(1, ',');

    getline(ifs,month,',');
    p2.SetMonth(month);
    ifs.ignore(1, ',');

    ifs >> number;
    p2.SetNumberOfMonth(number);

    ifs.ignore(1, '\n');
}

void CustumerType2::WriteFile(const std::string& filename){
    std::ofstream ofs(filename,std::ios::app);
    if(!ofs) {
        std::cerr<<"Can't open output file.\n";
        return;
    }
    ofs << this->GetCustumerNumer() << "," <<  FullName << "," << BornYear << "," << Gender << ", " << PhoneNumber << ", "
        << p2.GetDay() << ", " << p2.GetMonth() << ", " << p2.GetNumberOfMonth() << std::endl;

    ofs.close();
}