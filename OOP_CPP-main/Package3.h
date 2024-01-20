#ifndef PACKAGE3_H
#define PACKAGE3_H

#include <map>

#include <fstream>
#include "Package2.h"

class Package3 : public Package2
{
private:
    static std::map<int,std::string> Services;

public:
    Package3();
    static int PriceVIP;
    std::string ShowServices(int& choice);
    int GetSize(){
        return this->Services.size();
    }

    int GetPrice(){
        return this->PriceVIP;
    }

    std::string GetService();
    void ReadFile(const std::string&);
    void WriteFile(const std::string&);
};

#endif
