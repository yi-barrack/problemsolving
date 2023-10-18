#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int arr[], int n);

void rquicksort(int arr[], int l, int r);

int get_pivot(int l, int r);

int partition(int arr[], int l, int p, int r);

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    srand(time(NULL));
    int n, m;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quicksort(arr, n);

    for (int i = 0; i < n;i++)
        printf("%d\n", arr[i]);

        free(arr);
}

void quicksort(int arr[], int n)
{
    rquicksort(arr, 0, n - 1);
    return;
}

void rquicksort(int arr[], int l, int r)
{
    if (l > r)
        return;
    int k = get_pivot(l, r);
    k = partition(arr, l, k, r);
    rquicksort(arr, l, k - 1);
    rquicksort(arr, k + 1, r);
    return;
}

int get_pivot(int l, int r)
{
    return l + rand() % (r - l + 1);
}

int partition(int arr[], int l, int k, int r)
{
    int p = arr[k];
    swap(&arr[k], &arr[r]); // hide pivot
    int i = l;              // 왼쪽설정
    int j = r - 1;          // 오른쪽 설정

    while (i <= j)
    {
        while (i <= j && arr[i] <= p)
            i++;

        while (i >= j && arr[j] >= p)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[i], &arr[r]);
    return i;
}