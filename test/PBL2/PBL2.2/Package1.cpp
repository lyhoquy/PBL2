#include "Package1.h"

// std::string Package1::Year = "2023";
int Package1::PriceEachDay = 50;
std::string Package1::d[4][10] = {};
std::string Package1::m[12] = {"1","2","3","4","5","6","7","8","9","10","11","12"};

int Package1::StringToInt(const std::string& s) {
    int result = 0;
    bool isNegative = false;

    if (s[0] == '-') {
        isNegative = true;
    }

    for (size_t i = isNegative ? 1 : 0; i < s.length(); i++) {
        result = result * 10 + (s[i] - '0');
    }

    return isNegative ? -result : result;
}

bool Package1::CompareDay(const std::string& date1, const std::string& date2){
    std::istringstream iss1(date1);
    std::istringstream iss2(date2);
    
    int day1, month1, year1;
    int day2, month2, year2;

    char delimiter;

    // Phân tích chuỗi ngày tháng năm thành các thành phần
    iss1 >> day1 >> delimiter >> month1 >> delimiter >> year1;
    iss2 >> day2 >> delimiter >> month2 >> delimiter >> year2;

    // So sánh các thành phần ngày, tháng, năm
    if (year1 < year2) {
        return true;
    } else if (year1 > year2) {
        return false;
    } else {
        if (month1 < month2) {
            return true;
        } else if (month1 > month2) {
            return false;
        } else {
            if (day1 < day2) {
                return true;
            } else {
                return false;
            }
        }
    }
}

void Package1::ChangePrice(){
    std::cout << "Gia goi tap moi ngay hien tai : " << Package1::PriceEachDay << "000VND" << std::endl;
    std::cout << "Nhap gia tap moi ngay moi (Don vi nghin VND) : ";
    std::cin >> Package1::PriceEachDay;
    std::cout << "Da cap nhat lai gia goi tap moi ngay thanh " << Package1::PriceEachDay << "000VND" << std::endl;
}

void Package1::OutputMonth(const int& choice){
    for (size_t i = 0; i < 12; ++i)
    {
        if (i == choice)
        {
            std::cout << ">" << m[choice] << std::endl;
        }
        else{
            std::cout << " " << m[i] << std::endl;
        }
    }
    // std::cout << ((choice == 12) ? ">Thoat" : " Thoat"); 
}

std::string Package1::ChooseMonth(bool b){
    int input;
    int choice = StringToInt(MonthNow)-1;
    int maxChoice = 11;

    do
    {
        system("cls");
        std::cout << "Chon thang tap " << std::endl;
        if (!b)
        {
            std::cout << "Thang vua chon khong hop le " << std::endl;
        }
        
        OutputMonth(choice);

        input = getch();

        if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == maxChoice) {
                choice = 0; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 0) {
                choice = maxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }
    } while (input != 13);
    return m[choice];
}

void Package1::OutputDay(const int& m,const int& a, const int& b){
        int value = 1;
        for(int index=0; index<3; ++index){
            for(int j=0; j<10; ++j){
                d[index][j] = std::to_string(value++);
            }
        }
        if(m == 31){
            d[3][0] = "31";
        }
        if (m == 29)
        {
            d[2][9] = "";
        }
        if (m == 28)
        {
            d[2][9] = "";
            d[2][8] = "";
        }
        

    for(int index=0; index<3; ++index){
        for(int j=0; j<10; ++j){
            if(index == a && j == b){
                std::cout << ">" << std::setw(2) << d[a][b] << " ";
                continue;
            }
            std::cout << " " << std::setw(2) << d[index][j] << " ";
        }
        std::cout << std::endl;
    }
    if(m == 31){
        if(a==3 && b == 0){
        std::cout  << ">" << std::setw(2) << 31 << " ";
    }else{
        std::cout << " " << std::setw(2) << 31 << " ";
    }
    }
}

std::string Package1::ChooseDay(const int& m, bool b){
    int input;
    int i = 1, j = 5;
    int maxDown = 3, maxUp = 0, maxLeft = 0, maxRight = 9;

    do {
        system("cls");
        std::cout << "Chon ngay tap " << std::endl;
        // std::cout << "Chon ngay tap " << std::endl;
        if (!b)
        {
            std::cout << "Ngay vua nhap khong hop le " << std::endl;
        }
        
        OutputDay(m, i, j);

        input = _getch();

        switch (input) {
            case 72: // len
                // if(a[i][j] == 31){
                    
                // }
                if(i == maxUp) {
                    if(m == 31) {
                        i = maxDown;
                        j = 0;
                    }
                    else {
                        i = 2;
                    }
                }
                else {
                    --i;
                }
                break;
            case 80: // xuong
                switch (m)
                {
                case 30:
                    (i == 2) ? i = 0 : ++i;
                    break;
                
                case 31:
                    if(i == 2 ){
                        i = 3;
                        j = 0;
                    }
                    else if (i==3)
                    {
                        i = 0;
                        j = 0;
                    }
                    else{
                        ++i;
                    }   
                    break;

                default:
                    if (i == 1 && (d[i][j] == "19" || d[i][j] == "20"))
                    {
                        ++i;
                        j = 7;
                    }
                    
                    (i == 2) ? i = 0 : ++i;
                    break;
                }
                
                break;
            case 75: // trai
                if(d[i][j] == "31") {
                    continue;
                }
                if(m <= 29){
                    if(i==2 && j == 0)
                        j = 7;
                }
                (j == maxLeft) ? j = maxRight : --j;
                break;
            case 77: // phai
                if(d[i][j] == "31") {
                    continue;
                }
                if(m <= 29) {
                    if( d[i][j] == std::to_string(m))  j = maxLeft;
                }
                (j == maxRight) ? j = maxLeft : ++j; 
                break;
        } 
    } while (input != 13);

    if(i == 3) return "31";
    
    return d[i][j];
}

void Package1::OutputYear(const int& y){
    int year = StringToInt(this->YearNow);
    for (size_t i = 0; i <= 1; ++i)
    {
        if (y == i)
        {
            std::cout << ">" << year + i << std::endl;
        }
        else{
            std::cout << " " << year + i << std::endl;
        }
    }    
}

std::string Package1::ChooseYear(bool b){
    int input;
    int choice = 0;
    int maxChoice = 1;
    do
    {
        system("cls");
        std::cout << "Chon nam tap" << std::endl;
        if (!b)
        {
            std::cout << "Nam vua chon khong hop le" << std::endl;
        }
        
        OutputYear(choice);

        input = getch();

        if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == maxChoice) {
                choice = 0; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 0) {
                choice = maxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }
    } while (input != 13);
    return std::to_string(StringToInt(this->YearNow)+choice);
}