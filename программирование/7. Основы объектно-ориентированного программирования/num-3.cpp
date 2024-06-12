#include <iostream>
#include <vector>
#include <cmath>

class Circle {
private:
    double r; 

public:
    Circle() {
        r = 0.0;
    }

    Circle(double radius) {
        r = radius;
    }

    ~Circle() {
    }

    double getArea() {
        return M_PI * r * r;
    }

    double getLength() {
        return 2 * M_PI * r;
    }
};

int main() {
    int n; 
    double radius; 

    std::cout << "������� ���������� �����������: ";
    std::cin >> n;

    std::vector<Circle> circles;

    for (int i = 0; i < n; i++) {
        std::cout << "������� ������ " << (i + 1) << "-� ����������: ";
        std::cin >> radius;

        circles.push_back(Circle(radius));
    }

    double maxArea = circles[0].getArea();
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        double area = circles[i].getArea();
        if (area > maxArea) {
            maxArea = area;
            maxIndex = i;
        }
    }

    std::cout << "���������� � ������������ ��������: " << std::endl;
    std::cout << "������: " << circles[maxIndex].getRadius() << std::endl;
    std::cout << "�������: " << circles[maxIndex].getArea() << std::endl;
    std::cout << "�����: " << circles[maxIndex].getLength() << std::endl;

    return 0;
}
