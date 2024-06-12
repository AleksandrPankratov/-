#include <iostream>
#include <cmath>
using namespace std;

class Quadrilateral {
private:
    double x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->x3 = x3;
        this->y3 = y3;
        this->x4 = x4;
        this->y4 = y4;
    }

    double calculateSideLength(double x1, double y1, double x2, double y2) {
        return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    }

    double calculateDiagonal() {
        double diagonal1 = calculateSideLength(x1, y1, x3, y3);
        double diagonal2 = calculateSideLength(x2, y2, x4, y4);
        return sqrt(pow((diagonal1), 2) + pow((diagonal2), 2));
    }

    double calculatePerimeter() {
        double side1 = calculateSideLength(x1, y1, x2, y2);
        double side2 = calculateSideLength(x2, y2, x3, y3);
        double side3 = calculateSideLength(x3, y3, x4, y4);
        double side4 = calculateSideLength(x4, y4, x1, y1);
        return side1 + side2 + side3 + side4;
    }

    double calculateArea() {
        double side1 = calculateSideLength(x1, y1, x2, y2);
        double side2 = calculateSideLength(x2, y2, x3, y3);
        double side3 = calculateSideLength(x3, y3, x4, y4);
        double side4 = calculateSideLength(x4, y4, x1, y1);
        double semiPerimeter = (side1 + side2 + side3 + side4) / 2;
        return sqrt((semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3) * (semiPerimeter - side4));
    }

    bool isRectangle() {
        double side1 = calculateSideLength(x1, y1, x2, y2);
        double side2 = calculateSideLength(x2, y2, x3, y3);
        double side3 = calculateSideLength(x3, y3, x4, y4);
        double side4 = calculateSideLength(x4, y4, x1, y1);

        if (pow(side1, 2) + pow(side2, 2) == pow(side3, 2) + pow(side4, 2)) {
            return true;
        }
        else return false;
    }

    void printInformation() {
        cout << "Длины сторон: ";
        cout << calculateSideLength(x1, y1, x2, y2) << ", ";
        cout << calculateSideLength(x2, y2, x3, y3) << ", ";
        cout << calculateSideLength(x3, y3, x4, y4) << ", ";
        cout << calculateSideLength(x4, y4, x1, y1) << endl;

        cout << "Диагонали: " << calculateDiagonal() << endl;

        cout << "Периметр: " << calculatePerimeter() << endl;

        cout << "Площадь: " << calculateArea() << endl;

        if (isRectangle()) {
            cout << "Это прямоугольник." << endl;
        }
        else {
            cout << "Это не прямоугольник." << endl;
        }
    }

    ~Quadrilateral() {
    }
};

int main() {
    int n;
    cout << "Введите количество четырехугольников: ";
    cin >> n;

    Quadrilateral** quadrilaterals = new Quadrilateral*[n];

    double x1, y1, x2, y2, x3, y3, x4, y4;
    for (int i = 0; i < n; i++) {
        cout << "Введите координаты точек для " << i+1 << "-го четырехугольника:" << endl;
        cout << "X1: ";
        cin >> x1;
        cout << "Y1: ";
        cin >> y1;
        cout << "X2: ";
        cin >> x2;
        cout << "Y2: ";
        cin >> y2;
        cout << "X3: ";
        cin >> x3;
        cout << "Y3: ";
        cin >> y3;
        cout << "X4: ";
        cin >> x4;
        cout << "Y4: ";
        cin >> y4;

        quadrilaterals[i] = new Quadrilateral(x1, y1, x2, y2, x3, y3, x4, y4);
    }

    int minAreaIndex = 0;
    double minArea = quadrilaterals[0]->calculateArea();

    for (int i = 1; i < n; i++) {
        double area = quadrilaterals[i]->calculateArea();
        if (area < minArea) {
            minArea = area;
            minAreaIndex = i;
        }
    }

    cout << "Четырехугольник с минимальной площадью:" << endl;
    quadrilaterals[minAreaIndex]->printInformation();

    for (int i = 0; i < n; i++) {
        delete quadrilaterals[i];
    }
    delete[] quadrilaterals;

    return 0;
}
