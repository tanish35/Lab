#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int digit;
    struct Node *next;
};

struct Node *createNode(int digit)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int digit)
{
    struct Node *newNode = createNode(digit);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node *addLargeNumbers(struct Node *num1, struct Node *num2)
{
    struct Node *result = NULL;
    struct Node *p1 = num1, *p2 = num2;
    int carry = 0;

    while (p1 != NULL || p2 != NULL)
    {
        int sum = carry;
        if (p1 != NULL)
        {
            sum += p1->digit;
            p1 = p1->next;
        }
        if (p2 != NULL)
        {
            sum += p2->digit;
            p2 = p2->next;
        }
        carry = sum / 10;
        insertAtEnd(&result, sum % 10);
    }

    if (carry > 0)
    {
        insertAtEnd(&result, carry);
    }

    return result;
}

void printNumber(struct Node *head)
{
    if (head == NULL)
        return;
    printNumber(head->next);
    printf("%d", head->digit);
}

int main()
{
    char numStr1[1001], numStr2[1001];
    struct Node *num1 = NULL, *num2 = NULL;

    printf("Enter the first large number: ");
    scanf("%s", numStr1);
    printf("Enter the second large number: ");
    scanf("%s", numStr2);

    for (int i = strlen(numStr1) - 1; i >= 0; i--)
    {
        insertAtEnd(&num1, numStr1[i] - '0');
    }

    for (int i = strlen(numStr2) - 1; i >= 0; i--)
    {
        insertAtEnd(&num2, numStr2[i] - '0');
    }

    struct Node *result = addLargeNumbers(num1, num2);

    printf("Sum: ");
    printNumber(result);
    printf("\n");

    return 0;
}
