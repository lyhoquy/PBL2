#include "Package3.h"

std::map<int, std::string> Package3::Services{};
int Package3::PriceVIP = 1000;

Package3::Package3() {
}

std::string Package3::ShowServices(int& choice) {
    for (const auto& pair : Services) {
        if (pair.first == choice) {
            std::cout << ">" << pair.second << std::endl;
        } else {
            std::cout << " " << pair.second << std::endl;
        }
    }
}

void Package3::ReadFile(const std::string& filename) {
    std::ifstream ifs;
    ifs.open(filename, std::ios::in);
    if (!ifs) {
        std::cout << "Khong the mo file." << std::endl;
        return;
    }

    std::string service;
    int i = 1;
    while (!ifs.eof()) {
        getline(ifs, service);
        this->Services.insert(std::make_pair(i++, service));
    }
}

void Package3::WriteFile(const std::string& filename) {
    std::ofstream ofs(filename, std::ios::trunc);
    // std::ofstream ofs(filename,std::ios::app);
    if (!ofs) {
        std::cerr << "Can't open output file.\n";
        return;
    }

    for (int i = 1; i < Services.size(); ++i) {
        ofs << Services[i] << "\n";
    }
    ofs << Services[GetSize()];
    ofs.close();
}

std::string Package3::GetService() {
    int input;
    int choice = 1;
    int maxChoice = GetSize();
    do {
        system("cls");
        std::cout << "Dich vu tang kem cho khach vip " << std::endl;
        ShowServices(choice);

        input = getch();

        if (input == 80) { // Mũi tên đi xuống (lên)
            if (choice == maxChoice) {
                choice = 1; // Di chuyển lên đầu danh sách
            } else {
                choice++;
            }
        } else if (input == 72) { // Mũi tên lên (xuống)
            if (choice == 1) {
                choice = maxChoice; // Di chuyển xuống cuối danh sách
            } else {
                choice--;
            }
        }

    } while (input != 13);

    return Services[choice];
}

