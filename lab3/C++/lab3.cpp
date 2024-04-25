#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double dx, y, x;
    cout << "Enter a step: ";
    cin >> dx;
    cout << setw(3) << "y" << " " << setw(3) << "x" << endl;

    for (x = -6; x <= -2; x += dx) { //парабола
        y = -(x * x) - 7 * x - 10;
        cout << fixed << setprecision(3) << y << " " << setw(3) << x << endl;
    }
    cout << "___________" << endl;

    for (x = -2; x <= 2; x += dx) { //окружность
        double r = 2;
        y = sqrt(r * r - x* x);
        cout << fixed << setprecision(3) << y << " " << setw(3) << x << endl;
    }
    cout << "___________" << endl;

    for (x = 2; x <= 8; x += dx) { //логарифм
        y = log2(x) -1;
        cout << fixed << setprecision(3) << y << " " << setw(3) << x << endl;
    }
    cout << "___________" << endl;

    for (x = 8; x <= 9; x +=dx) {
        y = -2 * x + 18;
        cout << fixed << setprecision(3) << y << " " << setw(3) << x << endl;
    }
    return 0;
}
