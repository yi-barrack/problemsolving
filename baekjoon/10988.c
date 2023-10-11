#include <stdio.h>
#include <string.h>

int main(){
    char ch[101];
    scanf("%s", ch);
    int len = strlen(ch);
    int l = 0, r = len-1;
    while(l<=r){
        if (ch[l]!=ch[r]){
            printf("0");
            return 0;
        }
        l++;
        r--;
    }
    printf("1");
    return 0;
}