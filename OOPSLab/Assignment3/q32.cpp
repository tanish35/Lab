#include <iostream>
using namespace std;

class Employee
{
    string name;
    int salary;

public:
    Employee(string name, int salary)
    {
        this->name = name;
        this->salary = salary;
    }
    int getSalary()
    {
        return salary;
    }
    void virtual printDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee
{
    int type;
    int allowance;

public:
    Manager(string name, int salary, int type, int allowance) : Employee(name, salary)
    {
        this->type = type;
        this->allowance = allowance;
    }
    void printDetails()
    {
        Employee::printDetails();
        cout << "Type: " << type << endl;
        cout << "Allowance: " << allowance << endl;
    }
};

class Clerk : public Employee
{
    int type;
    int allowance;

public:
    Clerk(string name, int salary, int type, int allowance) : Employee(name, salary)
    {
        this->type = type;
        this->allowance = allowance;
    }
    void printDetails()
    {
        Employee::printDetails();
        cout << "Type: " << type << endl;
        cout << "Allowance: " << allowance << endl;
    }
};

int main()
{
    Employee *e[6];
    e[0] = new Employee("Alice", 30000);
    e[1] = new Manager("Bob", 50000, 1, 10000);
    e[2] = new Clerk("Charlie", 20000, 2, 5000);
    e[3] = new Employee("David", 40000);
    e[4] = new Manager("Eve", 60000, 1, 15000);
    e[5] = new Clerk("Frank", 25000, 2, 6000);

    int totSal = 0;
    for (int i = 0; i < 6; i++)
    {
        e[i]->printDetails();
        cout << endl;
        totSal += e[i]->getSalary();
    }

    cout << "Total Salary: " << totSal << endl;

    return 0;
}