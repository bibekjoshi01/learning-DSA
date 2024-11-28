#include <iostream>

using namespace std;

int main()
{
    int var = 5;
    int *ptr = &var;
    int **ptr2 = &ptr;

    int *ptr3 = NULL; // null poinnter

    cout << &var << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    cout << ptr2 << endl;
    cout << *ptr2 << endl;
    cout << **ptr2 << endl;

    cout << ptr3 << endl;
    cout << *ptr3 << endl;

    return 0;
}