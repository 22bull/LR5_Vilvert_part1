#include <iostream>
#include <limits> // Для std::numeric_limits
#include <string> // Для std::stoi и обработки исключений
#include "Vilvert_MathTask.h"
int main() {
    int width, height;

    // Ввод данных с проверкой
    inputRectangleDimensions(width, height);

    // Проверка на неотрицательные значения
    while (width <= 0 || height <= 0) {
        cout << "Ошибка: ширина и высота должны быть положительными числами.\n";
        inputRectangleDimensions(width, height);
    }

    // Вычисление и вывод площади
    int area = calculateRectangleArea(width, height);
    cout << "Площадь прямоугольника: " << area << endl;

    return 0;
}