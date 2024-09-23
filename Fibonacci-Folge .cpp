#include <iostream>

int fibonacci(int n) {
    if (n <= 2) {
        return 1;  
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  
}

int main() {
    int n = 15;
    std::cout << "The first " << n << " Fibonacci numbers are:" << std::endl;
    for (int i = 1; i <= n; ++i) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}