#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  // Исходный текст
  std::string text = "В 2023 году студент сдал 3 экзамена и получил 45 баллов, "
                     "а также 12 бонусов.";

  std::cout << "Исходный текст: " << text << "\n\n";
  std::cout << "Найденные числа: ";

  long long sum = 0;       // Сумма всех чисел
  std::string numStr = ""; // Буфер для текущего числа
  bool hasNumbers = false; // Флаг: найдено ли хоть одно число

  // Проходим по каждому символу
  for (size_t i = 0; i < text.length(); ++i) {
    char c = text[i];

    if (std::isdigit(static_cast<unsigned char>(c))) {
      numStr += c; // Накапливаем цифры
    } else {
      // Если встретили не цифру, но буфер не пуст — значит число закончилось
      if (!numStr.empty()) {
        long long number = std::stoll(numStr); // Преобразуем в число
        std::cout << number << " ";            // Выводим найденное число
        sum += number;                         // Добавляем к сумме
        numStr.clear();                        // Очищаем буфер
        hasNumbers = true;
      }
    }
  }

  // Проверка: если текст заканчивается цифрой, последнее число не было
  // обработано
  if (!numStr.empty()) {
    long long number = std::stoll(numStr);
    std::cout << number << " ";
    sum += number;
    hasNumbers = true;
  }

  std::cout << "\n\n";

  // Проверка: были ли вообще числа в тексте
  if (hasNumbers) {
    std::cout << "Сумма всех чисел: " << sum << "\n";
  } else {
    std::cout << "Числа в тексте не найдены.\n";
  }

  return 0;
}