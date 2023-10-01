#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sort(char arr[][21], int l, int r);
void merge(char arr[][21], int l, int m, int r);

int main()
{
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
    char ch[1000000][21];
    char same[500000][21];

    for (int i = 0; i < n + m; i++)
    {
        scanf("%s", ch[i]);
    }

    sort(ch, 0, n + m);

        for (int i = 0; i < n + m; i++)
        {
            if (strcmp(ch[i], ch[i + 1]) == 0)
            {
                strcpy(same[cnt], ch[i]);
                cnt++;
                i++;
            }
        }

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n", same[i]);
    }

    return 0;
}

void sort(char arr[][21], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    return;
}
void merge(char arr[][21], int l, int m, int r)
{
    int i = l, k = l;
    int j = m + 1;
    char buf[500000][21];
    while (i <= m && j <= r)
    {
        if (strcmp(arr[i], arr[j]) < 0)
        {
            strcpy(buf[k++], arr[i++]);
        }
        else
            strcpy(buf[k++], arr[j++]);
    }
    while (i <= m)
        strcpy(buf[k++], arr[i++]);
    while (j <= r)
        strcpy(buf[k++], arr[j++]);
    for (k=l; k <= r; k++)
        strcpy(arr[k], buf[k]);
    return;
}