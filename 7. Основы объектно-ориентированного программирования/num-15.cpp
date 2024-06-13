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
        cout << "������ �����������." << endl;
    }

    ~Triangle() {
        cout << "����������� ���������." << endl;
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
        cout << "������� ������������: " << side1 << ", " << side2 << ", " << side3 << endl;
        cout << "��������: " << getPerimeter() << endl;
        cout << "�������: " << getArea() << endl;
        if (isEquilateral()) {
            cout << "����������� ��������������." << endl;
        } else {
            cout << "����������� �� �������� ��������������." << endl;
        }
    }
};

int main() {
    int n;
    double a, b, c;
    double minPerimeter = numeric_limits<double>::max();
    double sumArea = 0;
    vector<Triangle> triangles;

    cout << "������� ���������� �������������: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "������� ����� ������ ������������ " << i+1 << " : ";
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
            cout << "����������� �� ��������� " << a << ", " << b << ", " << c << " �� ����������." << endl;
            i--;
        }
    }

    double avgArea = sumArea / triangles.size();

    cout << endl << "���������� � ������������:" << endl;
    for (int i = 0; i < triangles.size(); i++) {
        cout << "����������� " << i+1 << endl;
        triangles[i].printInfo();
        cout << endl;
    }

    cout << "������� �������: " << avgArea << endl;
    cout << "����������� ��������: " << minPerimeter << endl;

    return 0;
}
