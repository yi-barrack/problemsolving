#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int A[100][100];
    int B[100][100];

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            scanf("%d", &A[i][j]);
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            scanf("%d", &B[i][j]);
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            A[i][j] += B[i][j];
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }

}