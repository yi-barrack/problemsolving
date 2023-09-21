#include <stdio.h>

void quickSort(int arr[], int L, int R);

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return 0;
}

void quickSort(int arr[], int L, int R)
{
    // 좌우 설정 및 피벗값 설정
    int left = L, right = R;
    int pivot = arr[(L + R) / 2];
    int temp = 0;
    // 좌우 비교
    do
    {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;
        if (left <= right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);

    if (L < right)
        quickSort(arr, L, right);

    if (left < R)
        quickSort(arr, left, R);
}