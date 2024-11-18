/* Using technique:  Binary Exponentiation (also known as Exponentiation by Squaring) */
// The idea behind binary exponentiation is to reduce the number of multiplications by leveraging the binary representation of the exponent.
// Instead of multiplying a number x by itself n times,
// we break down the problem by squaring the base, reducing the exponent by half at each step.

#include <iostream>

using namespace std;

/* The main goal of binary exponentiation is to compute large powers of a number quickly.
For example, suppose we want to find 2^9.
Instead of multiplying 2 by itself 9 times, we can use a shortcut method by "breaking down" the exponent. */

double calculate_pow(double x, int n)
{

    // handling corner cases
    if (n == 0)
        return 0.0;
    if (x == 0)
        return 0.0;
    if (x == 1)
        return 1.0;
    if (x == -1 && n % 2 == 0)
        return 1.0;
    if (x == -1 && n % 2 != 0)
        return -1.0;

    // handling for negative powers
    if (n < 0)
    {
        x = 1 / x;
        n = abs(n);
    }

    double result = 1;
    double base = x;

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result *= base;
        }
        base *= base;

        n /= 2;
    }

    return result;
}

int main()
{
    double result = calculate_pow(5, -1);
    cout << "Result: " << result << endl;

    return 0;
}