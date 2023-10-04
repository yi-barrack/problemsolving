#include <stdio.h>


int main(){
    int n=28;
    int arr[28];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n-1;i++){
        for (int j = i + 1; j < n;j++){
            if (arr[i]>arr[j]){
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != cnt)
        {
            printf("%d\n", cnt);
            i--;
        }
        cnt++;
    }
    return 0;
}