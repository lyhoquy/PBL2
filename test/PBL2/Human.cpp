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