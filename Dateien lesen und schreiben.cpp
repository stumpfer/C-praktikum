#include <iostream>
#include <fstream>
#include <string>

void read_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " <<filename << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void write_file(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    
    std::string input;
    std::cout << "Enter text to append to the file (type 'exit' to finish):" << std::endl;
    while (true) {
        std::getline(std::cin, input);
        if (input == "exit") { 
            break;
        }
        file << input << std::endl; 
    }

    file.close();  
}

int main() {
    std::string filename;
    std::cout << "Please enter the file name: ";
    std::getline(std::cin, filename);

    std::cout << "\nFile contents before appending text:\n";
    read_file(filename);

    write_file(filename);

    std::cout << "\nFile contents after appending text:\n";
    read_file(filename);

    return 0;
}