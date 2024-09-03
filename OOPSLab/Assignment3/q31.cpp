#include <iostream>
using namespace std;

class Person
{
    string name;
    int age;
    int height;

public:
    Person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
    void printDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << endl;
    }
};

class Student : public Person
{
    int rollNo;
    int yearOfAdmission;

public:
    Student(string name, int age, int height, int rollNo, int yearOfAdmission) : Person(name, age, height)
    {
        this->rollNo = rollNo;
        this->yearOfAdmission = yearOfAdmission;
    }
    void printDetails()
    {
        Person::printDetails();
        cout << "Roll No: " << rollNo << endl;
        cout << "Year of Admission: " << yearOfAdmission << endl;
    }
};

int main()
{
    Student s("John Doe", 20, 180, 12345, 2020);
    Person p("Jane Doe", 25, 160);

    s.printDetails();

    return 0;
}