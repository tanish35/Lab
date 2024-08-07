#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[50];
    char address[1000];
    int marks[5];
};

struct student *createStudent()
{
    struct student *s = (struct student *)malloc(sizeof(struct student));
    printf("Enter name: ");
    scanf("%s", s->name);
    while (getchar() != '\n')
        ;
    printf("Enter address: ");
    fgets(s->address, 1000, stdin);
    for (int i = 0; i < 5; i++)
    {
        printf("Enter marks in subject %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
    return s;
}

void maxMaths(struct student *s, int n)
{
    int max = s[0].marks[0];
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i].marks[0] > max)
        {
            max = s[i].marks[0];
            index = i;
        }
    }
    printf("Student with max marks in maths is: %s\n", s[index].name);
}

void maxPhysics(struct student *s, int n)
{
    int max = s[0].marks[1];
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i].marks[1] > max)
        {
            max = s[i].marks[1];
            index = i;
        }
    }
    printf("Student with max marks in physics is: %s\n", s[index].name);
}

void maxAverage(struct student *s, int n)
{
    float max = (s[0].marks[0] + s[0].marks[1] + s[0].marks[2] + s[0].marks[3] + s[0].marks[4]) / 5.0;
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        float avg = (s[i].marks[0] + s[i].marks[1] + s[i].marks[2] + s[i].marks[3] + s[i].marks[4]) / 5.0;
        if (avg > max)
        {
            max = avg;
            index = i;
        }
    }
    printf("Student with max average marks is: %s\n", s[index].name);
}

void print(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Name: %s\n", s[i].name);
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += s[i].marks[j];
        }
        printf("Total marks: %f\n", sum);
    }
}

void failAndPass(struct student *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < 5; j++)
        {
            if (s[i].marks[j] < 40)
            {
                count++;
            }
        }
        if (count >= 3)
        {
            printf("%s has failed\n", s[i].name);
        }
        else
        {
            printf("%s has passed\n", s[i].name);
        }
    }
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student *s = (struct student *)malloc(n * sizeof(struct student));
    for (int i = 0; i < n; i++)
    {
        s[i] = *createStudent();
    }
    failAndPass(s, n);
    maxMaths(s, n);
    maxPhysics(s, n);
    maxAverage(s, n);
    print(s, n);
    return 0;
}
