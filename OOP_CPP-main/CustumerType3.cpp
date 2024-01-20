#include "CustumerType3.h"

std::string CustumerType3::NameCustumerType3 = "Khach hang loai VIP";
int CustumerType3::Count3 = 0;

void CustumerType3::Show(){
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(17) << "Ma khach hang : " << this->CustumerNumber << std::setw(22) << "|" << std::endl;
    Human::Show();
    CustumerType2::ShowDate();
    std::cout << "|" << std::setw(17) << "Uu dai di kem : " << this->Service << std::setw(28 - this->Service.length()) << "|" << std::endl; 
    std::cout << "----------------------------------------------" << std::endl;
}

void CustumerType3::Upgrade(CustumerType2& ct2){
    this->FullName = ct2.GetName();
    this->BornYear = ct2.GetBornYear();
    this->Gender = ct2.GetGender();
    this->PhoneNumber = ct2.GetPhoneNumber();

    std::string str = this->CustumerType1::InputTrainDay();
    if (str == "0")
    {
        --CustumerType3::Count3;
        return ;
    }
    
    std::string temp1 = str.substr(0,2);
    p3.SetDay(temp1);
    temp1 = str.substr(3);
    p3.SetMonth(temp1);

    std::cout << "Nhap so thang tap : " ;
    int n;
    std::cin >> n;
    this->p3.SetNumberOfMonth(n);

    this->Service = this->p3.GetService();
    ++Count3;
    this->CustumerNumber = "VIP" + std::string(3-std::to_string(CustumerType3::Count3).length(),'0') + std::to_string(CustumerType3::Count3);
}

void CustumerType3::ReadFile(std::ifstream& ifs){

    ++CustumerType3::Count3;
    std::string s;
    getline(ifs,s,',');
    this->SetCustumerNumber(s);

    getline(ifs, s,',');
    this->SetName(s);

    getline(ifs,s,',');
    this->SetBornYear(s);
    ifs.ignore(1, ',');
    
    getline(ifs,s,',');
    this->SetGender(s);
    ifs.ignore(1, ',');

    getline(ifs,s,',');
    this->SetPhoneNumber(s);
    ifs.ignore(1, ',');
    
    int number;

    getline(ifs,s,',');    
    p1.SetDay(s);
    ifs.ignore(1, ',');

    getline(ifs,s,',');
    p1.SetMonth(s);
    ifs.ignore(1, ',');

    getline(ifs,s,',');
    p1.SetYear(s);
    ifs.ignore(1, ',');

    ifs >> number;
    p2.SetNumberOfMonth(number);
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
    ofs << this->GetCustumerNumer() << "," << this->GetName() << "," << this->GetBornYear() << ", " << this->GetGender() << ", " << this->GetPhoneNumber() << ", "
        << p1.GetDay() << ", " << p1.GetMonth() << ", " << p1.GetYear() << ", " << p2.GetNumberOfMonth() 
        << "," << this->ChooseService();

    ofs.close();
}

int CustumerType3::Input(const std::string& s){
    std::cin.ignore(); 
    CustumerType2::Input(s);
    --CustumerType2::Count2;

    this->Service = this->p3.GetService();
    ++CustumerType3::Count3;
    this->CustumerNumber = "VIP" + std::string(3-std::to_string(CustumerType3::Count3).length(),'0') + std::to_string(CustumerType3::Count3);
    return 1;
}