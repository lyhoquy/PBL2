#include "CustumerType1.h"

// #include <stdexcept>
#include <string>
#include "Exp.h"
// #include <limits>

std::string CustumerType1::NameCustumerType1 = "Khach hang tap theo ngay";
int CustumerType1::Count1 = 1;

void CustumerType1::ReadFile(std::ifstream& ifs) {
    std::string line;
    if (std::getline(ifs, line)) {
        std::istringstream iss(line);
        getline(iss, FullName, ',');
        getline(iss, BornYear, ',');
        ifs.ignore(1, ',');
        getline(iss, Gender, ',');
        ifs.ignore(1, ',');
        getline(iss, PhoneNumber, ',');
        ifs.ignore(1, ',');

        std::string s;
        History.clear();

        while (getline(iss, s, ',')) {
            if (s.find('-') != std::string::npos) {
                s.erase(s.find('-'));
                History.push_back(s);
                break;
            }
            History.push_back(s);
        }
    }
}


void CustumerType1::WriteFile(const std::string& filename){
    std::ofstream ofs(filename,std::ios::app);
    if(!ofs) {
        std::cerr<<"Can't open output file.\n";
        return;
    }

    if(Count1 == 1){
        Count1 = 0;
    }
    else{
        ofs << std::endl << "   ";
    }

ofs << FullName << "," << BornYear << "," << Gender << "," << PhoneNumber;
for(int i = 0; i < History.size(); ++i) {
    ofs << "," << History[i];
}
ofs << "-";

ofs.close();
}


void CustumerType1::Show(){
    std::cout << "----------------------------------------------" << std::endl;
    Human::Show();
    std::cout << "|" << std::setw(17) << "Nhung ngay tap : " << this->History[0] << std::setw(18) << "|" << std::endl;
    for(int i=1; i<this->History.size(); ++i){
        std::cout << "|" << std::setw(27) << this->History[i] << std::setw(18) << "|" << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;
    
}

void CustumerType1::Update(){
    int temp = 1;
    int input;
    int choice = 1;
    int MaxChoice = 5;
    do{
        system("cls");
        std::cout<<"Chon dich vu muon cap nhat:"<<std::endl;
            std::cout << (choice == 1 ? ">":" ") << "Ten khach hang hien tai: " << this->GetName() << std::endl;
            std::cout << (choice == 2 ? ">":" ") << "Nam sinh khach hang hien tai: " << this->GetYear() << std::endl;
            std::cout << (choice == 3 ? ">":" ") << "Gioi tinh khach hang hien tai: " << this->GetGender() << std::endl;
            std::cout << (choice == 4 ? ">":" ") << "So dien thoai khach hang hien tai: " << this->GetPhoneNumber() << std::endl;
            std::cout << (choice == 5 ? ">":" ") << "Thoat" << std::endl;

            input = getch();

            if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == MaxChoice) {
                choice = 1; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 1) {
                choice = MaxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }

        if(input == 13){
            switch (choice){
                case 1:
                    if(temp == 1){
                        std::cin.ignore();
                        temp = 0;
                    } 
                    std::cout << "Cap nhat ten : " << std::endl;
                    getline(std::cin,this->FullName);
                    break;
                case 2:
                    temp = 1;
                    std::cout << "Cap nhat nam sinh : ";
                    std::cin >> this->BornYear;
                    std::cout << "Da cap nhat lai nam sinh cua khach hang" << std::endl;
                    break;

                case 3:
                    temp = 1;
                    std::cout << "Cap nhat lai gioi tinh : ";
                    this->Gender = Human::ChooseGender();
                    std::cout << "Da cap nhat lai gioi tinh cua khach hang " << std::endl;
                    break;
                case 4:
                    temp = 1;
                    std::cout << "Nhap so dien thoai moi : ";
                    std::cin >> this->PhoneNumber;
                    std::cout << "Da cap nhat lai so dien thoai cua khach hang" << std::endl;
                    break;
                case 5:
                    std::cout << "Da thoat khoi muc chinh sua thong tin" << std::endl;
                    system("pause");
                    return;
                    break;
            }
        }
    }while (input != '0');
}


void CustumerType1::InputTrainDay(){
    // Exp e;
    std::string month;
    this->History.clear();
    int Year = p1.StringToInt(p1.Year);

    month = p1.ChooseMonth();
    p1.SetMonth(month);
    int high;
    if(month == "1"|| month == "3"|| month == "5"|| month == "7"|| month == "8"|| month == "10" || month == "12"){
        high = 31;
    }
    else if (month == "4" || month == "6" || month == "9" || month == "11")
    {
        high = 30;
    }
    else{
        (Year % 4 == 0 && Year % 100 != 0) ? high = 29 : high = 28;
    }

    std::string day;

    day = p1.ChooseDay(high);
    p1.SetDay(day);


    std::string s = day + "/" + month + "/" + p1.Year;
    if(s[2] != '/') s = "0" + s;
    if(s[5] != '/') s.insert(3,"0");
    this->History.push_back(s);
}



void CustumerType1::AddTrainDay(){
    Exp e;
    std::string month;
    // do
    // {
    //     std::cout<<"Nhap thang tap" << std::endl;
    //     getline(std::cin,month);
    // } while (!e.CheckNumber(month,1,12));
    // p1.SetMonth(month);

    int year = p1.StringToInt(p1.Year);

    month = p1.ChooseMonth();
    p1.SetMonth(month);
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
    // do
    // {
    //     std::cout<<"Nhap ngay tap" << std::endl;
    //     getline(std::cin,day);
    // } while (!e.CheckNumber(day,1,high));
    
    day = p1.ChooseDay(high);
    p1.SetDay(day);


    std::string s = day + "/" + month + "/" + p1.Year;
    if(s[2] != '/') s = "0" + s;
    if(s[5] != '/') s.insert(3,"0");
    this->History.push_back(s);
}

void CustumerType1::Input(const std::string& s){
    Human::Input(s);
    this->InputTrainDay();
}

std::istream& operator>>(std::istream& in, CustumerType1& ct1) {
    Exp check;
    std::cout << "Nhap ten khach hang: ";
    getline(in, ct1.FullName);

    ct1.Gender = ct1.ChooseGender();

    std::cout << "Nhap so dien thoai (10 chu so): ";
    in >> ct1.PhoneNumber;
    // check.Check(ct1.PhoneNumber, 10);
    

    std::cout << "Nhap nam sinh (4 chu so): ";
    in >> ct1.BornYear;
    // check.Check(ct1.BornYear, 4);

    std::cout << "Nam hien tai la 2023" << std::endl;

    std::string day;
    std::cout << "Nhap ngay tap: ";
    in >> day;
    // check.validateNumeric(day);
    ct1.p1.SetDay(day);

    std::string month;
    std::cout << "Nhap thang bat dau tap: ";
    in >> month;
    // check.validateNumeric(month);
    ct1.p1.SetMonth(month);

    return in;
}