#include <iostream>
#include <fstream>

int main() {
    int size;
    std::cout << "������� ������ �������: ";
    std::cin >> size;

    int* x = new int[size];
    std::cout << "������� �������� ������� x: ";
    for (int i = 0; i < size; i++) {
        std::cin >> x[i];
    }

    int* y = new int[2 * size];
    int j = 0;
    for (int i = 0; i < size; i++) {
        y[j++] = x[i];
        y[j++] = x[size - i - 1];
    }

    std::ofstream outfile("output.txt");
    for (int i = 0; i < 2 * size; i++) {
        outfile << y[i] << " ";
    }
    outfile.close();

    delete[] x;
    delete[] y;

    return 0;
}
