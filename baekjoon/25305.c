#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int n);

int main()
{
    int n = 0, k = 0;
    int arr[1000] = {
        0,
    };
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, n);

    printf("%d", arr[k-1]);
    return 0;
}

void sort(int* arr, int n){
    for (int i = 0; i < n-1;i++){
        int maxloc = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j]>arr[maxloc]){
                maxloc = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[maxloc];
        arr[maxloc] = tmp;
    }
    return;
}