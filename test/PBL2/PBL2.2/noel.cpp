#include <iostream>
#include <thread>
#include <chrono>

void printSpaces(int numSpaces) {
    for (int i = 0; i < numSpaces; i++) {
        std::cout << " ";
    }
}

void printStars(int numStars) {
    for (int i = 0; i < numStars; i++) {
        std::cout << "*";
    }
}

void printChristmasTree(int height, int colorIndex) {
    int numSpaces = height - 1;
    int numStars = 1;

    for (int i = 0; i < height; i++) {
        printSpaces(numSpaces);
        for (int j = 0; j < numStars; j++) {
            // Thay đổi màu của các dấu sao dựa trên chỉ số màu
            switch (colorIndex) {
                case 0:
                    std::cout << "\033[32m"; // Màu xanh lá cây
                    break;
                case 1:
                    std::cout << "\033[31m"; // Màu đỏ
                    break;
                case 2:
                    std::cout << "\033[33m"; // Màu vàng
                    break;
            }
            std::cout << "*";
            std::cout << "\033[0m"; // Đặt lại màu mặc định
        }
        std::cout << std::endl;

        numSpaces--;
        numStars += 2;
    }

    // In phần thân của cây
    printSpaces(height - 1);
    std::cout << "|";
    std::cout << std::endl;
}

int main() {
    int treeHeight;
    int colorIndex = 0; // Chỉ số màu ban đầu

    std::cout << "Enter the height of the Christmas tree: ";
    std::cin >> treeHeight;

    while (true) {
        // Xóa màn hình console
        std::cout << "\033[2J\033[1;1H";

        printChristmasTree(treeHeight, colorIndex);

        // Tạm dừng chương trình trong 2 giây
        // std::this_thread::sleep_for(std::chrono::seconds(2));
        _sleep(1000);
        

        // Tăng chỉ số màu hoặc đặt lại nếu đã đạt màu cuối cùng
        colorIndex = (colorIndex + 1) % 3;
    }

    return 0;
}