#include <stdio.h>

void MergeSort(int arr[], int L, int R);

int temp[1000000];

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return 0;
}

void MergeSort(int arr[], int L, int R)
{
    if (L >= R)
        return;

    int M = (L + R) / 2;

    // Divide

    MergeSort(arr, L, M);
    MergeSort(arr ,M + 1, R);

    // Conquer

    for (int i = L, l = L, r = M + 1;
         l != M + 1 || r != R + 1;
         i++)
    {

        if ((r != R + 1 && l <= M && arr[l] < arr[r]) || r == R + 1)
        {
            temp[i] = arr[l++];
        }
        else
        {
            temp[i] = arr[r++];
        }
    }

    for (int i = L; i <= R; i++)
    {
        arr[i] = temp[i];
    }
}