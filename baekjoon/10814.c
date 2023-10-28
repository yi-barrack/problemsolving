#include <stdio.h>
#include <stdlib.h>

typedef struct dictionary {
    int key;
    char value[201];
} dictionary;

void mergesort(dictionary d[], int l, int r);

int main(){
    int n;
    scanf("%d", &n);
    dictionary *d = (dictionary *)malloc(sizeof(dictionary) * n);
    for (int i=0;i<n;i++)
        scanf("%d %s", &d[i].key, d[i].value);

    mergesort(d, 0, n-1);

    for (int i=0;i<n;i++)
        printf("%d %s\n", d[i].key, d[i].value);


    free(d);
}

void mergesort(dictionary d[], int l, int r){
    if (l < r){
        int m = (l + r) / 2;
        mergesort(d, l, m);
        mergesort(d, m+1, r);
        merge(d, l, m, r);
    }
}

void merge(dictionary d[], int l, int m, int r){
    int i = l, j = m+1, k = l;
    dictionary *tmp = (dictionary *)malloc(sizeof(dictionary) * (r+1));
    while (i <= m && j <= r){
        if (d[i].key <= d[j].key)
            tmp[k++] = d[i++];
        else
            tmp[k++] = d[j++];
    }
    while (i <= m)
        tmp[k++] = d[i++];
    while (j <= r)
        tmp[k++] = d[j++];
    for (int i=l;i<=r;i++)
        d[i] = tmp[i];
    free(tmp);
}