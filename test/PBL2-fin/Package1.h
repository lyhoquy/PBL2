#ifndef PACKAGE1_H
#define PACKAGE1_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include "Package.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"

class Package1 : public Package
{
protected:
    std::string Day;
    std::string Month;
    std::vector<std::string> History;
public:
    static std::string d[4][10];
    static std::string m[12];
    std::string DayNow;
    std::string MonthNow;
    std::string Year;
    static int PriceEachDay;

    void SetTime(){
        // Lấy thời gian hiện tại
        auto now = std::chrono::system_clock::now();

        // Chuyển đổi thời gian hiện tại thành dạng chuỗi
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        // Chuyển đổi thời gian thành cấu trúc tm
        std::tm* timeInfo = std::localtime(&currentTime);
        Year = std::to_string(timeInfo->tm_year+1900);
        MonthNow = m[timeInfo->tm_mon];
        DayNow = std::to_string(timeInfo->tm_mday);

    }

    Package1(){
        // Lấy thời gian hiện tại
        auto now = std::chrono::system_clock::now();

        // Chuyển đổi thời gian hiện tại thành dạng chuỗi
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        // Chuyển đổi thời gian thành cấu trúc tm
        std::tm* timeInfo = std::localtime(&currentTime);
        Year = std::to_string(timeInfo->tm_year+1900);
        MonthNow = m[timeInfo->tm_mon];
        DayNow = std::to_string(timeInfo->tm_mday);
    }

    std::string GetDay(){
        return this->Day;
    }

    void SetDay(const std::string& day){
        this->Day = day;
    }

    std::string GetMonth() const{
        return this->Month;
    }

    void SetMonth(const std::string& month){
        this->Month = month;
    }

    int StringToInt(const std::string&);
    
    void ChangePrice();
    void OutputMonth(const int&);
    std::string ChooseMonth();
    void OutputDay(const int& ,const int&, const int&);
    std::string ChooseDay(const int&,bool=true);

};

#endif