#include <iostream>
#include <cmath>
 
int main() 
{
setlocale(LC_ALL, "Russian");
double a, b;
std::cout << "������� �������� ���������� a � b: ";
std::cin >> a >> b;
double result = 8.15 * cbrt(b) * log(a) / (24.38 * cos(b) * (exp(a) - pow(a, a)));
std::cout << "��������� ����������: " << result << std::endl;
return 0;
}
