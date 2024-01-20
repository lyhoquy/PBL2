#include <iostream>
#include <string>
#include <cctype>
#include "Exp.h"

void Exp::validateFormat(std::string& userInput, int length) {
    while (userInput.length() != length) {
        std::cout << "Sai do dai. Nhap lai: ";
        std::getline(std::cin, userInput);
    }
}
    
bool Exp::isNumeric(const std::string& userInput) {
    for (char c : userInput) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

void Exp::validateNumeric(std::string& userInput) {
    while (!isNumeric(userInput)) {
        std::cout << "Sai dinh dang. Nhap lai: ";
        std::getline(std::cin, userInput);
    }
}

void Exp::Check(std::string & s, int l){
    validateFormat(s, l);
    validateNumeric(s);
}