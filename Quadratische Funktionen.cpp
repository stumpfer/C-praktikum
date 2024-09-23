#include <iostream>
#include <cmath>  

bool solveQuadraticEquation(double a, double b, double c, double* root1, double* root2) {
    double discriminant = b * b - 4 * a * c; 
    
    if (discriminant < 0) {
        return false;
    } else if (discriminant == 0) {
        *root1 = -b / (2 * a);
        *root2 = *root1;  
    } else {
        *root1 = (-b + sqrt(discriminant)) / (2 * a);
        *root2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    
    return true;
}

int main() {
    double a, b, c;
    double x1, x2;
    
    std::cout << "Geben Sie die Koeffizienten a, b und c für die quadratische Gleichung (ax^2 + bx + c = 0) ein: ";
    std::cin >> a >> b >> c;
    
    if (solveQuadraticEquation(a, b, c, &x1, &x2)) {
        if (x1 == x2) {
            std::cout << "Die Gleichung hat eine reelle Lösung: x = " << x1 << std::endl;
        } else {
            std::cout << "Die Gleichung hat zwei reelle Lösungen: x1 = " << x1 << ", x2 = " << x2 << std::endl;
        }
    } else {
        std::cout << "Die Gleichung hat keine reellen Lösungen." << std::endl;
    }
    
    return 0;
}