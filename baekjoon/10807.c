#include <stdio.h>

int main(){
    int arr[100], n, find,cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &find);
    for (int i = 0; i < n;i++){
        if (arr[i] == find)
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}