#ifndef EXP_H
#define EXP_H

#include <string>

class Exp {
public:
    bool CheckName(const std::string&);
    bool CheckPhone(const std::string&);
    bool CheckLength(const std::string&, const int&);
    bool CheckNumber(const std::string&,const std::string&);

};

#endif