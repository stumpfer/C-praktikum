#include <iostream>

class square {
private:
    const double side_length;

public:
    square(double length): side_length(length) {}

    square(const square& other): side_length(other.side_length) {}

    double getLength() const {
        return side_length;
    }

    double getArea() const {
        return side_length * side_length;
    }

    double getPerimeter() const {
        return 4 * side_length;
    }

    square operator+(const square& other) const {
        return square(this->side_length + other.side_length);
    }

    square operator-(const square& other) const {
        double new_length = (this->side_length > other.side_length) ? (this->side_length - other.side_length) : 0;
        return new_length;
    }

    friend std::ostream &operator<<(std::ostream& os, const square& sq) {
        os << "Quadrat: Kantenlaenge=" << sq.getLength()
           << ", Flaesche=" << sq.getArea()
           << ", Umfang=" << sq.getPerimeter();
        return os;
    }
};

int main() {
    square sq1(6.0);
    square sq2(7.0);

    std::cout << sq1 << std::endl;
    std::cout << sq2 << std::endl;

    square sq3 =sq1;
    std::cout << "Copy of sq1:" << sq3 << std::endl;

    square sq4 = sq1 + sq2;
    std::cout << "sq1 + sq2: " << sq4 << std::endl;

    square sq5 = sq1 - sq2;
    std::cout << "sq1 - sq2: " << sq5 << std::endl;

    return 0;
}