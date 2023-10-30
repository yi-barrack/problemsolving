#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)

void hanoi(int n, int l, int m, int r);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (int)(pow(2, n) - 1));
    hanoi(n, 1, 2, 3);
}

void hanoi(int n, int l, int m, int r)
{
    if (n == 1)
    {
        printf("%d %d\n", l, r);
        return;
    }
    else
    {
        hanoi(n - 1, l, r, m);
        printf("%d %d\n", l, r);
        hanoi(n - 1, m, l , r);
    }
}