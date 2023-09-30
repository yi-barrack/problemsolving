#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int *arr = (int *)malloc(sizeof(arr)*(n+1));
    for (int l = 0; l< m; l++)
    {
        int i = 0, j = 0, k = 0;
        scanf("%d %d %d", &i, &j, &k);
        for (i; i <= j;i++){
            arr[i] = k;
        }
    }
    for (int i = 0; i < n;i++){
        printf("%d ", arr[i + 1]);
    }
        free(arr);
    return 0;
}