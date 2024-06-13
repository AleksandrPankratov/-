#include <iostream>
#include <cmath>

int main() {
    int r;
    std::cout << "������� ����� r: ";
    std::cin >> r;

    int n;
    std::cout << "������� ������ ������� n: ";
    std::cin >> n;

    int* array = new int[n];
    std::cout << "������� �������� �������: ";
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }

    int maxDiff = std::abs(array[0] - r);
    int firstElem = array[0];
    int secondElem = array[1];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = std::abs(array[i] - array[j]);
            if (diff > maxDiff) {
                maxDiff = diff;
                firstElem = array[i];
                secondElem = array[j];
            }
        }
    }

    std::cout << "�������� � ���������� ��������� �� ����� " << r << ": " << firstElem << ", " << secondElem << std::endl;

    delete[] array;

    return 0;
}
