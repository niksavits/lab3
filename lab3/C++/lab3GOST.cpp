#include <iostream>
#include <cmath>

using namespace std;

// Функция modPow выполняет возведение в степень по модулю.
long long modPow(long long a, long long b, long long m) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % m; // Если текущая степень нечетна, умножаем результат на основание и берем по модулю.
        a = (a * a) % m; // Умножаем основание на само себя и берем по модулю.
        b /= 2; // Уменьшаем степень вдвое.
    }
    return result;
}

// Функция isPrime проверяет, является ли число простым.
bool isPrime(long long p) {
    if (p <= 1) return false;
    if (p <= 3) return true;
    if (p % 2 == 0 || p % 3 == 0) return false;

    for (long long i = 5; i * i <= p; i += 6) {
        if (p % i == 0 || p % (i + 2) == 0) return false; // Проверяем делится ли число на i или i + 2 без остатка.
    }
    return true;
}

// Функция generateProvablePrime генерирует простое число по заданным параметрам.
long long generateProvablePrime(int t, long long q) {
    // Вычисляем начальное значение N.
    long long N = (1LL << (t - 1)) / q; // 1LL << (t - 1) - это эквивалент 2^(t - 1).
    if ((1LL << (t - 1)) % q != 0) N++; // Если 2^(t - 1) не делится на q без остатка, увеличиваем N.
    if (N % 2 != 0) N++; // Если N нечетное, увеличиваем его.

    long long u = 0, p;
    do {
        p = (N + u) * q + 1; // Вычисляем текущее простое число p.

        if (p >= (1LL << t)) { // Если p больше или равно 2^t, увеличиваем N и сбрасываем u.
            N += 2;
            u = 0;
            continue;
        }

        // Проверяем условия простоты Ферма и квадратичной вычетности.
        if (modPow(2, p - 1, p) == 1 && modPow(2, N + u, p) != 1) {
            if (isPrime(p)) { // Если число p простое, завершаем генерацию.
                break;
            }
        }
        u += 2; // Увеличиваем u для следующей итерации.
    } while (true);

    return p; // Возвращаем сгенерированное простое число.
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите размерность: " << endl;
    int t;
    cin >> t;
    cout << "Введите малое простое число: " << endl;
    long long q;
    cin >> q;

    long long p = generateProvablePrime(t, q); // Генерируем простое число.
    cout << "Сгенерированное простое число: " << p << endl; // Выводим результат.

    return 0;
}