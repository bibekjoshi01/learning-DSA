#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, j, k;
    float a[20][21], factor;

    printf("\nGauss Jordan Method\n");
    printf("\nImplmented by: Bibek Joshi\n");

    printf("Enter the number of unknowns (n): ");
    scanf("%d", &n);

    if (n > 20)
    {
        printf("Matrix size exceeds predefined limit.\n");
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

    // Gauss-Jordan Elimination Process
    for (i = 0; i < n; i++)
    {
        // Partial Pivoting
        if (fabs(a[i][i]) < 1e-6)
        {
            for (k = i + 1; k < n; k++)
            {
                if (fabs(a[k][i]) > fabs(a[i][i]))
                {
                    for (j = 0; j <= n; j++)
                    {
                        float temp = a[i][j];
                        a[i][j] = a[k][j];
                        a[k][j] = temp;
                    }
                    break;
                }
            }
        }

        // Make the pivot element 1
        factor = a[i][i];
        if (fabs(factor) < 1e-6)
        {
            printf("Mathematical Error! Division by zero or near-zero pivot detected.\n");
            return 1;
        }
        for (j = 0; j <= n; j++)
        {
            a[i][j] /= factor;
        }

        // Make all elements in the current column (except pivot) zero
        for (k = 0; k < n; k++)
        {
            if (k != i)
            {
                factor = a[k][i];
                for (j = 0; j <= n; j++)
                {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

    // Output the solution
    printf("\nThe system is consistent, and the unique solution is:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %0.6f\n", i + 1, a[i][n]);
    }

    return 0;
}
