#include <iostream>
#include <string>

class Vehicle {
public:
    enum Color {
        Blau, Rot, Gruen, Weiss, Schwarz
    };

private:
    Color m_color;
    double m_price;
    int m_year;
    int m_ID;

    static int s_nextID;

public:
    Vehicle(Color color, double price, int year)
        : m_color(color), m_price(price), m_year(year), m_ID(s_nextID++) {}

    std::string getColor() const {
        switch (m_color) {
            case Blau: return "Blau";
            case Rot: return "Rot";
            case Gruen: return "Gruen";
            case Weiss: return "Weiss";
            case Schwarz: return "Schwarz";
            default: return "Unbekannt";
        }
    }

    double getPrice() const {
        return m_price;
    }

    int getYear() const {
        return m_year;
    }

    int getID() const {
        return m_ID;
    }

    static bool isOldtimer(const Vehicle& vehicle) {
        return vehicle.getYear() < 1980;
    }
};

int Vehicle::s_nextID = 1;

int main() {
    Vehicle car1(Vehicle::Rot, 15000.0, 1975);
    Vehicle car2(Vehicle::Blau, 25000.0, 1995);

    std::cout << "Car 1: " << car1.getColor() << ", Price: " << car1.getPrice() 
              << ", Year: " << car1.getYear() << ", ID: " << car1.getID() << std::endl;
    
    std::cout << "Car 2: " << car2.getColor() << ", Price: " << car2.getPrice() 
              << ", Year: " << car2.getYear() << ", ID: " << car2.getID() << std::endl;

    std::cout << "Car 1 is oldtimer: " << (Vehicle::isOldtimer(car1) ? "Yes" : "No") << std::endl;
    std::cout << "Car 2 is oldtimer: " << (Vehicle::isOldtimer(car2) ? "Yes" : "No") << std::endl;
}