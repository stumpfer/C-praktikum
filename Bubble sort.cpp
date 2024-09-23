#include <iostream>
#include <random>  
#include <ctime>   

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 100); 

    int* array = new int[32];

    std::cout << "Unsortiertes Array: ";
    for (int i = 0; i < 32; ++i) {
        array[i] = distr(gen);
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    bubbleSort(array, 32);

    std::cout << "Sortiertes Array: ";
    for (int i = 0; i < 32; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}