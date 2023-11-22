#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[100][100] = {0, };
    int n, x, y, count = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        for(int j = x; j < x + 10; j++){
            for(int k = y; k < y + 10; k++){
                if(arr[j][k] == 0){
                    arr[j][k] = 1;
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
}