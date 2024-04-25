#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

long long buildF(const set<long>& q) {
    long long F = 1;
    for (auto it = q.begin(); it != q.end(); ++it) {
        F *= (*it);
    }
    return F;
}

long long buildN(long long R, long long F) {
    return R * F + 1;
}

long long buildR(long long F) {
    return (rand() % (F / 2)) * 2 + 2; // Генерируем четное случайное число меньше F
}

long long buildA(long long n) {
    return 2 + rand() % (n - 3); // Выбираем случайное число a в интервале (2, n-2)
}

long long power(long long a, long long b, long long n) {
    long long result = 1;
    a %= n;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % n;
        }
        b >>= 1;
        a = (a * a) % n;
    }
    return result;
}

bool PoklingtonTest(long long n, int t, const set<long>& q) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    long long F = buildF(q);
    for (int i = 0; i < t; ++i) {
        long long R = buildR(F);
        long long constructed_n = buildN(R, F);
        long long a = buildA(n);
        long long x = power(a, F * R, constructed_n);
        if (x != 1) {
            return false;
        }
        x = power(a, F, constructed_n);
        if (x == 1 || x == constructed_n - 1) {
            return false;
        }
        for (long long j : q) {
            x = power(a, F * j, constructed_n);
            if (x == 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    set<long> q;

    cout << "Введите число для проверки (n): ";
    long long n;
    cin >> n;

    int t;
    cout << "Введите параметр надежности (t): ";
    cin >> t;

    int q_size;
    cout << "Введите количество элементов множества q: ";
    cin >> q_size;
    cout << "Введите элементы множества q:\n";

    for (int i = 0; i < q_size; ++i) { // Заполнение множества q
        long elem;
        cin >> elem;
        q.insert(elem);
    }

    if (PoklingtonTest(n, t, q)) {
        cout << "Вероятно, что " << n << " - простое число." << endl;
    } else {
        cout << n << " - составное число." << endl;
    }

    return 0;
}