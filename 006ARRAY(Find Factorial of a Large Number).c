//Given a non-negative integer n, find n! and return a list of integers representing the digits of the factorial. 
#include <stdio.h>

#define MAX 10000

void factorial(int n)
{
    int result[MAX];
    int size = 1;

    result[0] = 1;

    for (int x = 2; x <= n; x++)
    {
        int carry = 0;

        for (int i = 0; i < size; i++)
        {
            int product = result[i] * x + carry;

            result[i] = product % 10;
            carry = product / 10;
        }

        while (carry > 0)
        {
            result[size] = carry % 10;
            carry = carry / 10;
            size++;
        }
    }

    // Digits are stored in reverse order, so print backwards
    printf("Factorial: ");

    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", result[i]);
    }

    printf("\n");
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

    factorial(n);

    return 0;
}
