#include <iostream>
#include <string>

class Person {
private:
    std::string m_sName;
    std::string m_sSurname;
    int m_iAge;

public:
    Person(std::string sName, std::string sSurname, int iAge)
        : m_sName(sName), m_sSurname(sSurname), m_iAge(iAge) {}

    Person() : m_sName(""), m_sSurname(""), m_iAge(0) {}

    virtual std::string getName() const {
        return m_sName;
    }

    std::string getSurname() const {
        return m_sSurname;
    }

    int getAge() const {
        return m_iAge;
    }

    bool setAge(int iAge) {
        if (iAge > 0) {
            m_iAge = iAge;
            return true;
        }
        return false;
    }
};

class Student : public Person {
private:
    unsigned int m_uiStudentID;

public:
    Student(std::string sName, std::string sSurname, int iAge, unsigned int uiStudentID)
        : Person(sName, sSurname, iAge), m_uiStudentID(uiStudentID) {}

    unsigned int getStudentID() const {
        return m_uiStudentID;
    }

    std::string getName() const override {
        return "Student " + Person::getName();
    }
};

int main() {
    Person person1("John", "Doe", 30);
    std::cout << "Person Name: " << person1.getName() << std::endl;

    Student student1("Alice", "Smith", 20, 12345);
    std::cout << "Student Name: " << student1.getName() << std::endl;

    Person person2 = student1;
    std::cout << "Person2 Name (after assigning Student): " << person2.getName() << std::endl;

    return 0;
}