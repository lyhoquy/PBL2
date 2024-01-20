#include "CustumerType2.h"
#include <string>
#include <cstdlib>

int CustumerType2::Count2 = 0;
std::string CustumerType2::NameCustumerType2 = "Khach hang tap hang thang";

void CustumerType2::Show(){
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(17) << "Ma khach hang : " << this->CustumerNumber << std::setw(24) << "|" << std::endl;
    Human::Show();
    std::cout << "|" << std::setw(17) << "Ngay bat dau : " << ((p2.GetDay().length()==1) ? ("0"+p2.GetDay()) : p2.GetDay())
              << "/" << ((p2.GetMonth().length()==1) ? ("0"+p2.GetMonth()) : p2.GetMonth()) << "/" << p2.GetYear()
              << std::setw(18) << "|" << std::endl;

    int number = p2.GetNumberOfMonth();
    std::string s = std::to_string(number);

    std::cout << "|" << std::setw(17) << "Thoi han : " << ((s.length()==1) ? ("0"+s) : s) << " thang" 
              << std::setw(20) << "|" << std::endl;

    std::cout << "----------------------------------------------" << std::endl;
}

void CustumerType2::ReadFile(std::ifstream& ifs){
    ++CustumerType2::Count2;
    getline(ifs,this->CustumerNumber,',');

    getline(ifs, this->FullName,',');

    getline(ifs,BornYear,',');
    ifs.ignore(1, ',');
    
    getline(ifs,this->Gender,',');
    ifs.ignore(1, ',');

    getline(ifs,this->PhoneNumber,',');
    ifs.ignore(1, ',');

    std::string day, month,year;
    int number;

    getline(ifs,day,',');    
    p2.SetDay(day);
    ifs.ignore(1, ',');

    getline(ifs,month,',');
    p2.SetMonth(month);
    ifs.ignore(1, ',');

    getline(ifs,year,',');
    p2.SetYear(year);
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
    if(Count2 != 0){
        Count2 = 0;
    }
    else{
        ofs << std::endl;
    }
    ofs << this->GetCustumerNumer() << "," <<  FullName << "," << BornYear << ", " << Gender << ", " << PhoneNumber << ", "
        << p2.GetDay() << ", " << p2.GetMonth() << ", " << p2.GetYear() << ", " << p2.GetNumberOfMonth();

    ofs.close();
}

int CustumerType2::Input(const std::string& s){
    ++CustumerType2::Count2;
    this->CustumerNumber = "N" + std::string(3-std::to_string(CustumerType2::Count2).length(),'0') + std::to_string(CustumerType2::Count2);
    //neu thoat trong khi nhap thong tin tra ve 0
    if(!Human::Nhap(s)){
        --CustumerType2::Count2;
        return 0;
    }

    // neu thoat trong khi nhap ngay bat dau tap tra ve 0
    std::string str = this->CustumerType1::InputTrainDay();
    if (str == "0")
    {
        --CustumerType2::Count2;
        return 0;
    }
    
    if(str[2] != '/') str = "0" + str;
    if(str[5] != '/') str.insert(3,"0");

    std::string temp1 = str.substr(0,2);
    p2.SetDay(temp1);
    temp1 = str.substr(3,2);
    p2.SetMonth(temp1);
    temp1 = str.substr(6);
    p2.SetYear(temp1);

    int n;
    std::cout << "\nNhap so thang tap: ";
    std::cin >> n;
    this->p2.SetNumberOfMonth(n); 
    return 1; // Nhap tat ca thong tin tra ve 1
}