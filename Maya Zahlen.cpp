#include <iostream>
#include <vector>

void decimalToMaya(int decimalNumber) {
    std::vector<int> mayaDigits;

    while (decimalNumber > 0) {
        int remainder = decimalNumber % 20;  
        mayaDigits.push_back(remainder);     
        decimalNumber /= 20;         
    }

    std::cout << "Maya Zahl (von unten nach oben gelesen): " << std::endl;
    for (int i = mayaDigits.size() - 1; i >= 0; --i) {
        std::cout << mayaDigits[i] << std::endl;
    }
}

int main() {
    int decimalNumber;

    std::cout << "Bitte geben Sie eine Zahl im Dezimalsystem ein: ";
    std::cin >> decimalNumber;

    if (decimalNumber < 0) {
        std::cout << "Ungültige Eingabe! Bitte geben Sie eine positive Zahl ein." << std::endl;
        return 1;
    }
    if (decimalNumber == 0) {
        std::cout << "Maya Zahl: 0" << std::endl;
    } else {
        decimalToMaya(decimalNumber);
    }

    return 0;
}