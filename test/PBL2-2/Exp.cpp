#include <iostream>
#include <string>
#include <cctype>
#include "Exp.h"

// void Exp::validateFormat(std::string& userInput, int length) {
//     while (userInput.length() != length) {
//         std::cout << "Sai do dai. Nhap lai: ";
//         std::getline(std::cin, userInput);
//     }
// }
    
// bool Exp::isNumeric(const std::string& userInput) {
//     for (char c : userInput) {
//         if (!std::isdigit(c)) {
//             return false;
//         }
//     }
//     return true;
// }

// void Exp::validateNumeric(std::string& userInput) {
//     while (!isNumeric(userInput)) {
//         std::cout << "Sai dinh dang. Nhap lai: ";
//         std::getline(std::cin, userInput);
//     }
// }

// void Exp::Check(std::string & s, int l){
//     validateFormat(s, l);
//     validateNumeric(s);
// }

bool Exp::CheckName(const std::string& s){
    for (size_t i = 0; i < s.length(); ++i)
    {
        if(!isalpha(s[i]) && !isspace(s[i])){        
            return false;
        }
    }
    return true;
}

bool Exp::CheckPhone(const std::string& s){
    for (size_t i = 0; i < s.length(); ++i){
        if(!isdigit(s[i]) || isspace(s[i])){
            std::cout << "Khong nhap chua ki tu khac so hoac khoang trang" << std::endl;
            return false;
        }
    }
    return true;
}

bool Exp::CheckLength(const std::string& s, const int& l){
    return s.length() == l;
}

bool Exp::CheckNumber(const std::string& s, const int& low, const int& high){
    if(!CheckPhone(s)){
        return false;
    }
    int num = stoi(s);
    if(!(num >= low && num <= high)){
    std::cout << "Nhap so trong doan [" << low << "," << high << "]" << std::endl;
    }
    return num >= low && num <= high;
}