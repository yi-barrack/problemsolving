#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)
void mergesort(char *ch[], int n);

void rmergesort(char *ch[], int l, int r, int n);

void merge(char *ch[], int l, int m, int r, int n);

void swap(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    char **ch = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
        ch[i] = (char *)malloc(sizeof(char) * 51);

    for (int i = 0; i < n; i++)
        scanf("%s", ch[i]);

    mergesort(ch, n);

    for (int i = 0, j = 0; i < n;)
    {
        printf("%s\n", ch[i]);
        while (i < n && strcmp(ch[i], ch[j]) == 0)
            i++;
        j = i;
    }

    for (int i = 0; i < n; i++)
        free(ch[i]);
    free(ch);
}

void mergesort(char *ch[], int n)
{
    rmergesort(ch, 0, n - 1, n);
    return;
}

void rmergesort(char *ch[], int l, int r, int n)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        rmergesort(ch, l, m, n);
        rmergesort(ch, m + 1, r, n);
        merge(ch, l, m, r, n);
    }
    return;
}

void merge(char *ch[], int l, int m, int r, int n)
{
    int i = l, k = l;
    int j = m + 1;
    char **arr = (char **)malloc(sizeof(char *) * n);
    for (int v = 0; v < n; v++)
        arr[v] = (char *)malloc(sizeof(char) * 51);

    while (i <= m && j <= r)
    {
        if (strlen(ch[i]) < strlen(ch[j]))
            strcpy(arr[k++], ch[i++]);

        else if (strlen(ch[i]) > strlen(ch[j]))
            strcpy(arr[k++], ch[j++]);

        else
        {
            if (strcmp(ch[i], ch[j]) < 0)
                strcpy(arr[k++], ch[i++]);
            else
                strcpy(arr[k++], ch[j++]);
        }
    }

    while (i <= m)
        strcpy(arr[k++], ch[i++]);

    while (j <= r)
        strcpy(arr[k++], ch[j++]);

    for (k = l; k <= r; k++)
        strcpy(ch[k], arr[k]);

    for (int v = 0; v < n; v++)
        free(arr[v]);
    free(arr);
}