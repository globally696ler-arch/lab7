#include <algorithm>
#include <iostream>
#include <string>

bool isPalindrome(const std::string &text) {
  // Очистка букв, цифр, нижнего регистра
  std::string cleaned;
  for (char c : text) {
    // Проверяем, является ли символ буквой или цифрой
    if (std::isalnum(static_cast<unsigned char>(c))) {
      // Приводим к нижнему регистру и добавляем в очищенную строку
      cleaned += std::tolower(static_cast<unsigned char>(c));
    }
  }
  // Сравнение с реверсом
  std::string reversed = cleaned;
  // Разворачиваем копию строки
  std::reverse(reversed.begin(), reversed.end());
  // Сравниваем очищенную строку с её развёрнутой версией
  return cleaned == reversed;
}

int main() {
  std::string tests[] = {"А роза упала на лапу Азора", "Madam, I'm Adam",
                         "Hello< World!", "12321", "racecar"};

  // Проходим по каждому тестовому примеру
  for (const auto &text : tests) {
    std::cout << "'" << text << "' - "
              << (isPalindrome(text) ? "палиндром" : "не палиндром") << "\n";
  }
  return 0;
}