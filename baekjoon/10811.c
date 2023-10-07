#include <stdio.h>

void swap(int arr[], int a, int b);

int main(){
    int n,m, arr[100];
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n;i++){
        arr[i] = i+1;
    }
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            swap(arr, a-1, b-1);
        }
    for (int i = 0; i < n;i++)
        printf("%d ", arr[i]);
}

void swap(int arr[], int a, int b){
    while(a<b){
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        a++;
        b--;
    }
    return;
}