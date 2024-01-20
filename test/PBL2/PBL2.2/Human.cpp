#include "Human.h"

Human::Human(std::string fullname, std::string bornyear, std::string gender, std::string phonenumber)
    : FullName(fullname), BornYear(bornyear), Gender(gender), PhoneNumber(phonenumber)
{}

void Human::Show(){
    std::cout << "|" << std::setw(17) << "Ten khach hang : "<<this->FullName << std::setw(28-this->FullName.length()) <<"|" << std::endl;
    std::cout << "|" << std::setw(17) << "Nam sinh : " << this->BornYear << std::setw(24) <<"|" << std::endl;
    std::cout << "|" << std::setw(17) << "Gioi tinh : " << this->Gender << std::setw(24) << "|" << std::endl;
    std::cout << "|" << std::setw(17) << "So dien thoai : " << this->PhoneNumber << std::setw(18) <<"|" << std::endl;
}

std::string Human::ChooseGender(){
    int input;
    int choose = 1;
    int maxchoose = 3;

    do
    {
        system("cls");
        std::cout <<"Chon gioi tinh: \n";
        std::cout << (choose == 1 ? '>' : ' ') << " Nam  \n";
        std::cout << (choose == 2 ? '>' : ' ') << " Nu   \n";
        std::cout << (choose == 3 ? '>' : ' ') << " Khac \n";

        input = getch();
        if (input == 80) { // Mũi tên đi xuống (lên)
            if (choose == maxchoose) {
                choose = 1; // Di chuyển lên đầu danh sách
            } else {
                choose++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choose == 1) {
                choose = maxchoose; // Di chuyển xuống cuối danh sách
            } else {
                choose--;
            }
        }

    }while (input != 13); 

        switch (choose)
        {
        case 1:
            return "Nam ";
            break;
        case 2:
            return "Nu  ";
            break;
        case 3:
            return "Khac";
            break;
        }
}

void Human::Input(const std::string& s){
    Exp e;
    do
    {
        std::cout << "Nhap ten khach hang: " << std::endl;
        getline(std::cin, this->FullName);
        if(!e.CheckName(this->FullName)){
            std::cout << "Ten khong duoc chua ki tu khac chu. Vui long nhap lai." << std::endl;
            continue;
        }
        break;
    } while (1);
    
    this->Gender = this->ChooseGender();


    do
    {
        std::cout<<"Nhap nam sinh" << std::endl;
        std::cin >> this->BornYear;
    } while (!e.CheckNumber(this->BornYear,1023,2005));


    this->PhoneNumber = s;
}

std::string Human::Check(){
    std::string s;
    Exp e;
    do
    {
        do
        {
            std::cout << "Nhap vao so dien thoai cua khach hang" << std::endl;
            getline(std::cin,s);

        } while (!e.CheckPhone(s));

        if(s.length() != 10){
        std::cout << "So dien thoai vua nhap khong du 10 ki tu. Vui long nhap lai" << std::endl;
        }
    } while (!e.CheckLength(s,10));
    
    return s;
}

int Human::Nhap(const std::string& s){
    // system("cls");
    Exp e;
    int input;
    int choice = 1;
    int MaxChoice = 5;
    int temp1 = 0, temp2 = 0, temp3 = 0;

    std::string name,bornyear,gender;
    this->PhoneNumber = s;

    do
    {
        system("cls");
        std::cout << "NHAP THONG TIN KHACH HANG" << std::endl;
        std::cout << (choice == 1 ? ">":" ") << "Ten khach hang : "  << name <<  std::endl;
        std::cout << (choice == 2 ? ">":" ") << "Nam sinh khach hang : "  << bornyear <<  std::endl;
        std::cout << (choice == 3 ? ">":" ") << "Gioi tinh khach hang : "  << gender << std::endl;
        std::cout << (choice == 4 ? ">":" ") << "Hoan thanh nhap "  << std::endl;
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

        if (input == 13)
        {
            switch (choice)
        {
            case 1:
                do
                {
                    std::cout << "Nhap ten khach hang : " << std::endl;
                    getline(std::cin, name);
                    if(!e.CheckName(name)){
                        std::cout << "Ten khong duoc chua ki tu khac chu. Vui long nhap lai." << std::endl;
                        continue;
                    }
                    break;
                } while (1);
                temp1 = 1;
                break;
            case 2:
                do
                {
                    std::cout<<"Nhap nam sinh" << std::endl;
                    std::cin >> bornyear;
                } while (!e.CheckNumber(bornyear,1923,2005));
                temp2 = 1;
                break;
            case 3:
                std::cout << "Nhap gioi tinh khach hang : ";
                gender = ChooseGender();
                temp3 = 1;
                break;

            case 4:
                if(temp1+ temp2+temp3 == 3){
                    std::cout << "Da hoan thanh viec nhap thong tin khach hang " << std::endl;
                    this->FullName = name;
                    this->BornYear = bornyear;
                    this->Gender = gender;
                    
                    system("pause");
                    return 1;
                }
                else{
                    std::cout << "Chua hoan thanh viec nhap thong tin khach hang " << std::endl;
                    system("pause");
                    break;
                }

            case 5:
                std::cout << "Da thoat khoi muc nhap thong tin khach hang " << std::endl;
                return 0;
                break;
            }
        }
        
    } while (input != '0');
    
}