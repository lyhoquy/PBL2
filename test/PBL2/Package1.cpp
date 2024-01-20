#include "Package1.h"

std::string Package1::Year = "2023";
int Package1::PriceEachDay = 50;

void Package1::ChangePrice(){
    std::cout << "Gia goi tap moi ngay hien tai : " << Package1::PriceEachDay << std::endl;
    std::cout << "Nhap gia tap moi ngay moi ";
    std::cin >> Package1::PriceEachDay;
    std::cout << "Da cap nhat lai gia goi tap moi ngay thanh " << Package1::PriceEachDay << std::endl;
}

// int Package1::TotalPrice(){
//     return PriceEachDay;
// }