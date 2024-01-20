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
              << "/" << ((p2.GetMonth().length()==1) ? ("0"+p2.GetMonth()) : p2.GetMonth()) << "/" << p2.Year
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
        << p2.GetDay() << ", " << p2.GetMonth() << ", " << p2.GetNumberOfMonth();

    ofs.close();
}

void CustumerType2::Input(const std::string& s){
    ++CustumerType2::Count2;
    this->CustumerNumber = "N" + std::string(3-std::to_string(CustumerType2::Count2).length(),'0') + std::to_string(CustumerType2::Count2);
    Human::Input(s);


    int year = p1.StringToInt(p1.Year);
    std::string month;

    month = p1.ChooseMonth();
    p2.SetMonth(month);
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
    p2.SetDay(day);

    int n;
    std::cout << "\nNhap so thang tap: ";
    std::cin >> n;
    this->p2.SetNumberOfMonth(n); 
}