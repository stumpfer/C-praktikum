#include <iostream>
#include <string>

bool isPalindrom(const std::string& word) {
    int length = word.size();
    
    for (int i = 0; i < length / 2; ++i) {
        if (word[i] != word[length - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string word;
    
    std::cout << "Geben Sie ein Wort ein: ";
    std::cin >> word;
    
    if (isPalindrom(word)) {
        std::cout << word << " ist ein Palindrom." << std::endl;
    } else {
        std::cout << word << " ist kein Palindrom." << std::endl;
    }
    
    return 0;
}