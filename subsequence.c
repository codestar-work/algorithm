// compile: gcc subsequence.c
// execute: ./a.out < subsequence.txt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 512

long count(char *s, char *p) {
	long table[MAX_LENGTH][MAX_LENGTH];

	for (int i = 0; i < MAX_LENGTH; i++) {
		for (int j = 0; j < MAX_LENGTH; j++) {
			table[i][j] = 0;
		}
	}

	if (s[0] == p[0]) {
		table[0][0] = 1;
	}
	for (int i = 1; i < (int)strlen(s); i++) {
		if (s[i] == p[0]) {
			table[i][0] = table[i-1][0] + 1;
		} else {
			table[i][0] = table[i-1][0];
		}
	}

	for (int j = 1; j < (int)strlen(p); j++) {
		for (int i = 1; i < (int)strlen(s); i++) {
			table[i][j] += table[i-1][j];
			if (s[i] == p[j]) {
				table[i][j] += table[i-1][j-1];
			}
			table[i][j] %= 10000;
		}
	}

	/*
	printf("\n\t");
	for (int i = 0; i < (int)strlen(p); i++) {
		printf("%c\t", p[i]);
	}
	printf("\n");
	for (int i = 0; i < (int)strlen(s); i++) {
		printf("%c\t", s[i]);
		for (int j = 0; j < strlen(p); j++) {
			printf("%ld\t", table[i][j]);
		}
		printf("\n");
	}
	*/
	return table[strlen(s)-1][strlen(p)-1];
}

char s[MAX_LENGTH * 2];
char p[] = "welcome to code jam";

int main() {
	int T;
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++) {
		gets((char*)s);
		long result = count(s, p);
		printf("Case #%d: %04ld\n", t, result % 10000);
	}
	return 0;
}
