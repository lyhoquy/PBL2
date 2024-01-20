#include <iostream>
#include "CustumerType3.h"
#include "Management.cpp"
#include <windows.h>
// #include "Management.cpp"

int ChooseType(){
    int input;
    int choice = 1;
    int maxChoice = 3;

    do
    {
        system("cls");
        std::cout << (choice == 1 ? ">" : " ") << "Cho khach hang tap theo ngay " << std::endl;
        std::cout << (choice == 2 ? ">" : " ") << "Cho khach hang tap dinh ki " << std::endl;
        std::cout << (choice == 3 ? ">" : " ") << "Cho khach hang loai VIP " << std::endl; 

        input = getch();
        if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == maxChoice) {
                choice = 1; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 1) {
                choice = maxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }
    } while (input != 13);
    return choice;
}

int ChooseChange(){
    int input;
    int choice = 1;
    int maxChoice = 2;
    do
    {
        system("cls");
        std::cout << (choice == 1 ? ">" : " ") << "Thay doi gia goi tap hang thang loai VIP" << std::endl;
        std::cout << (choice == 2 ? ">" : " ") << "Them dich vu cho khach VIP" << std::endl;

        input = getch();
        if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == maxChoice) {
                choice = 1; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 1) {
                choice = maxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }
    } while (input != 13);
    
    return choice;
}

int main(){

    int input;
    int choice = 1;
    int maxChoice = 7; // so luong lua chon trong menu

    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;

    Management<CustumerType1> m1;
    m1.ReadFile("text1.txt");
    Management<CustumerType2> m2;
    m2.ReadFile("text2.txt");
    Management<CustumerType3> m3;
    m3.ReadFile("text3.txt");

    CustumerType1 ct1;
    CustumerType2 ct2;
    CustumerType3 ct3;

    std::string s;

    Package1 p1;
    Package2 p2;
    Package3 p3;
    p3.ReadFile("service.txt");

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    do
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout <<"         MENU           \n";
        std::cout << "**      " << (choice == 1 ? '>' : ' ') << " Them thong tin khach hang         ** \n";
        std::cout << "**      " << (choice == 2 ? '>' : ' ') << " Xoa thong tin khach hang          ** \n";
        std::cout << "**      " << (choice == 3 ? '>' : ' ') << " Chinh sua thong tin khach hang    ** \n";
        std::cout << "**      " << (choice == 4 ? '>' : ' ') << " Xem danh sach khach hang          ** \n";
        std::cout << "**      " << (choice == 5 ? '>' : ' ') << " Nang cap len goi VIP              ** \n";
        std::cout << "**      " << (choice == 6 ? '>' : ' ') << " Cap nhat cac goi tap              ** \n";
        std::cout << "**      " << (choice == 7 ? '>' : ' ') << " Thoat                             ** \n";

        input = getch();
        if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == maxChoice) {
                choice = 1; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 1) {
                choice = maxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }


        if (input == 13){
            switch (choice)
            {
                // std::cout << "Hello " << std::endl;
                case 1:
                    switch (ChooseType())
                    {
                    case 1:    
                        // if(temp1 == 0){
                        //     // m1.ReadFile("text1.txt");
                        // }                   
                        std::cin >> ct1;
                        m1.AddCustomer(ct1);
                        std::cout << "Tong gia la: " << ct1.TotalPrice() << std::endl;
                        std::cout << "Da them khach hang tap theo ngay" << std::endl;
                        break;
                        
                    case 2:
                        // if(temp2 == 0){
                        //     // m2.ReadFile("text2.txt");
                        //     temp2 = 1;
                        // }                                              
                        std::cin >> ct2;
                        m2.AddCustomer(ct2);
                        std::cout << "Da them khach hang tap dinh ki" << std::endl;
                        break;

                    case 3:
                        // if(temp3 == 0){
                        //     // m3.ReadFile("text3.txt");
                        //     temp3 = 1;
                        // }                                
                        std::cin >> ct3;
                        m3.AddCustomer(ct3);
                        std::cout << "Da them khach hang loai VIP" << std::endl;
                        break;
                    }
                    break;

                case 2:
                    switch (ChooseType())
                    {
                    case 1:
                        std::cout << "Nhap so dien thoai khach hang can xoa : ";
                        std::cin >> s;
                        m1.DeleteCustomer(s);
                        break;
                    case 2:
                        std::cout << "Nhap so dien thoai khach hang can xoa : ";
                        std::cin >> s;
                        m2.DeleteCustomer(s);
                        break;
                    case 3:
                        std::cout << "Nhap so dien thoai khach hang can xoa : ";
                        std::cin >> s;
                        m3.DeleteCustomer(s);
                        break;
                    }
                    break;
                    
                case 3:
                    switch (ChooseType())
                    {
                    case 1:
                        std::cout << "Nhap so dien thoai can cap nhat : ";
                        std::cin >> s;
                        m1.Update(s);
                        break;
                    case 2:
                        std::cout << "Nhap so dien thoai can cap nhat : ";
                        std::cin >> s;
                        m2.Update(s);
                        break;
                    
                    default:
                        break;
                    }
                    break;

                case 4:
                    switch (ChooseType())
                    {
                        case 1:
                    if(temp1 == 0){
                        m1.ReadFile("text1.txt");
                        temp1 = 1;
                    } 
                    std::cout << "Danh sach " << ct1.NameCustumerType1 << " hien tai" << std::endl;
                    m1.ShowAllCustomers();
                    break;
                        case 2:
                    if(temp2 == 0){
                    m2.ReadFile("text2.txt");
                    temp2 = 1;
                    } 
                    std::cout << "Danh sach " << ct2.NameCustumerType2 << " hien tai" << std::endl;
                    m2.ShowAllCustomers();
                    break;
                        case 3:
                        if(temp3 == 0){
                            m3.ReadFile("text3.txt");
                            temp3 = 1;
                        } 
                    std::cout << "Danh sach " << ct3.NameCustumerType3 << " hien tai" << std::endl;
                    m3.ShowAllCustomers();
                    break;
                    }
                    break;

                case 5:
                    std::cout << "Nhap so dien thoai cua khach hang : ";
                    std::cin >> s;
                    m3.Upgrade(m2.GetCustumer(s));
                    break;

                case 6:
                    switch (ChooseType())
                    {
                    case 1:
                        p1.ChangePrice();
                        break;
                    case 2:
                        p2.ChangePrice();
                        break;
                    case 3:
                        (ChooseChange() == 1) ? p3.ChangePrice() : p3.AddService();
                        break;
                    
                    default:
                        break;
                    }
                    break;

                case 7:
                    m1.WriteFile("text1.txt");
                    m2.WriteFile("text2.txt");
                    m3.WriteFile("text3.txt");
                    p3.WriteFile("service.txt");
                    std::cout << "Du lieu da duoc cap nhat truoc khi ket thuc chuong trinh" << std::endl;
                    exit(1);
                    break;
            }
            std::cout << "Nhan phim bat ky de tiep tuc...";
            getch(); // Đợi nhấn Enter để tiếp tục
        } 

    }while (input != '0');
    return 0;
}