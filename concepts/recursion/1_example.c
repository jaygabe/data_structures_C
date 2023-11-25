#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        func(n - 1);
    }
}

void main() 
{
    int x = 3;
    func(x);
}