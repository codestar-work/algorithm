// compile: gcc partition.c
// execute: ./a.out

#include <stdio.h>
#define MAX 1024

int solve(int a [], int n) {
	int sum = 0;
	char p[MAX][MAX];

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			p[i][j] = 0;
		}
	}

	for (int j = 0; j < n; j++) {
		sum += a[j];
	}
	if (sum % 2 != 0)
		return 0;
	p[0][0] = 1;
	p[a[0]][0] = 1;
	for (int j = 1; j < n; j++) {
		for (int i = 0; i <= sum; i++) {
			int previous = i - a[j];
			if (previous >= 0 && p[previous][j-1]) {
				p[i][j] = 1;
			}
			if (p[i][j-1]) {
				p[i][j] = 1;
			}
		}
	}

	return p[sum/2][n-1];
}


int main() {
	int a[] = {5, 2, 1, 8};
	char result = solve(a, 4);
	printf("%s\n", result ? "Yes" : "No");
	return 0;
}
