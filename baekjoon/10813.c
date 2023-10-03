#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a = 0, b = 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        arr[i] = i+1;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        int tmp = arr[a-1];
        arr[a-1] = arr[b-1];
        arr[b-1] = tmp;
    }

    for (int i = 0; i < n;i++)
        printf("%d ", arr[i]);

        return 0;
}