#include <stdio.h>
#include <stdlib.h>


typedef struct Coor{
    int x;
    int y;
} Coor;

void mergesort(Coor arr[], int n);
void rmergesort(Coor arr[], int l, int r);
void merge(Coor arr[], int l, int m, int r);

int main(){
    int n;
    scanf("%d", &n);
    Coor *arr = (Coor *)malloc(sizeof(Coor) * n);

    for (int i = 0; i < n;i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);

    mergesort(arr, n);

    for (int i = 0; i < n;i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    free(arr);
    return 0;
}

void mergesort(Coor arr[], int n){
    rmergesort(arr, 0, n - 1);
    return;
}

void rmergesort(Coor arr[], int l, int r){
    if (l<r){
        int m = (l + r) / 2;
        rmergesort(arr, l, m);
        rmergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    return;
}

void merge(Coor arr[], int l, int m, int r){
    int i=l, k = 0;
    int j = m + 1;
    Coor b[r - l + 1];
    while (i <= m && j <= r)
    {
        if (arr[i].x == arr[j].x){
            if (arr[i].y <= arr[j].y)
                b[k++] = arr[i++];
            else
                b[k++] = arr[j++];
        }
        else if (arr[i].x <= arr[j].x)
            b[k++] = arr[i++];
        else 
            b[k++] = arr[j++];
        }

    while (i<=m)
        b[k++] = arr[i++];
    
    while (j<=r)
        b[k++] = arr[j++];

    for (k = l, i=0; k <= r;k++,i++)
        arr[k] = b[k];
    return;
}