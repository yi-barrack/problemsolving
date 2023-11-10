#include <stdio.h>
#include <string.h>

int main(){
    char ch[101];
    scanf("%s", ch);
    int offset = 'a' - 'A';
    for (int i = 0; i < strlen(ch); i++)
    {
        if ('a'<=ch[i] && ch[i]<='z')
            ch[i] -= offset;
        else
            ch[i] += offset;
    }

    printf("%s", ch);
}