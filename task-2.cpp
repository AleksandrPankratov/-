#include <stdio.h> 
#include <iostream>
int main() 
{
setlocale(LC_ALL, "Russian");
float x, y;
printf("������� ���������� x: ");
scanf("%f", &x);
printf("������� ���������� y: ");
scanf("%f", &y);
if (x >= 1 && x <= 2 && y >= 1 && y <= 2 || y <= -1 && y >= -2 ) {
printf("����� ����������� �������������� �������\n");
} 
else {
printf("����� �� ����������� �������������� �������\n");
}
return 0;
}
