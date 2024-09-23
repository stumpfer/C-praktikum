#include <iostream>
#include <cmath>

double heron_ite(double a, double x0, int iterations) {
    double x = x0;
    for (int i=0; i < iterations; ++i) {
        x = ( x + a / x) / 2.0;
    }
    return x;
}

int main() {
    double a;
    int iterations  = 10;
    double x0 = 1.0;

    std::cout << "Bitte geben Sie eine Zahl ein, deren Quadratwurzel berechnet werden soll: ";
    std::cin >> a;

    double result = heron_ite(a, x0, iterations);
    std::cout << "Die berechnete Quadratwurzel von " << a << " ist: " << result << std::endl;

    return 0;
}