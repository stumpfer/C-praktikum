#include <iostream>
#include <string>

std::string swapLetters(const std::string& word) {
    std::string result = word; 
    for (size_t i = 2; i < result.size(); i += 2) {
        std::swap(result[i-1], result[i]);
    }
    return result;
}

std::string removeVowels(const std::string& word) {
    std::string result;
    for (char letter : word) {
        if (letter != 'a' && letter != 'e' && letter != 'i' && letter != 'o' && letter != 'u') {
            result += letter;
        }
    }
    return result;
}

int main() {
    std::string word;
    
    std::cout << "Bitte geben Sie ein Wort ein: ";
    std::cin >> word;
    
    std::string swapped = swapLetters(word);
    std::cout << "Vertauschtes Wort: " << swapped << std::endl;
    
    std::string withoutVowels = removeVowels(word);
    std::cout << "Wort ohne Vokale: " << withoutVowels << std::endl;
    
    return 0;
}