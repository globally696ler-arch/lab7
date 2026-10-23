#include <cctype>
#include <iostream>
#include <string>

int main() {
  // Исходный текст с целыми, дробными и отрицательными числами
  std::string text = "В 2023 году температура упала до -5 градусов, а затем "
                     "поднялась до 3.5. Прибыль -100.25 рублей.";

  std::cout << "Исходный текст: " << text << "\n\n";
  std::cout << "Найденные числа: ";

  double sum = 0.0;        // Используем double для дробных чисел
  std::string numStr = ""; // Буфер текущего числа
  bool hasNumbers = false;

  for (size_t i = 0; i < text.length(); ++i) {
    char c = text[i];

    // 1. Если это цифра — добавляем в буфер
    if (std::isdigit(static_cast<unsigned char>(c))) {
      numStr += c;
    }
    // 2. Если это точка И после неё идет цифра (дробная часть)
    else if (c == '.' && i + 1 < text.length() &&
             std::isdigit(static_cast<unsigned char>(text[i + 1]))) {
      numStr += c;
    }
    // 3. Если это минус И следующий символ — цифра (начало отрицательного
    // числа)
    else if (c == '-' && i + 1 < text.length() &&
             std::isdigit(static_cast<unsigned char>(text[i + 1]))) {
      // Если в буфере уже есть число, сохраняем его перед началом нового
      if (!numStr.empty()) {
        double number = std::stod(numStr);
        std::cout << number << " ";
        sum += number;
        numStr.clear();
        hasNumbers = true;
      }
      numStr += c; // Начинаем новое число с минуса
    }
    // 4. Любой другой символ (пробел, буква, запятая) — завершаем число
    else {
      if (!numStr.empty()) {
        double number = std::stod(numStr);
        std::cout << number << " ";
        sum += number;
        numStr.clear();
        hasNumbers = true;
      }
    }
  }

  // Обработка последнего числа в строке (если текст заканчивается цифрой)
  if (!numStr.empty()) {
    double number = std::stod(numStr);
    std::cout << number << " ";
    sum += number;
    hasNumbers = true;
  }

  std::cout << "\n\n";

  if (hasNumbers) {
    std::cout << "Сумма всех чисел: " << sum << "\n";
  } else {
    std::cout << "Числа в тексте не найдены.\n";
  }

  return 0;
}
