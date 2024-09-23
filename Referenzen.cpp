#include <iostream>

void swap(int &a, int &b) {
    int temp = a;  
    a = b;       
    b = temp;    
}

int main() {
    int x = 5;
    int y = 10;

    std::cout << "Vor dem Tausch: x = " << x << ", y = " << y << std::endl;

    swap(x, y);

    std::cout << "Nach dem Tausch: x = " << x << ", y = " << y << std::endl;

    return 0;
}