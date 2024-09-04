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
    void virtual printDetails()
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

    Person *people[4];
    people[0] = new Person("Alice", 30, 170);
    people[1] = new Student("Bob", 22, 175, 54321, 2018);
    people[2] = new Person("Charlie", 35, 165);
    people[3] = new Student("David", 24, 180, 67890, 2019);

    for (int i = 0; i < 4; i++)
    {
        people[i]->printDetails();
        cout << endl;
    }

    return 0;
}