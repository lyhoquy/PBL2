
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
              << "/" << ((p3.GetMonth().length()==1) ? ("0"+p3.GetMonth()) : p3.GetMonth()) << "/" << p1.Year
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

    // std::string day, month;
    // int year = p1.StringToInt(p1.Year);
    std::cout << "Nhap thoi gian bat dau goi tap VIP " << std::endl;

    std::string str = this->CustumerType1::InputTrainDay();
    if (str == "0")
    {
        --CustumerType3::Count3;
        // std::cout << "Check1 " << std::endl;
        return ;
    }
    
    std::string temp1 = str.substr(0,2);
    p3.SetDay(temp1);
    temp1 = str.substr(3);
    p3.SetMonth(temp1);

    // std::cout << "Check2 " << std::endl;
    std::cout << "Nhap so thang tap : " ;
    int n;
    std::cin >> n;
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

int CustumerType3::Input(const std::string& s){
    ++CustumerType3::Count3;
    this->CustumerNumber = "VIP" + std::string(3-std::to_string(CustumerType3::Count3).length(),'0') + std::to_string(CustumerType3::Count3);
    std::cin.ignore();
    if(!Human::Nhap(s)){
        --CustumerType3::Count3;
        return 0;
    }

    std::string str = this->CustumerType1::InputTrainDay();
    if (str == "0")
    {
        --CustumerType3::Count3;
        return 0;
    }
    
    std::string temp1 = str.substr(0,2);
    p3.SetDay(temp1);
    temp1 = str.substr(3);
    p3.SetMonth(temp1);

    int n;
    std::cout << "\nNhap so thang tap: ";
    std::cin >> n;
    this->p3.SetNumberOfMonth(n); 

    this->Service = this->p3.GetService();
    return 1;
}