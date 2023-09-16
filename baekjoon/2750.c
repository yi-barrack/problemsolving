#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n);

int main(){
    int n = 0, *arr = NULL;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr, n);

    for (int i = 0; i < n;i++)
        printf("%d\n", arr[i]);

    return 0;
}

void sort(int arr[], int n){
    int tmp = 0;
    for (int pass = 0; pass < n - 1;pass++){
        for (int j = pass + 1; j < n;j++){
            if (arr[pass] > arr[j]){
                tmp = arr[pass];
                arr[pass] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}