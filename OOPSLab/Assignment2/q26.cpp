#include <iostream>
#include <vector>
#include <random>
using namespace std;

class GradeCard
{
public:
    int roll;
    string name;
    string dept;
    int semester;
    vector<int> marks;
    float cgpa;

    GradeCard(int roll, string name, string dept, int semester, vector<int> marks, float cgpa)
    {
        this->roll = roll;
        this->name = name;
        this->dept = dept;
        this->semester = semester;
        this->marks = marks;
        this->cgpa = cgpa;
    }

    void display()
    {
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Semester: " << semester << endl;
        cout << "Marks: ";
        for (int i = 0; i < marks.size(); i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

int main()
{
    srand(time(0));
    vector<GradeCard> gradeCards;
    for (int i = 0; i < 60; i++)
    {
        vector<int> marks;
        for (int j = 0; j < 5; j++)
        {
            marks.push_back(rand() % 100);
        }
        float cgpa;
        int sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += marks[i] / 10;
        }
        cgpa = sum / 5.0;
        gradeCards.push_back(GradeCard(i + 1, "Student " + to_string(i + 1), "IT", 3, marks, cgpa));
    }
    GradeCard max = gradeCards[0];
    for (int i = 1; i < gradeCards.size(); i++)
    {
        if (gradeCards[i].cgpa > max.cgpa)
        {
            max = gradeCards[i];
        }
    }
    max.display();
}