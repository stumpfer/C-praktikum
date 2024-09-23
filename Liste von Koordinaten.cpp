#include <iostream>
#include <list>
#include <cstdlib> 
#include <ctime>   

struct coord {
    float x, y;
    coord(float xVal, float yVal) : x(xVal), y(yVal) {}
};

void printlist(const std::list<coord>& coordinates) {
    for (const auto& c : coordinates) {
        std::cout << "X: " << c.x << ", Y: " << c.y << std::endl;
    }
}
void delcoords(std::list<coord>& coordinates) {
    for (auto it = coordinates.begin(); it != coordinates.end(); ) {
        if (it->x < it->y) {
            it = coordinates.erase(it);  
        } else {
            ++it; 
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::list<coord> coordList;
    
    for (int i = 0; i < 10; ++i) {
        float x = static_cast<float>(std::rand() % 100) / 10.0f; 
        float y = static_cast<float>(std::rand() % 100) / 10.0f; 
        coordList.emplace_back(x, y);  
    }

    std::cout << "Initial List of Coordinates:" << std::endl;
    printlist(coordList);

    std::list<coord> backupList = coordList;

    delcoords(coordList);

    std::cout << "\nModified List (after deleting x < y):" << std::endl;
    printlist(coordList);

    std::cout << "\nBackup List:" << std::endl;
    printlist(backupList);

    return 0;
}