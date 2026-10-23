import re


def extract_and_sum(text: str):
    """Извлекает числа и возвращает их список и сумму."""
    # Регулярное выражение для поиска чисел (последовательности цифр)
    numbers = re.findall(r"\d+", text)

    # Проверка: найдены ли числа
    if not numbers:
        return [], 0

    # Преобразуем строки в целые числа
    int_numbers = [int(n) for n in numbers]
    return int_numbers, sum(int_numbers)


if __name__ == "__main__":
    # Тестовые данные
    text = (
        "В 2023 году студент сдал 3 экзамена и получил 45 баллов, а также 12 бонусов."
    )

    print(f"Исходный текст: {text}\n")

    numbers, total = extract_and_sum(text)

    # Проверки и вывод
    if numbers:
        print(f"Найденные числа: {numbers}")
        print(f"Сумма всех чисел: {total}")
    else:
        print("Числа в тексте не найдены.")

    # Дополнительный тест: пустая строка (краевой случай)
    print("\n--- Дополнительный тест (пустая строка) ---")
    numbers2, total2 = extract_and_sum("")
    if not numbers2:
        print("Числа в тексте не найдены.")
