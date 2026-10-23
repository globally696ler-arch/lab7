import re


def extract_and_sum(text: str):
    # Извлекает числа и возвращает их список и сумму.
    # Регулярное выражение для поиска чисел (последовательности цифр)
    numbers = re.findall(r"-?\d+(?:\.\d+)?", text)
    # Проверка: найдены ли числа
    if not numbers:
        return [], 0
    # Преобразуем строки в целые числа
    float_numbers = [float(n) for n in numbers]
    return float_numbers, sum(float_numbers)


text = "В 2023 году температура упала на -3.5 градуса, а затем поднялась на 15, прибыль составила 1029 рублей."
print(f"Исходный текст: {text}\n")
numbers, total = extract_and_sum(text)
# Проверки и вывод
if numbers:
    print(f"Найденные числа: {numbers}")
    print(f"Сумма всех чисел: {total}")
else:
    print("Числа в тексте не найдены.")
