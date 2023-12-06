#include <stdio.h>
int main()
{
    int N = 0, i = 0, j = 0;
	scanf("%d", &N);
	for (i = N; i>0; i--)
	{
		for (j = 1; j <= i; j++) printf("*");
		printf("\n");
	}
    return 0;
}
출처: https://developerin.tistory.com/33 [개발자 IN:티스토리]