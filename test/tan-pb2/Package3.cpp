#include "Package3.h"

std::map<int, std::string> Package3::Services{};
int Package3::PriceVIP = 1000;

Package3::Package3() {
    // Services[1] = "Do uong tu chon";
    // Services[2] = "Ho boi vo cuc";
    // Services[3] = "Phong xong hoi";
    // Services[4] = "Massage thu gian";
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

void Package3::AddService() {
    std::string service;
    do
    {
        std::cout << "Nhap them dich cua khach vip " << std::endl;
        getline(std::cin, service);
    } while (service == "\n");
    
    Package3::Services.insert(std::make_pair(GetSize() + 1, service));
    std::cout << "Da cap nhat them dich vu " << std::endl;
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

void Package3::ChangePrice(){
    std::cout << "Gia goi tap moi thang hien tai : " << Package3::PriceVIP << "000VND" << std::endl;
    std::cout << "Nhap gia goi tap moi thang moi(Don vi nghin VND) : ";
    std::cin >> Package3::PriceVIP;
    std::cout << "Da thay doi gia goi tap moi thang sang : " << Package3::PriceVIP << std::endl;   
}

void Package3::ChangeService(){
    int input;
    int choice = 1;
    int maxChoice = GetSize();
    do {
        system("cls");
        std::cout << "Chinh sua dich vu tang kem " << std::endl;
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

    std::cout << "Cap nhat dich vu " << std::endl;
    getline(std::cin,Services[choice]);
    std::cout << "Da cap nhat dich vu" << std::endl;
}

void Package3::DeleteService(){
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

        if (input == 13)
        {
            break;
        }
        

    } while (true);
    Services.erase(choice);
    
    for (auto it = Services.begin(); it != Services.end();) {
        if (it->first > choice) {
            int NewIndex = it->first - 1;
            std::string NewValue = it->second;
            Services.erase(it++);
            Services[NewIndex] = NewValue;
        } else {
            ++it;
        }
    }
    
    std::cout << "Xoa dich vu thanh cong" << std::endl;
}