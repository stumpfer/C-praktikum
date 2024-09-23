#include <iostream>

int factorialIter(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int factorialRec(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRec(n - 1); 
}

int main() {
    int number = 5;
    std::cout << "Iterative factorial of " << number << " is: " << factorialIter(number) << std::endl;
    std::cout << "Recursive factorial of " << number << " is: " << factorialRec(number) << std::endl;
    return 0;
}