#include<stdio.h>

int main()
{
	int t, n;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);

		int cnt = 0;

		//이진수로 변환 후 출력
		while (n != 0)
		{
			if (n % 2 == 1) {
				printf("%d ", cnt);
			}
			n = n / 2;
			cnt++;
		}
		printf("\n");
	}

	return 0;
}