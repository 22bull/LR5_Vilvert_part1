#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include "Vilvert_MathTask.h"
using namespace cute;
using namespace std;
void testCalcRectangleArea()
{      int a = 3;
      int b = 5;      int expected = 15;
      int actual = CalcRectangleArea(a, b);      
      ASSERT_EQUAL(expected, actual);
}
void testUserInput_Empty()
{
    string str = "";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}
void testUserInput_Letter()
{
    string str = "a";
    bool expected = false;
    bool actual = UserInput(str);

}
// Тест, проверяющий отсев цифро-буквенных значений
void testUserInput_DigitLetterValue() {
    // Исходные данные
    string str = "5a";
    // Ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // Получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // Сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}
// Тест, проверяющий отсев отрицательных значений
void testUserInput_NegativeValue() {
    // Исходные данные
    string str = "-5";
    // Ожидаемое значение результата работы функции UserInput
    bool expected = false;

    // Получение значения с помощью тестируемого метода
    bool actual = UserInput(str);

    // Сравнение ожидаемого результата с полученным
    ASSERT_EQUAL(expected, actual);
}
int main() {
    // Создаем тестовый набор
    suite s;

    // Добавляем тестовые функции в набор
    s.push_back(CUTE(testCalcRectangleArea));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_NegativeValue));
    s.push_back(CUTE(testUserInput_DigitLetterValue));

    // Создаем listener и runner
    ide_listener<> listener;
    makeRunner(listener)(s, "All Rectangle Tests");

    return 0;
}