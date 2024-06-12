#include <iostream>
#include <cmath>
#include <vector>

class Quadrilateral {
private:
    double side1, side2, side3, side4;

public:
    Quadrilateral(double s1, double s2, double s3, double s4) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
        side4 = s4;
    }

    ~Quadrilateral() {}

    bool isSquare() {
        return (side1 == side2 && side2 == side3 && side3 == side4);
    }

    double calculateDiagonal1() {
        return sqrt(pow(side1, 2) + pow(side3, 2));
    }

    double calculateDiagonal2() {
        return sqrt(pow(side2, 2) + pow(side4, 2));
    }

    double calculatePerimeter() {
        return side1 + side2 + side3 + side4;
    }

    double calculateArea() {
        double semiperimeter = calculatePerimeter() / 2;
        return sqrt((semiperimeter - side1) * (semiperimeter - side2) * (semiperimeter - side3) * (semiperimeter - side4));
    }

    void printInfo() {
        std::cout << "������� 1: " << side1 << std::endl;
        std::cout << "������� 2: " << side2 << std::endl;
        std::cout << "������� 3: " << side3 << std::endl;
        std::cout << "������� 4: " << side4 << std::endl;
        std::cout << "��������� 1: " << calculateDiagonal1() << std::endl;
        std::cout << "��������� 2: " << calculateDiagonal2() << std::endl;
        std::cout << "��������: " << calculatePerimeter() << std::endl;
        std::cout << "�������: " << calculateArea() << std::endl;
        std::cout << "�������� ���������? " << (isSquare() ? "��" : "���") << std::endl;
    }
};

int main() {
    int n;
    std::cout << "������� ���������� �����������������: ";
    std::cin >> n;

    std::vector<Quadrilateral> quadrilaterals;

    for (int i = 0; i < n; i++) {
        double s1, s2, s3, s4;
        std::cout << "������� ������� ���������������� " << i+1 << ": ";
        std::cin >> s1 >> s2 >> s3 >> s4;

        Quadrilateral quad(s1, s2, s3, s4);
        quadrilaterals.push_back(quad);
    }

    double minPerimeter = quadrilaterals[0].calculatePerimeter();
    int minPerimeterIndex = 0;

    for (int i = 1; i < n; i++) {
        double perimeter = quadrilaterals[i].calculatePerimeter();
        if (perimeter < minPerimeter) {
            minPerimeter = perimeter;
            minPerimeterIndex = i;
        }
    }

    std::cout << "��������������� � ����������� ����������:" << std::endl;
    quadrilaterals[minPerimeterIndex].printInfo();

    return 0;
}
