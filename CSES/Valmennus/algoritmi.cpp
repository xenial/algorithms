#include <iostream>

int main() {
    unsigned long a;
    std::cin >> a;
    std::cout << a << " ";
    while (a != 1) {
        if (a % 2 == 0) {
            a = a / 2;
        } else {
            a = a * 3 + 1;
        }

        std::cout << a << " ";
    }
}