#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        sum += a * b;
    }
    if (sum == n)
        printf("Yes");
    else
        printf("No");
    return 0;
}