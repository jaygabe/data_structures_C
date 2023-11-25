#include <stdio.h>

void func(int n)
{
    if (n > 0)
    {
        func(n - 1);
        printf("%d\n", n);
    }
}

void main() 
{
    int x = 3;
    func(x);
}