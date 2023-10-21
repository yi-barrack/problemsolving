#include <stdio.h>

int main(){
    int arr[3];
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    for (int i = 0; i < 2;i++){
        for (int j = i; j < 3;j++){
            if (arr[i]>arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    for (int i = 0; i < 3;i++)
        printf("%d ", arr[i]);
    return 0;
}