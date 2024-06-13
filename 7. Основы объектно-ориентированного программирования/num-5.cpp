#include <iostream>
using namespace std;

class Rectangle {
private:
    int a; 
    int b; 

public:
    Rectangle() {
        a = 0;
        b = 0;
    }

    Rectangle(int sideA, int sideB) {
        a = sideA;
        b = sideB;
    }

    ~Rectangle() {}

    void printSides() {
        cout << "����� ������: " << a << ", " << b << endl;
    }

    void printDiagonals() {
        cout << "����� ����������: " << sqrt(a*a + b*b) << ", " << sqrt(a*a + b*b) << endl;
    }

    int getPerimeter() {
        return 2 * (a + b);
    }

    int getArea() {
        return a * b;
    }

    bool isSquare() {
        return a == b;
    }
};

int main() {
    int n;
    cout << "������� ���������� ���������������: ";
    cin >> n;

    Rectangle* rectangles = new Rectangle[n];

    int totalArea = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sideA, sideB;
        cout << "������� ����� ������ " << i + 1 << " ��������������: ";
        cin >> sideA >> sideB;
        rectangles[i] = Rectangle(sideA, sideB);
        totalArea += rectangles[i].getArea();
    }

    int averageArea = totalArea / n;

    for (int i = 0; i < n; i++) {
        if (rectangles[i].getArea() > averageArea) {
            count++;
        }
    }

    cout << "���������� ��������������� � �������� ������ �������: " << count << endl;

    delete[] rectangles;
    return 0;
}
