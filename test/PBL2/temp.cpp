// #include "CustumerType1.h"
// #include "Exp.h"
// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <cctype>
// #include <conio.h>
// #include "Management.cpp"

// #define RESET   "\033[0m"
// #define RED     "\033[31m"

// // bool IsPhoneNumberValid(const std::string& phoneNumber) {
// //     // Kiểm tra số điện thoại không chứa chữ cái
// //     for (char c : phoneNumber) {
// //         if (!std::isdigit(c)) {
// //             return false;
// //         }
// //     }

// //     // Kiểm tra số điện thoại có đủ 10 chữ số
// //     if (phoneNumber.length() != 10) {
// //         return false;
// //     }

// //     return true;
// // }

//     int a[4][10];
// void init(){

//     int value = 1;
//     for(int index=0; index<3; ++index){
//         for(int j=0; j<10; ++j){
//             a[index][j] = value++;
//         }
//     }
//     a[3][0] = 31;
// }

// void in(int a[][10],int i, int b){

//     init();
//     for(int index=0; index<3; ++index){
//         for(int j=0; j<10; ++j){
//             if(index == i && j == b){
//                 std::cout << RED << ">" << std::setw(2) << a[i][b] << RESET << " ";
//                 continue;
//             }
//             std::cout << " " << std::setw(2) << a[index][j] << " ";
//         }
//         std::cout << std::endl;
//     }
//     if(i==3 && b == 0){
//         std::cout << RED << ">" << std::setw(2) << 31 << RESET << " ";
//     }else{
//         std::cout << " " << std::setw(2) << 31 << " ";
//     }
// }

// int main() {
//     // CustumerType1 c;
//     // std::string s;
//     // Exp e;

//     // do
//     // {
//     //     std::cout<<"Enter day" << std::endl;
//     //     getline(std::cin,s);
//     // } while (!e.CheckNumber(s,1,31));
    

//     // int input;
//     // int i = 1, j= 5;
//     // int maxDown = 3, maxUp = 0, maxLeft = 0, maxRight = 9;

//     // do
//     // {
//     //     system("cls");
//     //     std::cout << "Choose" << std::endl;
//     //     in(a,i,j);

//     //     input = getch();

//     //     switch (input)
//     //     {
//     //     case 72: // len
//     //         // if(a[i][j] == 31){
                
//     //         // }
//     //         if(i == maxUp){
//     //             i = maxDown;
//     //             j = 0;
//     //         }
//     //         else{
//     //             --i;
//     //         }
//     //         break;
//     //     case 80: // xuong
//     //         if(i == 2){
//     //             i = maxDown;
//     //             j = 0;
//     //         }else if (a[i][j] == 31)
//     //         {
//     //             i = maxUp;
//     //             j = 0;
//     //         }
//     //         else{
//     //             ++i;
//     //         }
//     //         break;
//     //     case 75: // trai
//     //         if(a[i][j] == 31){
//     //             continue;
//     //         }
//     //         (j == maxLeft) ? j = maxRight : --j;
//     //         break;
//     //     case 77: // phai
//     //         if(a[i][j] == 31){
//     //             continue;
//     //         }
//     //         (j == maxRight) ? j = maxLeft : ++j; 
//     //         break;
        
//     //     }
        
//     // } while (input != 13);
    
//     // std::cout << a[i][j] << std::endl;
//     // return 0;

//     Management<CustumerType1> m1;
//     m1.ReadFile("text1.txt");
//     m1.Revenue1();
//     // m1.ShowAllCustomers();
//     m1.ShowRevenue();
// }

#include <iostream>
#include <chrono>
#include <ctime>
#include "CustumerType1.h"

int main() {
    // Lấy thời gian hiện tại
    // auto now = std::chrono::system_clock::now();

    // // Chuyển đổi thời gian hiện tại thành dạng chuỗi
    // std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // // Chuyển đổi thời gian thành cấu trúc tm
    // std::tm* timeInfo = std::localtime(&currentTime);

    // // Lấy thông tin về ngày và thời gian từ cấu trúc tm
    // int year = timeInfo->tm_year + 1900; // Năm
    // int month = timeInfo->tm_mon + 1; // Tháng (từ 0 đến 11)
    // int day = timeInfo->tm_mday; // Ngày
    // int hour = timeInfo->tm_hour; // Giờ
    // int minute = timeInfo->tm_min; // Phút
    // int second = timeInfo->tm_sec; // Giây

    // // In ra ngày và thời gian thực
    // std::cout << "Ngay: " << day << "/" << month << "/" << year << std::endl;
    // std::cout << "Thoi gian: " << hour << ":" << minute << ":" << second << std::endl;

    CustumerType1 ct1;
    // ct1.Nhap();
    // ct1.AddTrainDay();
    ct1.thu();
    ct1.Show();
    // std::cout << "Hello World" << std::endl;

    return 0;
}