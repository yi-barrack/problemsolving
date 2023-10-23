#include <stdio.h>

int main(){
    int row = 0, col = 0, max = 0;
    int arr[9][9];
    for (int i = 0; i < 9;i++){
        for (int j = 0; j < 9;j++){
            scanf("%d", &arr[i][j]);
            if (arr[i][j]>max){
                row = i;
                col = j;
                max = arr[i][j];
            }
        }
    }
    printf("%d\n", max);
    printf("%d %d", row+1, col+1);
    return 0;
}