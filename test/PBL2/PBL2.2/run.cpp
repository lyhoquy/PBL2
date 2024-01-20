#include <iostream>
#include "CustumerType3.h"
#include "Management.cpp"
#include <windows.h>
#include "Exp.h"
// #include "Management.cpp"

int ChooseType(std::string s1 = "Cho khach hang tap theo ngay ",
               std::string s2 = "Cho khach hang tap dinh ki ",
               std::string s3 = "Cho khach hang tap goi VIP "){
    int input;
    int choice = 1;
    int maxChoice = 3;

    do
    {
        system("cls");
        std::cout << (choice == 1 ? ">" : " ") << s1 << std::endl;
        std::cout << (choice == 2 ? ">" : " ") << s2 << std::endl;
        std::cout << (choice == 3 ? ">" : " ") << s3 << std::endl; 

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
        std::cout << (choice == 2 ? ">" : " ") << "Cap nhat dich vu cho khach VIP" << std::endl;

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

    // int temp1 = 0;
    // int temp2 = 0;
    // int temp3 = 0;

    int index;

    Management<CustumerType1> m1;
    m1.ReadFile("text1.txt");
    m1.ReadRevenueFromFile("revenue1.txt");
    // m1.Revenue1();

    Management<CustumerType2> m2;
    m2.ReadFile("text2.txt");
    m2.ReadRevenueFromFile("revenue2.txt");
    // m2.Revenue();

    Management<CustumerType3> m3;
    m3.ReadFile("text3.txt");
    m3.ReadRevenueFromFile("revenue3.txt");
    // m3.Revenue();

    CustumerType1 ct1;
    CustumerType2 ct2;
    CustumerType3 ct3;

    std::string s;
    int temp1;
    int temp2;

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
        std::cout << "**      " << (choice == 7 ? '>' : ' ') << " Xem gia cac goi tap               ** \n";
        std::cout << "**      " << (choice == 8 ? '>' : ' ') << " Xem doanh thu                     ** \n";
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
                case 1: // Them khach hang
                    switch (ChooseType())
                    {
                    case 1:    
                        s = ct1.Check();
                        index = m1.Check(s);
                        if(index == -1){

                            if(!ct1.Input(s))
                            break;

                            m1.AddCustomer(ct1);
                            // std::cout << ct1.TotalPrice() << "000VND" << std::endl;
                            std::cout << "Da them khach hang tap theo ngay" << std::endl;
                            // std::cout << "Check" << std::endl;
                            m1.AddRevenue(ct1.TotalPrice(),ct1.GetMonth()-1);

                        }              
                        else{
                            std::cout << "Da co thong tin cua khach hang" << std::endl;
                            // m1.LastHope(index);
                            m1[index].AddTrainDay();
                            // m1[index].InputTrainDay();
                            // std::cout << ct1.TotalPrice() << "000VND" << std::endl;
                            m1.AddRevenue(ct1.TotalPrice(),m1[index].GetMonth()-1);
                        }
                        break;
                        
                    case 2:
                        // std::cout << "Nhap so dien thoai khach hang " << std::endl;
                        // std::cin >> s;
                        s = ct2.Check();
                        if(m2.Check(s) == -1){

                            if(!ct2.Input(s)){
                                break;
                            }

                            m2.AddCustomer(ct2);
                            std::cout << "Da them khach hang tap theo dinh ki" << std::endl;
                            m2.AddRevenue(ct2.TotalPrice(),ct2.GetMonth()-1);

                        }              
                        else{
                            std::cout << "Da co thong tin cua khach hang" << std::endl;
                            // std::cout << m2[0].GetMonth() << std::endl;
                        }
                        break;

                    case 3:
                        std::cout << "Nhap so dien thoai khach hang " << std::endl;
                        std::cin >> s;
                        if(m3.Check(s) == -1){

                           if(!ct3.Input(s)){
                                continue;
                           }

                            m3.AddCustomer(ct3);
                            std::cout << "Da them khach hang tap goi VIP" << std::endl;
                            m3.AddRevenue(ct3.TotalPrice(),ct3.GetMonth()-1);

                        }              
                        else{
                            std::cout << "Da co thong tin cua khach hang" << std::endl;
                        }
                        break;
                    }
                    break;

                case 2: // Xoa Khach hang
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
                    
                case 3: // Cap nhat thong tin khach hang
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
                    }
                    break;

                case 4: // Xem danh sach khach hang
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

                case 5: // Tim khach hang
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

                case 6: // nang cap len goi vip
                    std::cout << "Nhap so dien thoai cua khach hang : ";
                    std::cin >> s;
                    //kiem tra khach han co trong danh sach khong
                    index = m2.Check(s);
                    // m3.Upgrade(m2.GetCustumer(s));
                    if(index == -1){
                        std::cout << "Khong ton tai khach hang co so dien thoai vua nhap" << std::endl;
                        // return;
                    }
                    else{
                        // s = m3.Upgrade(m2[index]);
                        // temp1 = p1.StringToInt(s.substr(0,2));
                        // temp2 = p1.StringToInt(s.substr(2));
                        // if(temp2>0){
                        //     m3.AddRevenue(temp2,temp1-1);
                        //     std::cout << "So tien can tra them la: " << temp2 << "000VND" << std::endl;
                        // }else{
                        //     m2.AddRevenue(temp2,m2[index].GetMonth()-1);
                        //     std::cout << "So tien hoan lai la: " << -1*temp2 << "000VND" << std::endl;;
                        //     }
                        m3.Upgrade(m2[index]);
                        m2.DeleteCustomer(index);
                    }
                    break;

                case 7: // Chinh sua goi tap
                    switch (ChooseType("Goi tap theo ngay","Goi tap theo thang","Goi tap VIP"))
                    {
                    case 1:
                        std::cout << "Gia moi ngay tap " << p1.PriceEachDay << "000VND" << std::endl;
                        break;
                    case 2:
                        // p2.ChangePrice();
                        std::cout << "Gia moi thang tap " << p2.PriceEachMonth << "000VND" << std::endl;
                        break;
                    case 3:
                        // if(ChooseChange() == 1){
                        //     p3.ChangePrice(); 
                        // }else{
                        //     switch (ChooseType("Them dich vu","Chinh sua dich vu","Xoa dich vu"))
                        //     {
                        //     case 1:
                        //         p3.AddService();
                        //         break;
                        //     case 2:
                        //         p3.ChangeService();
                        //         break;
                        //     case 3:
                        //         p3.DeleteService();
                        //         break;
                        //     }
                        // }
                        std::cout << "Gia moi thang goi VIP " << p3.PriceVIP << "000VND" << std::endl;
                    }
                    break;

                case 8: // Doanh thu
                    switch (ChooseType())
                    {
                    case 1:
                        
                        m1.ShowRevenue();
                        break;
                    case 2:
                        
                        m2.ShowRevenue();
                        break;
                    case 3:
                        
                        m3.ShowRevenue();
                        break;
                    
                    }
                    break;

                case 9: // Thoat
                    m1.WriteFile("text1.txt");
                    m1.UpdateRevenueFile("revenue1.txt");
                    m2.WriteFile("text2.txt");
                    m2.UpdateRevenueFile("revenue2.txt");
                    m3.WriteFile("text3.txt");
                    m3.UpdateRevenueFile("revenue3.txt");
                    p3.WriteFile("service.txt");
                    std::cout << "Du lieu da duoc cap nhat truoc khi ket thuc chuong trinh" << std::endl;
                    // m1.ShowPay();
                    exit(1);
                    break;
            }
            std::cout << "Nhan phim bat ky de tiep tuc...";
            getch(); // Đợi nhấn Enter để tiếp tục
        } 

    }while (input != '0');

    // ct1.Nhap();
    // ct1.Show();
    // m1.Revenue1();
    // m1.ShowRevenue();
    // m2.Revenue();
    // m2.ShowRevenue();
    // m3.Revenue();
    // m3.ShowRevenue();
    return 0;
}