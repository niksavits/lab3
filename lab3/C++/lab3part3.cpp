#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

// Функция для моделирования остывания кофе
double coffeeCooling(double T_env, double T_initial, double k, double time) {
    return T_env + (T_initial - T_env) * exp(-k * time);
}

// Функция для вычисления коэффициентов a и b линейной аппроксимации
pair<double, double> linearApproximation(const vector<double>& x, const vector<double>& y) {
    double x_sum = accumulate(x.begin(), x.end(), 0.0);
    double y_sum = accumulate(y.begin(), y.end(), 0.0);
    double xy_sum = 0.0;
    double x2_sum = 0.0;
    int n = x.size();

    for (int i = 0; i < n; ++i) {
        xy_sum += x[i] * y[i];
        x2_sum += x[i] * x[i];
    }

    double a = (n * xy_sum - x_sum * y_sum) / (n * x2_sum - x_sum * x_sum);
    double b = (y_sum - a * x_sum) / n;

    return {a, b};
}

// Функция для вычисления коэффициента корреляции
double correlationCoefficient(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    double mean_x = accumulate(x.begin(), x.end(), 0.0) / n;
    double mean_y = accumulate(y.begin(), y.end(), 0.0) / n;
    double s_xy = 0.0;
    double s_xx = 0.0;
    double s_yy = 0.0;

    for (int i = 0; i < n; ++i) {
        s_xy += (x[i] - mean_x) * (y[i] - mean_y);
        s_xx += (x[i] - mean_x) * (x[i] - mean_x);
        s_yy += (y[i] - mean_y) * (y[i] - mean_y);
    }

    double r = s_xy / (sqrt(s_xx * s_yy));
    return r;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double T_env, T_initial, k;
    cout << "Введите температуру окружающей среды, начальную температуру кофе и коэффициент остывания: ";
    cin >> T_env >> T_initial >> k;

    // Введите общее время остывания и интервал уменьшения температуры
    double total_time, interval;
    cout << "Введите общее время остывания (в минутах): ";
    cin >> total_time;
    cout << "Введите интервал уменьшения температуры (в минутах): ";
    cin >> interval;

    // Вычисление времени и температуры для каждого интервала
    cout << "Время (мин)\tТемпература (C)" << endl;
    for (double time = 0; time <= total_time; time += interval) {
        double temperature = coffeeCooling(T_env, T_initial, k, time);
        cout << time << "\t\t" << setprecision(4) << temperature << endl;
    }

    return 0;
}
