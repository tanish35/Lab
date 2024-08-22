#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1001

void addLargeNumbers(char num1[], char num2[], char result[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0;
    int i, j, k;

    strrev(num1);
    strrev(num2);

    for (i = 0; i < MAX_DIGITS; i++)
    {
        result[i] = '0';
    }

    for (i = 0, j = 0, k = 0; i < len1 || j < len2 || carry; i++, j++, k++)
    {
        int digit1 = (i < len1) ? num1[i] - '0' : 0;
        int digit2 = (j < len2) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        result[k] = (sum % 10) + '0';
        carry = sum / 10;
    }

    result[k] = '\0';
    strrev(result);
}

void printNumber(char num[])
{
    int i = 0;
    while (num[i] == '0')
    {
        i++;
    }
    if (num[i] == '\0')
    {
        printf("0");
    }
    else
    {
        printf("%s", num + i);
    }
}

int main()
{
    char num1[MAX_DIGITS], num2[MAX_DIGITS], result[MAX_DIGITS];

    printf("Enter the first large number: ");
    scanf("%s", num1);
    printf("Enter the second large number: ");
    scanf("%s", num2);

    addLargeNumbers(num1, num2, result);

    printf("Sum: ");
    printNumber(result);
    printf("\n");

    return 0;
}
