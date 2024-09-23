#include <iostream>
#include <fstream>
#include <exception>
#include <string>

class nofileException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Die Datei existiert nicht";
    }
};

void read_file(const std::string& filename) {
    std::ifstream file(filename);  
    if (file.fail()) {  
        throw nofileException();  
    }

    std::string line;
    while (getline(file, line)) { 
        std::cout << line << std::endl;
    }

    file.close(); 
}

int main() {
    std::string filename;
    std::cout << "Bitte geben Sie den Dateinamen ein: ";
    std::getline(std::cin, filename);

    try {
        read_file(filename);
    } catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
    }

    return 0;
}