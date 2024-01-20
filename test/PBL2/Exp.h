#include <string>

class Exp {
public:
    void validateFormat(std::string& userInput, int length);
    void validateNumeric(std::string& userInput);
    bool isNumeric(const std::string& userInput);
    void Check(std::string& s, int l);
};

