#include <iostream>
#include <vector>

using namespace std;

class RightTriangle {
private:
    double a, b, c;
public:
    RightTriangle(double sideA, double sideB, double sideC) {
        a = sideA;
        b = sideB;
        c = sideC;
    }

    bool isIsosceles() {
        return a == b || a == c || b == c;
    }

    double calculatePerimeter() {
        return a + b + c;
    }

    double calculateArea() {
        double p = calculatePerimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    void printInfo() {
        cout << "Длины сторон треугольника: " << a << ", " << b << ", " << c << endl;
        cout << "Периметр треугольника: " << calculatePerimeter() << endl;
        cout << "Площадь треугольника: " << calculateArea() << endl;
        if (isIsosceles()) {
            cout << "Треугольник является равнобедренным." << endl;
        } else {
            cout << "Треугольник не является равнобедренным." << endl;
        }
    }
};

int main() {
    int n;
    cout << "Введите количество треугольников: ";
    cin >> n;

    vector<RightTriangle> triangles;
    double totalArea = 0.0;

    for (int i = 0; i < n; i++) {
        double a, b, c; 
        cout << "Введите длины сторон треугольника " << i + 1 << ": ";
        cin >> a >> b >> c;

        RightTriangle triangle(a, b, c);
        triangles.push_back(triangle);

        totalArea += triangle.calculateArea();
    }

    double averageArea = totalArea / n; 
    int count = 0; 

    for (const RightTriangle& triangle : triangles) {
        if (triangle.calculateArea() < averageArea) {
            count++;
        }
    }

    cout << "Кольчество треугольниковы с площадью меньше средней: " << count << endl;

    return 0;
}
