#include "Package1.h"


std::string Package1::Year = "2023";
int Package1::PriceEachDay = 50;
std::string Package1::d[4][10] = {};
std::string Package1::m[12] = {"1","2","3","4","5","6","7","8","9","10","11","12"};

void Package1::ChangePrice(){
    std::cout << "Gia goi tap moi ngay hien tai : " << Package1::PriceEachDay << "000VND" << std::endl;
    std::cout << "Nhap gia tap moi ngay moi (Don vi nghin VND) : ";
    std::cin >> Package1::PriceEachDay;
    std::cout << "Da cap nhat lai gia goi tap moi ngay thanh " << Package1::PriceEachDay << "000VND" << std::endl;
}

void Package1::OutputMonth(const int& choice){
    std::cout << "Chon thang tap " << std::endl;
    for (size_t i = 0; i < 12; ++i)
    {
        if (i== choice)
        {
            std::cout << ">" << m[choice] << std::endl;
        }
        else{
            std::cout << " " << m[i] << std::endl;
        }
    }
    
}

std::string Package1::ChooseMonth(){
    int input;
    int choice = 5;
    int maxChoice = 11;

    do
    {
        system("cls");
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
            d[2][9] = "  ";
        }
        if (m == 28)
        {
            d[2][9] = "  ";
            d[2][8] = "  ";
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

std::string Package1::ChooseDay(const int& m){
    int input;
    int i = 1, j= 5;
    int maxDown = 3, maxUp = 0, maxLeft = 0, maxRight = 9;

    do
    {
        system("cls");
        std::cout << "Choose" << std::endl;
        OutputDay(m,i,j);

        input = getch();

        switch (input)
        {
        case 72: // len
            // if(a[i][j] == 31){
                
            // }
            if(i == maxUp){
                if(m==31){
                    i = maxDown;
                    j = 0;
                }
                else{
                    i = 2;
                }
            }
            else{
                --i;
            }
            break;
        case 80: // xuong
            if(i == 2){
                if (m == 31)
                {
                    i = maxDown;
                    j = 0;
                }
                else{
                    i = 0;
                    --maxDown;
                }
                
            }else if (i == maxDown)
            {
                i = maxUp;
                j = 0;
            }
            else{
                ++i;
            }
            break;
        case 75: // trai
            if(d[i][j] == "31"){
                continue;
            }
            (j == maxLeft) ? j = maxRight : --j;
            break;
        case 77: // phai
            if(d[i][j] == "31"){
                continue;
            }
            if(m <=29){
                if( d[i][j] == "28" || d[i][j] == "29")  j = maxLeft;
            }
            (j == maxRight) ? j = maxLeft : ++j; 
            break;
        
        }
        
    } while (input != 13);

    if(i == 3) return "31";
    return d[i][j];
}

int Package1::StringToInt(const std::string& s) const{
    int result = 0;
    for (char c : s)
        result = result * 10 + (c - '0');

    return result;
}