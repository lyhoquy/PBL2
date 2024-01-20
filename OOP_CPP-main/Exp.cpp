#include <iostream>
#include <string>
#include <cctype>
#include "Exp.h"

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

bool Exp::CheckNumber(const std::string& s, const std::string& yearnow) {
    if (!CheckPhone(s)) {
        return false;
    }
    
    int num = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        num = num * 10 + static_cast<int>(s[i] - '0');    
    }

    int year = 0;
    for (size_t i = 0; i < yearnow.length(); ++i) {
        year = year * 10 + static_cast<int>(yearnow[i] - '0');    
    }
    // khach hang co do tuoi tu 18 den 80
    int high = year - 18;
    int low = year - 80;
    
    if (!(num >= low && num <= high)) {
        std::cout << "Khach hang co do tuoi tu 18 den 80" << std::endl;
        return false;
    }
    
    return true;
}