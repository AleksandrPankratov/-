#include <iostream>
#include <fstream>

int main() {
  int r;

  std::ifstream inputFile("r.txt");
  if (inputFile.is_open()) {
    inputFile >> r;
    inputFile.close();

    int x = r / 3;

    std::ofstream outputFile("stepen.txt");
    if (outputFile.is_open()) {
      outputFile << x;
      outputFile.close();

      std::cout << "Максимальное значение x: " << x << std::endl;
    } else {
      std::cout << "Ошибка открытия файла stepen.txt для записи" << std::endl;
    }
  } else {
    std::cout << "Ошибка открытия файла r.txt для чтения" << std::endl;
  }

  return 0;
}
