/* Program to generate the fibonacci series upto nth term */

#include <stdio.h>
#include <stdlib.h>

// void generateFibonacciSeries(int n)
// {
//     int first = 0;
//     int second = 1;
//     for (int i = 0; i <= n; i++)
//     {
//         if (i == 0 || i == 1)
//         {
//             printf("%d\t", i);
//         }
//         else
//         {
//             int current = first + second;
//             printf("%d\t", current);
//             first = second;
//             second = current;
//         }
//     }
// }

int generateFibonacciSeries(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return generateFibonacciSeries(n - 1) + generateFibonacciSeries(n - 2);
    }
}

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", generateFibonacciSeries(i));
    }
    return 0;
}