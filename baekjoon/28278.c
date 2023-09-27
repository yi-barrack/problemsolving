#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int S[1000000];
    int rank;
} Stack;

void push(Stack *s, int data);
int pop(Stack *s);

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->rank = -1;

    int n = 0, mod = 0, data = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mod);
        if (mod == 1)
        {
            scanf("%d", &data);
            push(s, data);
        }
        else if (mod == 2)
        {
            printf("%d\n", pop(s));
        }
        else if (mod == 3)
        {
            printf("%d\n", s->rank + 1);
        }
        else if (mod == 4)
        {
            if (s->rank==-1)
                printf("1\n");
            else
                printf("0\n");
        }
        else
        {
            if (s->rank!=-1)
                printf("%d\n", s->S[s->rank]);
            else
                printf("-1\n");
        }
    }
    free(s);

    return 0;
}

void push(Stack *s, int data)
{
    s->rank++;
    s->S[s->rank] = data;
    return;
}

int pop(Stack *s){
    if (s->rank == -1)
        return -1;
    int pop_data = s->S[s->rank];
    s->rank--;
    return pop_data;
}