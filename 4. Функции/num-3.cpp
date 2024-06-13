#include <iostream>
#include <vector>

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int n;
    std::cout << "Введите количество чисел:";
    std::cin >> n;

    std::vector<int> numbers(n);
    std::cout << "Введите " << n << " натуральных чисел:";

    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    int result = numbers[0];

    for (int i = 1; i < n; i++) {
        result = gcd(result, numbers[i]);
    }

    std::cout << "Наибольший общий делитель: " << result << std::endl;

    return 0;
}
