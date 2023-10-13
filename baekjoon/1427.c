#include <stdio.h>
#include <stdlib.h>

void mergesort(int arr[], int n);
void rmergesort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);


int main(){
    int arr[11];
    long long a;
    int n=0;

    scanf("%lld", &a);
    long long b = a;
    while (b>0){
        b /= 10;
        n++;
        }

        for (int i = 0; i < n; i++){
            arr[i] = a % 10;
            a = a/10;
        }

        mergesort(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d", arr[i]);

        return 0;
}

void mergesort(int arr[], int n){
    rmergesort(arr, 0, n - 1);
    return;
}

void rmergesort(int arr[], int l, int r){
    if (l<r){
        int m = (l + r) / 2;
        rmergesort(arr, l, m);
        rmergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r){
    int b[11];
    int i = l, k = l;
    int j = m + 1;
    while(i<=m && j<=r){
        if(arr[i]>=arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }
    while(i<=m)
        b[k++] = arr[i++];
    while(j<=r)
        b[k++] = arr[j++];
    for (int k = l; k <= r;k++)
        arr[k] = b[k];

    return;
}