#include <stdio.h>
#pragma warning(disable : 4996)
int main()
{
    long long a, b, c;
    scanf("%ld %ld %ld", &a, &b, &c);
    long long sum = a + b + c;
    printf("%ld", sum);
    return 0;
}