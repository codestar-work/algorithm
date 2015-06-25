// compile: gcc prisoners.c
// run:     ./a.out < prisoners.txt

#include <stdio.h>
#define MAX 10000

int cache[MAX+1][MAX+1];
int a[MAX];
int N, P;

int solve(int L, int R) {
	if (cache[L][R] == -1) {
		int min = 0;
		for (int i = 0; i < N; i++) {
			if (a[i] >= L && a[i] <= R) {
				int cost = R-L;
				int costL = solve(L, a[i]-1);
				int costR = solve(a[i]+1, R);
				int sum = cost + costL + costR;
				if (min == 0)
					min = sum;
				if (min > sum)
					min = sum;
			}
		}
		cache[L][R] = min;
		return min;
	} else {
		return cache[L][R];
	}
}

int main() {
	int T;
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++) {
		int result = 0;
		scanf("%d %d\n", &P, &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i <= P; i++) {
			for (int j = 0; j <= P; j++) {
				cache[i][j] = -1;
			}
		}
		result = solve(1, P);
		printf("Case #%d: %d\n", t, result);
	}
	return 0;
}
