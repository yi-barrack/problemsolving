#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char ch[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", ch);
        int r = strlen(ch);
        printf("%c%c\n", ch[0], ch[r - 1]);
    }
    return 0;
}