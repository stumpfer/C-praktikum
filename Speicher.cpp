#include <iostream>

int main() {

    int* iHeap = new int[100000000]; 

    delete[] iHeap;

    return 0;
}