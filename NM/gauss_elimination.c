#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k;
    float a[20][21], x[20], ratio, sum;

    printf("\nGauss Elimination Method\n");
    printf("\nImplmented by: Bibek Joshi\n");

    printf("\nEnter the size of the coefficient matrix A (number of unknowns): ");
    scanf("%d", &n);

    if (n > 20)
    {
        printf("Matrix size exceeds the predefined limit.\n");
        return 1;
    }

    printf("Enter the elements of the augmented matrix [A|C]:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }

    // Partial Pivoting and Gaussian Elimination
    for (k = 0; k < n - 1; k++)
    {
        for (i = k + 1; i < n; i++)
        {
            if (fabs(a[k][k]) < 1e-6)
            {
                printf("Mathematical Error! Division by zero or near-zero detected.\n");
                exit(0);
            }
            ratio = a[i][k] / a[k][k];
            for (j = k; j <= n; j++)
            {
                a[i][j] -= ratio * a[k][j];
            }
        }
    }

    // Back Substitution
    for (i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum += a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Display Solution
    printf("The system is consistent, and the unique solution is:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %0.6f\n", i + 1, x[i]);
    }

    return 0;
}
