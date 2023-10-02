#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int s[1000];
    int rank;
} Stack;

void push(Stack *s, int data);
int pop(Stack *s);
int peek(Stack *s)
{
    return s->s[s->rank];
}
int is_empty(Stack *s)
{
    return s->rank == -1 ? 1 : 0;
}

int main()
{
    Stack *a = (Stack *)malloc(sizeof(Stack));
    a->rank = -1;
    Stack *b = (Stack *)malloc(sizeof(Stack));
    b->rank = -1;
    int n, data, cnt = 1, arr[1000] = {
                              0,
                          };
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        push(a, arr[i]);
    }

    while (!is_empty(a))
    {
        if (peek(a)==cnt || peek(b)==cnt){
            if (peek(a)==cnt){
                pop(a);
                cnt++;
            }
            else{
                pop(b);
                cnt++;
            }
        }
        else
            push(b, pop(a));
    }
    while (!is_empty(b))
    {
        if (peek(b)==cnt){
            pop(b);
            cnt++;
        }
        else
        {
            printf("Sad");
            return 0;
        }
    }
    if (is_empty(a) && is_empty(b))
    {
        printf("Nice");
        return 0;
    }
    printf("Sad");

    return 0;
}

int pop(Stack *s)
{
    if (s->rank == -1)
    {
        printf("stack empty\n");
        return -1;
    }
    int pop = s->s[s->rank];
    s->rank--;
    return pop;
}

void push(Stack *s, int data)
{
    if (s->rank >= 1000)
    {
        printf("stack over flow\n");
        return;
    }
    s->rank++;
    s->s[s->rank] = data;
    return;
}