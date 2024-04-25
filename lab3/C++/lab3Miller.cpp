#include <iostream>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция для быстрого возведения числа a в степень b по модулю n
long long increaseDegree(long long a, long long b, long long n) {
    long long result = 1; // Инициализация результата
    a %= n; // Получение остатка от деления числа a на n
    while (b > 0) { // Пока степень b больше 0
        if (b % 2 == 1) { // Если степень b нечетная
            result = (result * a) % n; // Умножаем результат на a и берем остаток от деления на n
        }
        a = (a * a) % n; // Возводим a в квадрат и берем остаток от деления на n
        b /= 2; // Уменьшаем степень вдвое
    }
    return result; // Возвращаем результат
}

// Функция для проверки простоты числа по тесту Миллера
bool Miller(long long n, int t) {
    if (n <= 1 || n == 4) // Если n меньше или равно 1 или равно 4, то число не является простым
        return false;
    if (n <= 3) // Если n меньше или равно 3, то число простое
        return true;

    for (int i = 0; i < t; i++) { // Повторяем тест t раз
        long long a = 2 + rand() % (n - 4); // Генерируем случайное основание a в диапазоне (2, n-2)
        long long x = increaseDegree(a, n - 1, n); // Вычисляем a^(n-1) mod n
        if (x != 1) // Если a^(n-1) mod n не равно 1, то число n составное
            return false;
    }

    return true; // Если после t итераций для всех случайных оснований a число прошло тест, то оно вероятно простое
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL)); // Инициализация генератора случайных чисел

    long long n; // Число для проверки
    int t; // Параметр надежности
    set<int> q; // Множество оснований q

    cout << "Введите число для проверки (n): ";
    cin >> n;
    cout << "Введите параметр надежности (t): ";
    cin >> t;

    int q_size;
    cout << "Введите количество элементов множества q: ";
    cin >> q_size;
    cout << "Введите элементы множества q:\n";
    for (int i = 0; i < q_size; ++i) { // Заполнение множества q
        int elem;
        cin >> elem;
        q.insert(elem);
    }

    if (Miller(n, t)) // Проверка числа n на простоту
        cout << "n - простое число\n";
    else
        cout << "вероятно, n - составное число\n";

    return 0;
}
