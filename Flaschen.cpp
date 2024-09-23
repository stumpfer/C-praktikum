#include <iostream>
#include <string>

class Flasche {
private:
    double dVolumen;
    std::string sMaterial;

public:
    Flasche() : dVolumen(0.0), sMaterial("Unbekannt") {}
    double getVolumen() const {
        return dVolumen;
    }

    std::string getMaterial() const {
        return sMaterial;
    }

    void setVolumen(double volumen) {
        dVolumen = volumen;
    }

    void setMaterial(const std::string &material) {
        sMaterial = material;
    }

    void printFlasche() const {
        std::cout << "Volumen: " << dVolumen << " Liter" << std::endl;
        std::cout << "Material: " << sMaterial << std::endl;
    }

    void adoptFlasche(const Flasche &andereFlasche) {
        dVolumen = andereFlasche.getVolumen();
        sMaterial = andereFlasche.getMaterial();
    }
};

int main() {
    Flasche flasche1;
    Flasche flasche2;

    flasche1.setVolumen(1.5);
    flasche1.setMaterial("Glas");

    flasche2.setVolumen(0.75);
    flasche2.setMaterial("Plastik");

    std::cout << "Flasche 1:" << std::endl;
    flasche1.printFlasche();

    std::cout << "Flasche 2:" << std::endl;
    flasche2.printFlasche();

    flasche1.adoptFlasche(flasche2);

    std::cout << "Nach der Anwendung von adoptFlasche() auf Flasche 1:" << std::endl;
    flasche1.printFlasche();

    return 0;
}

