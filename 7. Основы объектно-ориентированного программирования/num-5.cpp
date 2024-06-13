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
        cout << "Длины сторон: " << a << ", " << b << endl;
    }

    void printDiagonals() {
        cout << "Длины диагоналей: " << sqrt(a*a + b*b) << ", " << sqrt(a*a + b*b) << endl;
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
    cout << "Введите количество прямоугольников: ";
    cin >> n;

    Rectangle* rectangles = new Rectangle[n];

    int totalArea = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int sideA, sideB;
        cout << "Введите длины сторон " << i + 1 << " прямоугольника: ";
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

    cout << "Количество прямоугольников с площадью больше средней: " << count << endl;

    delete[] rectangles;
    return 0;
}
