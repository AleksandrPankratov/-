#include <iostream>
#include <cmath>

int main() 
{
setlocale(LC_ALL, "Russian");
double e;
std::cout << "Введите значение точности e: ";
std::cin >> e;
double sum = 0.0; 
double term = 0.0; 
int n = 0;
do {
term = (n + 5) / pow(2, n + 2);
sum += term;
n++;
} 
while (term >= e);
printf("Сумма ряда: %.6f\n", sum);
return 0;
}


