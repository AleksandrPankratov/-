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

      std::cout << "������������ �������� x: " << x << std::endl;
    } else {
      std::cout << "������ �������� ����� stepen.txt ��� ������" << std::endl;
    }
  } else {
    std::cout << "������ �������� ����� r.txt ��� ������" << std::endl;
  }

  return 0;
}
