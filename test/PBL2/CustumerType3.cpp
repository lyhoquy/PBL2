
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

std::istream& operator >> (std::istream& in, CustumerType3& ct3){
    ++CustumerType3::Count3;
    ct3.CustumerNumber = "VIP" + std::string(3-std::to_string(CustumerType3::Count3).length(),'0') + std::to_string(CustumerType3::Count3);

    std::cout << "Nhap ten khach hang: ";
    getline(in, ct3.FullName);

    std::cout << "Nhap nam sinh: ";
    in >> ct3.BornYear;

    ct3.Gender = ct3.ChooseGender();
    
    std::cout << "Nhap so dien thoai: ";
    in >> ct3.PhoneNumber;
    std::cout << "Nam bay gio la 2023" << std::endl;
    
    std::string day;
    std::cout << "Nhap ngay tap: ";
    in >> day;
    ct3.p3.SetDay(day) ;
    std::string month;
    std::cout << "Nhap thang bat dau tap: ";
    in >> month;
    ct3.p3.SetMonth(month);
    // operator>>(in, static_cast<CustumerType1&>(ct2));
    std::cout << "Nhap so thang tap: ";
    int n; in >> n;
    ct3.p3.SetNumberOfMonth(n);

    // chon dich vu di kem
    system("cls");
    ct3.p3.ReadFile("service.txt");
    ct3.Service=ct3.p3.GetService();

    return in;
}

CustumerType3& CustumerType3::operator=(const CustumerType2& custumer2)
{
    // Gán các thông tin từ CustumerType2 vào CustumerType3
    static_cast<CustumerType2&>(*this) = custumer2;
    return *this;
}

void CustumerType3::Upgrade(CustumerType2& ct2){
    ++Count3;
    this->CustumerNumber = "VIP" + std::string(3-std::to_string(CustumerType3::Count3).length(),'0') + std::to_string(CustumerType3::Count3);
    this->FullName = ct2.GetName();
    this->BornYear = ct2.GetYear();
    this->Gender = ct2.GetGender();
    this->PhoneNumber = ct2.GetPhoneNumber();

    std::string day, month;
    std::cout << "Nhap thoi gian bat dau goi tap VIP " << std::endl;
    std::cout << "Nhap ngay bat dau " << std::endl;
    std::cin >> day;
    this->p3.SetDay(day);
    std::cout << "Nhap thang bat dau " << std::endl;
    std::cin >> month;
    this->p3.SetMonth(month);
    std::cout << "Nhap so thang bat dau " << std::endl;
    int n;
    std::cin >> n;

    std::cout << "Nhap so thang con lai cua goi tap 2: " << std::endl;
    int remainingMonths;
    std::cin >> remainingMonths;

    int remainingPrice = ct2.GetPackage().PriceEachMonth * remainingMonths;
    int upgradePrice = this->p3.PriceEachMonth * n;
    double totalPrice = remainingPrice - upgradePrice;
    if (totalPrice < 0) {
        std::cout << "Không đủ tiền để nâng cấp gói tập!" << std::endl;
        std::cout << "Con thieu: " << abs(totalPrice) << " VND" << std::endl;
        return;
    }
    std::cout << "So tien du la: " << totalPrice << " VND" << std::endl;

    this->p3.SetNumberOfMonth(n);
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

    ifs >> this->BornYear;
    ifs.ignore(1, ',');
    
    getline(ifs,this->Gender,',');
    ifs.ignore(1, ',');

    getline(ifs,this->PhoneNumber,',');
    ifs.ignore(1, ',');

    std::string day, month;
    int number;

    getline(ifs,day,',');    
    p3.SetDay(day);
    ifs.ignore(1, ',');

    getline(ifs,month,',');
    p3.SetMonth(month);
    ifs.ignore(1, ',');

    ifs >> number;
    p3.SetNumberOfMonth(number);
    ifs.ignore(1,',');
    getline(ifs, this->Service,'\n');


    // ifs.ignore(1, '\n');
}

void CustumerType3::WriteFile(const std::string& filename){
    std::ofstream ofs(filename,std::ios::app);
    if(!ofs) {
        std::cerr<<"Can't open output file.\n";
        return;
    }
    ofs << this->GetCustumerNumer() << "," <<FullName << "," << BornYear << "," << Gender << ", " << PhoneNumber << ", "
        << p3.GetDay() << ", " << p3.GetMonth() << ", " << p3.GetNumberOfMonth() 
        << "," << this->ChooseService() <<  std::endl;

    ofs.close();
}