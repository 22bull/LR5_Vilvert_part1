#ifndef _VILVERT_MATHTASK_H_
#define _VILVERT_MATHTASK_H_
#include <iostream>
#include <limits> // Для std::numeric_limits
#include <string> // Для std::stoi и обработки исключений

using namespace std;

// Функция контроля ввода целых чисел
int getValidatedIntegerInput(const string& prompt) {
    string input;
    int value;
    bool isValid = false;

    while (!isValid) {
        cout << prompt;
        getline(cin, input);

        try {
            size_t pos;
            value = stoi(input, &pos);

            // Проверяем, что вся строка была обработана (нет лишних символов)
            if (pos == input.size()) {
                isValid = true;
            } else {
                cout << "Ошибка: введены лишние символы. Пожалуйста, введите целое число.\n";
            }
        } catch (const invalid_argument&) {
            cout << "Ошибка: введено не число. Пожалуйста, введите целое число.\n";
        } catch (const out_of_range&) {
            cout << "Ошибка: число слишком большое или слишком маленькое. Пожалуйста, введите другое число.\n";
        }
    }

    return value;
}

// Метод ввода данных (ширины и высоты прямоугольника)
void inputRectangleDimensions(int& width, int& height) {
    cout << "Введите размеры прямоугольника:\n";
    width = getValidatedIntegerInput("Ширина: ");
    height = getValidatedIntegerInput("Высота: ");
}

// Метод вычисления площади прямоугольника
int calculateRectangleArea(int width, int height) {
    return width * height;
}
#endif