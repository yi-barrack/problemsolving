#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int n);

int main(){
    int arr[10], t;
    scanf("%d", &t);
    for (int i = 0; i < t;i++){
        for (int j = 0; j < 10;j++)
            scanf("%d", &arr[j]);

        quicksort(arr, 10);

        printf("%d\n", arr[7]);
    }



    return 0;
}

void quicksort(int arr[], int n){
    int pivot, temp;
    int i, j;

    if(n>1){
        pivot = arr[n / 2];
        for (i = 0, j = n - 1;;i++, j--){
            while(arr[i]<pivot)
                i++;
            while(arr[j]>pivot)
                j--;
            if(i>=j)
                break;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        quicksort(arr, i);
        quicksort(arr + i, n - i);
    }
}
