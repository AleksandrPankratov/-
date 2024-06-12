#include <iostream>
#include <fstream>

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countDivisors(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    std::ofstream output("result.txt");

    int num;
    int countPrimes = 0;
    do {
        std::cout << "������� ����� (��� ��������� ������������������ ������� 0): ";
        std::cin >> num;

        if (num != 0) {
            int divisors = countDivisors(num);
            output << "����� " << num << " ����� " << divisors << " ���������." << std::endl;

            if (isPrime(num)) {
                countPrimes++;
            }
        }
    } while (num != 0);

    output << "����� ���������� ������� ����� � ������������������: " << countPrimes << std::endl;

    output.close();

    return 0;
}
