#include <stdio.h>
#include <string.h>

int main(){
    char S[1001];
    scanf("%s", S);
    int n;
    scanf("%d", &n);
    printf("%c", S[n-1]);
    return 0;
}