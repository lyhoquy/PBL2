#include "Package2.h"

int Package2::PriceEachMonth = 500;

void Package2::ChangePrice(){
    std::cout << "Gia goi tap moi thang hien tai : " << Package2::PriceEachMonth << "000VND" << std::endl;
    std::cout << "Nhap gia goi tap moi thang moi(don vi nghin VND) : ";
    std::cin >> Package2::PriceEachMonth;
    std::cout << "Da thay doi gia goi tap moi thang sang : " << Package2::PriceEachMonth << "000VND" << std::endl;
}