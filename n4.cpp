#include <iostream>
#include <regex>
#include <string>

// Проверка email по шаблону: локальная часть + @ + домен с точкой и зоной
bool validateEmail(const std::string &email) {
  // Шаблон: начало строки, 1+ символов [\w.+-], @, домен [\w-], точка, зона
  // [\w.-], конец строки
  std::regex pattern(R"(^[\w.+-]+@[\w-]+\.[\w.-]+\$)");
  return std::regex_match(email, pattern);
}

// Проверка телефона в формате РФ: +7, далее 10 цифр с разделителями (скобки,
// пробелы, дефисы)
bool validatePhone(const std::string &phone) {
  // Шаблон:'+7', затем 3 цифры (в скобках или нет), далее 3+2+2 цифры с
  // опциональными разделителями
  std::regex pattern(
      R"(^\+?7[\s-]?$?\d{3}$?[\s-]?\d{3}[\s-]?\d{2}[\s-]?\d{2}\$)");
  return std::regex_match(phone, pattern);
}

// Проверка URL: http/https, домен, опциональный путь
bool validateUrl(const std::string &url) {
  // Шаблон: http/https, ://, домен (буквы, цифры, точки, дефисы), точка, зона
  // 2+ буквы, опциональный путь
  std::regex pattern(R"(^https?://[\w.-]+\.[a-z]{2,}(/[\w./-]*)?\$)");
  return std::regex_match(url, pattern);
}

int main() {
  std::cout << std::boolalpha; // выводить true/false вместо 1/0

  // Тестируем email: корректный пример
  std::cout << "Email valid: " << validateEmail("ivan@example.com")
            << "\n"; // true

  // Тестируем email: некорректный пример (нет домена)
  std::cout << "Email invalid: " << validateEmail("invalid@") << "\n"; // false

  // Тестируем телефон: корректный пример в формате РФ
  std::cout << "Phone valid: " << validatePhone("+7 (999) 123-45-67")
            << "\n"; // true

  // Тестируем URL: корректный пример
  std::cout << "URL valid: " << validateUrl("https://example.com")
            << "\n"; // true

  return 0;
}
