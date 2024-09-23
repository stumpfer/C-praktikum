#include <iostream>
#include <string>

class Person {
protected:
    std::string m_sName;
    std::string m_sSurname;
    int m_iAge;

public:
    Person(std::string sName, std::string sSurname, int iAge)
        : m_sName(sName), m_sSurname(sSurname), m_iAge(iAge) {}

    Person() : m_sName(""), m_sSurname(""), m_iAge(0) {}

    virtual void getName() const {
        std::cout << "Name: " << m_sName << ", Surname: " << m_sSurname << ", Age: " << m_iAge << std::endl;
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
    void getName() const override {
        std::cout << "Student Name: " << m_sName << ", Surname: " << m_sSurname << ", Age: " << m_iAge
                  << ", StudentID: " << m_uiStudentID << std::endl;
    }
};

int main() {
    Person *persons[3];
    persons[0] = new Student("Alice", "Smith", 20, 123232);
    persons[1] = new Student("Bob", "Scott", 21, 232451);
    persons[2] = new Student("Charlie", "Viet", 22, 142134);

    for (int i = 0; i < 3; i++) {
        persons[i]->getName();  
    }

    for (int i = 0; i < 3; i++) {
        delete persons[i];
    }

    return 0;
}