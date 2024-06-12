#include <iostream>
using namespace std;

void findMaxMinBelowDiagonal(int arr[5][5]) {
    int maxElem = arr[1][0];
    int minElem = arr[1][0];

    for (int i = 2; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i][j] > maxElem) {
                maxElem = arr[i][j];
            }
            if (arr[i][j] < minElem) {
                minElem = arr[i][j];
            }
        }
    }

    cout << "Максимальный элемент ниже побочной диагонали: " << maxElem << endl;
    cout << "Минимальный элемент ниже побочной диагонали: " << minElem << endl;
}

int main() {
    int arr[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    findMaxMinBelowDiagonal(arr);

    return 0;
}
