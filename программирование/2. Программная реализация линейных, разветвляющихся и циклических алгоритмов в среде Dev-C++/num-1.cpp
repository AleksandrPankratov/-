#include <iostream>
#include <cmath>
 
int main() 
{
setlocale(LC_ALL, "Russian");
double a, b;
std::cout << "Введите значения переменных a и b: ";
std::cin >> a >> b;
double result = 8.15 * cbrt(b) * log(a) / (24.38 * cos(b) * (exp(a) - pow(a, a)));
std::cout << "Результат вычисления: " << result << std::endl;
return 0;
}
