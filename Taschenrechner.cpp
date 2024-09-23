#include <iostream>
#include <limits>

double readNumber() {
    double number = 0;
    std::cout << "Bitte geben Sie eine Zahl ein: ";
    std::cin >> number;

    while (std::cin.fail()) {
        std::cout << "Fascheingabe:Bitte wirkliche Zahl eingeben" << std::endl;
        std::cin.clear();
        std::numeric_limits<std::streamsize>::max();
        std::cin >> number;
    }
    return number;
}

char readOperator() {
    char op;
    std::cout << "Bitte geben Sie einen Operator ein (+, -, *, /): ";
    std::cin >> op;
    
    while (op != '+' && op != '-' && op != '*' && op != '/') {
        std::cout << "Ungültiger Operator! Bitte geben Sie einen gültigen Operator ein (+, -, *, /): " << std::endl;
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cin >> op; 
    }
    return op; 
}

int main() {
    double num1, num2, result;
    char op;
    num1 = readNumber();
    op = readOperator();
    num2 = readNumber();
    switch (op) {
        case '+':
            result = num1+num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Fehler: Division durch 0 ist nicht erlaubt.\n";
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            std::cout << "Ungültiger Operator.\n";
            return 1;
    }

    std::cout << "Das Ergebnis der Berechung" << num1 << " " << op << " " << num2 << " ist: " << result << std::endl;
    return 0;
}