/* Program to solve tower of honoi algorithm steps */

#include <stdio.h>
#include <stdlib.h>

void towerOfHonoi(int n, char source, char dest, char aux)
{
    if (n == 1)
    {
        printf("Moving disc %d from peg %c to peg %c\n", n, source, dest);
    }
    else
    {
        towerOfHonoi(n - 1, source, aux, dest);
        printf("Moving disc %d from peg %c, to peg %c\n", n, source, dest);
        towerOfHonoi(n - 1, aux, dest, source);
    }
}

int main()
{
    int n;
    printf("Enter the number of disc: ");
    scanf("%d", &n);
    towerOfHonoi(n, 'S', 'D', 'A');
    return 0;
}