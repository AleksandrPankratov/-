#include <stdio.h> 
#include <iostream>
int main() 
{
setlocale(LC_ALL, "Russian");
float x, y;
printf("Введите координату x: ");
scanf("%f", &x);
printf("Введите координату y: ");
scanf("%f", &y);
if (x >= 1 && x <= 2 && y >= 1 && y <= 2 || y <= -1 && y >= -2 ) {
printf("Точка принадлежит заштрихованной области\n");
} 
else {
printf("Точка не принадлежит заштрихованной области\n");
}
return 0;
}
