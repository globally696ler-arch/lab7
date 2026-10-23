#include <iostream>
#include <sstream>
#include <string>
int countWords(const std::string &text) {
  std::istringstream iss(text); // создаём поток для чтения слов из строки
  std::string word;             // сюда будем считывать каждое слово по очереди
  int count =
      0; // счётчик слов
         // Пока из потока можно считать очередное слово, увеличиваем счётчик
  while (iss >> word) {
    ++count;
  }
  return count;
}

int main() {
  std::string text; // переменная для хранения введённого пользователем текста
  std::cout << "Введите текст: ";
  std::getline(std::cin, text); // читаем всю строку целиком (включая пробелы)

  std::cout << "Количество слов: " << countWords(text) << "\n";
  return 0;
}