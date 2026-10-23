#include <iostream>
#include <string>

std::string caesarCipher(const std::string &text, int shift) {
  std::string result = text; // копируем входную строку
  for (char &c : result) {
    // Обрабатываем только буквы
    if (std::isalpha(static_cast<unsigned char>(c))) {
      // Определяем базовый символ: 'A' для заглавных, 'a' для строчных
      char base = std::isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
      // Нормализуем сдвиг к диапазону [0, 25], корректно работая с
      // отрицательными значениями
      c = (c - base + shift % 26 + 26) % 26 + base;
    }
  }
  return result;
}

int main() {
  std::string original = "Hello< World!";
  // Шифруем со сдвигом 3
  std::string encrypted = caesarCipher(original, 3);
  // Расшифровываем обратным сдвигом −3 (то же самое, что сдвиг 23)
  std::string decrypted = caesarCipher(encrypted, -3);

  std::cout << "Оригинал: " << original << "\n";
  std::cout << "Зашифровано: " << encrypted << "\n";
  std::cout << "Расшифровано: " << decrypted << "\n";

  return 0;
}