#include <stdio.h>

int main(){
    char board[8][8];
    int count = 0;
    for(int i = 0; i < 8; i++){
        scanf("%s", board[i]);
        for(int j = 0; j < 8; j++){
            if((i + j) % 2 == 0 && board[i][j] == 'F') count++;
        }
    }
    printf("%d\n", count);
    return 0;
}