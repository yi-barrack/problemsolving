#include <stdio.h>

int main(void)
{
    char ary[101];
    while (gets(ary) != NULL)
    {
        printf("%s\n", ary);
    }
    return 0;
}