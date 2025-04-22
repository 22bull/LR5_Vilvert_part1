#ifndef _SURNAME_MATHTASK_H
#define _SURNAME_MATHTASK_H

#include <string>
using namespace std;

// Функция контроля вводимых данных
bool UserInput(string input) {
    // Если строка пустая - ввод некорректен
    if (input.empty()) return false;
    // Попытаться
    try {
        // Преобразование введенного значения в тип
        int number = stoi(input);
    }
    catch (...) // Если возникла ошибка в блоке try
    { return false; }
    return true;
}// Метод ввода данных
void EnterDigit(int& varLink, const string& label) {
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    while (!UserInput(raw_input)) {
        cout << label << " = ";
        getline(cin, raw_input);
    }
    varLink = stoi(raw_input);
}

// Вычисление площади прямоугольника
int CalcRectangleArea(int NumberA, int NumberB) {
    return NumberA * NumberB;
}
#endif