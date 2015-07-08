#include <stdio.h>
#include <string.h>

int count = 0;
void permute(char *s, int k) {
	if (k == 0) {
		count++;
		printf("%4d %s\n", count, s);
	} else {
		for (int i = k; i >= 0; i--) {
			char t;
			t = s[i]; s[i] = s[k]; s[k] = t;
			permute(s, k-1);
			t = s[i]; s[i] = s[k]; s[k] = t;
		}
	}
}

char s[26];
int main() {
	strcpy(s, "ABCDE");
	permute(s, strlen(s)-1);
	return 0;
}
