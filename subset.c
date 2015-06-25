#include <stdio.h>
#include <string.h>

int count = 0;
void subset(char *s, int k) {
	char t;
	if (k == 0) {
		count++;
		printf("%4d %s\n", count, s);
	} else {
		k--;
		subset(s, k);
		t = s[k];
		s[k] = ' ';
		subset(s, k);
		s[k] = t;
	}
}

int main() {
	char s[26];
	strcpy(s, "ABCDEFG");
	subset(s, strlen(s));
	return 0;
}
