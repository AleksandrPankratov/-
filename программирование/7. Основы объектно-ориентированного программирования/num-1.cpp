#include <iostream>
#include <vector>

using namespace std;

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

    ~Quadrilateral() {
        cout << "�������������� ������!" << endl;
    }

    double calculateDiagonal() {
        return sqrt((side1 * side1) + (side3 * side3));
    }

    double calculatePerimeter() {
        return side1 + side2 + side3 + side4;
    }

    double calculateArea() {
        double semiPerimeter = calculatePerimeter() / 2;

        return sqrt((semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3) * (semiPerimeter - side4));
    }

    bool isTrapezoid() {
        if ((side1 == side3 && side2 != side4) || (side1 != side3 && side2 == side4))
            return true;
        else
            return false;
    }
};

int main() {
    int n; 
    double s1, s2, s3, s4; 

    cout << "������� ���������� �����������������: ";
    cin >> n;

    vector<Quadrilateral> quadrilaterals; 
    for (int i = 0; i < n; i++) {
        cout << "������� ����� ������ ����������������: " << i + 1 << ": ";
        cin >> s1 >> s2 >> s3 >> s4;

        Quadrilateral quad(s1, s2, s3, s4);
        quadrilaterals.push_back(quad);
    }

    double maxArea = 0;
    int maxAreaIndex = -1;

    for (int i = 0; i < n; i++) {
        if (quadrilaterals[i].calculateArea() > maxArea) {
            maxArea = quadrilaterals[i].calculateArea();
            maxAreaIndex = i;
        }
    }

    cout << "��������������� � ������������ ��������: " << endl;
    cout << "����� ������: " << quadrilaterals[maxAreaIndex].calculatePerimeter() << endl;
    cout << "���������: " << quadrilaterals[maxAreaIndex].calculateDiagonal() << endl;
    cout << "��������: " << quadrilaterals[maxAreaIndex].calculatePerimeter() << endl;
    cout << "�������: " << quadrilaterals[maxAreaIndex].calculateArea() << endl;
    cout << "�������� �� ���������: " << (quadrilaterals[maxAreaIndex].isTrapezoid() ? "Да" : "Нет") << endl;

    return 0;
}
