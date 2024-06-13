#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double a, double b, double c) {
        side1 = a;
        side2 = b;
        side3 = c;
        cout << "Создан треугольник." << endl;
    }

    ~Triangle() {
        cout << "Треугольник уничтожен." << endl;
    }

    bool isTriangle() {
        if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
            return true;
        } else {
            return false;
        }
    }

    double getPerimeter() {
        return side1 + side2 + side3;
    }

    double getArea() {
        double s = getPerimeter() / 2;
        return sqrt(s*(s - side1)*(s - side2)*(s - side3));
    }

    bool isEquilateral() {
        if (side1 == side2 && side2 == side3) {
            return true;
        } else {
            return false;
        }
    }

    void printInfo() {
        cout << "Стороны треугольника: " << side1 << ", " << side2 << ", " << side3 << endl;
        cout << "Периметр: " << getPerimeter() << endl;
        cout << "Площадь: " << getArea() << endl;
        if (isEquilateral()) {
            cout << "Треугольник равносторонний." << endl;
        } else {
            cout << "Треугольник не является равносторонний." << endl;
        }
    }
};

int main() {
    int n;
    double a, b, c;
    double minPerimeter = numeric_limits<double>::max();
    double sumArea = 0;
    vector<Triangle> triangles;

    cout << "ВВедите количество треугольников: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Введите длины сторон треугольника " << i+1 << " : ";
        cin >> a >> b >> c;

        Triangle triangle(a, b, c);

        if (triangle.isTriangle()) {
            double currentPerimeter = triangle.getPerimeter();
            double currentArea = triangle.getArea();

            sumArea += currentArea;

            if (currentPerimeter < minPerimeter) {
                minPerimeter = currentPerimeter;
            }

            triangles.push_back(triangle);
        } else {
            cout << "Треугольник со сторонами " << a << ", " << b << ", " << c << " не существует." << endl;
            i--;
        }
    }

    double avgArea = sumArea / triangles.size();

    cout << endl << "Информация о треугольнике:" << endl;
    for (int i = 0; i < triangles.size(); i++) {
        cout << "Треугольник " << i+1 << endl;
        triangles[i].printInfo();
        cout << endl;
    }

    cout << "Средняя площадь: " << avgArea << endl;
    cout << "Минимальный периметр: " << minPerimeter << endl;

    return 0;
}
