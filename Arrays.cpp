#include <iostream>
#include <random>  
#include <ctime>    
int main() {
    std::random_device rd;                
    std::mt19937 gen(rd());              
    std::uniform_int_distribution<> distr(0, 100); 

    int *array = new int[100000];

    for (int i = 0; i < 100000; ++i) {
        array[i] = distr(gen);  
    }

    int divisibleBy13 = 0;
    for (int i = 0; i < 100000; ++i) {
        if (array[i] % 13 == 0) {
            divisibleBy13++;
        }
    }

    std::cout << "Anzahl der durch 13 teilbaren Zahlen: " << divisibleBy13 << std::endl;

    delete[] array;

    return 0;
}