#include <iostream>
#include "CustumerType3.h"
#include "Management.cpp"
#include <windows.h>
#include "Exp.h"

int ChooseType(){
    int input;
    int choice = 1;
    int maxChoice = 3;

    do
    {
        system("cls");
        std::cout << (choice == 1 ? ">" : " ") << "Khach hang tap theo ngay " << std::endl;
        std::cout << (choice == 2 ? ">" : " ") << "Khach hang tap dinh ki " << std::endl;
        std::cout << (choice == 3 ? ">" : " ") << "Khach hang loai VIP " << std::endl; 

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
    int maxChoice = 9; // so luong lua chon trong menu

    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;

    Management<CustumerType1> m1;
    m1.ReadFile("text1.txt");
    m1.ReadRevenueFromFile("Revenue1.txt");
    Management<CustumerType2> m2;
    m2.ReadFile("text2.txt");
    m2.ReadRevenueFromFile("Revenue2.txt");
    Management<CustumerType3> m3;
    m3.ReadFile("text3.txt");
    m3.ReadRevenueFromFile("Revenue3.txt");

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
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout <<"         MENU           \n";
        std::cout << "**      " << (choice == 1 ? '>' : ' ') << " Them thong tin khach hang         ** \n";
        std::cout << "**      " << (choice == 2 ? '>' : ' ') << " Xoa thong tin khach hang          ** \n";
        std::cout << "**      " << (choice == 3 ? '>' : ' ') << " Chinh sua thong tin khach hang    ** \n";
        std::cout << "**      " << (choice == 4 ? '>' : ' ') << " Xem danh sach khach hang          ** \n";
        std::cout << "**      " << (choice == 5 ? '>' : ' ') << " Tim kiem khach hang               ** \n";
        std::cout << "**      " << (choice == 6 ? '>' : ' ') << " Nang cap len goi VIP              ** \n";
        std::cout << "**      " << (choice == 7 ? '>' : ' ') << " Cap nhat cac goi tap              ** \n";
        std::cout << "**      " << (choice == 8 ? '>' : ' ') << " Doanh thu moi thang               ** \n";
        std::cout << "**      " << (choice == 9 ? '>' : ' ') << " Thoat                             ** \n";

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
                case 1:
                    switch (ChooseType())
                    {
                    case 1:
                        std::cout << "Nhap so dien thoai khach hang " << std::endl;
                        std::cin >> s;
                        if(m1.Check(s) == -1){

                            ct1.Input(s);

                            m1.AddCustomer(ct1);
                            std::cout << ct1.TotalPrice() << "000VND" << std::endl;
                            std::cout << "Da them khach hang tap theo ngay" << std::endl;

                        }              
                        else{
                            std::cout << "Da co thong tin cua khach hang" << std::endl;
                            int index = m1.Check(s);
                            m1.LastHope(index);
                            std::cout << ct1.TotalPrice() << "000VND" << std::endl;
                        }
                        break;
                        
                    case 2:
                        std::cout << "Nhap so dien thoai khach hang " << std::endl;
                        std::cin >> s;
                        if(m2.Check(s) == -1){

                            ct2.Input(s);

                            m2.AddCustomer(ct2);
                            std::cout << "Da them khach hang tap theo ngay" << std::endl;

                        }              
                        else{
                            std::cout << "Da co thong tin cua khach hang" << std::endl;
                        }
                        break;

                    case 3:
                        std::cout << "Nhap so dien thoai khach hang " << std::endl;
                        std::cin >> s;
                        if(m3.Check(s) == -1){

                            ct3.Input(s);

                            m3.AddCustomer(ct3);
                            std::cout << "Da them khach hang tap theo ngay" << std::endl;

                        }              
                        else{
                            std::cout << "Da co thong tin cua khach hang" << std::endl;
                        }
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
                    case 3:
                        std::cout << "Nhap so dien thoai can cap nhat : ";
                        std::cin >> s;
                        m3.Update(s);
                        break;
                    
                    default:
                        break;
                    }
                    break;

                case 4:
                    switch (ChooseType())
                    {
                        case 1:
                    std::cout << "Danh sach " << ct1.NameCustumerType1 << " hien tai" << std::endl;
                    m1.ShowAllCustomers();
                    break;
                        case 2:
                    std::cout << "Danh sach " << ct2.NameCustumerType2 << " hien tai" << std::endl;
                    m2.ShowAllCustomers();
                    break;
                        case 3:
                    std::cout << "Danh sach " << ct3.NameCustumerType3 << " hien tai" << std::endl;
                    m3.ShowAllCustomers();
                    break;
                    }
                    break;

                case 5:
                    switch (ChooseType())
                    {
                    case 1:
                        std::cout << "Nhap so dien thoai cua khach hang can tim " << std::endl;
                        std::cin >> s;
                        m1.FindCustumer(s);
                        break;
                    case 2:
                        std::cout << "Nhap so dien thoai cua khach hang can tim " << std::endl;
                        std::cin >> s;
                        m2.FindCustumer(s);
                        break;
                    case 3:
                        std::cout << "Nhap so dien thoai cua khach hang can tim " << std::endl;
                        std::cin >> s;
                        m3.FindCustumer(s);
                        break;
                    }
                    break;

                case 6:
                    std::cout << "Nhap so dien thoai cua khach hang : ";
                    std::cin >> s;
                    m3.Upgrade(m2.GetCustumer(s));
                    break;

                case 7:
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
                    }
                    break;

                case 8:

                    switch (ChooseType())
                    {
                        case 1:
                            m1.Revenue1();
                            m1.ShowRevenue();
                            break;
                        case 2:
                            m2.Revenue(); 
                            m2.ShowRevenue();
                            break;
                        case 3:
                            m3.Revenue();
                            m3.ShowRevenue();
                            break;
                    }
                    break;

                case 9:
                    m1.WriteFile("text1.txt");
                    m2.WriteFile("text2.txt");
                    m3.WriteFile("text3.txt");
                    p3.WriteFile("service.txt");
                    m1.UpdateRevenueFile("Revenue1.txt");
                    m2.UpdateRevenueFile("Revenue2.txt");
                    m3.UpdateRevenueFile("Revenue3.txt");
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