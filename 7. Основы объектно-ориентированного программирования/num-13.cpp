#include <iostream>
#include <cmath>
using namespace std;

class Quadrilateral {
private:
    int x1, y1; 
    int x2, y2; 
    int x3, y3;
    int x4, y4;

public:
    Quadrilateral(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
        x1 = xa; y1 = ya;
        x2 = xb; y2 = yb;
        x3 = xc; y3 = yc;
        x4 = xd; y4 = yd;
    }

    ~Quadrilateral() {
        cout << "Четырехугольник уничтожен" << endl;
    }

    double calculateSideLength(int x1, int y1, int x2, int y2) {
        double length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        return length;
    }

    void calculateAndPrintInfo() {
        double AB = calculateSideLength(x1, y1, x2, y2);
        double BC = calculateSideLength(x2, y2, x3, y3);
        double CD = calculateSideLength(x3, y3, x4, y4);
        double AD = calculateSideLength(x1, y1, x4, y4);
        double AC = calculateSideLength(x1, y1, x3, y3);
        double BD = calculateSideLength(x2, y2, x4, y4);

        cout << "Длины сторон: AB = " << AB << ", BC = " << BC << ", CD = " << CD << ", AD = " << AD << ", AC = " << AC << ", BD = " << BD << endl;

        double diagonalAC = calculateSideLength(x1, y1, x3, y3);
        double diagonalBD = calculateSideLength(x2, y2, x4, y4);

        cout << "Длины диагоналей: AC = " << diagonalAC << ", BD = " << diagonalBD << endl;

        double perimeter = AB + BC + CD + AD;
        cout << "Периметр: " << perimeter << endl;

        double semiperimeter = perimeter / 2;
        double area = sqrt((semiperimeter - AB) * (semiperimeter - BC) * (semiperimeter - CD) * (semiperimeter - AD));
        cout << "Площадь: " << area << endl;

        if (AB == BC && BC == CD && CD == AD) {
            cout << "Четырехугольник представляет собой ромб." << endl;
        } else {
            cout << "Четырехугольник не является ромбом." << endl;
        }
    }
};

int main() {
    int n;
    cout << "Введите количество четырехуглльников: ";
    cin >> n;

    Quadrilateral* quadrilaterals[n];
    double maxArea = 0;
    int countMaxArea = 0;

    for (int i = 0; i < n; i++) {
        cout << "Введите координаты 4 точек для четырехугольника " << (i + 1) << ":" << endl;
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        quadrilaterals[i] = new Quadrilateral(x1, y1, x2, y2, x3, y3, x4, y4);
        quadrilaterals[i]->calculateAndPrintInfo();
        double area = quadrilaterals[i]->calculateArea();
        if (area > maxArea) {
            maxArea = area;
            countMaxArea = 1;
        } else if (area == maxArea) {
            countMaxArea++;
        }
    }

    cout << "Кольчество четырехугольков с максимальной площадью: " << countMaxArea << endl;

    for (int i = 0; i < n; i++) {
        delete quadrilaterals[i];
    }

    return 0;
}
