#include <iostream>
#include <vector>
using namespace std;

// Функция для нахождения всех делителей числа
vector<int> findDivisors(int n) {
    vector<int> divisors; // Вектор для хранения делителей
    for (int i = 1; i <= n; ++i) { // Перебор всех чисел от 1 до n
        if (n % i == 0) { // Если число делится на i без остатка
            divisors.push_back(i); // Добавляем i в вектор делителей
        }
    }
    return divisors; // Возвращаем вектор делителей
}

int main() {
    int number;
    cout << "Введите число: ";
    cin >> number;

    vector<int> divisors = findDivisors(number);

    cout << "Делители числа " << number << ": ";
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}
