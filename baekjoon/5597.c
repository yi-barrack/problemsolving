#include <stdio.h>
#pragma warning(disable:4996)



int main() {
	int arr[31];
	for (int i = 0; i < 31; i++) 
		arr[i] = i;
	int n;
	for (int i = 0; i < 28; i++) {
		scanf("%d", &n);
		for (int j = 0; j < 31; j++) {
			if (arr[j] == n)
				arr[j] = 0;
		}
	}

	for (int i = 0; i < 31; i++) {
		if (arr[i] != 0)
			printf("%d\n", arr[i]);
	}
	return 0;
}