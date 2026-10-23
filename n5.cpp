#include <iomanip> // для манипуляторов форматирования (setw, fixed, setprecision)
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

int main() {
  // Вектор кортежей: (имя, возраст, средний балл)
  std::vector<std::tuple<std::string, int, double>> students = {
      {"Иван", 25, 4.5},
      {"Мария", 22, 4.85},
      {"Петр", 30, 4.2},
      {"Анна", 20, 4.95}};

  // Заголовок
  // выравнивание по левому краю для имени, по правому — для чисел
  std::cout << std::left << std::setw(10) << "Имя" << std::right << std::setw(8)
            << "Возраст" << std::setw(8) << "Балл" << "\n";
  // Разделительная линия
  std::cout << std::string(28, '-') << "\n";

  // Данные
  // Настройка формата вывода чисел: фиксированная точка, 2 знака после запятой
  std::cout << std::fixed << std::setprecision(2);
  double totalGpa = 0;
  // Перебор студентов с распаковкой кортежа в переменные name, age, gpa
  for (const auto &[name, age, gpa] : students) {
    std::cout << std::left << std::setw(10) << name << std::right
              << std::setw(8) << age << std::setw(8) << gpa << "\n";
    totalGpa += gpa; // накопление суммы баллов
  }

  // Итого
  // Итоговая разделительная линия
  std::cout << std::string(28, '-') << "\n";
  // Вычисление среднего балла
  double avgGpa = totalGpa / students.size();
  // Вывод строки со средним баллом
  std::cout << std::left << std::setw(10) << "Средний балл" << std::right
            << std::setw(8) << "" << std::setw(8) << avgGpa << "\n";

  return 0;
}