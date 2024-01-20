#ifndef EXP_H
#define EXP_H

#include <string>

class Exp {
public:
    // void validateFormat(std::string& userInput, int length);
    // void validateNumeric(std::string& userInput);
    // bool isNumeric(const std::string& userInput);
    // void Check(std::string& s, int l);

    bool CheckName(const std::string&);
    bool CheckPhone(const std::string&);
    bool CheckLength(const std::string&, const int&);
    bool CheckNumber(const std::string&, const int&, const int&);

};

#endif